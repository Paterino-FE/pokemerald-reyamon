Birthday_Route_3_MapScripts::
	.byte 0




Birthday_Route_3_Nigeltastic_EventScript::
	trainerbattle_single TRAINER_NIGELTASTIC, Birthday_Route_3_NigeltasticIntro_Text, Birthday_Route_3_NigeltasticDefeat_Text
	msgbox Birthday_Route_3_Nigeltastic_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Route_3_NigeltasticDefeat_Text:
	.string "Well, maybe I'm VYRAL's second\n"
	.string "strongest DIRKLING...$"

Birthday_Route_3_Nigeltastic_Text:
	.string "Happy Birthday {PLAYER}!\n"
	.string "Hope you have a nice day :)$"

Birthday_Route_3_NigeltasticIntro_Text:
	.string "Prepare to face the wrath of VYRAL's\n"
	.string "strongest DIRKLING!$"




Birthday_Route_3_Lyra_EventScript::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_LYRA, Birthday_Route_3_LyraSvelteBattle_EventScript
	msgbox Birthday_Route_3_LyraPostBattle_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Route_3_Svelte_EventScript::
	lock 
	faceplayer
	msgbox Birthday_Route_3_SveltePostBattle_Text, MSGBOX_DEFAULT
	goto_if_unset FLAG_GIVEN_AIR_BALLOON, Birthday_Route_3_SvelteGiveBalloon_EventScript
	release
	end

Birthday_Route_3_SvelteGiveBalloon_EventScript::
	giveitem ITEM_AIR_BALLOON
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GIVEN_AIR_BALLOON
	release
	end

Birthday_Route_3_LyraSvelteBattle_EventScript::
	msgbox Birthday_Route_3_LyraPreBattle1_Text, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Birthday_Route_3_LyraSvelteBattle1N_EventScript
	call_if_eq VAR_RESULT, YES, Birthday_Route_3_LyraSvelteBattle1Y_EventScript

	goto_if_eq VAR_RESULT, NO, Birthday_Route_3_LyraSvelteBattle2N_EventScript
	call_if_eq VAR_RESULT, YES, Birthday_Route_3_LyraSvelteBattle2Y_EventScript

	goto_if_eq VAR_RESULT, NO, Birthday_Route_3_LyraSvelteBattle3N_EventScript
	call_if_eq VAR_RESULT, YES, Birthday_Route_3_LyraSvelteBattle3Y_EventScript
	trainerbattle_two_trainers TRAINER_LYRA, Birthday_Route_3_LyraDefeat_Text, TRAINER_SVELTE, Birthday_Route_3_SvelteDefeat_Text
	release
	end

Birthday_Route_3_LyraSvelteBattle1Y_EventScript::
	msgbox Birthday_Route_3_LyraPreBattle1Y_Text, MSGBOX_YESNO
	return 

Birthday_Route_3_LyraSvelteBattle1N_EventScript::
	msgbox Birthday_Route_3_LyraPreBattle1N_Text, MSGBOX_DEFAULT
	release
	end 

Birthday_Route_3_LyraSvelteBattle2Y_EventScript::
	msgbox Birthday_Route_3_LyraPreBattle2Y_Text, MSGBOX_YESNO
	return 

Birthday_Route_3_LyraSvelteBattle2N_EventScript::
	msgbox Birthday_Route_3_LyraPreBattle2N_Text, MSGBOX_DEFAULT
	release
	end 

Birthday_Route_3_LyraSvelteBattle3Y_EventScript::
	msgbox Birthday_Route_3_LyraPreBattle3Y_Text, MSGBOX_DEFAULT
	return 

Birthday_Route_3_LyraSvelteBattle3N_EventScript::
	msgbox Birthday_Route_3_LyraPreBattle3N_Text, MSGBOX_DEFAULT
	release
	end 

Birthday_Route_3_Sign1_EventScript::
	msgbox Birthday_Route_3_Sign1_Text, MSGBOX_AUTOCLOSE
	end

Birthday_Route_3_Sign2_EventScript::
	msgbox Birthday_Route_3_Sign2_Text, MSGBOX_AUTOCLOSE
	end

Birthday_Route_3_Sign3_EventScript::
	msgbox Birthday_Route_3_Sign3_Text, MSGBOX_AUTOCLOSE
	end

Birthday_Route_3_Sign1_Text:
	.string "GROUDON was here.$"

Birthday_Route_3_Sign2_Text:
	.string "Nobody knows what the FUTURE holds\n"
	.string "but with PALLIANCE insurance, you\l"
	.string "are prepared for everything!$"

