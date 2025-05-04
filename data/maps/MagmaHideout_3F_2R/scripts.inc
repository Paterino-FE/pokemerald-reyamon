MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "I don’t understand anything our\n"
	.string "glorious leader says.\p"
	.string "But you know what? Doing stuff\n"
	.string "like digging up a super-ancient\l"
	.string "POKéMON and ripping off someone’s\l"
	.string "meteorite…\p"
	.string "I think that’s pretty cool and based.\n"
	.string "What do you think?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "Yeah, maybe you’re right, I think we\n"
	.string "are doing something wrong somehow.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "You know, something just seems off\n"
	.string "about our glorious leader.\p"
	.string "Every time she gives a grand speech\n"
	.string "about helping dragonkind it feels\l"
	.string "like she’s just talking about herself.$"

