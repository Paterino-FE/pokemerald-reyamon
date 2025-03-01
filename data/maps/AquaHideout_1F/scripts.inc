AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "What? What? Why are you here? No, our\n"
	.string "spokeswoman isn’t here!\p"
	.string "… Where did she go?\n"
	.string "How would I know?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "What? What?\n"
	.string "Are you a Dragon Gang grunt?\p"
	.string "I hear that Dragon Gang is trying to\n"
	.string "awaken an awesome POKéMON at their\l"
	.string "HIDEOUT.\p"
	.string "But where might their HIDEOUT be?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "Sorry? We’re not supposed to have\n"
	.string "potential customers back here.\p"
	.string "No, the spokeswoman isn’t here!\n"
	.string "She said something about a submarine!\p"
	.string "… Where did she go? Well, I really\n"
	.string "can’t give you her personal info like\p"
	.string "that now can I?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "What? What? Why are you here? No, our\n"
	.string "spokeswoman isn’t here! She was\p"
	.string "heading to Mt. Pyre or\n"
	.string "something!\p"
	.string "… Why did she go?\n"
	.string "How would I know?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "What? What?\n"
	.string "Are you a Dragon Gang grunt?\p"
	.string "I hear that Dragon Gang is after\n"
	.string "an awesome POKéMON at MT. CHIMNEY.\p"
	.string "But what is that POKéMON like?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "What? What? Why are you here? No, our\n"
	.string "spokeswoman isn’t here! She was\p"
	.string "heading to Slateport City or\n"
	.string "something!\p"
	.string "… Why did she go?\n"
	.string "How would I know?$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "Sorry, employees only right now.$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "Nobody listens to me!$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "I really need to learn to\n"
	.string "command some authority…$"

