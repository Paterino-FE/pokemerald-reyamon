Birthday_Main_Village_HouseEnd_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Birthday_Main_Village_HouseEnd_Setup
	.byte 0

Birthday_Main_Village_HouseEnd_Setup::
	setflag FLAG_TEMP_HIDE_FOLLOWER
	end

Birthday_Main_Village_HouseEnd_Paterino_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_HouseEnd_Paterino_Text, MSGBOX_AUTOCLOSE, MUGSHOT_PATERINO, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_HouseEnd_Paterino_Text:
	.string "Once more, a Happy Birthday to you!!\p"
	.string "We kinda have worked again on a fun\n"
	.string "project behind your back, hehe.\p"
	.string "Everyone did so splendidly, right?!\p"
	.string "I can't say enough how great it is to\n"
	.string "work with everyone who was involved.\p"
	.string "Maybe there will be something similar\n"
	.string "in the future, but who knows?\p"
	.string "I sincerely hope this experience\n"
	.string "showed you how much everyone\p"
	.string "actually adores you and your streams.\p"
	.string "Even if you feel tired or stressed,\n"
	.string "don't forget that you have a lot of\p"
	.string "loyal fans and friends beside you at\n"
	.string "every step now and in the future.\p"
	.string "The path you chose isn't easy, but\n"
	.string "isn't life itself a challenge?\p"
	.string "Another year has passed, and this\n"
	.string "is the second year that we know\p"
	.string "each other.\p"
	.string "Let's see how many years it might\n"
	.string "become!\p"
	.string "Stay cool, Reya, and on this special\n"
	.string "day I hope you have a fantastic time\p"
	.string "with your dearest people in your life.$"


Birthday_Main_Village_HouseEnd_Lilypad_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_HouseEnd_Lilypad_Text, MSGBOX_AUTOCLOSE, MUGSHOT_LILYPAD, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_HouseEnd_Lilypad_Text:
	.string "...$"

Birthday_Main_Village_HouseEnd_Grape_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_HouseEnd_Grape_Text, MSGBOX_AUTOCLOSE, MUGSHOT_GRAPE, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_HouseEnd_Grape_Text:
	.string "grape$"

Birthday_Main_Village_HouseEnd_Mable_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_HouseEnd_Mable_Text, MSGBOX_AUTOCLOSE, MUGSHOT_MABLE, CLEAR_MUGSHOT
	msgbox_mugshot Birthday_Main_Village_HouseEnd_Mable2_Text, MSGBOX_AUTOCLOSE, MUGSHOT_MABLE, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_HouseEnd_Mable_Text:
	.string "MABLE: Happy Birthday, REYA!\p"
	.string "You are such an inspiration.\n"
	.string "Your dedication, creativity,\l"
	.string "and care shine so brightly in\l"
	.string "everything you do.\p"
	.string "I admire how hard you work, how much\n"
	.string "love you pour into your craft, and\l"
	.string "how naturally you lift up everyone\l"
	.string "around you.\p"
	.string "You truly deserve all the love,\n"
	.string "recognition, and opportunities the\l"
	.string "world has to offer.\p"
	.string "It meant so much to me to finally\n"
	.string "meet you in person.\p"
	.string "Out of all my close friends, you were\n"
	.string "one of the few who took the time to\l"
	.string "sit down with me that weekend, even\l"
	.string "just for a short while, and that meant\l"
	.string "the world.\p"
	.string "You were also the first and only\n"
	.string "person to give me a spinning hug and\l"
	.string "lift me right off the ground.\p"
	.string "I will never forget that moment.\p"
	.string "You are such a bright soul, and I love\n"
	.string "you so much.$"

Birthday_Main_Village_HouseEnd_Mable2_Text:
	.string "I am relocating to France next year,\n"
	.string "and I genuinely hope that being closer\l"
	.string "will give us the chance to see each\l"
	.string "other more often, whether for fun,\l"
	.string "creative projects, or just catching up\l"
	.string "over coffee.\p"
	.string "Wishing you the happiest birthday,\n"
	.string "REYA.\p"
	.string "YOU FILTHY SCORPIO (affectionate).\n"
	.string "Get loved on, nerd. You deserve it.$"

Birthday_Main_Village_HouseEnd_Tsunami_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_HouseEnd_Tsunami_Text, MSGBOX_AUTOCLOSE, MUGSHOT_TSUNAMI, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_HouseEnd_Tsunami_Text:
	.string "Happy birthday!\n"
	.string "Your community's too good to you!$"

