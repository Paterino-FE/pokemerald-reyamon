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
	.string "paterino$"

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
	.string "tsunami$"

Birthday_Main_Village_HouseEnd_Purge_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_HouseEnd_Purge_Text, MSGBOX_AUTOCLOSE, MUGSHOT_PURGE, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_HouseEnd_Purge_Text:
	.string "purge$"

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
	.string "luminel$"

Birthday_Main_Village_HouseEnd_Thea_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_HouseEnd_Thea_Text, MSGBOX_AUTOCLOSE, MUGSHOT_THEA, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_HouseEnd_Thea_Text:
	.string "thea$"

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
	release
	end

Birthday_Main_Village_HouseEnd_Bo_Text:
	.string "bo$"

Birthday_Main_Village_HouseEnd_Ellie_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_HouseEnd_Ellie_Text, MSGBOX_AUTOCLOSE, MUGSHOT_ELLIE, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_HouseEnd_Ellie_Text:
	.string "ELLIE: Happy birthday REYA!!\n"
	.string "I'm so glad I know you!$"


