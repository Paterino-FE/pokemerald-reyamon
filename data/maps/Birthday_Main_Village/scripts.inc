.set LOCALID_EMI, 4
.set LOCALID_PAT, 3
.set LOCALID_SNORLAX, 2
.set LOCALID_THEA, 5
.set LOCALID_OSHAWOTT_1, 8

Birthday_Main_Village_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Birthday_Main_Village_Hide_Setup
	.byte 0

Birthday_Main_Village_Hide_Setup::
	call_if_eq VAR_BIRTHDAY_HIDE_PAST, 2, Birthday_Main_Village_Hide_Thea_1
	call_if_eq VAR_BIRTHDAY_HIDE_FUTURE, 0, Birthday_Main_Village_Hide_Pat_0
	call_if_eq VAR_BIRTHDAY_HIDE_FUTURE, 1, Birthday_Main_Village_Hide_Pat_1
	call_if_eq VAR_BIRTHDAY_HIDE_FUTURE, 4, Birthday_Main_Village_Hide_Pat_4
	call_if_eq VAR_BIRTHDAY_HIDE_PRESENT, 0, Birthday_Main_Village_Hide_Emilia_0
	call_if_eq VAR_BIRTHDAY_HIDE_PRESENT, 1, Birthday_Main_Village_Hide_Emilia_1
	call_if_eq VAR_BIRTHDAY_HIDE_PRESENT, 4, Birthday_Main_Village_Hide_Emilia_4
	call_if_eq VAR_BIRTHDAY_ENDING, 1, Birthday_Main_Village_Hide_Snorlax_1
	call_if_unset FLAG_HIDE_OSHAWOTT_1, Birthday_Main_Village_Hide_Oshawott_1
	release
	end

Birthday_Main_Village_Hide_Oshawott_1::
	setflag FLAG_HIDE_VILLAGE_OSHAWOTT
	removeobject LOCALID_OSHAWOTT_1
	return

Birthday_Main_Village_EventScript_Trigger_End::
	release
	end

Birthday_Main_Village_Hide_Thea_1::
	setflag	FLAG_HIDE_THEA_HAMLET
	removeobject LOCALID_THEA, 5
	return

Birthday_Main_Village_Hide_Pat_0::
	setflag FLAG_HIDE_PAT_HAMLET
	removeobject LOCALID_PAT, 3
	return

Birthday_Main_Village_Hide_Pat_1::
	clearflag FLAG_HIDE_PAT_HAMLET
	addobject LOCALID_PAT, 3
	return

Birthday_Main_Village_Hide_Pat_4::
	setflag FLAG_HIDE_PAT_HAMLET
	removeobject LOCALID_PAT, 3
	return

Birthday_Main_Village_Hide_Emilia_0::
	setflag	FLAG_HIDE_EMILIA_HAMLET
	removeobject LOCALID_EMI, 4
	return

Birthday_Main_Village_Hide_Emilia_1::
	clearflag FLAG_HIDE_EMILIA_HAMLET
	addobject LOCALID_EMI, 4
	return

Birthday_Main_Village_Hide_Emilia_4::
	setflag	FLAG_HIDE_EMILIA_HAMLET
	removeobject LOCALID_EMI, 4
	return

Birthday_Main_Village_Hide_Snorlax_1::
	removeobject LOCALID_SNORLAX, 2
	setflag	FLAG_HIDE_SNORLAX
	return

Birthday_Main_Village_Snorlax_EventScript::
	lock
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox Birthday_Main_Village_Snorlax_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Main_Village_After_Past_Pat::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_After_Past_Pat_Text, MSGBOX_DEFAULT, MUGSHOT_PATERINO, CLEAR_MUGSHOT
	setvar VAR_BIRTHDAY_HIDE_FUTURE, 2
	setflag FLAG_HIDE_FUTURE
	release
	end

Birthday_Main_Village_Sign1_EventScript::
	msgbox Birthday_Main_Village_Sign1_Text, MSGBOX_SIGN
	end


Birthday_Main_Village_HatzoomeFirst_Text:
	.string "Oh hey, {PLAYER}. These\n"
	.string "LILYPALS are the absolute sweetest!\p"
	.string "Did you know that people will try and\n"
	.string "scam you into getting insurance for\l"
	.string "products that needn't be insured?!?\p"
	.string "Well neither did I, but the LILYPALS\n"
	.string "pointed out that most of my contract\l"
	.string "is a scam!\p"
	.string "Lucky for me though, apparently the\n"
	.string "only thing it does insure me for is a\l"
	.string "mass consumption of my inventory!\p"
	.string "The LILYPALS just got me my deposit\n"
	.string "back and a 100 percent profit!\p"
	.string "They even offered to manage my\n"
	.string "finances as I'm 'lacking self-\l"
	.string "preservation skills', whatever that's\l"
	.string "supposed to mean.$"

Birthday_Main_Village_Hatzoome_Text:
	.string "I wonder if the LILYPALS would let me\n"
	.string "buy an EEVEELUTIONS Cafe with the\l"
	.string "money...?$"

Birthday_Main_Village_HatzoomePal_Text:
	.string "We have no clue how this woman has\n"
	.string "survived until this point.\p"
	.string "She says she's a 'doctor' but we can't\n"
	.string "fathom any academic institution\l"
	.string "signing off on that.$"

