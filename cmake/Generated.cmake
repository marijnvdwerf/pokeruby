macro(POKE_GEN_COMMON LIST_NAME HEADER_NAME BITMAP_NAME VARIABLE_NAME)
    poke_require_file(${BITMAP_NAME} FILE_IN FILE_IN_STATUS)

    set(FILE_OUT ${CMAKE_BINARY_DIR}/${HEADER_NAME})
    list(APPEND ${LIST_NAME} ${FILE_OUT})

    # Custom command to do the processing
    add_custom_command(
            OUTPUT ${FILE_OUT}
            COMMAND ${BIN2C} ${BITMAP_NAME} ${VARIABLE_NAME} ${ARGN} > ${FILE_OUT}
            DEPENDS ${FILE_IN}
    )
endmacro()

macro(POKE_GEN_FONT HEADER_NAME BITMAP_NAME VARIABLE_NAME)
    POKE_GEN_COMMON(GEN_FONT_HEADERS ${HEADER_NAME} ${BITMAP_NAME} ${VARIABLE_NAME} ${ARGN})
endmacro()
macro(POKE_GEN_LINK HEADER_NAME BITMAP_NAME VARIABLE_NAME)
    POKE_GEN_COMMON(GEN_LINK_HEADERS ${HEADER_NAME} ${BITMAP_NAME} ${VARIABLE_NAME} ${ARGN})
endmacro()

POKE_GEN_FONT(
    include/fonts/font0_lat_glyphs.h
    graphics/fonts/font0_lat.1bpp
    sFont0LatinGlyphs
    -static -col 8 -pad 4
)

POKE_GEN_FONT(
    include/fonts/font0_lat_glyphs.h
    graphics/fonts/font0_lat.1bpp
    sFont0LatinGlyphs
    -static -col 8 -pad 4
)

POKE_GEN_FONT(
    include/fonts/font1_lat_glyphs.h
    graphics/fonts/font1_lat.1bpp
    sFont1LatinGlyphs
    -static -col 8 -pad 4
)

POKE_GEN_FONT(
    include/fonts/font0_jpn_glyphs.h
    graphics/fonts/font0_jpn.1bpp
    sFont0JapaneseGlyphs
    -static -col 8 -pad 4
)

POKE_GEN_FONT(
    include/fonts/font1_jpn_glyphs.h
    graphics/fonts/font1_jpn.1bpp
    sFont1JapaneseGlyphs
    -static -col 8 -pad 4
)

POKE_GEN_FONT(
include/fonts/braille_glyphs.h
    graphics/fonts/font6_braille.1bpp
    sBrailleGlyphs
    -static -col 8 -pad 4
)

POKE_GEN_FONT(
    include/fonts/down_arrow_tiles.h
    graphics/fonts/down_arrow.4bpp
    sDownArrowTiles
    -static -size 4 -pad 10
)

POKE_GEN_FONT(
    include/fonts/unknown_palette_81E6692.h
    graphics/fonts/unknown_81E6692.gbapal
    gUnknownPalette_81E6692
     -size 2 -pad 6
)

POKE_GEN_FONT(
    include/fonts/default_palette.h
    graphics/fonts/default.gbapal
    gFontDefaultPalette
     -size 2 -pad 6
)

POKE_GEN_LINK(
    include/link/digit_tiles.h
    graphics/interface/link_test_digits.4bpp
    sLinkTestDigitTiles
    -static -size 4 -pad 10
)

POKE_GEN_LINK(
    include/link/digit_palette.h
    graphics/interface/link_test_digits.gbapal
    sLinkTestDigitPalette
    -static -size 2 -pad 6
)