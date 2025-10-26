.set LOCALID_ELLIE, 2
.set LOCALID_NEURO_1, 1
.set LOCALID_NEURO_2, 9
.set LOCALID_CODEBUG, 8
.set LOCALID_APPLIANCE, 10
.set LOCALID_APPLIANCE, 4
.set LOCALID_APPLIANCE, 5
.set LOCALID_APPLIANCE, 6
.set LOCALID_APPLIANCE, 7

Birthday_Ellies_House_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Birthday_Ellies_House_Setup
    .byte 0

Birthday_Ellies_House_Setup::
	call_if_eq VAR_ELLIE_HOUSE_HIDE, 0, Birthday_Ellies_House_Hide1
	call_if_eq VAR_ELLIE_HOUSE_HIDE, 2, Birthday_Ellies_House_Hide2
	release
	end

Birthday_Ellies_House_Hide1::
	removeobject LOCALID_APPLIANCE, 10
	removeobject LOCALID_APPLIANCE, 4
	removeobject LOCALID_APPLIANCE, 5
	removeobject LOCALID_APPLIANCE, 6
	removeobject LOCALID_APPLIANCE, 7
    removeobject LOCALID_NEURO_2, 9
	setflag	FLAG_HIDE_NEURO2
	setflag	FLAG_HIDE_APPLIANCE
	return

Birthday_Ellies_House_Hide2::
	addobject LOCALID_APPLIANCE, 4
	addobject LOCALID_APPLIANCE, 5
	addobject LOCALID_APPLIANCE, 6
	addobject LOCALID_APPLIANCE, 7
	addobject LOCALID_APPLIANCE, 10
	clearflag FLAG_HIDE_APPLIANCE
	return

Birthday_Ellies_House_RotomNotInParty::
    lock
    msgbox Birthday_Ellies_House_RotomNotInParty_Text, MSGBOX_DEFAULT
    release
    end

Birthday_Ellies_House_Text_DoYouWantToChange:
    .string "Do you want NEURO to change form?$"

Birthday_Ellies_House_Text_NoChange:
    .string "Nothing happened.$"

Birthday_Ellies_House_EventScript_NoChange::
    msgbox Birthday_Ellies_House_Text_NoChange, MSGBOX_AUTOCLOSE
    release
    end

Birthday_Ellies_House_BaseRotom::
    faceplayer
    specialvar VAR_RESULT, IsRotomInParty
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_RotomNotInParty
    msgbox Birthday_Ellies_House_Text_DoYouWantToChange, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, Birthday_Ellies_House_EventScript_NoChange
    setvar VAR_0x8004, 0
	specialvar VAR_RESULT, TryChangeRotomForm
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_EventScript_NoChange
    callnative UpdateFollowingPokemon
    release
    end

Birthday_Ellies_House_HeatRotom::
    specialvar VAR_RESULT, IsRotomInParty
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_RotomNotInParty
    msgbox Birthday_Ellies_House_Text_DoYouWantToChange, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, Birthday_Ellies_House_EventScript_NoChange
    setvar VAR_0x8004, 1
	specialvar VAR_RESULT, TryChangeRotomForm
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_EventScript_NoChange
    callnative UpdateFollowingPokemon
    release
    end

Birthday_Ellies_House_WashRotom::
    specialvar VAR_RESULT, IsRotomInParty
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_RotomNotInParty
    msgbox Birthday_Ellies_House_Text_DoYouWantToChange, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, Birthday_Ellies_House_EventScript_NoChange
    setvar VAR_0x8004, 2
	specialvar VAR_RESULT, TryChangeRotomForm
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_EventScript_NoChange
    callnative UpdateFollowingPokemon
    release
    end

Birthday_Ellies_House_FrostRotom::
    specialvar VAR_RESULT, IsRotomInParty
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_RotomNotInParty
    msgbox Birthday_Ellies_House_Text_DoYouWantToChange, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, Birthday_Ellies_House_EventScript_NoChange
    setvar VAR_0x8004, 3
	specialvar VAR_RESULT, TryChangeRotomForm
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_EventScript_NoChange
    callnative UpdateFollowingPokemon
    release
    end
    