Birthday_Main_Village_HatzoomeFirst_EventScript::
	setflag FLAG_TALKED_HATZOOME_ENDING
	msgbox_mugshot Birthday_Main_Village_HatzoomeFirst_Text, MSGBOX_AUTOCLOSE, MUGSHOT_HATZOOME, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_Hatzoome_EventScript::
	lock
	faceplayer
	goto_if_unset FLAG_TALKED_HATZOOME_ENDING, Birthday_Main_Village_HatzoomeFirst_EventScript
	msgbox_mugshot Birthday_Main_Village_Hatzoome_Text, MSGBOX_AUTOCLOSE, MUGSHOT_HATZOOME, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_HatzoomePal_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_HatzoomePal_Text, MSGBOX_AUTOCLOSE, MUGSHOT_LILYPAL, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_Sign1_Text:
	.string "ROSUURI's bakery -\n"
	.string "come right in!$"

Birthday_Main_Village_Snorlax_Text:
	.string "None shall pass!$"

Birthday_Main_Village_After_Past_Pat_Text:
	.string "Path to the future is free.$"

Birthday_Main_Village_After_Future_Emilia::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_After_Future_Emilia_Text, MSGBOX_DEFAULT, MUGSHOT_EMILIA, CLEAR_MUGSHOT
	setvar VAR_BIRTHDAY_HIDE_PRESENT, 2
	setflag FLAG_HIDE_PRESENT
	release
	end

Birthday_Main_Village_After_Future_Emilia_Text:
	.string "EMILIA: EMPRESS!\p"
	.string "Excellent work on retrieving the\n"
	.string "second part of LILYPAD's essence.\p"
	.string "I'm afraid this isn't the end of our\n"
	.string "troubles, though.\p"
	.string "A messenger arrived just before you\n"
	.string "came back, notifying us that the\l"
	.string "village of WUFFING to the NORTH is\l"
	.string "being attacked by DIRKLINGS and a\l"
	.string "talking OTTER!\p"
	.string "You should hurry there, LILYPAD's\n"
	.string "final essence should be with the\l"
	.string "IMPOSTER.$"

Birthday_Main_Village_After_Past_Thea_1::
	lock
	applymovement LOCALID_THEA, Birthday_Main_Village_After_Past_Movement
	waitmovement 0
	faceplayer
	msgbox_mugshot Birthday_Main_Village_After_Past_Thea_Text, MSGBOX_DEFAULT, MUGSHOT_THEA, CLEAR_MUGSHOT
	setvar VAR_BIRTHDAY_HIDE_PAST, 1
	applymovement LOCALID_THEA, Birthday_Main_Village_TheaLeaves_Movement
	waitmovement 0
	removeobject LOCALID_THEA
	setflag FLAG_HIDE_THEA_HAMLET
	release
	end

Birthday_Main_Village_After_Past_Thea_2::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_After_Past_Thea_Text, MSGBOX_DEFAULT, MUGSHOT_THEA, CLEAR_MUGSHOT
	setvar VAR_BIRTHDAY_HIDE_PAST, 1
	applymovement LOCALID_THEA, Birthday_Main_Village_TheaLeaves_Movement
	waitmovement 0
	removeobject LOCALID_THEA
	setflag FLAG_HIDE_THEA_HAMLET
	release
	end

Birthday_Main_Village_After_Past_Thea_Text:
	.string "THEA: Oh hey there!\p"
	.string "Funny how we keep running into each\n"
	.string "other. Me?\p"
	.string "I'm on vacation you see, being a GYM\n"
	.string "LEADER is hard hard work!\p"
	.string "Sometimes I dont even have time to get\n"
	.string "a nap in, so I closed down the GYM\l"
	.string "and here I am.\p"
	.string "Oh, yeah, before I forget, there was\n"
	.string "this very cute MAID lady called EMILIA\l"
	.string "that mentioned something about\l"
	.string "an OTTER?\p"
	.string "She told me to tell you that someone\n"
	.string "named LILY....or PAD had their essence\l"
	.string "split up into 3 parts.\p"
	.string "Isn't that crazy?\p"
	.string "I've seen a lot over the years,\n"
	.string "but that seems a little extreme,\l"
	.string "dont you think?\p"
	.string "Anyway, apparently there is a CAVE to\n"
	.string "the NORTH EAST where you can commune\l"
	.string "with spirits of the past!\p"
	.string "The MAID lady said that you should\l"
	.string "look there first. Actually...\p"
	.string "That sounds like a good adventure, I\n"
	.string "might just head there myself.\p"
	.string "Oh, before I go, would you happen to\n"
	.string "have that EMILIA girl's phone number?\p"
	.string "No? What do you mean noone except you\n"
	.string "is allowed to have YURI?\p"
	.string "I dont even know who this YURI guy is.\p"
	.string "Fine!\n"
	.string "I'm off to scout the CAVE!$"

Birthday_Main_Village_After_Past_Movement:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	step_end

Birthday_Main_Village_TheaLeaves_Movement:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Birthday_Main_Village_BeautifulOshawott_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Main_Village_BeautifulOshawott_Text, MSGBOX_AUTOCLOSE, MUGSHOT_MABLEWOTT, CLEAR_MUGSHOT
	release
	end

Birthday_Main_Village_BeautifulOshawott_Text:
	.string "I wish I had hair like that!$"


