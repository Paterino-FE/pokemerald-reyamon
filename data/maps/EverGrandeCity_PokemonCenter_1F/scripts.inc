.set LOCALID_NURSE, 1
.set LOCALID_SCOTT, 4

EverGrandeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EverGrandeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY
	call_if_unset FLAG_MET_SCOTT_IN_EVERGRANDE, EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott
	end

EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott::
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	return

EverGrandeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad, MSGBOX_DEFAULT
	msgbox EverGrandeCity_PokemonCenter_1F_Text_WantToDracoMeteor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EverGrandeCity_PokemonCenter_1F_EventScript_DeclineDracoMeteor
	msgbox EverGrandeCity_PokemonCenter_1F_Text_WhichMonDracoMeteor, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_DRACO_METEOR
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, EverGrandeCity_PokemonCenter_1F_EventScript_DeclineDracoMeteor
	msgbox EverGrandeCity_PokemonCenter_1F_Text_SvelteOutro, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_DeclineDracoMeteor::
	msgbox EverGrandeCity_PokemonCenter_1F_Text_DeclineDracoMeteor, MSGBOX_DEFAULT
	release
	end


EverGrandeCity_PokemonCenter_1F_EventScript_ExpertM::
	msgbox EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_EventScript_Scott::
	lock
	faceplayer
	msgbox EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
	call_if_eq VAR_FACING, DIR_WEST, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	playse SE_EXIT
	waitse
	removeobject LOCALID_SCOTT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth::
	applymovement LOCALID_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit::
	applymovement LOCALID_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExit
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Movement_ScottExit:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad:
	.string "Hi pretty lady! I practised real hard\n"
	.string "to come find my mummy out here.\p"
	.string "People say she is a bad meanie but\n"
	.string "she still loves me right?\p"
	.string "I can show you what I learned because\l"
	.string "you nice lady who saved us!$"

EverGrandeCity_PokemonCenter_1F_Text_WantToDracoMeteor:
	.string "Want me to teach DRACO METEOR,\n"
	.string "pretty lady?$"

EverGrandeCity_PokemonCenter_1F_Text_WhichMonDracoMeteor:
	.string "Which pokman i teach?$"

EverGrandeCity_PokemonCenter_1F_Text_DeclineDracoMeteor:
	.string "I wanted to be helpful....$"

EverGrandeCity_PokemonCenter_1F_Text_SvelteOutro:
	.string "Now you nearly as strong as dragon\n"
	.string "but dragon still stronker!$"

EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon:
	.string "The long and harrowing VICTORY ROAD…\p"
	.string "It's like reliving the path one has\n"
	.string "traveled in life…\p"
	.string "Believe in your POKéMON and give it\n"
	.string "your very best!$"

EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou:
	.string "SCOTT: {PLAYER}{KUN}, you've clawed your\n"
	.string "way up to face the POKéMON LEAGUE!\p"
	.string "I'm happy for you!\n"
	.string "You made my cheering worthwhile!\p"
	.string "{PLAYER}{KUN}, if you were to become\n"
	.string "the POKéMON LEAGUE CHAMPION…\p"
	.string "I'll get in touch with you then.\p"
	.string "Okay, {PLAYER}{KUN}.\n"
	.string "Go for greatness!$"

