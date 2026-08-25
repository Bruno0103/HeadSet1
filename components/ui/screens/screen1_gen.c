/**
 * @file screen1_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen1_gen.h"
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

lv_obj_t * screen1_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if UI_CHECK_COMPILE_TARGET(UI_TARGET_ALL)
    if (ui_check_target(UI_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "screen1_#");
        lv_obj_set_width(lv_obj_0, lv_pct(100));

        lv_obj_t * infobar_1 = infobar_create(lv_obj_0, &subject_battery_level);
        lv_obj_set_name(infobar_1, "infobar_1");
        lv_obj_set_width(infobar_1, lv_pct(100));

        lv_obj_t * panel_1 = panel_create(lv_obj_0);
        lv_obj_set_name(panel_1, "panel_1");
        lv_obj_set_width(panel_1, lv_pct(100));
        lv_obj_set_y(panel_1, 16);
        lv_obj_set_height(panel_1, 144);
        lv_obj_add_screen_create_event(panel_1, LV_EVENT_CLICKED, preview_home_create, LV_SCREEN_LOAD_ANIM_OVER_RIGHT, 1, 1);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

