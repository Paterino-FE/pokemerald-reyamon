.set LOCALID_ELLIE, 2
.set LOCALID_NEURO_1, 1
.set LOCALID_NEURO_2, 10
.set LOCALID_CODEBUG, 9
.set LOCALID_APPLIANCE, 3
.set LOCALID_APPLIANCE, 4
.set LOCALID_APPLIANCE, 5
.set LOCALID_APPLIANCE, 6
.set LOCALID_APPLIANCE, 7
.set LOCALID_APPLIANCE, 8

Birthday_Ellies_House_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Birthday_Ellies_House_Setup
    .byte 0

Birthday_Ellies_House_Setup::
	call_if_eq VAR_ELLIE_HOUSE_HIDE, 0, Birthday_Ellies_House_Hide1
	call_if_eq VAR_ELLIE_HOUSE_HIDE, 2, Birthday_Ellies_House_Hide2
	release
	end

Birthday_Ellies_House_Hide1::
	removeobject LOCALID_APPLIANCE, 3
	removeobject LOCALID_APPLIANCE, 4
	removeobject LOCALID_APPLIANCE, 5
	removeobject LOCALID_APPLIANCE, 6
	removeobject LOCALID_APPLIANCE, 7
	removeobject LOCALID_APPLIANCE, 8
    removeobject LOCALID_NEURO_2, 10
	setflag	FLAG_HIDE_NEURO2
	setflag	FLAG_HIDE_APPLIANCE
	return

Birthday_Ellies_House_Hide2::
	addobject LOCALID_APPLIANCE, 3
	addobject LOCALID_APPLIANCE, 4
	addobject LOCALID_APPLIANCE, 5
	addobject LOCALID_APPLIANCE, 6
	addobject LOCALID_APPLIANCE, 7
	addobject LOCALID_APPLIANCE, 8
	clearflag FLAG_HIDE_APPLIANCE
	return

Birthday_Ellies_House_RotomNotInParty::
    lock
    msgbox Birthday_Ellies_House_RotomNotInParty_Text, MSGBOX_DEFAULT
    release
    end

Birthday_Ellies_House_BaseRotom::
    specialvar VAR_RESULT, IsRotomInParty
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_RotomNotInParty
    setvar VAR_0x8004, 0
	special TryChangeRotomForm
    callnative UpdateFollowingPokemon
    end

Birthday_Ellies_House_HeatRotom::
    specialvar VAR_RESULT, IsRotomInParty
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_RotomNotInParty
    setvar VAR_0x8004, 1
	special TryChangeRotomForm
    callnative UpdateFollowingPokemon
    end

Birthday_Ellies_House_WashRotom::
    specialvar VAR_RESULT, IsRotomInParty
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_RotomNotInParty
    setvar VAR_0x8004, 2
	special TryChangeRotomForm
    callnative UpdateFollowingPokemon
    end

Birthday_Ellies_House_FrostRotom::
    specialvar VAR_RESULT, IsRotomInParty
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_RotomNotInParty
    setvar VAR_0x8004, 3
	special TryChangeRotomForm
    callnative UpdateFollowingPokemon
    end
    
Birthday_Ellies_House_FanRotom::
    specialvar VAR_RESULT, IsRotomInParty
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_RotomNotInParty
    setvar VAR_0x8004, 4
	special TryChangeRotomForm
    callnative UpdateFollowingPokemon
    end
    
Birthday_Ellies_House_MowRotom::
    specialvar VAR_RESULT, IsRotomInParty
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_RotomNotInParty
    setvar VAR_0x8004, 5
	special TryChangeRotomForm
    callnative UpdateFollowingPokemon
    end

Birthday_Ellies_House_RotomNotInParty_Text:
    .string "ROTOM is not in your party!$"


