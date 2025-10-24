Rosuuri_Bakery_MapScripts::
	.byte 0

Birthday_Rosuuri_Bakery_Rosuuri_EventScript::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_ROSUURI, Birthday_Rosuuri_Bakery_RosuuriBattle_EventScript
	msgbox_mugshot Birthday_Rosuuri_Bakery_Rosuuri_Text, MSGBOX_DEFAULT, MUGSHOT_ROSUURI, CLEAR_MUGSHOT
	release
	end

Birthday_Rosuuri_Bakery_RosuuriBattle_EventScript::
	trainerbattle_single TRAINER_ROSUURI, Birthday_Rosuuri_Bakery_RosuuriIntro_Text, Birthday_Rosuuri_Bakery_RosuuriDefeat_Text
	release
	end

Birthday_Rosuuri_Bakery_RosuuriDefeat_Text:
	.string "I'm so proud of you...!$"

Birthday_Rosuuri_Bakery_Rosuuri_Text:
	.string "Do you want some bread?$"

Birthday_Rosuuri_Bakery_RosuuriIntro_Text:
	.string "Let's see how much you've learned\n"
	.string "while you were away from home!$"

Birthday_Rosuuri_Bakery_Agdaleks_EventScript::
	lock
	faceplayer
	goto_if_unset FLAG_TALKED_TO_AGDALEKS, Birthday_Rosuuri_Bakery_AgdaleksGive_EventScript
	msgbox Birthday_Rosuuri_Bakery_AgdaleksRepeat_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Rosuuri_Bakery_AgdaleksGive_EventScript::
	msgbox Birthday_Rosuuri_Bakery_Agdaleks_Text, MSGBOX_DEFAULT
	givedecoration DECOR_VYRAL_DOLL
	goto_if_eq VAR_RESULT, FALSE, Birthday_Rosuuri_Bakery_AgdaleksComeBackLater_EventScript
	msgbox Birthday_Rosuuri_Bakery_Agdaleks2_Text, MSGBOX_DEFAULT
	setflag FLAG_TALKED_TO_AGDALEKS
	release
	end

Birthday_Rosuuri_Bakery_AgdaleksComeBackLater_EventScript::
	msgbox Birthday_Rosuuri_Bakery_AgdaleksComeBackLater_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Rosuuri_Bakery_AgdaleksComeBackLater_Text:
	.string "Make some space for DECORATIONS and\n"
	.string "come back!$"

Birthday_Rosuuri_Bakery_Agdaleks_Text:
	.string "Oh hi {PLAYER}! Haven't seen you in a\n"
	.string "few months. Bet you have been busy\l"
	.string "being CHAMPION and working on cool\l"
	.string "team ideas.\p"
	.string "I heard it was your birthday!\n"
	.string "I actually have something for you.\p"
	.string "Maybe it will come in handy in your\n"
	.string "secret base.$"

Birthday_Rosuuri_Bakery_Agdaleks2_Text:
	.string "Hope you can use this to make your\n"
	.string "base have a unique flair to it.\p"
	.string "A plushie makes any room better!\p"
	.string "Have a wonderful birthday, {PLAYER}!$"

Birthday_Rosuuri_Bakery_AgdaleksRepeat_Text:
	.string "Happy birthday! Are you using that\n"
	.string "plushie I gave you?$"

Birthday_Rosuuri_Bakery_Lilypal1_EventScript::
	lock
	faceplayer
	msgbox Birthday_Rosuuri_Bakery_Lilypal1_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Rosuuri_Bakery_Lilypal1_Text:
	.string "Sure, go ahead!\n"
	.string "I still haven't decided on\l"
	.string "what I want...$"

Birthday_Rosuuri_Bakery_Lilypal2_EventScript::
	lock
	faceplayer
	msgbox Birthday_Rosuuri_Bakery_Lilypal2_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Rosuuri_Bakery_Lilypal2_Text:
	.string "A spoonful of sugar, that is all\n"
	.string "it takes!\p"
	.string "It changes bread and water into\n"
	.string "tea and cakes!\p"
	.string "I do really like bread and water,\n"
	.string "though!$"

Birthday_Rosuuri_Bakery_Lilypal3_EventScript::
	lock
	faceplayer
	msgbox Birthday_Rosuuri_Bakery_Lilypal3_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Rosuuri_Bakery_Lilypal3_Text:
	.string "Stressed is Desserts spelled backward!$"

Birthday_Rosuuri_Bakery_Dirkling1_EventScript::
	lock
	faceplayer
	msgbox Birthday_Rosuuri_Bakery_Dirkling1_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Rosuuri_Bakery_Dirkling1_Text:
	.string "We LOVE the goods that ROSUURI bakes!\p"
	.string "If only they were a bit harder,\n"
	.string "and maybe a bit rounder, and \l"
	.string "perhaps a bit more grey...$"

Birthday_Rosuuri_Bakery_Dirkling2_EventScript::
	lock
	faceplayer
	msgbox Birthday_Rosuuri_Bakery_Dirkling2_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Rosuuri_Bakery_Dirkling2_Text:
	.string "I ordered pain,\n"
	.string "but all I got was french bread.\p"
	.string "Good bread, though.$"

