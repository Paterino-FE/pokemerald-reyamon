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
	.string "None of my Pokemon know Strength!\p"
	.string "How did i move those rocks.....\n"
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
	msgbox Birthday_Cave_Past_R3_Alex_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R3_AlexBattle_EventScript::
	msgbox_mugshot Birthday_Cave_Past_R3_AlexPreBattle_Text, MSGBOX_DEFAULT, MUGSHOT_ALEX, CLEAR_MUGSHOT
	msgbox_mugshot Birthday_Cave_Past_R3_AlexIntro_Text, MSGBOX_DEFAULT, MUGSHOT_ALEX, CLEAR_MUGSHOT
	trainerbattle_no_intro TRAINER_ALEX_2, Birthday_Cave_Past_R3_AlexDefeat_Text
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
	return

Birthday_Cave_Past_R3_AlexPreBattle_Text:
	.string "PreBattle.$"

Birthday_Cave_Past_R3_AlexDefeat_Text:
	.string "Defeat.$"

Birthday_Cave_Past_R3_Alex_Text:
	.string "Standard Text.$"

Birthday_Cave_Past_R3_AlexIntro_Text:
	.string "Intro.$"


Birthday_Cave_Past_R3_Sign1_EventScript::
	lock
	faceplayer
	msgbox Birthday_Cave_Past_R3_Sign1_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R3_Sign1_Text:
	.string "Placeholder.$"
