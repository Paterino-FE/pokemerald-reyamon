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
	trainerbattle_single TRAINER_ARCHONOFFOG, Birthday_Route_1_ArchonOfFogIntro_Text, Birthday_Route_1_ArchonOfFogDefeat_Text
	msgbox Birthday_Route_1_ArchonOfFog_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Route_1_ArchonOfFogDefeat_Text:
	.string "...This better make part of a video,\n"
	.string "your EDITOR owes me money...$"

Birthday_Route_1_ArchonOfFog_Text:
	.string "You know what I said...$"

Birthday_Route_1_ArchonOfFogIntro_Text:
	.string "Hey, you. I need to fight you so you\n"
	.string "have more content to make, you need\l"
	.string "to make more videos!$"

Birthday_Route_1_Nigeltastic_EventScript::
	trainerbattle_single TRAINER_NIGELTASTIC, Birthday_Route_1_NigeltasticIntro_Text, Birthday_Route_1_NigeltasticDefeat_Text
	msgbox Birthday_Route_1_Nigeltastic_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Route_1_NigeltasticDefeat_Text:
	.string "Well, maybe I'm VYRAL's second\n"
	.string "strongest DIRKLING...$"

Birthday_Route_1_Nigeltastic_Text:
	.string "Happy Birthday {PLAYER}!\n"
	.string "Hope you have a nice day :)$"

Birthday_Route_1_NigeltasticIntro_Text:
	.string "Prepare to face the wrath of VYRAL's\n"
	.string "strongest DIRKLING!$"

Birthday_Route_1_Quattuor_EventScript::
	lock
	faceplayer
	trainerbattle_single TRAINER_QUATTUOR, Birthday_Route_1_QuattuorIntro_Text, Birthday_Route_1_QuattuorDefeat_Text
	msgbox Birthday_Route_1_Quattuor_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Route_1_QuattuorIntro_Text:
	.string "That is fantastic! Four incredible\n"
	.string "POKéMON in a team!\p"
	.string "S-say that again...\n"
	.string "(He says to himself)$"

Birthday_Route_1_QuattuorDefeat_Text:
	.string "That was quite a thing.$"

Birthday_Route_1_Quattuor_Text:
	.string "Bop bop bop lin lin.$"

Birthday_Route_1_UmaTrainer_EventScript::
	lock
	faceplayer
	trainerbattle_single TRAINER_TREINA_SAN, Birthday_Route_1_UmaTrainerIntro_Text, Birthday_Route_1_UmaTrainerDefeat_Text
	msgbox Birthday_Route_1_UmaTrainer_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Route1_DirklingsNorth_EventScript::
	lock
	msgbox Birthday_Route_1_WeLikeRocks_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Route_1_WeLikeRocks_Text:
	.string "ROCKS! ROCKS!\n"
	.string "WE LIKE ROCKS!$"

Birthday_Route_1_UmaTrainerIntro_Text:
	.string "A challenge? I'll have you know we\n"
	.string "won the Triple Crown, all you will\p"
	.string "have is a triple frown!\p"
	.string "Heh, Rudolph would've loved that one.$$"

Birthday_Route_1_UmaTrainerDefeat_Text:
	.string "You are lucky we didn't fight on DIRT!$"

Birthday_Route_1_UmaTrainer_Text:
	.string "Guess I lost... my... debut$"

Birthday_Route_1_Sign1_EventScript::
	lock
	msgbox Birthday_Route_1_Sign1_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Route_1_Sign1_Text:
	.string "$"

Birthday_Route_1_Sign2_EventScript::
	lock
	msgbox Birthday_Route_1_Sign2_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Route_1_Sign2_Text:
	.string "$"


