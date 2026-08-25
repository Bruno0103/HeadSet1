/**
 * @file bar_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "bar_gen.h"
#include "../../../ui.h"

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

lv_obj_t * bar_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_indicator;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_main);
        lv_style_init(&style_indicator);

        lv_style_set_bg_color(&style_main, CONST_BASELIB_ACCENT_GLOBAL);
        lv_style_set_bg_opa(&style_main, (255 * 16 / 100));
        lv_style_set_radius(&style_main, CONST_BASELIB_RADIUS_GLOBAL);
        lv_style_set_border_width(&style_main, 0);
        lv_style_set_pad_all(&style_main, 0);
        lv_style_set_bg_color(&style_indicator, CONST_BASELIB_ACCENT_GLOBAL);
        lv_style_set_bg_opa(&style_indicator, (255 * 100 / 100));
        lv_style_set_radius(&style_indicator, CONST_BASELIB_RADIUS_GLOBAL);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if UI_CHECK_COMPILE_TARGET(UI_TARGET_ALL)
    if (ui_check_target(UI_TARGET_ALL)) {
        lv_obj_t * lv_bar_0 = lv_bar_create(parent);
        lv_obj_set_name_static(lv_bar_0, "bar_#");

        lv_obj_remove_style_all(lv_bar_0);
        lv_obj_add_style(lv_bar_0, &style_main, 0);
        lv_obj_add_style(lv_bar_0, &style_indicator, LV_PART_INDICATOR);

        the_root = lv_bar_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