Birthday_Ellies_House_FanRotom::
    specialvar VAR_RESULT, IsRotomInParty
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_RotomNotInParty
    msgbox Birthday_Ellies_House_Text_DoYouWantToChange, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, Birthday_Ellies_House_EventScript_NoChange
    setvar VAR_0x8004, 4
	specialvar VAR_RESULT, TryChangeRotomForm
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_EventScript_NoChange
    callnative UpdateFollowingPokemon
    release
    end
    
Birthday_Ellies_House_MowRotom::
    specialvar VAR_RESULT, IsRotomInParty
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_RotomNotInParty
    msgbox Birthday_Ellies_House_Text_DoYouWantToChange, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, Birthday_Ellies_House_EventScript_NoChange
    setvar VAR_0x8004, 5
	specialvar VAR_RESULT, TryChangeRotomForm
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_EventScript_NoChange
    callnative UpdateFollowingPokemon
    release
    end

Birthday_Ellies_House_RotomNotInParty_Text:
    .string "NEURO is not in your party!$"


Birthday_Ellies_House_NeuroHi_EventScript::
    lock
    faceplayer
    msgbox_mugshot Birthday_Ellies_House_NeuroHi_Text, NSGBOX_AUTOCLOSE, MUGSHOT_NEURO, CLEAR_MUGSHOT
    release
    end

Birthday_Ellies_House_NeuroHi_Text:
    .string "NEURO: Sorry for calling you intruder!$"

Birthday_Ellies_House_Ellie_EventScript::
	lock
	faceplayer
    goto_if_unset FLAG_HIDE_NEURO2, Birthday_Ellies_House_EventScript_NeuroWantsToJoin
	msgbox_mugshot Birthday_Ellies_House_Ellie_Text, MSGBOX_DEFAULT, MUGSHOT_ELLIE, CLEAR_MUGSHOT
	release
	end

Birthday_Ellies_House_EllieBattle_EventScript1::
	lock
	special StorePlayerCoordsInVars
    special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Birthday_Ellies_House_CamMovement1
	waitmovement 0
	special RemoveCameraObject
    msgbox_mugshot Birthday_Ellies_House_WhereDidIPut, MSGBOX_DEFAULT, MUGSHOT_ELLIE, CLEAR_MUGSHOT
    applymovement LOCALID_ELLIE, Birthday_Ellies_House_EllieMovement1
    applymovement LOCALID_CODEBUG, Birthday_Ellies_House_EllieMovement1
    waitmovement 0
    msgbox_mugshot Birthday_Ellies_House_HeyWhatAreYou, MSGBOX_DEFAULT, MUGSHOT_ELLIE, CLEAR_MUGSHOT
    applymovement LOCALID_NEURO_1, Birthday_Ellies_House_EllieMovement1
	msgbox_mugshot Birthday_Ellies_House_NeuroGives0Fucks, MSGBOX_DEFAULT, MUGSHOT_NEURO, CLEAR_MUGSHOT
    waitmovement 0
    special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Birthday_Ellies_House_CamMovement2
	waitmovement 0
	special RemoveCameraObject
    applymovement LOCALID_NEURO_1, Birthday_Ellies_House_NeuroMovement1
    waitmovement 0
    goto Birthday_Ellies_House_EllieActualBattle_EventScript
	release
	end