Birthday_Main_Village_HouseEnd_Purge_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_HouseEnd_Purge_Text, MSGBOX_AUTOCLOSE, MUGSHOT_PURGE, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_HouseEnd_Purge_Text:
	.string "Happy birthday!$"

Birthday_Main_Village_HouseEnd_Emilia_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_HouseEnd_Emilia_Text, MSGBOX_AUTOCLOSE, MUGSHOT_EMILIA, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_HouseEnd_Emilia_Text:
	.string "Credits part 1$"

Birthday_Main_Village_HouseEnd_Rosuuri_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_HouseEnd_Rosuuri_Text, MSGBOX_AUTOCLOSE, MUGSHOT_ROSUURI, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_HouseEnd_Rosuuri_Text:
	.string "Happy birthday, REYA!\n"
	.string "I'm so proud of you...!$"

Birthday_Main_Village_HouseEnd_Luminel_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_HouseEnd_Luminel_Text, MSGBOX_AUTOCLOSE, MUGSHOT_LUMI, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_HouseEnd_Luminel_Text:
	.string "I can't believe I finally got to meet\n"
	.string "LILYPAD! She's so precious, otters\l"
	.string "are kind of like little aquatic\l"
	.string "bears really.\p"
	.string "It was rough not having anything to\n"
	.string "spend my channel points on since she\l"
	.string "disappeared. Oh and HAPPY BIRTHDAY!!$"

Birthday_Main_Village_HouseEnd_Thea_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_HouseEnd_Thea_Text, MSGBOX_AUTOCLOSE, MUGSHOT_THEA, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_HouseEnd_Thea_Text:
	.string "Mhm...thith cake is delishssh....\n"
	.string "I hop thers more. Gulp\p"
	.string "Aaaaah, better.\p"
	.string "Oh, its your birthday right?!\n"
	.string "HAPPY BIRTHDAY!!!\p"
	.string "I hope you had fun on your adventure!\n"
	.string "I tried my very best to keep everyone\l"
	.string "in check :3.\p"
	.string "Ok enough talking, more cake!\n"
	.string "NOMNOMNOM$"

Birthday_Main_Village_HouseEnd_Forty_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_HouseEnd_Forty_Text, MSGBOX_AUTOCLOSE, MUGSHOT_FORTY, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_HouseEnd_Forty_Text:
	.string "FORTY: Happy birthday, REYA!\p"
	.string "I hope you had a good time with this\n"
	.string "adventure. I had a blast helping\l"
	.string "create it and getting to collaborate\l"
	.string "with all these creative people!\p"
	.string "And I think the fact that so many\n"
	.string "creative and motivated people are in\l"
	.string "your community really speaks for you\l"
	.string "as a person and as a content creator.\p"
	.string "Whatever path you will take next\n"
	.string "year, I am sure you will follow your\l"
	.string "heart and continue to surprise\l"
	.string "us all!$"
	
Birthday_Main_Village_HouseEnd_Bo_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_HouseEnd_Bo_Text, MSGBOX_AUTOCLOSE, MUGSHOT_BO, CLEAR_MUGSHOT
	msgbox_mugshot Birthday_Main_Village_HouseEnd_Bo2_Text, MSGBOX_AUTOCLOSE, MUGSHOT_BO, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_HouseEnd_Bo_Text:
	.string "Congratulations on making it through;\n"
	.string "it took you long enough.\p"
	.string "But besides the congratulations,\n"
	.string "thank you for being my friend.\p"
	.string "Well, one of my best friends.\p"
	.string "Which I'm sure will annoy you in\n"
	.string "some way that you're not the ONE best\l"
	.string "friend, but take what you can get.\p"
	.string "I hope you know how much you inspire\n"
	.string "me to continue my own journey.\p"
	.string "The time and effort you put into\n"
	.string "whatever project you've chosen to work\l"
	.string "on never cease to surprise me.\p"
	.string "You are a beautiful, skilled, and\n"
	.string "wonderful friend, and I'm happy to be\l"
	.string "the 'butler' for such a perfect Empress.$"

Birthday_Main_Village_HouseEnd_Bo2_Text:
	.string "Thank you for always being there for\n"
	.string "me. I think you're the best thing this\l"
	.string "fucked up year has given me,\l"
	.string "and without your constant laughter and\l"
	.string "support, I'd honestly be lost.\p"
	.string "I love you.$"

Birthday_Main_Village_HouseEnd_Ellie_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_HouseEnd_Ellie_Text, MSGBOX_AUTOCLOSE, MUGSHOT_ELLIE, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_HouseEnd_Ellie_Text:
	.string "ELLIE: Happy birthday REYA!!\n"
	.string "I'm so glad I know you!$"


