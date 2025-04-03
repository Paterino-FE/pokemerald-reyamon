.set LOCALID_MATT, 1
.set LOCALID_SUBMARINE, 4

AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_MATT
	setvar VAR_0x8009, LOCALID_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "HASTINGS: Hello there!\p"
	.string "You’re new, a new face!\n"
	.string "Ain’t no better way ta get to know\l"
	.string "each other than with a lil battle!$"

AquaHideout_B2F_Text_MattDefeat:
	.string "Yippiee! That was soo fun!\n"
	.string "Well done!$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "While I was talking with you, HATZOOME\n"
	.string "got through with her preparations!$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "You know, when HATZOOME approached me\n"
	.string "about this time-share business, I was\l"
	.string "kinda uncertain.\p"
	.string "But now that I’ve shared so many fun\n"
	.string "moments with so many different people,\l"
	.string "I’m glad I agreed! Wait…\p"
	.string "time-share doesn’t mean sharing\n"
	.string "time with others? Oh…$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "Nobody wants to battle me anymore!\n"
	.string "Do you want to battle?$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "Well, now I don’t want to battle\n"
	.string "you anymore… $"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "Losing sucks…$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "This guy won’t leave. He just keeps\n"
	.string "saying he’s here to collect\l"
	.string "HATZOOME’s debt but she’s too\l"
	.string "business savvy to have debt!$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "Miss HATZOOME would have won\n"
	.string "this battle…$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "I think HATZOOME is really smart!$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "I don’t know how to use these warp\n"
	.string "panels. I just need to find HATZOOME\l"
	.string "on behalf of the debt collection\l"
	.string "agency.$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "Can you just mention that I’m\n"
	.string "looking for her…$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "Do you remember which warp panel\n"
	.string "gets me out of here…?$"
