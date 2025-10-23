Birthday_Cave_Past_R1_MapScripts::
	.byte 0

Birthday_Cave_Past_R1_BandanaT_EventScript::
	trainerbattle_single TRAINER_BANDANAT, Birthday_Cave_Past_R1_BandanaTIntro_Text, Birthday_Cave_Past_R1_BandanaTDefeat_Text
	msgbox Birthday_Cave_Past_R1_BandanaT_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R1_BandanaTDefeat_Text:
	.string "I'm AZOOMARILLING out of here :<.$"

Birthday_Cave_Past_R1_BandanaT_Text:
	.string "Oh, I hear it's your birthday!\n"
	.string "HAPPY BIRTHDAYYYYYYYYYYYYYYYYYYYYYYY!$"

Birthday_Cave_Past_R1_BandanaTIntro_Text:
	.string "I'm Zigging. I'm Zagging...$"

Birthday_Cave_Past_R1_DAVID8887_EventScript::
	trainerbattle_single TRAINER_DAVID8887, Birthday_Cave_Past_R1_DAVID8887Intro_Text, Birthday_Cave_Past_R1_DAVID8887Defeat_Text
	msgbox Birthday_Cave_Past_R1_DAVID8887_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R1_DAVID8887Defeat_Text:
	.string "ARON't you glad that you won!$"

Birthday_Cave_Past_R1_DAVID8887_Text:
	.string "Please don't smash these rocks.\n"
	.string "I'm saving them for dinner!$"

Birthday_Cave_Past_R1_DAVID8887Intro_Text:
	.string "Rocks should make up 100 percent\n"
	.string "of a growing DIRKLING's diet!$"

Birthday_Cave_Past_R1_Sign1_EventScript::
	lock
	msgbox Birthday_Cave_Past_R1_Sign1_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R1_Sign1_Text:
	.string "placeholder$"

Birthday_Cave_Past_R1_Sign2_EventScript::
	lock
	msgbox Birthday_Cave_Past_R1_Sign2_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R1_Sign2_Text:
	.string "placeholder$"

Birthday_Cave_Past_R1_Sign3_EventScript::
	lock
	msgbox Birthday_Cave_Past_R1_Sign3_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R1_Sign3_Text:
	.string "placeholder$"

Birthday_Cave_Past_R1_Sign4_EventScript::
	lock
	msgbox Birthday_Cave_Past_R1_Sign4_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R1_Sign4_Text:
	.string "placeholder$"

