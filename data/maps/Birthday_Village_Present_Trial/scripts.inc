.set LOCALID_IMPOSTERPAL, 1
.set LOCALID_LILYPAD, 2

Birthday_Village_Present_Trial_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Birthday_Village_Present_Trial_Setup
	.byte 0

Birthday_Village_Present_Trial_Setup::
	call_if_eq VAR_BIRTHDAY_ENDING, 0, Birthday_Village_Present_Trial_Hide_Lilypad_1
	release
	end

Birthday_Village_Present_Trial_Hide_Lilypad_1::
	removeobject LOCALID_LILYPAD, 2
	setflag	FLAG_HIDE_LILYPAD_TRIAL
	return

Birthday_Village_Present_Trial_ImposterLilypad_EventScript::
	lock
	applymovement LOCALID_IMPOSTERPAL, Birthday_Village_Present_Trial_ImposterLilypad_Movement1
	waitmovement 0
	faceplayer
	msgbox_mugshot Birthday_Village_Present_Trial_ImposterLilypadPreBattle_Text, MSGBOX_DEFAULT, MUGSHOT_LILYPAD, CLEAR_MUGSHOT
	msgbox_mugshot Birthday_Village_Present_Trial_ImposterLilypadIntro_Text, MSGBOX_DEFAULT, MUGSHOT_LILYPAD, CLEAR_MUGSHOT
	trainerbattle_no_intro TRAINER_AMOGUSPAD, Birthday_Village_Present_Trial_ImposterLilypadDefeat1_Text
	goto Birthday_Village_Present_Trial_ImposterLilypadEnd_EventScript
	release
	end

Birthday_Village_Present_Trial_ImposterLilypadEnd_EventScript::
	setvar VAR_BIRTHDAY_ENDING, 1
	msgbox_mugshot Birthday_Village_Present_Trial_ImposterLilypadDefeat2_Text, MSGBOX_DEFAULT, MUGSHOT_LILYPAD, CLEAR_MUGSHOT
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_IMPOSTERPAL
	removeobject LOCALID_IMPOSTERPAL
	fadescreen FADE_FROM_BLACK
	delay 60
	setweather WEATHER_SUNNY
	doweather
	goto Birthday_Village_Present_Trial_Essence_EventScript
	release
	end

Birthday_Village_Present_Trial_Essence_EventScript::
	msgbox_mugshot Birthday_Village_Present_Trial_EssenceCombine1_Text, MSGBOX_DEFAULT, MUGSHOT_REYADETAIL, CLEAR_MUGSHOT
	fadescreen FADE_TO_BLACK
	delay 60
	clearflag FLAG_HIDE_LILYPAD_TRIAL
	fadescreen FADE_FROM_BLACK
	delay 60
	addobject LOCALID_LILYPAD
	applymovement LOCALID_LILYPAD, Birthday_Village_Present_Trial_Lilypad_Movement1
	playmoncry SPECIES_PIKACHU, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox_mugshot Birthday_Village_Present_Trial_EssenceCombine2_Text, MSGBOX_DEFAULT, MUGSHOT_REYADETAIL, CLEAR_MUGSHOT
	waitmovement 0
	release
	end

Birthday_Village_Present_Trial_ImposterLilypadPreBattle_Text:
	.string "You know, after falling for my disguise,\n" 
	.string "I might have underestimated you, after\p" 
	.string "all, it was so obvious! The real\n" 
	.string "Lilypad doesnt even TALK. And still\p" 
	.string "I fooled you!\p" 
	.string "Honestly I had no idea\n" 
	.string "what King Vyral sees in you but now...\p"
	.string "now I think I know. You are a thorn in my\n" 
	.string "side at every turn.\p"
	.string "But this will end NOW!\p" 
	.string "I will show our great Leader\n"
	.string "why I deserve to be right hand!\p" 
	.string "I will defeat you and\n" 
	.string "then...then I will take over your\p" 
	.string "identity and deliver your Kingdom to\n"
	.string "Vyral on a silver platter.\p"
	.string "She will have to recognize my value!$"

Birthday_Village_Present_Trial_ImposterLilypadDefeat1_Text:
	.string "I... how.. .this is impossible...\n"
	.string "I... I?... Me?...\p"
	.string "Who am I even... Don't...Know...$"

Birthday_Village_Present_Trial_ImposterLilypadDefeat2_Text:
	.string "AAAAAAAAAAAAAAAAAAAH$"

Birthday_Village_Present_Trial_ImposterLilypadIntro_Text:
	.string "PERISH!$"

Birthday_Village_Present_Trial_EssenceCombine1_Text:
	.string "The essences combine!$"

Birthday_Village_Present_Trial_EssenceCombine2_Text:
	.string "Lilypad!!!$"

Birthday_Village_Present_Trial_ImposterLilypad_Movement1:
	emote_exclamation_mark
	step_end

Birthday_Village_Present_Trial_Lilypad_Movement1:
	emote_question_mark
	step_end

Birthday_Village_Present_Trial_Lilypad_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Village_Present_Trial_LilyPadRescued_Text, MSGBOX_DEFAULT, MUGSHOT_LILYPAD, CLEAR_MUGSHOT
	multichoice 0, 0, MULTI_GO_WITH_LILYPAD, TRUE
	switch VAR_RESULT
	case 0, Birthday_Village_Present_Trial_LilypadYES_EventScript
	case 1, Birthday_Village_Present_Trial_LilypadNO_EventScript
	release
	end

Birthday_Village_Present_Trial_LilypadYES_EventScript:
	warp MAP_BIRTHDAY_MAIN_VILLAGE, 5, 12
	release
	end

Birthday_Village_Present_Trial_LilypadNO_EventScript:
	release
	end

Birthday_Village_Present_Trial_LilyPadRescued_Text:
	.string "Lilypad looks at you and seems\n"
	.string "overly happy to see you!\p"
	.string "She takes your hand.\n"
	.string "It seems Lilypad wants to go.\p"
	.string "Do you want to accompany her?$"
