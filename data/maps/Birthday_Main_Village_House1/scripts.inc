.set LOCALID_ATSUI, 1
Birthday_Main_Village_House1_MapScripts::
	.byte 0


Birthday_Main_Village_House1_AtsuiDance_Movement:
	face_left
	delay_8
	face_up
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_up
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_up
	delay_8
	face_right
	delay_8
	face_down
	delay_16
	face_player
	step_end

Birthday_Main_Village_House1_Atsui_EventScript::
	lock
	faceplayer
	goto_if_unset FLAG_TALKED_TO_ATSUI, Birthday_Main_Village_House1_Atsui_Monologue
	goto_if_not_defeated TRAINER_ATSUI, Birthday_Main_Village_House1_AtsuiBattle_EventScript
	goto Birthday_Main_Village_House1_Atsui_Repeat
	release
	end

Birthday_Main_Village_House1_Atsui_Monologue::
	msgbox Birthday_Main_Village_House1_Atsui_Text1, MSGBOX_DEFAULT
	applymovement LOCALID_ATSUI, Birthday_Main_Village_House1_AtsuiDance_Movement
	msgbox Birthday_Main_Village_House1_Atsui_Text2, MSGBOX_AUTOCLOSE
	waitmovement 0
	msgbox Birthday_Main_Village_House1_Atsui_Text3, MSGBOX_DEFAULT
	applymovement LOCALID_ATSUI, Birthday_Main_Village_House1_AtsuiDance_Movement
	msgbox Birthday_Main_Village_House1_Atsui_Text4, MSGBOX_AUTOCLOSE
	waitmovement 0
	msgbox Birthday_Main_Village_House1_Atsui_Text5, MSGBOX_DEFAULT
	applymovement LOCALID_ATSUI, Birthday_Main_Village_House1_AtsuiDance_Movement
	msgbox Birthday_Main_Village_House1_Atsui_Text6, MSGBOX_AUTOCLOSE
	waitmovement 0
	msgbox Birthday_Main_Village_House1_Atsui_Text7, MSGBOX_DEFAULT
	applymovement LOCALID_ATSUI, Birthday_Main_Village_House1_AtsuiDance_Movement
	msgbox Birthday_Main_Village_House1_Atsui_Text8, MSGBOX_AUTOCLOSE
	waitmovement 0
	msgbox Birthday_Main_Village_House1_Atsui_Text9, MSGBOX_DEFAULT
	applymovement LOCALID_ATSUI, Birthday_Main_Village_House1_AtsuiDance_Movement
	msgbox Birthday_Main_Village_House1_Atsui_Text10, MSGBOX_AUTOCLOSE
	waitmovement 0
	setflag FLAG_TALKED_TO_ATSUI
	release
	end

Birthday_Main_Village_House1_Atsui_Repeat::
	msgbox Birthday_Main_Village_House1_Atsui_Text_TalkAgain, MSGBOX_DEFAULT
	applymovement LOCALID_ATSUI, Birthday_Main_Village_House1_AtsuiDance_Movement
	msgbox Birthday_Main_Village_House1_Atsui_Text2, MSGBOX_AUTOCLOSE
	waitmovement 0
	release
	end

Birthday_Main_Village_House1_Atsui_Text1:
	.string "ATSUI: Wuddup Nerd!\n"
	.string "You know who it is. You know what's\l"
	.string "gonna happen.\p"
	.string "Time to trash talk you for 45\n"
	.string "minutes straight.\p"
	.string "Heck yeah!$"

Birthday_Main_Village_House1_Atsui_Text2:
	.string "Dances to Ice Ice Baby by Vanilla Ice.$"

Birthday_Main_Village_House1_Atsui_Text3:
	.string "ATSUI: JK JK. I heard from my discord\n"
	.string "kittens (plural) that it is your\l"
	.string "birthday. SO!!\p"
	.string "I'm just here to wish you the happiest\n"
	.string "of happy birthdays.$"

Birthday_Main_Village_House1_Atsui_Text4:
	.string "Dances to Boten Anna - Radio Edit\n"
	.string "by Basshunter.$"

Birthday_Main_Village_House1_Atsui_Text5:
	.string "Thank you for picking me up from the\n"
	.string "trash pile and putting me on a\l"
	.string "pedestal. You are the bestest boss,\l"
	.string "the bestest british person, and the\l"
	.string "bestest white haired woman person\l"
	.string "(maybe not) that I have ever met.$"

Birthday_Main_Village_House1_Atsui_Text6:
	.string "Dances to Boombastic by Shaggy.$"

Birthday_Main_Village_House1_Atsui_Text7:
	.string "Fly high {PLAYER}, I'll wait for you\n"
	.string "down here to catch you if you ever\l"
	.string "fall down.\p"
	.string "I’m here with you through thick\n"
	.string "and thin.\p"
	.string "I'm already a thick skull so we're\n"
	.string "halfway there.$"

Birthday_Main_Village_House1_Atsui_Text8:
	.string "ATSUI breakdown and did the\n"
	.string "Orange Justice.$"

Birthday_Main_Village_House1_Atsui_Text9:
	.string "Happy birthday to you again and I hope\n"
	.string "you have a great rest of the year!$"

Birthday_Main_Village_House1_Atsui_Text10:
	.string "Dances to EKSE by OffTheMeds.$"

Birthday_Main_Village_House1_Atsui_Text_TalkAgain:
	.string "ATSUI: I'm Vanilla Ice Ice Baby!$"

Birthday_Main_Village_House1_AtsuiBattle_EventScript::
	msgbox Birthday_Main_Village_House1_AtsuiPreBattle_Text, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_ATSUI, Birthday_Main_Village_House1_AtsuiIntro_Text, Birthday_Main_Village_House1_AtsuiDefeat_Text
	release
	end

Birthday_Main_Village_House1_AtsuiPreBattle_Text:
	.string "Crazy$"

Birthday_Main_Village_House1_AtsuiDefeat_Text:
	.string "Crazy$"

Birthday_Main_Village_House1_AtsuiIntro_Text:
	.string "Crazy$"
