.set LOCALID_EMI, 4
.set LOCALID_PAT, 3
.set LOCALID_SNORLAX, 2
.set LOCALID_THEA, 5

Birthday_Main_Village_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Birthday_Main_Village_Hide_Setup
	.byte 0

Birthday_Main_Village_Hide_Setup::
	call_if_eq VAR_BIRTHDAY_HIDE_PAST, 2, Birthday_Main_Village_Hide_Thea_1
	call_if_eq VAR_BIRTHDAY_HIDE_FUTURE, 0, Birthday_Main_Village_Hide_Pat_0
	call_if_eq VAR_BIRTHDAY_HIDE_FUTURE, 1, Birthday_Main_Village_Hide_Pat_1
	call_if_eq VAR_BIRTHDAY_HIDE_FUTURE, 4, Birthday_Main_Village_Hide_Pat_4
	call_if_eq VAR_BIRTHDAY_HIDE_PRESENT, 0, Birthday_Main_Village_Hide_Emilia_0
	call_if_eq VAR_BIRTHDAY_HIDE_PRESENT, 1, Birthday_Main_Village_Hide_Emilia_1
	call_if_eq VAR_BIRTHDAY_HIDE_PRESENT, 4, Birthday_Main_Village_Hide_Emilia_4
	call_if_eq VAR_BIRTHDAY_ENDING, 1, Birthday_Main_Village_Hide_Snorlax_1

Birthday_Main_Village_EventScript_Trigger_End::
	release
	end

Birthday_Main_Village_Hide_Thea_1::
	setflag	FLAG_HIDE_THEA_HAMLET
	removeobject LOCALID_THEA, 5
	return

Birthday_Main_Village_Hide_Pat_0::
	setflag FLAG_HIDE_PAT_HAMLET
	removeobject LOCALID_PAT, 3
	return

Birthday_Main_Village_Hide_Pat_1::
	clearflag FLAG_HIDE_PAT_HAMLET
	addobject LOCALID_PAT, 3
	return

Birthday_Main_Village_Hide_Pat_4::
	setflag FLAG_HIDE_PAT_HAMLET
	removeobject LOCALID_PAT, 3
	return

Birthday_Main_Village_Hide_Emilia_0::
	setflag	FLAG_HIDE_EMILIA_HAMLET
	removeobject LOCALID_EMI, 4
	return

Birthday_Main_Village_Hide_Emilia_1::
	clearflag FLAG_HIDE_EMILIA_HAMLET
	addobject LOCALID_EMI, 4
	return

Birthday_Main_Village_Hide_Emilia_4::
	setflag	FLAG_HIDE_EMILIA_HAMLET
	removeobject LOCALID_EMI, 4
	return

Birthday_Main_Village_Hide_Snorlax_1::
	removeobject LOCALID_SNORLAX, 2
	setflag	FLAG_HIDE_SNORLAX
	return

Birthday_Main_Village_After_Past_Pat::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_After_Past_Pat_Text, MSGBOX_DEFAULT, MUGSHOT_ARLE, CLEAR_MUGSHOT
	setvar VAR_BIRTHDAY_HIDE_FUTURE, 2
	setflag FLAG_HIDE_FUTURE
	release
	end

Birthday_Main_Village_After_Past_Pat_Text:
	.string "Path to the future is free.$"

Birthday_Main_Village_After_Future_Emilia::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_After_Future_Emilia_Text, MSGBOX_DEFAULT, MUGSHOT_EMILIA, CLEAR_MUGSHOT
	setvar VAR_BIRTHDAY_HIDE_PRESENT, 2
	setflag FLAG_HIDE_PRESENT
	release
	end

Birthday_Main_Village_After_Future_Emilia_Text:
	.string "Path to the present is free.$"

Birthday_Main_Village_After_Past_Thea_1::
	lock
	applymovement LOCALID_THEA, Birthday_Main_Village_After_Past_Movement
	waitmovement 0
	faceplayer
	msgbox_mugshot Birthday_Main_Village_After_Past_Thea_Text, MSGBOX_DEFAULT, MUGSHOT_THEA, CLEAR_MUGSHOT
	setvar VAR_BIRTHDAY_HIDE_PAST, 1
	release
	end

Birthday_Main_Village_After_Past_Thea_2::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_After_Past_Thea_Text, MSGBOX_DEFAULT, MUGSHOT_THEA, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_After_Past_Thea_Text:
	.string "You must go to Route 1. To the East!$"

Birthday_Main_Village_After_Past_Movement:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	step_end
