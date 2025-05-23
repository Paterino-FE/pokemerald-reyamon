.set LOCALID_WALLYS_DAD, 1

PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "You're…\n"
	.string "Ah, you must be {PLAYER}{KUN}, right?\p"
	.string "Thank you for playing with LILYPAD a\n"
	.string "little while ago.\p"
	.string "She has left for a journey now, with\n"
	.string "some of the other PALS.\p"
	.string "She will surely have great adventures,\n"
	.string "but please look after her.\p"
	.string "I wonder where she could have\n"
	.string "gotten by now?$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "I wonder how LILYPAD is doing?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN}! Please excuse us for\n"
	.string "dragging you here this way.\p"
	.string "But our LILYPAD's become very happy\n"
	.string "since she became your best friend!\p"
	.string "We owe it all to you!\p"
	.string "When LILYPAD left town, you helped\n"
	.string "her learn fighting, didn't you?\p"
	.string "I think that made LILYPAD really\n"
	.string "happy.\p"
	.string "Actually, not just her.\n"
	.string "It made me, her PAL, happy too.\p"
	.string "Happy that she's gained such a great\n"
	.string "friend as you.\p"
	.string "This isn't a bribe or anything, but\n"
	.string "I'd really like you to have this.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "If your POKéMON can SURF, you'll be\n"
	.string "able to go to all sorts of places.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "LILYPAD's coming home soon.\n"
	.string "I'm looking forward to that.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Oh? You met LILYPAD in\n"
	.string "EVER GRANDE CITY?\p"
	.string "Oh, {PLAYER}{KUN}, don't be silly.\p"
	.string "She may have gotten strong, but she\n"
	.string "can't go somewhere far away like\l"
	.string "that all by herself.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "LILY was really happy when she told\n"
	.string "us that she caught a POKéMON.\p"
	.string "It's been ages since I've seen her\n"
	.string "smile like that.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "I want you to keep this a secret\n"
	.string "from my PAL-husband…\p"
	.string "But our LILYPAD left VERDANTURF TOWN\n"
	.string "without telling anyone.\p"
	.string "You know, LILYPAD is frail, but\n"
	.string "she's surprisingly strong-willed.\p"
	.string "I'm sure that she'll come back safe\n"
	.string "and sound one day!$"

