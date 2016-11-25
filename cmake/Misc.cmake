set(MENUGFXDIR graphics/interface)
set(TRADEGFXDIR graphics/trade)
set(INTROGFXDIR graphics/intro)
set(PSSGFXDIR graphics/pokemon_storage)
set(MISCGFXDIR graphics/misc)
set(PKNAVGFXDIR graphics/pokenav)
set(UNKNOWNGFXDIR graphics/unknown)
set(UNUSEDGFXDIR graphics/unused)
set(REELGFXDIR graphics/slot_machine)
set(ROULGFXDIR graphics/roulette)
set(BTLANMSPRGFXDIR graphics/battle_anims/sprites)
set(PICFRAMEGFXDIR graphics/picture_frame)
set(CONTESTGFXDIR graphics/contest)
set(MASKSGFXDIR graphics/battle_anims/masks)
set(BATTRANSGFXDIR graphics/battle_transitions)
set(TYPESGFXDIR graphics/types)
set(TITLEGFXDIR graphics/title_screen)

set(types               normal fight flying poison ground rock bug ghost steel mystery fire water grass electric psychic ice dragon dark)
set(contest_types       cool beauty cute smart tough)


POKE_CAT(${MENUGFXDIR}/menu.gbapal ${MENUGFXDIR}/menu_0.gbapal ${MENUGFXDIR}/menu_1.gbapal)

POKE_CAT(${INTROGFXDIR}/intro.4bpp ${INTROGFXDIR}/intro1_waterdrops.4bpp ${INTROGFXDIR}/intro1_gamefreak.4bpp)
POKE_CAT(${INTROGFXDIR}/introgfx.4bpp ${INTROGFXDIR}/intro1_bg.4bpp ${INTROGFXDIR}/intro1_leaves.4bpp)

POKE_GFX_TILES(${PKNAVGFXDIR}/region_map.8bpp	${PKNAVGFXDIR}/region_map.png	233)

POKE_GFX_TILES(${PSSGFXDIR}/forest_frame.4bpp	${PSSGFXDIR}/forest_frame.png	49)
POKE_CAT(${PSSGFXDIR}/forest.4bpp ${PSSGFXDIR}/forest_frame.4bpp ${PSSGFXDIR}/forest_bg.4bpp)

POKE_GFX_TILES(${PSSGFXDIR}/city_frame.4bpp	${PSSGFXDIR}/city_frame.png	37)
POKE_CAT(${PSSGFXDIR}/city.4bpp ${PSSGFXDIR}/city_frame.4bpp ${PSSGFXDIR}/city_bg.4bpp)

POKE_GFX_TILES(${PSSGFXDIR}/desert_frame.4bpp	${PSSGFXDIR}/desert_frame.png	48)
POKE_CAT(${PSSGFXDIR}/desert.4bpp ${PSSGFXDIR}/desert_frame.4bpp ${PSSGFXDIR}/desert_bg.4bpp)

POKE_GFX_TILES(${PSSGFXDIR}/savanna_frame.4bpp	${PSSGFXDIR}/savanna_frame.png	40)
POKE_CAT(${PSSGFXDIR}/savanna.4bpp ${PSSGFXDIR}/savanna_frame.4bpp ${PSSGFXDIR}/savanna_bg.4bpp)

POKE_GFX_TILES(${PSSGFXDIR}/crag_frame.4bpp	${PSSGFXDIR}/crag_frame.png	46)
POKE_CAT(${PSSGFXDIR}/crag.4bpp ${PSSGFXDIR}/crag_frame.4bpp ${PSSGFXDIR}/crag_bg.4bpp)

POKE_GFX_TILES(${PSSGFXDIR}/volcano_frame.4bpp	${PSSGFXDIR}/volcano_frame.png	49)
POKE_CAT(${PSSGFXDIR}/volcano.4bpp ${PSSGFXDIR}/volcano_frame.4bpp ${PSSGFXDIR}/volcano_bg.4bpp)

POKE_GFX_TILES(${PSSGFXDIR}/snow_frame.4bpp	${PSSGFXDIR}/snow_frame.png	46)
POKE_CAT(${PSSGFXDIR}/snow.4bpp ${PSSGFXDIR}/snow_frame.4bpp ${PSSGFXDIR}/snow_bg.4bpp)

POKE_GFX_TILES(${PSSGFXDIR}/cave_frame.4bpp	${PSSGFXDIR}/cave_frame.png	57)
POKE_CAT(${PSSGFXDIR}/cave.4bpp ${PSSGFXDIR}/cave_frame.4bpp ${PSSGFXDIR}/cave_bg.4bpp)

POKE_GFX_TILES(${PSSGFXDIR}/beach_frame.4bpp	${PSSGFXDIR}/beach_frame.png	48)
POKE_CAT(${PSSGFXDIR}/beach.4bpp ${PSSGFXDIR}/beach_frame.4bpp ${PSSGFXDIR}/beach_bg.4bpp)

POKE_GFX_TILES(${PSSGFXDIR}/seafloor_frame.4bpp	${PSSGFXDIR}/seafloor_frame.png	45)
POKE_CAT(${PSSGFXDIR}/seafloor.4bpp ${PSSGFXDIR}/seafloor_frame.4bpp ${PSSGFXDIR}/seafloor_bg.4bpp)

POKE_GFX_TILES(${PSSGFXDIR}/river_frame.4bpp	${PSSGFXDIR}/river_frame.png	57)
POKE_CAT(${PSSGFXDIR}/river.4bpp ${PSSGFXDIR}/river_frame.4bpp ${PSSGFXDIR}/river_bg.4bpp)

POKE_GFX_TILES(${PSSGFXDIR}/sky_frame.4bpp	${PSSGFXDIR}/sky_frame.png	45)
POKE_CAT(${PSSGFXDIR}/sky.4bpp ${PSSGFXDIR}/sky_frame.4bpp ${PSSGFXDIR}/sky_bg.4bpp)

POKE_GFX_TILES(${PSSGFXDIR}/polkadot_frame.4bpp	${PSSGFXDIR}/polkadot_frame.png	34)
POKE_CAT(${PSSGFXDIR}/polkadot.4bpp ${PSSGFXDIR}/polkadot_frame.4bpp ${PSSGFXDIR}/polkadot_bg.4bpp)

POKE_GFX_TILES(${PSSGFXDIR}/pokecenter_bg.4bpp	${PSSGFXDIR}/pokecenter_bg.png	38)
POKE_CAT(${PSSGFXDIR}/pokecenter.4bpp ${PSSGFXDIR}/pokecenter_frame.4bpp ${PSSGFXDIR}/pokecenter_bg.4bpp)

POKE_GFX_TILES(${PSSGFXDIR}/machine_frame.4bpp	${PSSGFXDIR}/machine_frame.png	46)
POKE_CAT(${PSSGFXDIR}/machine.4bpp ${PSSGFXDIR}/machine_frame.4bpp ${PSSGFXDIR}/machine_bg.4bpp)

POKE_GFX_TILES(${PSSGFXDIR}/plain_frame.4bpp	${PSSGFXDIR}/plain_frame.png	18)
POKE_CAT(${PSSGFXDIR}/plain.4bpp ${PSSGFXDIR}/plain_frame.4bpp ${PSSGFXDIR}/plain_bg.4bpp)

POKE_GFX_TILES(${PKNAVGFXDIR}/outline.4bpp	${PKNAVGFXDIR}/outline.png	43)

POKE_CAT(${REELGFXDIR}/reel_time.4bpp ${REELGFXDIR}/reel_pikachu.4bpp ${REELGFXDIR}/reel_machine.4bpp)

POKE_CAT(${MISCGFXDIR}/birch_help.4bpp ${MISCGFXDIR}/birch_bag.4bpp ${MISCGFXDIR}/birch_grass.4bpp)

POKE_CAT(${MISCGFXDIR}/clock_misc.4bpp ${MISCGFXDIR}/clock_hands.4bpp ${MISCGFXDIR}/clock_ampm.4bpp)

POKE_CAT(${ROULGFXDIR}/roulette_tilt.4bpp ${ROULGFXDIR}/shroomish.4bpp ${ROULGFXDIR}/tailow.4bpp)

POKE_CAT(${ROULGFXDIR}/poke_icons2.4bpp ${ROULGFXDIR}/wynaut.4bpp ${ROULGFXDIR}/azurill.4bpp ${ROULGFXDIR}/skitty.4bpp ${ROULGFXDIR}/makuhita.4bpp)