Birthday_Ellies_House_EllieBattle_EventScript2::
	lock
	special StorePlayerCoordsInVars
    special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Birthday_Ellies_House_CamMovement1
	waitmovement 0
	special RemoveCameraObject
    msgbox_mugshot Birthday_Ellies_House_WhereDidIPut, MSGBOX_DEFAULT, MUGSHOT_ELLIE, CLEAR_MUGSHOT
    applymovement LOCALID_ELLIE, Birthday_Ellies_House_EllieMovement1
    applymovement LOCALID_CODEBUG, Birthday_Ellies_House_EllieMovement1
    waitmovement 0
    msgbox_mugshot Birthday_Ellies_House_HeyWhatAreYou, MSGBOX_DEFAULT, MUGSHOT_ELLIE, CLEAR_MUGSHOT
	applymovement LOCALID_NEURO_1, Birthday_Ellies_House_EllieMovement1
	msgbox_mugshot Birthday_Ellies_House_NeuroGives0Fucks, MSGBOX_DEFAULT, MUGSHOT_NEURO, CLEAR_MUGSHOT
    waitmovement 0
    special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Birthday_Ellies_House_CamMovement2
	waitmovement 0
	special RemoveCameraObject
    applymovement LOCALID_NEURO_1, Birthday_Ellies_House_NeuroMovement2
    waitmovement 0
    goto Birthday_Ellies_House_EllieActualBattle_EventScript
	release
	end

Birthday_Ellies_House_EllieBattle_EventScript3::
	lock
	special StorePlayerCoordsInVars
    special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Birthday_Ellies_House_CamMovement1
	waitmovement 0
	special RemoveCameraObject
	msgbox_mugshot Birthday_Ellies_House_WhereDidIPut, MSGBOX_DEFAULT, MUGSHOT_ELLIE, CLEAR_MUGSHOT
    applymovement LOCALID_ELLIE, Birthday_Ellies_House_EllieMovement1
    applymovement LOCALID_CODEBUG, Birthday_Ellies_House_EllieMovement1
    waitmovement 0
    msgbox_mugshot Birthday_Ellies_House_HeyWhatAreYou, MSGBOX_DEFAULT, MUGSHOT_ELLIE, CLEAR_MUGSHOT
	applymovement LOCALID_NEURO_1, Birthday_Ellies_House_EllieMovement1
	msgbox_mugshot Birthday_Ellies_House_NeuroGives0Fucks, MSGBOX_DEFAULT, MUGSHOT_NEURO, CLEAR_MUGSHOT
    waitmovement 0
    special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Birthday_Ellies_House_CamMovement2
	waitmovement 0
	special RemoveCameraObject
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
    waitmovement 0
    applymovement LOCALID_NEURO_1, Birthday_Ellies_House_NeuroMovement3
    waitmovement 0
    goto Birthday_Ellies_House_EllieActualBattle_EventScript
	release
	end

Birthday_Ellies_House_EllieActualBattle_EventScript::
	trainerbattle_no_intro TRAINER_ELLIE, Birthday_Ellies_House_EllieDefeat_Text
    goto Birthday_Ellies_House_EllieEND_EventScript
	release
	end

Birthday_Ellies_House_EllieEND_EventScript::
    fadescreen FADE_TO_BLACK
    setflag FLAG_HIDE_NEURO1
    removeobject LOCALID_NEURO_1
    clearflag FLAG_HIDE_NEURO2
    addobject LOCALID_NEURO_2
    setvar VAR_ELLIE_HOUSE_HIDE, 1
    fadescreen FADE_FROM_BLACK
	release
	end

Birthday_Ellies_House_WhereDidIPut:
    .string "ELLIE: Now let's see where did I\n"
    .string "put those--$"

Birthday_Ellies_House_HeyWhatAreYou: 
    .string "Hey what are you doing in my workshop!$"

Birthday_Ellies_House_NeuroGives0Fucks:
    .string "NEURO: INTRUDER ALERT!$"

Birthday_Ellies_House_EllieDefeat_Text:
    .string "Wow you really know what you're doing!\p"
    .string "I'd love to see what you and NEURO\n"
    .string "could do with that mow I fixed up!$"

Birthday_Ellies_House_Ellie_Text:
    .string "Oh hey!\n"
    .string "Have you seen my calipers?$"

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
    step_end

Birthday_Ellies_House_NeuroMovement2:
    walk_fast_left
    walk_fast_left
    walk_fast_left
    walk_fast_down
    step_end

