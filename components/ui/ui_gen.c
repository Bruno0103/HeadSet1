/**
 * @file ui_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "ui_gen.h"

#if defined(LV_USE_XML) && LV_USE_XML
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void check_font(lv_font_t ** font, const char * name);

/**********************
 *  STATIC VARIABLES
 **********************/

static uint32_t ui_target = UI_TARGET_ALL;

/*----------------
 * Translations
 *----------------*/

#ifndef LV_EDITOR_PREVIEW
    static const char * translation_languages[] = {"en", "de", NULL};
    static const char * translation_tags[] = {"dog", "cat", "house", NULL};
    static const char * translation_texts[] = {
        "This is a dog", "Das ist ein Hund", /* dog */
        "A curious little cat", "Eine neugierige kleine Katze", /* cat */
        "The house is cozy and warm", "Das Haus ist gemütlich und warm", /* house */
    };
#endif

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Fonts
 *----------------*/

lv_font_t * font_cousine_regular_8;
lv_font_t * font_cousine_bold_8;
lv_font_t * font_cousine_bold_10;
lv_font_t * font_cousine_regular_7;
lv_font_t * font_cousine_regular_9;
lv_font_t * font_cousine_bold_9;

/*----------------
 * Images
 *----------------*/

/* Targets: any */
const void * image_1 = NULL;
extern const void * image_1_data;
const void * image_music = NULL;
extern const void * image_music_data;
const void * image_bluetooth = NULL;
extern const void * image_bluetooth_data;

/*----------------
 * Global styles
 *----------------*/

lv_style_t style_screen_base_global;

/*----------------
 * Subjects
 *----------------*/

lv_subject_t subject_battery_level;
lv_subject_t subject_consumo;
lv_subject_t subject_home_artAtual;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void ui_init_gen(const char * asset_path)
{
    char buf[256];

    /* When running from the editor the theme set from the XML should overwrite this */
#if !defined(LV_EDITOR_PREVIEW)
#if LV_USE_THEME_SIMPLE
    lv_display_t * disp = lv_display_get_default();
    lv_theme_t * th = lv_theme_simple_init(disp);
    lv_display_set_theme(disp, th);
#else
    LV_LOG_WARN("Simple theme is selected in project.xml but LV_USE_THEME_SIMPLE is disabled");
#endif
#endif /*LV_EDITOR_PREVIEW*/


    /*----------------
     * Fonts
     *----------------*/

    /* Targets: any */

    #if UI_CHECK_COMPILE_TARGET(UI_TARGET_ALL)
    if (ui_check_target(UI_TARGET_ALL)) {
        if (!font_cousine_regular_8) {
            /* font_cousine_regular_8 */
            /* create bin font 'font_cousine_regular_8' from file */
            lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/font_cousine_regular_8.bin");
            font_cousine_regular_8 = lv_binfont_create(buf);

        }
        if (!font_cousine_bold_8) {
            /* font_cousine_bold_8 */
            /* create bin font 'font_cousine_bold_8' from file */
            lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/font_cousine_bold_8.bin");
            font_cousine_bold_8 = lv_binfont_create(buf);

        }
        if (!font_cousine_bold_10) {
            /* font_cousine_bold_10 */
            /* create bin font 'font_cousine_bold_10' from file */
            lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/font_cousine_bold_10.bin");
            font_cousine_bold_10 = lv_binfont_create(buf);

        }
        if (!font_cousine_regular_7) {
            /* font_cousine_regular_7 */
            /* create bin font 'font_cousine_regular_7' from file */
            lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/font_cousine_regular_7.bin");
            font_cousine_regular_7 = lv_binfont_create(buf);

        }
        if (!font_cousine_regular_9) {
            /* font_cousine_regular_9 */
            /* create bin font 'font_cousine_regular_9' from file */
            lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/font_cousine_regular_9.bin");
            font_cousine_regular_9 = lv_binfont_create(buf);

        }
        if (!font_cousine_bold_9) {
            /* font_cousine_bold_9 */
            /* create bin font 'font_cousine_bold_9' from file */
            lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/font_cousine_bold_9.bin");
            font_cousine_bold_9 = lv_binfont_create(buf);

        }
    }
    #endif

    /*----------------
     * Images
     *----------------*/

    /* Targets: any */
    #if UI_CHECK_COMPILE_TARGET(UI_TARGET_ALL)
    if (ui_check_target(UI_TARGET_ALL)) {
        /* image_1 */
        if (!image_1) {
            image_1 = &image_1_data;
        }
        /* image_music */
        if (!image_music) {
            image_music = &image_music_data;
        }
        /* image_bluetooth */
        if (!image_bluetooth) {
            image_bluetooth = &image_bluetooth_data;
        }
    }
    #endif

    /*----------------
     * Global styles
     *----------------*/

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_screen_base_global);

        lv_style_set_border_width(&style_screen_base_global, 0);
        lv_style_set_radius(&style_screen_base_global, 0);
        lv_style_set_shadow_width(&style_screen_base_global, 0);
        lv_style_set_shadow_opa(&style_screen_base_global, 0);

        style_inited = true;
    }

    /*----------------
     * Subjects
     *----------------*/
    lv_subject_init_int(&subject_battery_level, 76);
    static char subject_consumo_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_consumo_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_consumo,
                           subject_consumo_buf,
                           subject_consumo_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "42mA"
                          );
    lv_subject_init_pointer(&subject_home_artAtual, (void *)image_1);

    /*----------------
     * Translations
     *----------------*/

    #ifndef LV_EDITOR_PREVIEW
        lv_translation_add_static(translation_languages, translation_tags, translation_texts);
        lv_translation_set_language(translation_languages[0]);
    #endif

