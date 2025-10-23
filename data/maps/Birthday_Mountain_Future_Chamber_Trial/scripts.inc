.set LOCALID_VYRAL, 1

Birthday_Mountain_Future_Chamber_Trial_MapScripts::
	.byte 0

Birthday_Mountain_Future_Chamber_Trial_Vyral_EventScript::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_KING_VYRAL, Birthday_Mountain_Future_Chamber_Trial_VyralBattle_EventScript
	release
	end

Birthday_Mountain_Future_Chamber_Trial_VyralBattle_EventScript::
	fadeoutbgm 0
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox_mugshot Birthday_Mountain_Future_Chamber_Trial_VyralPreBattle_Text, MSGBOX_DEFAULT, MUGSHOT_VYRAL, CLEAR_MUGSHOT
	playse SE_M_CUT
	waitse
	msgbox_mugshot Birthday_Mountain_Future_Chamber_Trial_VyralIntro_Text, MSGBOX_DEFAULT, MUGSHOT_VYRAL, CLEAR_MUGSHOT
	trainerbattle_no_intro TRAINER_KING_VYRAL, Birthday_Mountain_Future_Chamber_Trial_VyralDefeat_Text
	setvar VAR_BIRTHDAY_HIDE_FUTURE, 4
	setvar VAR_BIRTHDAY_HIDE_PRESENT, 1
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_VYRAL
	removeobject LOCALID_VYRAL
	delay 16
	fadescreen FADE_FROM_BLACK
	release
	end

Birthday_Mountain_Future_Chamber_Trial_VyralPreBattle_Text:
	.string "How did you get out of the dungeons?\n"
	.string "...No ...Wait\p"
	.string "...This is different...\n"
	.string "The fire in your eyes. I remember it.\p"
	.string "Just like before I took the throne.\n"
	.string "Yes... YES!\p"
	.string "I almost missed this.\n"
	.string "You must be from somewhere else....\p"
	.string "Or somewhen? MY little Empress would\n"
	.string "know who owns her... She wouldn't\l"
	.string "dare stand up to me like this.\p"
	.string "She hasnt had this fire in years.\n"
	.string "That rebellious spirit....No matter!$"

Birthday_Mountain_Future_Chamber_Trial_VyralDefeat_Text:
	.string "NO!\n"
	.string "THIS IS NOT FAIR....\p"
	.string "I WON, I ALREADY WON. NOOOOOOOOO!!!$"

Birthday_Mountain_Future_Chamber_Trial_VyralIntro_Text:
	.string "I will defeat you again and teach you\n"
	.string "MY rules, just like I did before.\p"
	.string "It will be so much easier a second\n"
	.string "time, but just as fun.\p"
	.string "Now be a good girl, don't resist\n"
	.string "and I will be gentle.\p"
	.string "Unless you dont want me to...$"
