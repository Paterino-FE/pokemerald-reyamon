MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "I mention VYRAL once and I get this\n"
	.string "guard posting?\p"
	.string "I’m an ice dragon, my left ear is\n"
	.string "burning up!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "I’m melting…$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "I just had to be the one dragon who\n"
	.string "doesn’t enjoy being in volcanos huh?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "We joined so we can help our glorious\n"
	.string "leader achieve her fantastic vision.\p"
	.string "Shes’s given us dragons the first bit\n"
	.string "of hope in at least three weeks.\p"
	.string "I don’t care if you’re with Tentacool\n"
	.string "Cruises or if you’re just some\l"
	.string "stuffed up Empress.\p"
	.string "No one interferes with my girlboss!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Hahaha, oh you poor thing,\n"
	.string "you think you can beat her?$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Listen to me.\n"
	.string "Dragon Gang offers real change.\p"
	.string "Tentacool cruises are just a bunch\n"
	.string "of fatcats gaming the system!\p"
	.string "They don’t even have any tacos!$"

