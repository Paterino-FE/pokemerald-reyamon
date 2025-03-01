.set LOCALID_GROUDON, 1
.set LOCALID_GRUNT_1, 2
.set LOCALID_GRUNT_2, 3
.set LOCALID_GRUNT_3, 4
.set LOCALID_TABITHA, 5
.set LOCALID_MAXIE, 6
.set LOCALID_GROUDON_SLEEPING, 7

MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_GROUDON_SLEEPING
	addobject LOCALID_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "I want to see Groudon, too, but they\n"
	.string "won’t let me see even its tail…\p"
	.string "It’s got me feeling really frustrated.\p"
	.string "Oh, no!\n"
	.string "I blabbed about GROUDON!$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "I guess it's impossible to win if one\n"
	.string "doesn't have a calm mind…$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "I wonder if GROUDON even has a tail?$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "What’s up chat. It’s your boy here!\n"
	.string "Here to break the fourth wall and\l"
	.string "kick your Oshi’s butt!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Chat am I cooked?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "If you have amazon prime you get a\n"
	.string "free prime gaming sub once a month\l"
	.string "to use on twitch dot television\l"
	.string "forward slash LongLiveReya.\p"
	.string "Use it now!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "Soon we will have enough land to\n"
	.string "fairly split amongst dragons instead\l"
	.string "of fighting for territory all\l"
	.string "the time.$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "I’m so weak I’m a disgrace\n"
	.string "to dragonkind!$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "Will more land really stop the\n"
	.string "fighting or will people like Lyra\l"
	.string "and Vyral continue to wage war?$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "My mummy wake up sleepy mr godon and\n"
	.string "then she win because she’s the\l"
	.string "strongest!\p"
	.string "She say you die now, pretty lady!$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Mummy is scary sometimes, but she’ll\n"
	.string "get me shinies soon…\p"
	.string "Right, pretty lady?$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "I glad you no die pretty lady, you\n"
	.string "nice, can I eat your hair?$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "Lyra: GROUDON…\p"
	.string "Nothing could awaken you from your\n"
	.string "sleep. What a magnificently red\l"
	.string "pokemon, perfect for controlling\l"
	.string "with this obviously blue and not\l"
	.string "red orb.$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "Lyra: Haha.. Hahahaha..HAHAHAHAHA.\p"
	.string "That loser Hatzoome is going to\n"
	.string "get a wonderful surprise.$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "Ah Little Empress. Why must you oppose\n"
	.string "our great and noble goal of expanding\l"
	.string "the land so we can distribute it more\l"
	.string "equally amongst dragon kind.\p"
	.string "Think of the glorious bounty of\n"
	.string "shinies deep within its rocks.\p"
	.string "Hahahaha. HAHAHAHAHAH\n"
	.string "Enough of this degrading charade.\p"
	.string "As you can plainly see, Groudon has\n"
	.string "been driven mad out of control.\p"
	.string "Oh no you must say. How horrible,\n"
	.string "won’t it cause a drought that will\l"
	.string "kill billions. Yes indeed it will.\p"
	.string "Unless a great hero swoops in to\n"
	.string "defeat it and earn the adoration of\l"
	.string "the masses!\p"
	.string "I’m tired of being compared to that\n"
	.string "(redacted) Vyral. Her beautiful tail.\p"
	.string "Magnificent scales. Wonderful claws\n"
	.string "and finely chiselled abdominal\l"
	.string "muscles.\p"
	.string "All of those are superficial and\n"
	.string "worthless. She’s not smarter than me.\p"
	.string "She’s not more powerful than me. And\n"
	.string "by defeating Groudon I’ll prove it.\p"
	.string "I’m better than her. I’m better than\n"
	.string "all of dragon gang.\p"
	.string "I’M BETTER THAN YOU. I’M BETTER THAN\n"
	.string "EVERYONE. I AM PERFECTION AND YOU WILL\l"
	.string "FALL BEFORE ME! EN GARDE!$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "Am I… not strong enough?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "If I can’t defeat you then Groudon…\p"
	.string "No. Don’t be ridiculous. THIS WASN’T\n"
	.string "EVEN MY FINAL FORM. I’M STRONGER\l"
	.string "THAN VYRAL. I’M THE BEST DRAGON.\p"
	.string "I AM. I AM. I’M NOT INFERIOR. YOU’LL\n"
	.string "SEE. YOU’LL ALL SEE!$"

