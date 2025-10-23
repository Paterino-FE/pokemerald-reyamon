.set LOCALID_VYRAL, 1

Birthday_Mountain_Future_Chamber_Trial_MapScripts::
	.byte 0

Birthday_Mountain_Future_Chamber_Trial_Vyral_EventScript::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_KING_VYRAL, Birthday_Mountain_Future_Chamber_Trial_VyralBattle_EventScript
	msgbox Birthday_Mountain_Future_Chamber_Trial_Vyral_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Mountain_Future_Chamber_Trial_VyralBattle_EventScript::
	msgbox Birthday_Mountain_Future_Chamber_Trial_VyralPreBattle_Text, MSGBOX_DEFAULT
	@trainerbattle_single TRAINER_KING_VYRAL, Birthday_Mountain_Future_Chamber_Trial_VyralIntro_Text, Birthday_Mountain_Future_Chamber_Trial_VyralDefeat_Text
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
	.string "PreBattle.$"

Birthday_Mountain_Future_Chamber_Trial_VyralDefeat_Text:
	.string "Defeat.$"

Birthday_Mountain_Future_Chamber_Trial_Vyral_Text:
	.string "Standard Text.$"

Birthday_Mountain_Future_Chamber_Trial_VyralIntro_Text:
	.string "Intro.$"
