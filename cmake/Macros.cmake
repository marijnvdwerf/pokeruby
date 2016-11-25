macro(POKE_CAT OUT_FILE_NAME)
    set(_DEPS)
    foreach(loop_var ${ARGN})
        poke_require_file(${loop_var} _DEP_IN NULL)
        list(APPEND _DEPS "${_DEP_IN}")
    endforeach()

    LIST(APPEND GENERATED ${OUT_FILE_NAME})
    add_custom_command(
            OUTPUT "${CMAKE_BINARY_DIR}/${OUT_FILE_NAME}"
            COMMAND cat ${_DEPS} > "${CMAKE_BINARY_DIR}/${OUT_FILE_NAME}"
            DEPENDS ${_DEPS}
    )
    list(APPEND MISC_DEPS "${CMAKE_BINARY_DIR}/${OUT_FILE_NAME}")
endmacro()


macro(POKE_GFX_TILES FILE_OUT_NAME FILE_IN_NAME NUM_TILES)
    poke_require_file(${FILE_IN_NAME} FILE_IN FILE_IN_STATUS)

    list(APPEND GENERATED ${FILE_OUT_NAME})
    set(FILE_OUT ${CMAKE_BINARY_DIR}/${FILE_OUT_NAME})

    # Custom command to do the processing
    add_custom_command(
            OUTPUT ${FILE_OUT}
            COMMAND ${GFX} ${FILE_IN} ${FILE_OUT} -num_tiles ${NUM_TILES}
            DEPENDS ${FILE_IN}
    )
    list(APPEND MISC_DEPS "${FILE_OUT}")
endmacro()


macro(POKE_GFX_OVERFLOW FILE_OUT_NAME OVERFLOW)
    string(REGEX REPLACE "\\.(lz|rl)$" "" FILE_IN_NAME "${FILE_OUT_NAME}")
    poke_require_file(${FILE_IN_NAME} FILE_IN FILE_IN_STATUS)

    list(APPEND GENERATED ${FILE_OUT_NAME})
    set(FILE_OUT ${CMAKE_BINARY_DIR}/${FILE_OUT_NAME})

    # Custom command to do the processing
    add_custom_command(
            OUTPUT ${FILE_OUT}
            COMMAND ${GFX} ${FILE_IN} ${FILE_OUT} -overflow ${OVERFLOW}
            DEPENDS ${FILE_IN}
    )
    list(APPEND MISC_DEPS "${FILE_OUT}")
endmacro()


macro(POKE_FONT OUTPUT_FILE_NAME INPUT_FILE_NAME NUM_GLYPHS LAYOUT_TYPE)
    poke_require_file(${INPUT_FILE_NAME} INPUT_FILE NULL)

    LIST(APPEND GENERATED ${OUTPUT_FILE_NAME})
    add_custom_command(
            OUTPUT "${CMAKE_BINARY_DIR}/${OUTPUT_FILE_NAME}"
            COMMAND ${RSFONT} ${INPUT_FILE} "${CMAKE_BINARY_DIR}/${OUTPUT_FILE_NAME}" ${NUM_GLYPHS} ${LAYOUT_TYPE}
            DEPENDS ${INPUT_FILE}
    )
    list(APPEND MISC_DEPS "${CMAKE_BINARY_DIR}/${OUTPUT_FILE_NAME}")
endmacro()
