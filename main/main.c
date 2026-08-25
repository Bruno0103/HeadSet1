/**
 * @file main.c
 *
 * Minimal LVGL simulator.
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_lcd_st7735.h"
#include "lvgl.h"
#include "ui.h"

#define LCD_HOST               SPI2_HOST
#define LCD_PIXEL_CLOCK_HZ     (20 * 1000 * 1000) // 20MHz
#define LCD_H_RES              128
#define LCD_V_RES              160

// Defina os pinos GPIO conforme o seu hardware
#define PIN_NUM_SCLK           23
#define PIN_NUM_MOSI           18
#define PIN_NUM_MISO           -1
#define PIN_NUM_LCD_DC         2
#define PIN_NUM_LCD_RST        4
#define PIN_NUM_LCD_CS         5
#define PIN_NUM_BK_LIGHT       -1

#define DRAW_BUF_LINES         10 // 128 * 10 * 2 bytes = 2560 bytes de buffer

static const char *TAG = "main";
static lv_display_t *lv_disp = NULL;

static bool notify_lvgl_flush_ready(esp_lcd_panel_io_handle_t panel_io, esp_lcd_panel_io_event_data_t *edata, void *user_ctx)
{
    lv_display_t *disp = (lv_display_t *)user_ctx;
    lv_display_flush_ready(disp);
    return false;
}

static void lvgl_flush_cb(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map)
{
    esp_lcd_panel_handle_t panel_handle = (esp_lcd_panel_handle_t)lv_display_get_user_data(disp);
    int offsetx1 = area->x1;
    int offsetx2 = area->x2;
    int offsety1 = area->y1;
    int offsety2 = area->y2;

    esp_lcd_panel_draw_bitmap(panel_handle, offsetx1, offsety1, offsetx2 + 1, offsety2 + 1, px_map);
}

void app_main(void)
{
    ESP_LOGI(TAG, "Iniciando SPI Bus...");
    spi_bus_config_t buscfg = {
        .sclk_io_num = PIN_NUM_SCLK,
        .mosi_io_num = PIN_NUM_MOSI,
        .miso_io_num = PIN_NUM_MISO,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = LCD_H_RES * DRAW_BUF_LINES * sizeof(uint16_t),
    };
    ESP_ERROR_CHECK(spi_bus_initialize(LCD_HOST, &buscfg, SPI_DMA_CH_AUTO));

    ESP_LOGI(TAG, "Instalando Painel IO...");
    esp_lcd_panel_io_handle_t io_handle = NULL;
    esp_lcd_panel_io_spi_config_t io_config = {
        .dc_gpio_num = PIN_NUM_LCD_DC,
        .cs_gpio_num = PIN_NUM_LCD_CS,
        .pclk_hz = LCD_PIXEL_CLOCK_HZ,
        .lcd_cmd_bits = 8,
        .lcd_param_bits = 8,
        .spi_mode = 0,
        .trans_queue_depth = 10,
        .on_color_trans_done = notify_lvgl_flush_ready,
        .user_ctx = NULL, // Atualizado após criação do display LVGL
    };
    ESP_ERROR_CHECK(esp_lcd_new_panel_io_spi((esp_lcd_spi_bus_handle_t)LCD_HOST, &io_config, &io_handle));

    ESP_LOGI(TAG, "Instalando Driver ST7735...");
    esp_lcd_panel_handle_t panel_handle = NULL;
    esp_lcd_panel_dev_config_t panel_config = {
        .reset_gpio_num = PIN_NUM_LCD_RST,
        .rgb_endian = LCD_RGB_ENDIAN_BGR,
        .bits_per_pixel = 16,
    };
    ESP_ERROR_CHECK(esp_lcd_new_panel_st7735(io_handle, &panel_config, &panel_handle));
    
    ESP_ERROR_CHECK(esp_lcd_panel_reset(panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_init(panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_disp_on_off(panel_handle, true));

    ESP_LOGI(TAG, "Inicializando LVGL 9...");
    lv_init();

    lv_disp = lv_display_create(LCD_H_RES, LCD_V_RES);
    lv_display_set_user_data(lv_disp, panel_handle);
    lv_display_set_flush_cb(lv_disp, lvgl_flush_cb);

    // Conecta o callback de flush com o contexto do display LVGL
    io_config.user_ctx = lv_disp;

    // Alocação de buffer parcial com DMA (~2.5 KB RAM)
    size_t buf_size = LCD_H_RES * DRAW_BUF_LINES * sizeof(lv_color16_t);
    void *buf1 = heap_caps_malloc(buf_size, MALLOC_CAP_DMA | MALLOC_CAP_INTERNAL);
    assert(buf1 != NULL);

    lv_display_set_buffers(lv_disp, buf1, NULL, buf_size, LV_DISPLAY_RENDER_MODE_PARTIAL);

    // Inicialização da interface exportada
    ui_init();

    ESP_LOGI(TAG, "Entrando no laço principal...");
    while (1) {
        // Executa as tarefas de renderização do LVGL
        uint32_t task_delay_ms = lv_timer_handler();
        if (task_delay_ms > 10) {
            task_delay_ms = 10;
        } else if (task_delay_ms < 1) {
            task_delay_ms = 1;
        }
        vTaskDelay(pdMS_TO_TICKS(task_delay_ms));
    }
}
