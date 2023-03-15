file(GLOB CAPTIVE_PORTAL_MAIN "captive_portal.c" "dns_server.c")
list(APPEND SOURCES ${CAPTIVE_PORTAL_MAIN} )

idf_component_register(SRCS ${SOURCES}
        INCLUDE_DIRS "include"
        REQUIRES nvs_flash esp_http_server
        EMBED_FILES index.html
        )

set_source_files_properties(captive_portal.c
        PROPERTIES COMPILE_FLAGS
        -Wno-pointer-sign
        )
