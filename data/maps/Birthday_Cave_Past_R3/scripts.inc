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
	msgbox Birthday_Cave_Past_R3_TheaPreBattle_Text, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_THEA_2, Birthday_Cave_Past_R3_TheaIntro_Text, Birthday_Cave_Past_R3_TheaDefeat_Text
	release
	end

Birthday_Cave_Past_R3_TheaPreBattle_Text:

Birthday_Cave_Past_R3_TheaDefeat_Text:

Birthday_Cave_Past_R3_Thea_Text:

Birthday_Cave_Past_R3_TheaIntro_Text:

Birthday_Cave_Past_R3_Alex_EventScript::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_ALEX_2, Birthday_Cave_Past_R3_AlexBattle_EventScript
	msgbox Birthday_Cave_Past_R3_Alex_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R3_AlexBattle_EventScript::
	msgbox Birthday_Cave_Past_R3_AlexPreBattle_Text, MSGBOX_DEFAULT
	@trainerbattle_single TRAINER_ALEX_2, Birthday_Cave_Past_R3_AlexIntro_Text, Birthday_Cave_Past_R3_AlexDefeat_Text
	setvar VAR_BIRTHDAY_HIDE_FUTURE, 1
	setvar VAR_BIRTHDAY_HIDE_PAST, 2
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ALEX
	removeobject LOCALID_ALEX
	delay 16
	fadescreen FADE_FROM_BLACK
	release
	end

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
