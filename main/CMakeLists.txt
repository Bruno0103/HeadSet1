idf_component_register(
    SRCS 
        "main.c"
        "ui.c"
        "ui_gen.c"
        "screens/screen1_gen.c"
        "screens/preview_home_gen.c"
        "components/base/panel/panel_gen.c"
        "components/base/label/label_gen.c"
        "components/base/container/container_gen.c"
    INCLUDE_DIRS "." "screens" "components"
    REQUIRES lvgl
)