Birthday_Ellies_House_Ellie_EventScript::
	lock
	faceplayer
	msgbox Birthday_Ellies_House_Ellie_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Ellies_House_EllieBattle_EventScript1::
	lock
	special StorePlayerCoordsInVars
    special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Birthday_Ellies_House_CamMovement1
	waitmovement 0
	special RemoveCameraObject
    applymovement LOCALID_ELLIE, Birthday_Ellies_House_EllieMovement1
    applymovement LOCALID_CODEBUG, Birthday_Ellies_House_EllieMovement1
    waitmovement 0
	msgbox_mugshot Birthday_Ellies_House_EllieWarnsNeuro, MSGBOX_DEFAULT, MUGSHOT_ELLIE, CLEAR_MUGSHOT
	msgbox_mugshot Birthday_Ellies_House_NeuroGives0Fucks, MSGBOX_DEFAULT, MUGSHOT_NEURO, CLEAR_MUGSHOT
    special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Birthday_Ellies_House_CamMovement2
	waitmovement 0
	special RemoveCameraObject
    applymovement LOCALID_NEURO_1, Birthday_Ellies_House_NeuroMovement1
	msgbox_mugshot Birthday_Ellies_House_ElliePreBattle_Text, MSGBOX_DEFAULT, MUGSHOT_ELLIE, CLEAR_MUGSHOT
    waitmovement 0
    goto Birthday_Ellies_House_EllieActualBattle_EventScript
	release
	end

Birthday_Ellies_House_EllieActualBattle_EventScript::
	trainerbattle_single TRAINER_ELLIE, Birthday_Ellies_House_EllieIntro_Text, Birthday_Ellies_House_EllieDefeat_Text
    goto Birthday_Ellies_House_EllieEND_EventScript
	release
	end

Birthday_Ellies_House_EllieEND_EventScript::
	msgbox_mugshot Birthday_Ellies_House_EllieSorry_Text, MSGBOX_DEFAULT, MUGSHOT_ELLIE, CLEAR_MUGSHOT
    fadescreen FADE_TO_BLACK
    setflag FLAG_HIDE_NEURO1
    removeobject LOCALID_NEURO_1
	fadescreen FADE_FROM_BLACK
    clearflag FLAG_HIDE_NEURO2
    addobject LOCALID_NEURO_2
    setvar VAR_ELLIE_HOUSE_HIDE, 1
	release
	end

Birthday_Ellies_House_EllieWarnsNeuro:
    .string "Neuro stop!! If you drive\n"
    .string "so reckless you might hurt\p"
    .string "someone!$"

Birthday_Ellies_House_NeuroGives0Fucks:
    .string "WROOM WROOM! I can't hear\n"
    .string "you, while I am exceeding\p"
    .string "speedlimits beyond human\n"
    .string "comprehension!\p"
    .string "Look! A prefect test subject!$"

Birthday_Ellies_House_ElliePreBattle_Text:
    .string "REYA WATCHOUT!$"

Birthday_Ellies_House_EllieSorry_Text:
    .string "Are you alright Reya?!\n"
    .string "I hope Neuro didnt hurt you...$"

Birthday_Ellies_House_EllieDefeat_Text:
    .string "placeholder!$"

Birthday_Ellies_House_Ellie_Text:
    .string "placeholder!$"

Birthday_Ellies_House_EllieIntro_Text:
    .string "placeholder!$"

Birthday_Ellies_House_CamMovement1:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	step_end

Birthday_Ellies_House_CamMovement2:
	walk_slow_left
	walk_slow_left
	walk_slow_left
	step_end

Birthday_Ellies_House_EllieMovement1:
    emote_exclamation_mark
    step_end

Birthday_Ellies_House_NeuroMovement1:
    walk_fast_left
    walk_fast_left
    walk_fast_left
    walk_fast_left
    walk_fast_down
    emote_exclamation_mark
    step_end

Birthday_Ellies_House_CHARJABUG_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Ellies_House_CHARJABUG_Text, MSGBOX_DEFAULT, MUGSHOT_CHARJABUG, CLEAR_MUGSHOT
	release
	end

Birthday_Ellies_House_CHARJABUG_Text:
    .string "Codebugs rules!!$"
