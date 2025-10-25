.set LOCALID_GRAPE, 1

Birthday_Cave_Past_R2_MapScripts::
	.byte 0


Birthday_Cave_Past_R2_Sign1_EventScript::
	msgbox Birthday_Cave_Past_R2_Sign1_Text, MSGBOX_SIGN
	end

Birthday_Cave_Past_R2_Sign1_Text:
	.string "This text is an ancient tale about a\n"
	.string "young EMPRESS that has to fight an\l"
	.string "evil DRAGON KING!\p"
	.string "After a convoluted middle section,\n"
	.string "it ends with kissing.$"

Birthday_Cave_Past_R2_Sign2_EventScript::
	msgbox Birthday_Cave_Past_R2_Sign2_Text, MSGBOX_SIGN
	end

Birthday_Cave_Past_R2_Sign2_Text:
	.string "'Here may be found the last words of\n"
	.string "JOSEPH OF ARIMANTHEA.\p"
	.string "She who is valiant and pure of spirit\n"
	.string "may find the Holy Grail in the Castle\l"
	.string "of aaarrrrggh'\p"
	.string "Must have died while carving it...$"

Birthday_Cave_Past_R2_Sign3_EventScript::
	msgbox Birthday_Cave_Past_R2_Sign3_Text, MSGBOX_SIGN
	end

Birthday_Cave_Past_R2_Sign3_Text:
	.string "I can't read that!$"

Birthday_Cave_Past_R2_Grape_AttackScript::
	applymovement LOCALID_GRAPE, Birthday_Cave_Past_R2_Grape_Movement_1
	waitmovement 0
	setvar VAR_GRAPE_EVENT, 1
	goto Birthday_Cave_Past_R2_Grape_EventScript
	release
	end

Birthday_Cave_Past_R2_Grape_EventScript::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_GRAPE, Birthday_Cave_Past_R2_GrapeBattle_EventScript
	msgbox Birthday_Cave_Past_R2_Grape_Text, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	release
	end

Birthday_Cave_Past_R2_GrapeBattle_EventScript::
	trainerbattle_single TRAINER_GRAPE, Birthday_Cave_Past_R2_GrapeIntro_Text, Birthday_Cave_Past_R2_GrapeDefeat_Text
	release
	end

Birthday_Cave_Past_R2_GrapeDefeat_Text:
	.string "Jeez, are you 10k MMR or something?!\n"
	.string "That battle was intense!!$"

Birthday_Cave_Past_R2_Grape_Text:
	.string "Girl, you look like you could use a\n"
	.string "little rest!\p"
	.string "You're the hardest worker I know,\n"
	.string "but don't forget to take breaks\l"
	.string "sometimes, ok?$"

Birthday_Cave_Past_R2_GrapeIntro_Text:
	.string "Hey {PLAYER}!! Just because you're my\n"
	.string "friend doesn't mean I'll be going\l"
	.string "easy on you - prepare yourself, GAO!$"

Birthday_Cave_Past_R2_Grape_Movement_1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Birthday_Cave_Past_R2_Grape_Movement_2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

Birthday_Cave_Past_R2_Oldman1_EventScript::
	lock
	faceplayer
	msgbox Birthday_Cave_Past_R2_Oldman1_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R2_Oldman1_Text:
	.string "I really like this new emote that you\n$"
	.string "added to your channel!\l"
	.string "Toucans are hilarious!\n"
	.string "le Toucan has arrived hahaha!$"

Birthday_Cave_Past_R2_Oldman2_EventScript::
	lock
	faceplayer
	msgbox Birthday_Cave_Past_R2_Oldman2_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R2_Oldman2_Text:
	.string "DENDI is my favorite midlaner.\n"
	.string "Does he still play?\p"
	.string "I used to watch you play with\l"
	.string "SINGSING.$"

Birthday_Cave_Past_R2_Oldwoman1_EventScript::
	lock
	faceplayer
	msgbox Birthday_Cave_Past_R2_Oldwoman1_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R2_Oldwoman1_Text:
	.string "Damn, that new DOTA Digest is\n$"
	.string "really funny!$"



