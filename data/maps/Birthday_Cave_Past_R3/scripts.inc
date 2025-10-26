.set LOCALID_ALEX, 16

Birthday_Cave_Past_R3_MapScripts::
	.byte 0

Birthday_Cave_Past_R3_BOULDER::
	msgbox_mugshot Birthday_Cave_Past_R3_TEXT_BOULDER, MSGBOX_SIGN, MUGSHOT_REYADETAIL, CLEAR_MUGSHOT
	end

Birthday_Cave_Past_R3_TEXT_BOULDER:
	.string "This boulder is strange.\p"
	.string "It seems to be softer and\n"
	.string "kinda stuck on this space...$"

Birthday_Cave_Past_R3_Thea_EventScript::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_THEA_2, Birthday_Cave_Past_R3_TheaBattle_EventScript
	msgbox Birthday_Cave_Past_R3_Thea_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R3_TheaBattle_EventScript::
	trainerbattle_double TRAINER_THEA_2, Birthday_Cave_Past_R3_TheaIntro_Text, Birthday_Cave_Past_R3_TheaDefeat_Text, Birthday_Cave_Past_R3_TheaNotEnoughMon_Text
	release
	end

Birthday_Cave_Past_R3_TheaNotEnoughMon_Text:
	.string "If you want to battle, return with\n"
	.string "more POKéMON!$"

Birthday_Cave_Past_R3_TheaDefeat_Text:
	.string "Aww shucks, i lost again.\n"
	.string "I still had a lot of fun though.\p"
	.string "I will take a break now, the next\n"
	.string "room looks like some sort of maniac\l"
	.string "designed it.\p"
	.string "I will need my full strength and\n"
	.string "all my wits to best it!$"

Birthday_Cave_Past_R3_Thea_Text:
	.string "Wait a second....\n"
	.string "None of my POKéMON know Strength!\p"
	.string "How did I move those rocks.....\n"
	.string "Ah, best not to think about it too\l"
	.string "hard AYAYA$"

Birthday_Cave_Past_R3_TheaIntro_Text:
	.string "Oh, Hey! You made it!\p"
	.string "I thought getting here was a little\n"
	.string "easy, so I decided to move some ROCKS\l"
	.string "around, you know, make it more of\l"
	.string "a challenge.\p"
	.string "I hope I didn't cause too much\n"
	.string "trouble. Anyway, let's battle,\l"
	.string "I have some new friends I want\l"
	.string "to show off!$"

Birthday_Cave_Past_R3_Alex_EventScript::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_ALEX_2, Birthday_Cave_Past_R3_AlexBattle_EventScript
	msgbox_mugshot Birthday_Cave_Past_R3_Alex_Text, MSGBOX_DEFAULT, MUGSHOT_ALEX, CLEAR_MUGSHOT
	release
	end

Birthday_Cave_Past_R3_AlexBattle_EventScript::
	msgbox_mugshot Birthday_Cave_Past_R3_AlexIntro_Text, MSGBOX_DEFAULT, MUGSHOT_ALEX, CLEAR_MUGSHOT
	trainerbattle_no_intro TRAINER_ALEX_2, Birthday_Cave_Past_R3_AlexDefeat_Text
	msgbox_mugshot Birthday_Cave_Past_R3_Alex_Text, MSGBOX_DEFAULT, MUGSHOT_ALEX, CLEAR_MUGSHOT
	goto Birthday_Cave_Past_R3_AlexEnd_EventScript
	release
	end

Birthday_Cave_Past_R3_AlexEnd_EventScript::
	setvar VAR_BIRTHDAY_HIDE_FUTURE, 1
	setvar VAR_BIRTHDAY_HIDE_PAST, 2
	delay 60
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ALEX
	setflag FLAG_BEAT_ALEX
	removeobject LOCALID_ALEX
	delay 16
	fadescreen FADE_FROM_BLACK
	delay 60
	msgbox_mugshot Birthday_Cave_Past_R3_WowIWasCool_Text, MSGBOX_AUTOCLOSE, MUGSHOT_REYADETAIL, CLEAR_MUGSHOT
	msgbox Birthday_Cave_Past_R3_ReturnQuestion_Text, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Birthday_Cave_Past_R3_ReturnToVillage_EventScript
	return

Birthday_Cave_Past_R3_WowIWasCool_Text:
	.string "Wow, I was really cool even back then!\p"
	.string "I should probably return to the\n"
	.string "village now...$"

Birthday_Cave_Past_R3_ReturnQuestion_Text:
	.string "Return to LILYPAD HAMLET now?$"

Birthday_Cave_Past_R3_ReturnToVillage_EventScript::
	warp MAP_BIRTHDAY_MAIN_VILLAGE, 18, 34
	waitstate
	end

Birthday_Cave_Past_R3_AlexDefeat_Text:
	.string "WOW YOU ARE SO LUCKY. NICE LUCK NOOB.\n"
	.string "KYS KYS KYS!$"

Birthday_Cave_Past_R3_Alex_Text:
	.string "I meant keep yourself safe of course.$"

Birthday_Cave_Past_R3_AlexIntro_Text:
	.string "Who's this loser? Is this low\n"
	.string "priority?\p"
	.string "I guess I have to defeat you to\n"
	.string "become a pro gamer!$"


Birthday_Cave_Past_R3_Sign1_EventScript::
	lock
	faceplayer
	msgbox Birthday_Cave_Past_R3_Sign1_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R3_Sign1_Text:
	.string "Placeholder.$"
