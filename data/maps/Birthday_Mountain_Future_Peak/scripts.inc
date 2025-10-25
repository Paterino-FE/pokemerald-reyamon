Birthday_Mountain_Future_Peak_MapScripts::
	.byte 0

Birthday_Mountain_Future_Peak_Sign1_EventScript::
	lock
	msgbox Birthday_Mountain_Future_Peak_Sign1_Text, MSGBOX_SIGN
	release
	end

Birthday_Mountain_Future_Peak_Purge_EventScript::
	trainerbattle_single TRAINER_PURGE, Birthday_Mountain_Future_Peak_PurgeIntro_Text, Birthday_Mountain_Future_Peak_PurgeDefeat_Text
	msgbox_mugshot Birthday_Mountain_Future_Peak_PurgePostBattle_Text, MSGBOX_DEFAULT, MUGSHOT_PURGE, CLEAR_MUGSHOT
	release
	end

Birthday_Mountain_Future_Peak_Sign1_Text:
	.string "You went all the way here, expecting\n"
	.string "that this would get you somewhere.\p"
	.string "Some good place.\n"
	.string "Some nice reward.\p"
	.string "Well, sometimes, our expectations are\n"
	.string "betrayed by the cruel reality that our\l"
	.string "path led us into a dead end.$"

Birthday_Mountain_Future_Peak_PurgeIntro_Text:
	.string "Hah! You won't find any McDonalds fry\n"
	.string "looking POKéMON in my squad. You'll\l"
	.string "see after I defeat you that they don't\l"
	.string "make them like they used to!\p"
	.string "And that's because the devs pumped\n"
	.string "their hearts and souls into the first\l"
	.string "two generations of POKéMON.\p"
	.string "They truly mixed a balance of great art\n"
	.string "design AND fun personality, if we just\l"
	.string "ignore the gaping hole left by any\l"
	.string "reasonable POISON attacks, BUG\l"
	.string "attacks, and GHOST attacks, I think\l"
	.string "you'll find that you agree with me\l"
	.string "that it was the absolute best\l"
	.string "designed POKéMON because of the...\p"
	.string "(Trails off after another three minutes\n"
	.string "of dialogue)$"

Birthday_Mountain_Future_Peak_PurgeDefeat_Text:
	.string "What.....\n"
	.string "My iconic Pokemon were defeated????\p"
	.string "Could only be power creep compensating\n"
	.string "for poorly designed characters...$"

Birthday_Mountain_Future_Peak_PurgePostBattle_Text:
	.string "What.....\n"
	.string "My iconic Pokemon were defeated????\p"
	.string "Could only be power creep compensating\n"
	.string "for poorly designed characters...$"

