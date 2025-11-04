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
	setflag FLAG_BEAT_IMPOSTERPAD
	clearflag FLAG_HIDE_HATZOOME_ENDING
	removeobject LOCALID_IMPOSTERPAL
	fadescreen FADE_FROM_BLACK
	delay 60
	goto Birthday_Village_Present_Trial_Essence_EventScript
	release
	end

Birthday_Village_Present_Trial_Essence_EventScript::
	msgbox_mugshot Birthday_Village_Present_Trial_EssenceCombine1_Text, MSGBOX_DEFAULT, MUGSHOT_REYADETAIL, CLEAR_MUGSHOT
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox_mugshot Birthday_Village_Present_Trial_EssenceCombine2_Text, MSGBOX_DEFAULT, MUGSHOT_REYADETAIL, CLEAR_MUGSHOT
	msgbox Birthday_Village_Present_Trial_EssenceCombine3_Text, MSGBOX_DEFAULT
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	msgbox_mugshot Birthday_Village_Present_Trial_EssenceCombine4_Text, MSGBOX_DEFAULT, MUGSHOT_ESSENCE, CLEAR_MUGSHOT
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	setweather WEATHER_SUNNY
	doweather
	playse SE_M_DETECT
	dofieldeffectsparkle 38, 12, 0
	waitfieldeffect FLDEFF_SPARKLE
	closemessage
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	delay 150
	clearflag FLAG_HIDE_LILYPAD_TRIAL
	waitstate
	delay 150
	addobject LOCALID_LILYPAD
	special FadeOutOrbEffect
	waitstate
	delay 60
	applymovement LOCALID_LILYPAD, Birthday_Village_Present_Trial_Lilypad_Movement1
	playmoncry SPECIES_PIKACHU, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox_mugshot Birthday_Village_Present_Trial_EssenceCombine5_Text, MSGBOX_DEFAULT, MUGSHOT_REYADETAIL, CLEAR_MUGSHOT
	waitmovement 0
	release
	end

Birthday_Village_Present_Trial_Sign1_EventScript::
	msgbox Birthday_Village_Present_Trial_Sign1_Text, MSGBOX_SIGN
	release
	end

Birthday_Village_Present_Trial_Sign1_Text:
	.string "'We cannot change the past, but we\n"
	.string "can still ruin the present!'\p"
	.string "That is very deep...$"

Birthday_Village_Present_Trial_ImposterLilypadPreBattle_Text:
	.string "You know, after falling for my disguise,\n" 
	.string "I might have underestimated you, after\p" 
	.string "all, it was so obvious! The real\n" 
	.string "LILYPAD doesnt even TALK. And still\p" 
	.string "I fooled you!\p" 
	.string "Honestly I had no idea\n" 
	.string "what KING VYRAL sees in you but now...\p"
	.string "now I think I know. You are a thorn in my\n" 
	.string "side at every turn.\p"
	.string "But this will end NOW!\p" 
	.string "I will show our great LEADER why I\n"
	.string "deserve to be her right hand!\p" 
	.string "I will defeat you and\n" 
	.string "then...then I will take over your\p" 
	.string "identity and deliver your Kingdom to\n"
	.string "VYRAL on a silver platter.\p"
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
	.string "Where is LILYPAD? I thought I would\n"
	.string "free her, if I complete all trials...$"

Birthday_Village_Present_Trial_EssenceCombine2_Text:
	.string "Mh... What is happening?$"

Birthday_Village_Present_Trial_EssenceCombine3_Text:
	.string "You feel how the mysterious\n"
	.string "energy inside you is manifesting...$"

Birthday_Village_Present_Trial_EssenceCombine4_Text:
	.string "The essences are coming forth!$"

Birthday_Village_Present_Trial_EssenceCombine5_Text:
	.string "Lilypad!!!$"

Birthday_Village_Present_Trial_ImposterLilypad_Movement1:
	emote_exclamation_mark
	step_end

Birthday_Village_Present_Trial_Lilypad_Movement1:
	walk_down
	walk_down
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
