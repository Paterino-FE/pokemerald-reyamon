Birthday_Beach_Start_MapScripts::
	.byte 0


Birthday_Beach_Dirkling1_EventScript::
	lock
	faceplayer
	msgbox Birthday_Beach_Dirkling1_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Beach_Dirkling2_EventScript::
	lock
	faceplayer
	msgbox Birthday_Beach_Dirkling2_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Beach_Dirkling3_EventScript::
	lock
	faceplayer
	msgbox Birthday_Beach_Dirkling3_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Beach_Lilypal1_EventScript::
	lock
	faceplayer
	msgbox Birthday_Beach_Lilypal1_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Beach_Lilypal2_EventScript::
	lock
	faceplayer
	msgbox Birthday_Beach_Lilypal2_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Beach_Lilypal3_EventScript::
	lock
	faceplayer
	msgbox Birthday_Beach_Lilypal3_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Beach_Dylan_EventScript::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_DDYLAN, Birthday_Beach_DylanKittyBattle_EventScript
	msgbox Birthday_Beach_DylanPostBattle_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Beach_Kitty_EventScript::
	lock 
	faceplayer
	goto_if_not_defeated TRAINER_DDYLAN, Birthday_Beach_DylanKittyBattle_EventScript
	msgbox Birthday_Beach_KittyPostBattle_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Beach_DylanKittyBattle_EventScript::
	msgbox Birthday_Beach_DylanKittyPreBattle_Text, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_DDYLAN, Birthday_Beach_DylanDefeat_Text, TRAINER_KITTY, Birthday_Beach_KittyDefeat_Text
	release
	end

Birthday_Beach_Astarion_EventScript::
	lock
	faceplayer
	msgbox Birthday_Beach_Astarion_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Beach_NanamiBear_EventScript::
	lock
	faceplayer
	playmoncry SPECIES_BEARTIC, CRY_MODE_ENCOUNTER
	waitmoncry
	release
	end

Birthday_Beach_Luminel_EventScript::
	trainerbattle_single TRAINER_LUMI_BEACH, Birthday_Beach_Luminel_IntroText, Birthday_Beach_Luminel_DefeatText
	msgbox Birthday_Beach_Luminel_PostBattleText, MSGBOX_AUTOCLOSE
	end

Birthday_Beach_Luminel_IntroText:
	.string "Oh so fluffy!$"

Birthday_Beach_Luminel_DefeatText:
	.string "Oh so defeated!$"

Birthday_Beach_Luminel_PostBattleText:
	.string "Oh so post battle!$"

Birthday_Beach_DylanKittyPreBattle_Text:
	.string "DYLAN: Hey, can you NOT interrupt out\n"
	.string "perfect date?!\p"
	.string "KITTY: DYLAN has really worked hard\n"
	.string "on this date.$"

Birthday_Beach_DylanDefeat_Text:
	.string "DYLAN: Well dang, another date ruined,\n"
	.string "happy birthday at least.$"

Birthday_Beach_KittyDefeat_Text:
	.string "KITTY: Happy birthday! But sad\n"
	.string "that DYLAN is sad about the date.$"
	
Birthday_Beach_KittyPostBattle_Text:
	.string "It's fine, a birthday battle made the\n"
	.string "date more interesting!$"

Birthday_Beach_DylanPostBattle_Text:
	.string "Yeah yeah, happy birthday,\n"
	.string "like I said.$"

Birthday_Beach_Dirkling1_Text:
	.string "I have spent 50000 LILIES on\n"
	.string "fishing already, surely I will\l"
	.string "get something good SOON!$"

Birthday_Beach_Dirkling2_Text:
	.string "I came here to get tons of tasty\n"
	.string "ROCKS but all that bites is stinky\l"
	.string "FISH!$"

Birthday_Beach_Dirkling3_Text:
	.string "Don't interrupt, need to concentrate!$"

Birthday_Beach_Lilypal1_Text:
	.string "I feel like as an Otter I shouldn't\n"
	.string "have to use tools to catch fish.$"

Birthday_Beach_Lilypal2_Text:
	.string "I actually forgot my FISHING\n"
	.string "ROD, so I'm just pretending...$"

Birthday_Beach_Lilypal3_Text:
	.string "I wanted to fish on the other side,\n"
	.string "but those DIRKLINGS chased me away...$"

Birthday_Beach_Astarion_Text:
	.string "You're wondering what you are\n"
	.string "looking at?\p"
	.string "Why, just a sunbathing vampire,\n"
	.string "here to wish you a happy\l"
	.string "birthday, darling! Much love!\p"
	.string "Now would you kindly step out of the\n"
	.string "sun, I'm trying to get a tan here.$"


