set(LV_EDITOR_PROJECT_SOURCES)

include(${CMAKE_CURRENT_LIST_DIR}/user_config.cmake)
set(LV_EDITOR_USER_SOURCES ${LV_EDITOR_PROJECT_SOURCES})

set(LV_EDITOR_PROJECT_SOURCES)
include(${CMAKE_CURRENT_LIST_DIR}/file_list_gen.cmake)

list(APPEND LV_EDITOR_PROJECT_SOURCES ${LV_EDITOR_USER_SOURCES})

idf_component_register(
    SRCS ${LV_EDITOR_PROJECT_SOURCES}
    INCLUDE_DIRS
        "."
        "screens"
        "components"
        "fonts"       # Adicione se o gerador tiver criado esta pasta
        "images"      # Adicione se o gerador tiver criado esta pasta
    REQUIRES 
        lvgl
)