Birthday_Ellies_House_NeuroMovement3:
    walk_fast_left
    walk_fast_left
    walk_fast_down
    walk_fast_down
    step_end

Birthday_Ellies_House_CHARJABUG_EventScript::
	lock
	faceplayer
    goto_if_set FLAG_HIDE_NEURO2, Birthday_Ellies_House_BaseRotom
	msgbox_mugshot Birthday_Ellies_House_CHARJABUG_Text, MSGBOX_DEFAULT, MUGSHOT_CHARJABUG, CLEAR_MUGSHOT
	release
	end

Birthday_Ellies_House_CHARJABUG_Text:
    .string "Codebugs rule!!$"


Birthday_Ellies_House_EventScript_NeuroWantsToJoin::
    lock
    faceplayer
	msgbox Birthday_Ellies_House_Text_NeuroWantsToJoin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Birthday_Ellies_House_EventScript_NeuroRejected
	closemessage
    msgbox_mugshot Birthday_Ellies_House_Text_TakeCare, MSGBOX_AUTOCLOSE, MUGSHOT_ELLIE, CLEAR_MUGSHOT
    setflag P_FLAG_FORCE_SHINY
	givemon SPECIES_ROTOM_MOW, 65, ITEM_LIFE_ORB, ITEM_LUXURY_BALL
    clearflag P_FLAG_FORCE_SHINY
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Birthday_Ellies_House_EventScript_ReceiveNeuroParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Birthday_Ellies_House_EventScript_ReceiveNeuroPC
	release
	end

Birthday_Ellies_House_Text_TakeCare:
    .string "Lemme know if she gives you\n"
    .string "any trouble!$"

Birthday_Ellies_House_Text_NeuroWantsToJoin:
    .string "Hey do you wanna take NEURO out for\n"
    .string "a spin? She's so cute, isn't she?$"

Birthday_Ellies_House_EventScript_NeuroRejected::
    closemessage
	msgbox_mugshot Birthday_Ellies_House_Text_NeuroRejected, MSGBOX_DEFAULT, MUGSHOT_ELLIE, CLEAR_MUGSHOT
	release
	end

Birthday_Ellies_House_Text_NeuroRejected:
    .string "Well hey, you know where to find\n"
    .string "me if you change your mind!$"

Birthday_Ellies_House_EventScript_ReceiveNeuroParty::
	call Birthday_Ellies_House_EventScript_ReceivedNeuroFanfare
	call Common_EventScript_GetGiftMonPartySlot
	call Birthday_Ellies_House_EventScript_HideNeuro
	end

Birthday_Ellies_House_EventScript_ReceiveNeuroPC::
	call Birthday_Ellies_House_EventScript_ReceivedNeuroFanfare
	call Birthday_Ellies_House_EventScript_SendNeuroToPC
	end

Birthday_Ellies_House_EventScript_SendNeuroToPC::
	call Common_EventScript_TransferredToPC
	goto Birthday_Ellies_House_EventScript_HideNeuro
	end

Birthday_Ellies_House_EventScript_ReceivedNeuroFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Birthday_Ellies_House_Text_PlayerReceivedNeuro
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_ROTOM_MOW
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ROTOM_MOW
	return

Birthday_Ellies_House_Text_PlayerReceivedNeuro:
    .string "{PLAYER} received NEURO!$"

Birthday_Ellies_House_EventScript_HideNeuro::
	lockall  
	playmoncry SPECIES_ROTOM_MOW, CRY_MODE_ENCOUNTER
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_NEURO2
    setvar VAR_ELLIE_HOUSE_HIDE, 2
    call Birthday_Ellies_House_Hide2
	removeobject LOCALID_NEURO_2
    getplayerxy VAR_TEMP_2, VAR_TEMP_3
    warp MAP_BIRTHDAY_ELLIES_HOUSE, VAR_TEMP_2, VAR_TEMP_3
	waitmoncry
	fadescreen FADE_FROM_BLACK
	release
	return