#if defined(LV_USE_XML) && LV_USE_XML
    /* Register widgets */

    /* Check all fonts / default if needed. This prevents fonts that are used in one target but
       defined in another from causing assertion failures during rendering of the Preview. */
    check_font(&font_cousine_regular_8, "font_cousine_regular_8");
    check_font(&font_cousine_bold_8, "font_cousine_bold_8");
    check_font(&font_cousine_bold_10, "font_cousine_bold_10");
    check_font(&font_cousine_regular_7, "font_cousine_regular_7");
    check_font(&font_cousine_regular_9, "font_cousine_regular_9");
    check_font(&font_cousine_bold_9, "font_cousine_bold_9");

    /* Register fonts */
    lv_xml_register_font(NULL, "font_cousine_regular_8", font_cousine_regular_8);
    lv_xml_register_font(NULL, "font_cousine_bold_8", font_cousine_bold_8);
    lv_xml_register_font(NULL, "font_cousine_bold_10", font_cousine_bold_10);
    lv_xml_register_font(NULL, "font_cousine_regular_7", font_cousine_regular_7);
    lv_xml_register_font(NULL, "font_cousine_regular_9", font_cousine_regular_9);
    lv_xml_register_font(NULL, "font_cousine_bold_9", font_cousine_bold_9);

    /* Register subjects */
    lv_xml_register_subject(NULL, "subject_battery_level", &subject_battery_level);
    lv_xml_register_subject(NULL, "subject_consumo", &subject_consumo);
    lv_xml_register_subject(NULL, "subject_home_artAtual", &subject_home_artAtual);

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if defined(LV_USE_XML) && LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "image_1", image_1);
    lv_xml_register_image(NULL, "image_music", image_music);
    lv_xml_register_image(NULL, "image_bluetooth", image_bluetooth);
#endif

#if !defined(LV_USE_XML) || LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manually from XML using lv_xml_create() */
#endif
}

void ui_set_target(uint32_t target)
{
    ui_target = target;
}

uint32_t ui_get_target(void)
{
    return ui_target;
}

bool ui_check_target(uint32_t target)
{
    return (ui_target & target) ? true : false;
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void check_font(lv_font_t ** font, const char * name)
{
    if (!(*font)) {
        *font = (lv_font_t *)LV_FONT_DEFAULT;
        LV_LOG_WARN("font `%s` was not set. Using `LV_FONT_DEFAULT` instead", name);
    }
}