MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "Hey, me again. I hear you know VYRAL.\p"
	.string "Training under our glorious leader\n"
	.string "will hopefully one day make me win\l"
	.string "VYRAL’s gaze.\p"
	.string "Beating you is the next step!$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "VYRAL… I’m sorry I failed you!$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "Hey, I don’t suppose you have any\n"
	.string "pictures of VYRAL. I’d be willing\l"
	.string "to pay you for them.$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "Hello potential intruder!\p"
	.string "Unfortunately it is my duty to inform\n"
	.string "you that at the behest of our\l"
	.string "‘glorious’ leader it is my\l"
	.string "responsibility to dispose of you.\p"
	.string ".....\n"
	.string "So much effort...$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "Yeah. It do be like that.$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "I can’t believe I’m taking orders\n"
	.string "from some del-\p"
	.string "Oh nevermind me you can continue on.$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "I won’t let you anywhere near SVELTE.\n"
	.string "She’s like a daughter to me.$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "I failed to protect her.$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "That child deserves so much better\n"
	.string "than her mother (real).\p"
	.string "I’m only here for her wellbeing.$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "Mimimi Kill Kill Kill!$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "Grawr…$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "Hissssssssssssssss$"

