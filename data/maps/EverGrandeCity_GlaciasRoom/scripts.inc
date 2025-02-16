EverGrandeCity_GlaciasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_GlaciasRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_GlaciasRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_GlaciasRoom_OnWarp
	.byte 0

EverGrandeCity_GlaciasRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_GlaciasRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 2, EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 3
	releaseall
	end

EverGrandeCity_GlaciasRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 3, EverGrandeCity_GlaciasRoom_EventScript_CloseDoor
	end

EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_GlaciasRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_GlaciasRoom_EventScript_Glacia::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_GlaciasRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GLACIA, EverGrandeCity_GlaciasRoom_Text_Defeat
	goto EverGrandeCity_GlaciasRoom_EventScript_Defeated
	end

EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_GlaciasRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_GLACIA
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_GlaciasRoom_Text_IntroSpeech:
	.string "Have you been keeping well?\n"
	.string "Thank you for saving Hoenn.\p"
	.string "I'm truly grateful. Together,\n"
	.string "you and your Pokémon overcame all\l"
	.string "the challenges you faced,\l"
	.string "however difficult.\p"
	.string "It means that you've triumphed over\n"
	.string "any personal weaknesses, too.\p"
	.string "The power you learned... I can feel\n"
	.string "it emanating from you.\p"
	.string "But that's enough talk.\n"
	.string "Let's get on with why you're here.\p"
	.string "As the Pokémon League Champion of\n"
	.string "Sinnoh, I accept your challenge!$"

EverGrandeCity_GlaciasRoom_Text_Defeat:
	.string "...Just a few moments ago, you were\n"
	.string "the most powerful challenger.\p"
	.string "And just now, you became the most\n"
	.string "powerful of all the Trainers.\p"
	.string "You are an outstanding Trainer!$"

EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech:
	.string "That was excellent.\n"
	.string "Truly, an outstanding battle.\p"
	.string "You gave the support your Pokémon\n"
	.string "needed to maximize their power.\p"
	.string "And you guided them with certainty\n"
	.string "to secure victory. You have both\l"
	.string "passion and calculating coolness.\p"
	.string "Together, you and your Pokémon can\n"
	.string "overcome any challenge that may come\l"
	.string "your way.\p"
	.string "Those are the impressions I got\n"
	.string "from our battle.\p"
	.string "I'm glad I got to take part in the\n"
	.string "crowning of upcoming new Champion!\p"
	.string "Go on, more challenges await you.$"

