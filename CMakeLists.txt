cmake_minimum_required(VERSION 3.6.1)

project(pokeruby)

set(PATTERN "**/*")

set(DEPENDENCIES)

set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/pokeruby")

file(GLOB ROOT RELATIVE "${CMAKE_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}/*")

add_custom_command(
        OUTPUT "${BUILD_DIR}/override.mk"
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/override-de.mk" "${BUILD_DIR}/override.mk"
        DEPENDS "${CMAKE_SOURCE_DIR}/override-de.mk"
)
list(APPEND DEPENDENCIES "${BUILD_DIR}/override.mk")
set(MAP_${BUILD_DIR}/override.mk 1)

foreach(PATH ${ROOT})
    if(IS_DIRECTORY ${BUILD_DIR}/${PATH})
        continue()
    endif()

    set(INPUT "${CMAKE_SOURCE_DIR}/${PATH}")
    set(OUTPUT "${BUILD_DIR}/${PATH}")
    if(NOT MAP_${OUTPUT})
        add_custom_command(
                OUTPUT "${OUTPUT}"
                COMMAND ${CMAKE_COMMAND} -E copy ${INPUT} ${OUTPUT}
                DEPENDS "${INPUT}"
        )
        list(APPEND DEPENDENCIES ${OUTPUT})
    endif()
endforeach()

foreach(GROUP asm common_syms constants data graphics include sound src tools)
    file(GLOB_RECURSE ${GROUP} RELATIVE "${CMAKE_SOURCE_DIR}/${GROUP}" "${CMAKE_SOURCE_DIR}/${GROUP}/*")
    file(GLOB_RECURSE ${GROUP}_DE RELATIVE "${CMAKE_SOURCE_DIR}/${GROUP}-de" "${CMAKE_SOURCE_DIR}/${GROUP}-de/*")

    foreach(PATH ${${GROUP}_DE})
        set(INPUT "${CMAKE_SOURCE_DIR}/${GROUP}-de/${PATH}")
        set(OUTPUT "${BUILD_DIR}/${GROUP}/${PATH}")
        add_custom_command(
            OUTPUT "${OUTPUT}"
            COMMAND ${CMAKE_COMMAND} -E copy ${INPUT} ${OUTPUT}
            DEPENDS "${INPUT}"
        )
        list(APPEND DEPENDENCIES ${OUTPUT})
        set(MAP_${OUTPUT} 1)
    endforeach()

    foreach(PATH ${${GROUP}})
        set(INPUT "${CMAKE_SOURCE_DIR}/${GROUP}/${PATH}")
        set(OUTPUT "${BUILD_DIR}/${GROUP}/${PATH}")
            if(NOT MAP_${OUTPUT})
                add_custom_command(
                    OUTPUT "${OUTPUT}"
                    COMMAND ${CMAKE_COMMAND} -E copy ${INPUT} ${OUTPUT}
                    DEPENDS "${INPUT}"
                )
                list(APPEND DEPENDENCIES ${OUTPUT})
            endif()
    endforeach()
endforeach()



add_custom_target(compare_ruby_de_debug
    DEPENDS ${DEPENDENCIES}
    WORKING_DIRECTORY ${BUILD_DIR}
    COMMAND /usr/local/bin/gmake "compare_ruby_de_debug" -j DEVKITARM=/opt/devkitpro/devkitARM
)

add_custom_target(compare_ruby_de
    DEPENDS ${DEPENDENCIES}
    WORKING_DIRECTORY ${BUILD_DIR}
    COMMAND /usr/local/bin/gmake "compare_ruby_de" DEVKITARM=/opt/devkitpro/devkitARM
)

add_custom_target(compare_sapphire_de
    DEPENDS ${DEPENDENCIES}
    WORKING_DIRECTORY ${BUILD_DIR}
    COMMAND /usr/local/bin/gmake "compare_sapphire_de" -j DEVKITARM=/opt/devkitpro/devkitARM
)