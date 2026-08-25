/**
 * @file battery_body_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "battery_body_gen.h"
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

lv_obj_t * battery_body_create(lv_obj_t * parent, lv_subject_t * value)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_base);

        lv_style_set_bg_color(&style_base, lv_color_hex(0x00F0FF));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if UI_CHECK_COMPILE_TARGET(UI_TARGET_ALL)
    if (ui_check_target(UI_TARGET_ALL)) {
        lv_obj_t * bar_0 = bar_create(parent);
        lv_obj_set_name_static(bar_0, "battery_body_#");
        lv_obj_set_width(bar_0, 12);
        lv_obj_set_height(bar_0, 6);
        lv_bar_set_min_value(bar_0, 0);
        lv_bar_set_max_value(bar_0, 100);
        lv_bar_bind_value(bar_0, value);

        lv_obj_add_style(bar_0, &style_base, 0);

        the_root = bar_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