POKE_CAT(${INTROGFXDIR}/intro3_misc.4bpp ${INTROGFXDIR}/intro3_star.4bpp ${INTROGFXDIR}/intro3_attackgfx.4bpp ${INTROGFXDIR}/intro3_explosion.4bpp)

POKE_GFX_TILES(${TRADEGFXDIR}/gba_affine.8bpp	${TRADEGFXDIR}/gba_affine.png	129)

POKE_GFX_TILES(${TRADEGFXDIR}/menu.4bpp	${TRADEGFXDIR}/menu.png	148)

POKE_CAT(${BTLANMSPRGFXDIR}/001.4bpp ${BTLANMSPRGFXDIR}/001_0.4bpp ${BTLANMSPRGFXDIR}/001_1.4bpp)

POKE_CAT(${BTLANMSPRGFXDIR}/010.4bpp ${BTLANMSPRGFXDIR}/010_0.4bpp ${BTLANMSPRGFXDIR}/010_1.4bpp ${BTLANMSPRGFXDIR}/010_2.4bpp ${BTLANMSPRGFXDIR}/010_3.4bpp)

POKE_CAT(${BTLANMSPRGFXDIR}/074.4bpp ${BTLANMSPRGFXDIR}/074_0.4bpp ${BTLANMSPRGFXDIR}/074_1.4bpp)

POKE_CAT(${BTLANMSPRGFXDIR}/141.4bpp ${BTLANMSPRGFXDIR}/141_0.4bpp ${BTLANMSPRGFXDIR}/141_1.4bpp ${BTLANMSPRGFXDIR}/141_2.4bpp ${BTLANMSPRGFXDIR}/141_3.4bpp ${BTLANMSPRGFXDIR}/141_4.4bpp)

POKE_CAT(${BTLANMSPRGFXDIR}/159.4bpp ${BTLANMSPRGFXDIR}/159_0.4bpp ${BTLANMSPRGFXDIR}/159_1.4bpp)

POKE_GFX_TILES(${PICFRAMEGFXDIR}/frame5.4bpp	${PICFRAMEGFXDIR}/frame5.png	86)

POKE_GFX_TILES(${CONTESTGFXDIR}/nextturn.4bpp	${CONTESTGFXDIR}/nextturn.png	8)

POKE_CAT(${UNUSEDGFXDIR}/obi_palpak1.gbapal ${UNUSEDGFXDIR}/old_pal1.gbapal ${UNUSEDGFXDIR}/old_pal2.gbapal ${UNUSEDGFXDIR}/old_pal3.gbapal)

POKE_CAT(${UNUSEDGFXDIR}/obi_palpak3.gbapal ${UNUSEDGFXDIR}/old_pal5.gbapal ${UNUSEDGFXDIR}/old_pal6.gbapal ${UNUSEDGFXDIR}/old_pal7.gbapal)

POKE_CAT(${UNUSEDGFXDIR}/obi1.4bpp ${UNUSEDGFXDIR}/old_bulbasaur.4bpp ${UNUSEDGFXDIR}/old_charizard.4bpp)

POKE_CAT(${UNUSEDGFXDIR}/obi2.4bpp ${UNUSEDGFXDIR}/old_bulbasaur2.4bpp ${UNUSEDGFXDIR}/old_battle_interface_1.4bpp ${UNUSEDGFXDIR}/old_battle_interface_2.4bpp ${UNUSEDGFXDIR}/old_battle_interface_3.4bpp)

POKE_CAT(${MENUGFXDIR}/hp_numbers.4bpp ${MENUGFXDIR}/hpbar_anim.4bpp ${MENUGFXDIR}/numbers1.4bpp ${MENUGFXDIR}/numbers2.4bpp)

POKE_CAT(${UNUSEDGFXDIR}/redyellowgreen_frame.bin ${UNUSEDGFXDIR}/red_frame.bin ${UNUSEDGFXDIR}/yellow_frame.bin ${UNUSEDGFXDIR}/green_frame.bin ${UNUSEDGFXDIR}/blank_frame.bin)

POKE_GFX_TILES(${UNUSEDGFXDIR}/color_frames.4bpp	${UNUSEDGFXDIR}/color_frames.png	353)

POKE_CAT(${UNUSEDGFXDIR}/old_contest.4bpp ${UNUSEDGFXDIR}/old_contest_frame_1.4bpp ${UNUSEDGFXDIR}/old_contest_floor.4bpp ${UNUSEDGFXDIR}/old_contest_frame_2.4bpp ${UNUSEDGFXDIR}/old_contest_symbols.4bpp ${UNUSEDGFXDIR}/old_contest_meter.4bpp ${UNUSEDGFXDIR}/old_contest_classes.4bpp ${UNUSEDGFXDIR}/old_contest_numbers.4bpp)

POKE_CAT(${UNUSEDGFXDIR}/old_contest_2.4bpp ${UNUSEDGFXDIR}/old_contest_2_1.4bpp ${UNUSEDGFXDIR}/old_contest_2_2.4bpp)

POKE_GFX_TILES(${MASKSGFXDIR}/unknown_D2EDFC.4bpp	${MASKSGFXDIR}/unknown_D2EDFC.png	14)

POKE_GFX_TILES(${BATTRANSGFXDIR}/vs_frame.4bpp	${BATTRANSGFXDIR}/vs_frame.png	16)

POKE_GFX_TILES(${MENUGFXDIR}/party_menu_misc.4bpp	${MENUGFXDIR}/party_menu_misc.png	116)

set(IN_FILES)
foreach(_TYPE ${types})
    list(APPEND IN_FILES "${TYPESGFXDIR}/${_TYPE}.4bpp")
endforeach()
foreach(_TYPE ${contest_types})
    list(APPEND IN_FILES "${TYPESGFXDIR}/contest_${_TYPE}.4bpp")
endforeach()
POKE_CAT(${TYPESGFXDIR}/move_types.4bpp ${IN_FILES})

POKE_CAT(${TYPESGFXDIR}/move_types.gbapal ${TYPESGFXDIR}/move_types_1.gbapal ${TYPESGFXDIR}/move_types_2.gbapal ${TYPESGFXDIR}/move_types_3.gbapal)

POKE_GFX_TILES(${MENUGFXDIR}/status_screen.4bpp	${MENUGFXDIR}/status_screen.png	217)

POKE_CAT(${PKNAVGFXDIR}/menu_options.4bpp ${PKNAVGFXDIR}/menu_hoennmap.4bpp ${PKNAVGFXDIR}/menu_condition.4bpp ${PKNAVGFXDIR}/menu_eyes.4bpp ${PKNAVGFXDIR}/menu_ribbons.4bpp ${PKNAVGFXDIR}/menu_off.4bpp)

POKE_GFX_TILES(${PKNAVGFXDIR}/condition_menu_misc.4bpp	${PKNAVGFXDIR}/condition_menu_misc.png	41)

POKE_CAT(${PKNAVGFXDIR}/condition_search.4bpp ${PKNAVGFXDIR}/condition_search_cool.4bpp ${PKNAVGFXDIR}/condition_search_beauty.4bpp ${PKNAVGFXDIR}/condition_search_cute.4bpp ${PKNAVGFXDIR}/condition_search_smart.4bpp ${PKNAVGFXDIR}/condition_search_tough.4bpp ${PKNAVGFXDIR}/condition_search_cancel.4bpp)

POKE_GFX_TILES(${PSSGFXDIR}/header.4bpp	${PSSGFXDIR}/header.png	47)

POKE_GFX_TILES(${PSSGFXDIR}/misc1.4bpp	${PSSGFXDIR}/misc1.png	91)

POKE_GFX_TILES(${MISCGFXDIR}/hof.4bpp	${MISCGFXDIR}/hof.png	37)

POKE_GFX_TILES(${MENUGFXDIR}/wordgroup_frame.4bpp	${MENUGFXDIR}/wordgroup_frame.png	65)

POKE_GFX_TILES(${INTROGFXDIR}/copyright.4bpp	${INTROGFXDIR}/copyright.png	43)

POKE_GFX_TILES(${TITLEGFXDIR}/press_start.4bpp	${TITLEGFXDIR}/press_start.png	41)

POKE_GFX_TILES(${MISCGFXDIR}/end_copyright.4bpp	${MISCGFXDIR}/end_copyright.png	90)
