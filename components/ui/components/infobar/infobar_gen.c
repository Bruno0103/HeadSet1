/**
 * @file infobar_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "infobar_gen.h"
#include "../../ui.h"

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

lv_obj_t * infobar_create(lv_obj_t * parent, lv_subject_t * n_76)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if UI_CHECK_COMPILE_TARGET(UI_TARGET_ALL)
    if (ui_check_target(UI_TARGET_ALL)) {
        lv_obj_t * panel_0 = panel_create(parent);
        lv_obj_set_name_static(panel_0, "infobar_#");
        lv_obj_set_flex_flow(panel_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(panel_0, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
        lv_obj_set_style_flex_cross_place(panel_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(panel_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_hor(panel_0, 6, 0);
        lv_obj_set_style_pad_ver(panel_0, 0, 0);
        lv_obj_set_style_pad_column(panel_0, 0, 0);
        lv_obj_set_width(panel_0, 128);
        lv_obj_set_height(panel_0, 16);
        lv_obj_set_style_bg_color(panel_0, lv_color_hex(0x0F0F12), 0);
        lv_obj_set_style_border_color(panel_0, lv_color_hex(0x00CCCC), 0);
        lv_obj_set_style_border_opa(panel_0, 23, 0);
        lv_obj_set_style_border_width(panel_0, 1, 0);
        lv_obj_set_style_border_side(panel_0, LV_BORDER_SIDE_BOTTOM, 0);

        lv_obj_t * container_0 = container_create(panel_0);
        lv_obj_set_flex_flow(container_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_cross_place(container_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(container_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_all(container_0, 0, 0);
        lv_obj_set_style_pad_column(container_0, 4, 0);
        lv_obj_set_width(container_0, LV_SIZE_CONTENT);
        lv_obj_set_height(container_0, LV_SIZE_CONTENT);
        lv_obj_t * container_1 = container_create(container_0);
        lv_obj_set_flex_flow(container_1, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(container_1, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(container_1, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(container_1, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_all(container_1, 0, 0);
        lv_obj_set_style_pad_row(container_1, 0, 0);
        lv_obj_set_width(container_1, 8);
        lv_obj_set_height(container_1, 8);
        lv_obj_t * image_0 = image_create(container_1);
        lv_obj_set_width(image_0, 8);
        lv_obj_set_height(image_0, 8);
        lv_image_set_src(image_0, image_music);
        lv_obj_set_flag(image_0, LV_OBJ_FLAG_SCROLLABLE, false);

        lv_obj_t * label_0 = label_create(container_0);
        lv_label_set_text(label_0, "PLAY");
        lv_obj_set_style_text_font(label_0, font_cousine_bold_8, 0);
        lv_obj_set_style_text_color(label_0, lv_color_hex(0x00F0FF), 0);

        lv_obj_t * container_2 = container_create(panel_0);
        lv_obj_set_flex_flow(container_2, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_cross_place(container_2, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(container_2, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_all(container_2, 0, 0);
        lv_obj_set_style_pad_column(container_2, 4, 0);
        lv_obj_set_width(container_2, LV_SIZE_CONTENT);
        lv_obj_set_height(container_2, LV_SIZE_CONTENT);
        lv_obj_t * container_3 = container_create(container_2);
        lv_obj_set_flex_flow(container_3, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(container_3, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(container_3, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(container_3, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_all(container_3, 0, 0);
        lv_obj_set_style_pad_row(container_3, 0, 0);
        lv_obj_set_width(container_3, 8);
        lv_obj_set_height(container_3, 8);
        lv_obj_t * image_1 = image_create(container_3);
        lv_obj_set_width(image_1, 8);
        lv_obj_set_height(image_1, 8);
        lv_image_set_src(image_1, image_bluetooth);
        lv_obj_set_flag(image_1, LV_OBJ_FLAG_SCROLLABLE, false);

        lv_obj_t * label_1 = label_create(container_2);
        lv_label_bind_text(label_1, n_76, "%d");
        lv_obj_set_style_text_font(label_1, font_cousine_regular_8, 0);
        lv_obj_set_style_text_color(label_1, lv_color_hex(0x8F8F9D), 0);

        lv_obj_t * battery_body_0 = battery_body_create(container_2, &subject_battery_level);
        lv_obj_set_width(battery_body_0, 12);
        lv_obj_set_height(battery_body_0, 6);

        the_root = panel_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

