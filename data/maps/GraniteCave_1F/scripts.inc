.set LOCALID_MAKUHITA, 3

GraniteCave_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GraniteCave_1F_MapScripts_OnLoad
	.byte 0

GraniteCave_1F_MapScripts_OnLoad::
	call_if_eq VAR_ENCOUNTER_MAKUHITA_GRANITE_CAVE_1F, 1, GraniteCave_1F_EventScript_RemoveMakuhita

GraniteCave_1F_EventScript_RemoveMakuhita::
	removeobject LOCALID_MAKUHITA
	end

GraniteCave_1F_MoveScript_Makuhita::
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	delay_16
	delay_16
	emote_exclamation_mark
	jump_in_place_up_down
	walk_fast_up
	walk_fast_left
	walk_fast_down
	walk_fast_right
	walk_fast_up
	walk_fast_left
	walk_fast_down
	walk_fast_right
	walk_fast_up
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

GraniteCave_1F_MoveScript_MakuhitaAttack::
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	step_end

GraniteCave_1F_Top_EventScript_Makuhita::
	lockall
	fadeoutbgm 0
	addobject LOCALID_MAKUHITA
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAKUHITA, GraniteCave_1F_MoveScript_Makuhita
	delay 238
	playmoncry SPECIES_MAKUHITA, CRY_MODE_ENCOUNTER
	waitmoncry
	waitmovement 0
	setvar VAR_ENCOUNTER_MAKUHITA_GRANITE_CAVE_1F, 1
	removeobject LOCALID_MAKUHITA
	setflag FLAG_HIDE_MAKUHITA
	playse SE_FLEE
	fadeinbgm 0
	releaseall
	end

GraniteCave_1F_Top_EventScript_MakuhitaBattle::
	lockall
	fadeoutbgm 0
	clearflag FLAG_HIDE_MAKUHITA
	addobject LOCALID_MAKUHITA
	setobjectxy LOCALID_MAKUHITA, 12, 9
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playmoncry SPECIES_MAKUHITA, CRY_MODE_ENCOUNTER
	waitmoncry
	applymovement LOCALID_MAKUHITA, GraniteCave_1F_MoveScript_MakuhitaAttack
	waitmovement 0
	setwildbattle SPECIES_MAKUHITA, 10
	playmoncry SPECIES_MAKUHITA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	dowildbattle
	fadescreen FADE_TO_WHITE
	setflag FLAG_HIDE_MAKUHITA
	setvar VAR_ENCOUNTER_MAKUHITA_GRANITE_CAVE_1F, 2
	removeobject LOCALID_MAKUHITA
	fadescreen FADE_FROM_WHITE
	fadeinbgm 0
	releaseall
	end


GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Hey, you.\n"
	.string "It gets awfully dark ahead.\l"
	.string "It'll be tough trying to explore.\p"
	.string "That guy who came by earlier…\n"
	.string "STEVEN, I think it was.\p"
	.string "He knew how to use FLASH, so he ought\n"
	.string "to be all right, but…\p"
	.string "Well, for us HIKERS, helping out those\n"
	.string "that we meet is our motto.\p"
	.string "Here you go, I'll pass this on to you.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Teach that hidden move FLASH to\n"
	.string "a POKéMON and use it.\p"
	.string "It lights up even the inky darkness\n"
	.string "of caves.\p"
	.string "But, to use it, you need the GYM BADGE\n"
	.string "from DEWFORD's POKéMON GYM.$"

