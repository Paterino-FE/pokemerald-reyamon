Birthday_Mountain_Future_Peak_MapScripts::
	.byte 0


Birthday_Mountain_Future_Peak_Sign1_EventScript::
	lock
	msgbox Birthday_Mountain_Future_Peak_Sign1_Text, MSGBOX_SIGN
	release
	end

Birthday_Mountain_Future_Peak_Sign1_Text:
	.string "You went all the way here, expecting\n"
	.string "that this would get you somewhere.\p"
	.string "Some good place.\n"
	.string "Some nice reward.\p"
	.string "Well, sometimes, our expectations are\n"
	.string "betrayed by the cruel reality that our\l"
	.string "path lead us into a dead end.$"