Birthday_Route_3_Sign3_Text:
	.string "'A dead end leading to giant rock\n"
	.string "is its own reward.' -DIRKFUCIUS$"

Birthday_Route_3_LyraPostBattle_Text:
	.string "Oh well, this is embarrassing.\n"
	.string "Happy birthday again I guess!\p"
	.string "One day I’ll have my vengeance\n"
	.string "though… you’ll see…\l"
	.string "you’ll all see…(real).\p"
	.string "Never break character!$"

Birthday_Route_3_SveltePostBattle_Text:
	.string "Hi pretty lady! Happy bornday!\p"
	.string "The polis let me spend 2 days a month\n"
	.string "with my mummy, so we took grumpy mr\l"
	.string "godon on holday together.\p"
	.string "He likes his balloon.\p"
	.string "If my mummy said somethink mean to you\n"
	.string "she doesn’t meanie mean it.\p"
	.string "I go into her room sometimes and she\n"
	.string "watches your strim with smile on her\l"
	.string "face talking to nice dirklings and\l"
	.string "even stinkypals but don’t tell her I\l"
	.string "said so or I will get no dinner.\p"
	.string "Take a balloon for your bornday so\n"
	.string "you can have fun like mr godon!$"

Birthday_Route_3_LyraPreBattle1_Text:
	.string "REYA!? What the hell are you doing\n"
	.string "here. Here I am on a nice holiday\l"
	.string "with my real daughter (real) and\l"
	.string "here you are to rub my defeat in\l"
	.string "my face!\p"
	.string "I thought after you foiled my evil\n"
	.string "plot I would get in big trouble with\l"
	.string "VYRAL but apparently when she was \l"
	.string "told about it, she said ‘Who?’ so I\l"
	.string "got off scot-free!\p"
	.string "It’s your birthday?\n"
	.string "Well in that case I’ll lie to you and\l"
	.string "tell you that you made me see the\l"
	.string "light and I am not hatching any\l"
	.string "fiendish schemes, devilish plans or\l"
	.string "morally dubious hijinks.\p"
	.string "I’m on the straight and narrow from\n"
	.string "now on because of you, REYA!\p"
	.string "Happy birthday!\p"
	.string "Hey I know that look! You don’t\n"
	.string "believe me, do you?!\p"
	.string "You think I’m paranoid and plotting\n"
	.string "something evil! Everybody does, I can\l"
	.string "tell I’m an empath! HOW DARE YOU?\p"
	.string "Care to back up that stance with\n"
	.string "a battle?$"

Birthday_Route_3_LyraPreBattle1Y_Text:
	.string "Really? I’m not sure that’s a good\n"
	.string "idea, you are barely worth my time.\p"
	.string "You’d better be sure you’re willing\n"
	.string "to fight for your beliefs.$"

Birthday_Route_3_LyraPreBattle1N_Text:
	.string "Yeah, that’s what I thought, coward!\n"
	.string "Spits on ground.$"

Birthday_Route_3_LyraPreBattle2Y_Text:
	.string "Look REYA, I know you want to prove\n"
	.string "I’m up to no good real bad but I\l"
	.string "promise you this isn’t a good idea.\p"
	.string "Are you really sure you want to go\n"
	.string "through with this? I promise you I\l"
	.string "will cheat.$"

Birthday_Route_3_LyraPreBattle2N_Text:
	.string "Awww little EMPRESS is a chicken,\n"
	.string "I can’t wait to tell VYRAL about\l"
	.string "this if she ever acknowledges\l"
	.string "my existence.$"

Birthday_Route_3_LyraPreBattle3Y_Text:
	.string "Now you’ve really gone and done it!?\n"
	.string "You provoked me! I have witnesses!\p"
	.string "This is self defense now.\n"
	.string "I am not responsible for what happens.\p"
	.string "Goodbye, little EMPRESS.$"

Birthday_Route_3_LyraPreBattle3N_Text:
	.string "Okay, but you weren’t actually meant\n"
	.string "to say no, I’m goading you into a\l"
	.string "fight for a bit, please don’t leave\l"
	.string "me hanging, I have nothing else.$"

Birthday_Route_3_LyraDefeat_Text:
	.string "I don’t actually have an evil plan\n"
	.string "though… Not yet anyway…$"

Birthday_Route_3_SvelteDefeat_Text:
	.string "Pretty Lady!!!$"

Birthday_Route_3_Groudon_EventScript::
	lock
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox Birthday_Route_3_Groudon_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Route_3_Groudon_Text:
	.string "You see that for some reason GROUDON\n"
	.string "has a balloon tied around its wrist.\p"
	.string "There is writing on it:\n"
	.string "WOOF WOOF!$"


