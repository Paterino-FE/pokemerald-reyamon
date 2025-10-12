.set LOCALID_OSHAWOTT_1, 4
.set LOCALID_MABLE, 1
.set LOCALID_OSHAWOTT_2, 7
.set LOCALID_SAMUROTT, 9

Birthday_Mable_Lighthouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Birthday_Mable_Lighthouse_EventScript_Samurott_Setup
	.byte 0

Birthday_Mable_Lighthouse_EventScript_Samurott_Setup::
	call_if_eq VAR_MABLE_EVENT_EVOLVE_OSHAWOTT, 1, Birthday_Mable_Lighthouse_HIDE_SAMUROTT_1
	return

Birthday_Mable_Lighthouse_HIDE_SAMUROTT_1::
	removeobject LOCALID_SAMUROTT
	setvar VAR_MABLE_EVENT_EVOLVE_OSHAWOTT, 2
	return

Birthday_Mable_Lighthouse_HIDE_SAMUROTT_2::
	setvar VAR_MABLE_EVENT_EVOLVE_OSHAWOTT, 1
	removeobject LOCALID_SAMUROTT
	setflag FLAG_HIDE_SAMUROTT
	return

Birthday_Mable_Lighthouse_Mablewott::
	lockall
	special StorePlayerCoordsInVars
	msgbox_mugshot Birthday_Mable_Lighthouse_TEXT_Mablewott_1, MSGBOX_SIGN, MUGSHOT_REYADETAIL, CLEAR_MUGSHOT
	playmoncry SPECIES_OSHAWOTT, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox_mugshot Birthday_Mable_Lighthouse_TEXT_Mablewott_2, MSGBOX_SIGN, MUGSHOT_MABLEWOTT, CLEAR_MUGSHOT
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Mable_Lighthouse_Movement_Mablewott_Event_1
	waitmovement 0
	special RemoveCameraObject
	delay 60
	msgbox_mugshot Birthday_Mable_Lighthouse_TEXT_Mablewott_3, MSGBOX_SIGN, MUGSHOT_MABLE, CLEAR_MUGSHOT
	delay 20
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Mable_Lighthouse_Movement_Mablewott_Event_5
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_OSHAWOTT_1, Mable_Lighthouse_Movement_Mablewott_Event_2
	delay 20
	playmoncry SPECIES_OSHAWOTT, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox_mugshot Birthday_Mable_Lighthouse_TEXT_Mablewott_4, MSGBOX_SIGN, MUGSHOT_MABLE, CLEAR_MUGSHOT
	applymovement LOCALID_MABLE, Mable_Lighthouse_Movement_Mablewott_Event_7
	delay 60
	playmoncry SPECIES_OSHAWOTT, CRY_MODE_ENCOUNTER
	waitmoncry
	applymovement LOCALID_OSHAWOTT_1, Mable_Lighthouse_Movement_Mablewott_Event_3
	waitmovement 0
	removeobject LOCALID_OSHAWOTT_1
	setflag FLAG_HIDE_OSHAWOTT_1
	releaseall
	end

Mable_Lighthouse_Movement_Mablewott_Event_1:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_up
	walk_slow_up
	step_end

Mable_Lighthouse_Movement_Mablewott_Event_2:
	jump_in_place_down
	jump_in_place_down
	step_end

Mable_Lighthouse_Movement_Mablewott_Event_3:
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Mable_Lighthouse_Movement_Mablewott_Event_5:
	walk_diag_southwest
	walk_diag_southwest
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Mable_Lighthouse_Movement_Mablewott_Event_7:
	jump_in_place_left
	jump_in_place_left
	step_end

Birthday_Mable_Lighthouse_TEXT_Mablewott_1:
	.string "Wow, this Oshawott has some\n"
	.string "beautiful hair!$"

Birthday_Mable_Lighthouse_TEXT_Mablewott_2:
	.string "OSHAWOTT!!\n"
	.string "It jumps around in a cute way.$"

Birthday_Mable_Lighthouse_TEXT_Mablewott_3:
	.string "Hey, what are you holding in your hands?!$"

Birthday_Mable_Lighthouse_TEXT_Mablewott_4:
	.string "She got a knife!$"

Mable_Lighthouse_EventScript_Mable::
	goto_if_not_defeated TRAINER_MABLE, Mable_Lighthouse_EventScript_DoBattle
	msgbox_mugshot Birthday_Mable_Lighthouse_TEXT_MableFight_4, MSGBOX_DEFAULT, MUGSHOT_MABLE, CLEAR_MUGSHOT
	release
	end

Mable_Lighthouse_EventScript_DoBattle::
	msgbox_mugshot Birthday_Mable_Lighthouse_TEXT_MableFight_1_1, MSGBOX_DEFAULT, MUGSHOT_MABLE, CLEAR_MUGSHOT
	playmoncry SPECIES_OSHAWOTT, CRY_MODE_ENCOUNTER
	waitmoncry
	applymovement LOCALID_OSHAWOTT_2, Mable_Lighthouse_Movement_Oshawott_Evolves
	waitmovement 0
	delay 20
	removeobject LOCALID_OSHAWOTT_2
	setflag FLAG_HIDE_OSHAWOTT_2
	clearflag FLAG_HIDE_SAMUROTT
	addobject LOCALID_SAMUROTT
	playmoncry SPECIES_SAMUROTT, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox_mugshot Birthday_Mable_Lighthouse_TEXT_MableFight_1_2, MSGBOX_DEFAULT, MUGSHOT_MABLE, CLEAR_MUGSHOT
	trainerbattle_single TRAINER_MABLE, Birthday_Mable_Lighthouse_TEXT_MableFight_5, Birthday_Mable_Lighthouse_TEXT_MableFight_2, Mable_Lighthouse_EventScript_MableDefeated
	release
	end

Mable_Lighthouse_EventScript_MableDefeated::
	msgbox_mugshot Birthday_Mable_Lighthouse_TEXT_MableFight_3, MSGBOX_DEFAULT, MUGSHOT_MABLE, CLEAR_MUGSHOT
	release
	end

Mable_Lighthouse_Movement_Oshawott_Evolves:
	jump_in_place_left
	jump_in_place_left
	emote_heart
	step_end

Birthday_Mable_Lighthouse_TEXT_MableFight_1_1:
	.string "Pre-Battle$"

Birthday_Mable_Lighthouse_TEXT_MableFight_1_2:
	.string "Oshawott Evolves$"

Birthday_Mable_Lighthouse_TEXT_MableFight_2:
	.string "Defeat$"

Birthday_Mable_Lighthouse_TEXT_MableFight_3:
	.string "Post-Battle$"

Birthday_Mable_Lighthouse_TEXT_MableFight_4:
	.string "Repeat$"

Birthday_Mable_Lighthouse_TEXT_MableFight_5:
	.string "Intro$"
