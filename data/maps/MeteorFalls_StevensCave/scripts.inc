.set LOCALID_STEVEN, 1

MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "LILYPAD: Well, {PLAYER}.\n"
	.string "You made it all the way here.\p"
	.string "You know what that means. It’s the\n"
	.string "final battle of the game!\p"
	.string "There is nothing left to say.\p"
	.string "Nothing except for:\p"
	.string "Did you know that otters have pockets?\n"
	.string "There are folds of skin below our arms\l"
	.string "where we can store our favorite rocks.$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "And again, I stood no chance against\n"
	.string "you. If it wasn’t you I lost to,\l"
	.string "I would be very frustrated by now.$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "LILYPAD: Come to think of it, the game\n"
	.string "has really run out of content now.\p"
	.string "It is probably best if you turn it off\n"
	.string "and touch some grass now.\p"
	.string "I hope you enjoyed the journey!$"

