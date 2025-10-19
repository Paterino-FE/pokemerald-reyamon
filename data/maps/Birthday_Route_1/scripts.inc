.set LOCALID_LILYPAL_1, 5
.set LOCALID_LILYPAL_2, 6
.set LOCALID_LILYPAL_3, 8
.set LOCALID_LILYPAL_4, 11
.set LOCALID_SVELTE, 9
.set LOCALID_LYRA, 7
.set LOCALID_GROUDON, 12
.set LOCALID_DIRKLING_1, 10
.set LOCALID_DIRKLING_2, 13
.set LOCALID_DIRKLING_3, 14
.set LOCALID_DIRKLING_4, 15
.set LOCALID_DIRKLING_5, 16
.set LOCALID_ROCK_SMASH_1, 17
.set LOCALID_ROCK_SMASH_2, 18

Birthday_Route_1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Birthday_Route_1_EventScript_Hide_Future_Present_Setup
	map_script MAP_SCRIPT_ON_LOAD, Birthday_Route_1_EventScript_Hide_Future_Future_Setup
	.byte 0

Birthday_Route_1_EventScript_Hide_Future_Future_Setup::
	call_if_eq VAR_BIRTHDAY_HIDE_FUTURE, 2, Birthday_Route_1_Hide_Future
	return

Birthday_Route_1_EventScript_Hide_Future_Present_Setup::
	call_if_eq VAR_BIRTHDAY_HIDE_PRESENT, 2, Birthday_Route_1_Hide_Present
	return

Birthday_Route_1_EventScript_Trigger_End::
	release
	end

Birthday_Route_1_Hide_Future::
	removeobject LOCALID_LILYPAL_1, 5
	removeobject LOCALID_LILYPAL_2, 6
	removeobject LOCALID_LILYPAL_3, 8
	removeobject LOCALID_LILYPAL_4, 11
	removeobject LOCALID_SVELTE, 9
	removeobject LOCALID_LYRA, 7
	removeobject LOCALID_GROUDON, 12
	removeobject LOCALID_DIRKLING_1, 10
	setvar VAR_BIRTHDAY_HIDE_FUTURE, 3
	return

Birthday_Route_1_Hide_Present::
	removeobject LOCALID_DIRKLING_2, 13
	removeobject LOCALID_DIRKLING_3, 14
	removeobject LOCALID_DIRKLING_4, 15
	removeobject LOCALID_DIRKLING_5, 16
	removeobject LOCALID_ROCK_SMASH_1, 17
	removeobject LOCALID_ROCK_SMASH_2, 18
	setvar VAR_BIRTHDAY_HIDE_PRESENT, 3
	return

Birthday_Route_1_ArchonOfFog_EventScript::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_ARCHONOFFOG, Birthday_Route_1_ArchonOfFogBattle_EventScript
	msgbox Birthday_Route_1_ArchonOfFog_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Route_1_ArchonOfFogBattle_EventScript::
	msgbox Birthday_Route_1_ArchonOfFogPreBattle_Text, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_ARCHONOFFOG, Birthday_Route_1_ArchonOfFogIntro_Text, Birthday_Route_1_ArchonOfFogDefeat_Text
	release
	end

Birthday_Route_1_ArchonOfFogPreBattle_Text:

Birthday_Route_1_ArchonOfFogDefeat_Text:

Birthday_Route_1_ArchonOfFog_Text:

Birthday_Route_1_ArchonOfFogIntro_Text:

Birthday_Route_1_Nigeltastic_EventScript::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_NIGELTASTIC, Birthday_Route_1_NigeltasticBattle_EventScript
	msgbox Birthday_Route_1_Nigeltastic_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Route_1_NigeltasticBattle_EventScript::
	msgbox Birthday_Route_1_NigeltasticPreBattle_Text, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_NIGELTASTIC, Birthday_Route_1_NigeltasticIntro_Text, Birthday_Route_1_NigeltasticDefeat_Text
	release
	end

Birthday_Route_1_NigeltasticPreBattle_Text:

Birthday_Route_1_NigeltasticDefeat_Text:

Birthday_Route_1_Nigeltastic_Text:

Birthday_Route_1_NigeltasticIntro_Text:

Birthday_Route_1_Quattuor_EventScript::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_QUATTUOR, Birthday_Route_1_QuattuorBattle_EventScript
	msgbox Birthday_Route_1_Quattuor_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Route_1_QuattuorBattle_EventScript::
	msgbox Birthday_Route_1_QuattuorPreBattle_Text, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_QUATTUOR, Birthday_Route_1_QuattuorIntro_Text, Birthday_Route_1_QuattuorDefeat_Text
	release
	end

Birthday_Route_1_QuattuorPreBattle_Text:

Birthday_Route_1_QuattuorDefeat_Text:

Birthday_Route_1_Quattuor_Text:

Birthday_Route_1_QuattuorIntro_Text:

Birthday_Route_1_Sign1_EventScript::
	lock
	faceplayer
	msgbox Birthday_Route_1_Sign1_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Route_1_Sign1_Text:

Birthday_Route_1_Sign2_EventScript::
	lock
	faceplayer
	msgbox Birthday_Route_1_Sign2_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Route_1_Sign2_Text:
