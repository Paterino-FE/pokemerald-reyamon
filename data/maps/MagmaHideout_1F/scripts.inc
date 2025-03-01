MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "Drat drat drat, I didn’t set the\n"
	.string "password. It was foolproof too nobody\l"
	.string "would have expected a girafarig to\l"
	.string "be called HORSE.$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "I’m always messing up like this but\n"
	.string "luckily our glorious leader just\l"
	.string "laughs and says I’m committed\l"
	.string "to the bit…$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "Did you know she used to have a\n"
	.string "Scyther called ‘giraffe’.\p"
	.string "Do you think it’s okay for her to\n"
	.string "be let out of the house?$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "Our glorious leader told us to dig\n"
	.string "into Mt. Chimney, so we dug and dug.\p"
	.string "I have no idea why but she says\n"
	.string "she’s the smartest and who am I to\l"
	.string "doubt her? What did we find?\p"
	.string "Fuhahaha!\n"
	.string "I’ll tell you if you beat me!$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "Hehe.$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "I can’t tell you after all.\p"
	.string "Our glorious leader refuses to tell\n"
	.string "anybody because only she can\l"
	.string "understand it, I guess.$"

