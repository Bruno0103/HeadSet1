/**
 * @file ui_gen.h
 */

#ifndef LVGL_PRO_UI_GEN_H
#define LVGL_PRO_UI_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/lvgl_private.h"
#endif

#if defined(LV_USE_XML) && LV_USE_XML
    #include "lv_xml/lv_xml.h"
#endif



/* Prototypes for target functions, needed by responsive const definitions */

void ui_set_target(uint32_t target);
uint32_t ui_get_target(void);
bool ui_check_target(uint32_t target);

/*********************
 *      DEFINES
 *********************/

#define UI_TARGET_UNDEFINED  (0 << 1)
#define UI_TARGET_TARGET1    (1 << 1)
#define UI_TARGET_ALL        0x0FFFFFFF

/* By default compile for all targets, allowing to switch to any targets at runtime */
#ifndef UI_COMPILE_TARGET
#define UI_COMPILE_TARGET UI_TARGET_ALL
#endif

#define UI_CHECK_COMPILE_TARGET(target) (UI_COMPILE_TARGET & (target) ? 1 : 0)

#define CONST_BASELIB_ACCENT_GLOBAL lv_color_hex(0x70609C)
#define CONST_BASELIB_RADIUS_GLOBAL 8
#define CONST_BASELIB_UNIT_SM_GLOBAL 4


#ifndef LV_XML_EVAL_STRING_BUF_SIZE
    #define LV_XML_EVAL_STRING_BUF_SIZE 256
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

extern lv_style_t style_screen_base_global;

/*----------------
 * Fonts
 *----------------*/

/* Targets: any */
extern lv_font_t * font_cousine_regular_8;
extern lv_font_t * font_cousine_bold_8;
extern lv_font_t * font_cousine_bold_10;
extern lv_font_t * font_cousine_regular_7;
extern lv_font_t * font_cousine_regular_9;
extern lv_font_t * font_cousine_bold_9;


/*----------------
 * Images
 *----------------*/

/* Targets: any */
extern const void * image_1;
extern const void * image_music;
extern const void * image_bluetooth;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t subject_battery_level;
extern lv_subject_t subject_consumo;
extern lv_subject_t subject_home_artAtual;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void ui_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widgets, components and screens of this library*/
#include "components/base/bar/bar_gen.h"
#include "components/base/column/column_gen.h"
#include "components/base/container/container_gen.h"
#include "components/base/image/image_gen.h"
#include "components/base/label/label_gen.h"
#include "components/base/panel/panel_gen.h"
#include "components/base/row/row_gen.h"
#include "components/battery_body/battery_body_gen.h"
#include "components/infobar/infobar_gen.h"
#include "screens/preview_home_gen.h"
#include "screens/screen1_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_PRO_UI_GEN_H*/