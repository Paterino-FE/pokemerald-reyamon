VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Nurse::
	lockall
	faceplayer
	msgbox VictoryRoad_B2F_Text_Nurse, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	releaseall
	end

VictoryRoad_B2F_Text_Nurse:
	.string "Your POKéMON deserve rest.\n"
	.string "Let me heal them.$"

VictoryRoad_B2F_Text_VitoIntro:
	.string "VYRAL told me to invest in antiques,\n"
	.string "now you stand no chance!$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "How can this be? These were top of\n"
	.string "the line products!$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "{PLAYER}, you're the very best like\n"
	.string "no one ever was!\p"
	.string "Please give LILYPAD a real good\n"
	.string "snuggle from me <3.$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "What did my pokemon evolve\n"
	.string "from again?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "It's magcargover console fans...$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "I may have ma-choked,\n"
	.string "but you can be ma-champ!$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "Prepare for trouble!\p"
	.string "To protect the world from\n"
	.string "devastation!\p"
	.string "To unite all peoples within\n"
	.string "our nation!\p"
	.string "To denounce the evils of\n"
	.string "truth and love!\p"
	.string "To extend our reach to the\n"
	.string "stars above!\p"
	.string "Team Rocket blasts off at\n"
	.string "the speed of light!\p"
	.string "Surrender now, or prepare to fight!$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "Team Rocket Blasts Off Again!$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "TEAM ROCKET is currently seeking\n"
	.string "GRUNTs to help carry out our\l"
	.string "dream to steal POKEMON.\p"
	.string "Apply at our HEADQUARTERS please.$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "Sorry Reya, but I'm team VYRAL\n"
	.string "until the end!$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "Okay okay, I guess you're\n"
	.string "pretty great, too.$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "Okay okay, I guess you're\n"
	.string "pretty great, too.$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "This time, I'll show YOU the\n"
	.string "power of Solar Beam!$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "My Solar Beam... \n"
	.string "wasn't strong enough?\p"
	.string "How could this be?$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "I can't teach your Pokémon Solar Beam\n"
	.string "here, sorry. You need to go all the\l"
	.string "way back for that.$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "FABULOUS. I see you made it here.$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "FABULOUS. FABULOUS. FABULOUSLY DONE.$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "Your fabulousness will shine\n"
	.string "throughout the world.$"

