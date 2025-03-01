SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "Please just let me win,\n"
	.string "I need a promotion!$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "I just wanted a promotion…$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "I just want a promotion so I can\n"
	.string "stop having to do these weird jobs…$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "The lengths I go to for this job!$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "I’m just trying to serve her\n"
	.string "the debt collection notice.$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "I’m just gonna leave these\n"
	.string "papers somewhere…$"

