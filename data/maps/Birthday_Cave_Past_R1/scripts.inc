Birthday_Cave_Past_R1_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Birthday_Cave_Past_R1_OnResume
	.byte 0

Birthday_Cave_Past_R1_OnResume:
	setescapewarp MAP_BIRTHDAY_ROUTE_2, 45, 20
	end


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
	.string "Once the world was consumed by\n"
	.string "rage and filtered all chat messages.$"

Birthday_Cave_Past_R1_Sign2_EventScript::
	lock
	msgbox Birthday_Cave_Past_R1_Sign2_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R1_Sign2_Text:
	.string "Moves that increase stats or\n"
	.string "have status effects?\p"
	.string "Not on my watch, we only\n"
	.string "care about big numbers!$"

Birthday_Cave_Past_R1_Sign3_EventScript::
	lock
	msgbox Birthday_Cave_Past_R1_Sign3_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R1_Sign3_Text:
	.string "Should POKéMON add more types?\n"
	.string "A fairy type? How ridiculous.\p"
	.string "That would never happen.$"

Birthday_Cave_Past_R1_Sign4_EventScript::
	lock
	msgbox Birthday_Cave_Past_R1_Sign4_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R1_Sign4_Text:
	.string "If you don't send this message\n"
	.string "to ten of your friends in a minute...\p"
	.string "You will be cursed for\n"
	.string "all eternity!!!$"
