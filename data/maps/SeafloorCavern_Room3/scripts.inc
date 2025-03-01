SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "DP: How did a pipsqueak like you find\n"
	.string "your way down here? Were you that\l"
	.string "impatient that you couldn't wait a\l"
	.string "month for our rematch?\p"
	.string "Well, I'll just have to deal with\n"
	.string "you now. But you won't be so lucky\l"
	.string "this time!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "You're lucky I take it easy on\n"
	.string "trainers like you.$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "The odds of you getting this lucky\n"
	.string "twice has to be well below 0.01%.\p"
	.string "There's no way you'll get that lucky\n"
	.string "a third time!\p"
	.string "But this time I'm going to make sure\n"
	.string "we wait a month.$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "You really should just let us do this!\p"
	.string "The boss is gonna get super upset if\n"
	.string "this fails and it’s really hard to\l"
	.string "watch…$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Well, I tried.$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "I don’t question the spokeswoman’s\n"
	.string "plans, but she really does seem to\l"
	.string "have some issues…$"



