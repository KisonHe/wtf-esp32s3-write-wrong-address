file(GLOB MAIN_SOURCES
        "main.cpp" "wifi_can_hub.cpp" "main_task.cpp" "ws_task.cpp" "gui/*.*" "hardware/*.*"
        )


idf_component_register(
        SRCS ${MAIN_SOURCES}
        INCLUDE_DIRS ""
#        REQUIRES can
        )
