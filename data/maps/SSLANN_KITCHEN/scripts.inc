SSLANN_KITCHEN_MapScripts::
	.byte 0

SSLANN_KITCHEN_Chef_EventScript::
	lock
	faceplayer
	msgbox SSLANN_KITCHEN_Chef_Text, MSGBOX_DEFAULT
	release
	end

SSLANN_Kitchen_Dishwasher_EventScript::
	lock
	faceplayer
	msgbox SSLANN_Kitchen_Dishwasher_Text, MSGBOX_DEFAULT
	release
	end

SSLANN_Kitchen_Cook_EventScript::
	lock
	faceplayer
	msgbox SSLANN_Kitchen_Cook_Text, MSGBOX_DEFAULT
	release
	end


SSLANN_KITCHEN_Chef_Text:
	.string "I am the head CHEF of this boat!\p"
	.string "Every day, people approach me and\n"
	.string "they ask me the same thing:\p"
	.string "'CHEF, is {PLAYER} cooked?'\p"
	.string "And then I tell them:\n"
	.string "'She is in no way cooked! She is\l"
	.string "doing absolutely fantastically!'$"

SSLANN_Kitchen_Dishwasher_Text:
	.string "I'm just washing the dishes here.\n"
	.string "Did you know that if you wash the\l"
	.string "dishes, you will become a\l"
	.string "billionaire later?$"

SSLANN_Kitchen_Cook_Text:
	.string "Yes, it's true, this doesn't pay\n"
	.string "very well. It's also a very toxic\l"
	.string "environment, the heat is killing\l"
	.string "me and I don't eat anything all day.\p"
	.string "But on the flipside, I get to travel\n"
	.string "to all kinds of places on this boat.\p"
	.string "And then I don't get to see these\n"
	.string "places because I am in here, cooking.\p"
	.string "So at least that's something!$"

