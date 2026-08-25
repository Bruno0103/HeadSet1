/**
 * @file preview_home_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "preview_home_gen.h"
#include "../ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * preview_home_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if UI_CHECK_COMPILE_TARGET(UI_TARGET_ALL)
    if (ui_check_target(UI_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "preview_home_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_all(lv_obj_0, 0, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 0, 0);
        lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0x1A1A2E), 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

        lv_obj_add_style(lv_obj_0, &style_screen_base_global, 0);
        lv_obj_t * infobar_0 = infobar_create(lv_obj_0, &subject_battery_level);
        lv_obj_set_width(infobar_0, lv_pct(100));

        lv_obj_t * panel_0 = panel_create(lv_obj_0);
        lv_obj_set_flex_flow(panel_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(panel_0, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
        lv_obj_set_style_pad_all(panel_0, 0, 0);
        lv_obj_set_style_pad_row(panel_0, 0, 0);
        lv_obj_set_width(panel_0, lv_pct(100));
        lv_obj_set_height(panel_0, 0);
        lv_obj_set_flex_grow(panel_0, 1);
        lv_obj_set_style_bg_color(panel_0, lv_color_hex(0x0F0F12), 0);
        lv_obj_set_style_border_color(panel_0, lv_color_hex(0x26262B), 0);
        lv_obj_set_style_border_width(panel_0, 1, 0);
        lv_obj_t * image_0 = image_create(panel_0);
        lv_obj_set_width(image_0, lv_pct(100));
        lv_obj_set_height(image_0, 0);
        lv_obj_set_flex_grow(image_0, 1);
        lv_image_set_inner_align(image_0, LV_IMAGE_ALIGN_STRETCH);
        lv_image_bind_src(image_0, &subject_home_artAtual);

        lv_obj_t * column_0 = column_create(panel_0, 8, 8, 0, 0, 0, 0, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_0, lv_pct(100));
        lv_obj_set_height(column_0, 18);
        lv_obj_t * row_0 = row_create(column_0, 0, 0, 0, 0, 0, 0, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_width(row_0, lv_pct(100));
        lv_obj_set_height(row_0, LV_SIZE_CONTENT);
        lv_obj_t * label_0 = label_create(row_0);
        lv_label_set_text(label_0, "CONSUMO:");
        lv_obj_set_style_text_font(label_0, font_cousine_regular_8, 0);
        lv_obj_set_style_text_color(label_0, lv_color_hex(0x8F8F9D), 0);

        lv_obj_t * label_1 = label_create(row_0);
        lv_label_bind_text(label_1, &subject_consumo, NULL);
        lv_obj_set_style_text_font(label_1, font_cousine_bold_8, 0);
        lv_obj_set_style_text_color(label_1, lv_color_hex(0x00F0FF), 0);

        lv_obj_add_screen_create_event(panel_0, LV_EVENT_SHORT_CLICKED, screen1_create, LV_SCREEN_LOAD_ANIM_OVER_LEFT, 2, 3);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

