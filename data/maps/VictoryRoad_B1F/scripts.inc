VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Nurse::
	lockall
	faceplayer
	msgbox VictoryRoad_B1F_Text_Nurse, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	releaseall
	end

VictoryRoad_B1F_Text_Nurse:
	.string "Your POKéMON deserve rest.\n"
	.string "Let me heal them.$"


VictoryRoad_B1F_Text_SamuelIntro:
	.string "VYRAL gave me some tips on how\n"
	.string "to improve my team!$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "Aw man, atleast I'm still\n"
	.string "a great Dirkling...$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "VYRAL will beat you up when\n"
	.string "she sees you!$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "Last time I went easy on you.\n"
	.string "Here is my true power!$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "How could I lose again????$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "-.-- --- ..- / --. --- --- \n"
	.string "--. .-.. . -.. / - .... .. \l"
	.string "... / -.. .. -.. -. .----. \l"
	.string "- / -.-- --- ..-$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "Oh hey, it’s {PLAYER} again!\n"
	.string "Guess what! I don’t have to pitch you\l"
	.string "that stupid timeshare anymore!\p"
	.string "I’m finally free! I even sold off\n"
	.string "some of some of Tentacool Cruise’s\l"
	.string "equipment to settle my debt!\p"
	.string "Now I get to focus on Pokémon\n"
	.string "contests again!\p"
	.string "Well, and battling trainers like you!$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "I’m used to losing now.\n"
	.string "This does nothing to me!$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "You should join me on my upcoming\n"
	.string "trip to SINNOH. The travel and hotel\l"
	.string "are free!\p"
	.string "All we have to do is sit through some\n"
	.string "business pitch, but I won’t fall for\l"
	.string "that one again! I hope…$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "Oh, hi again! I look forward to\n"
	.string "a rematch!$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "Go become the CHAMPION! Woweez$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "WOWEEZ$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "Our battle has FOURever been in my\n"
	.string "heart, I've been FOURgetting to\l"
	.string "sleep out of excitement!"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "I guess my defeat was FOURtold...$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "01010101 00100000 01101010 01110101\n"
	.string "01110011 01110100 00100000 01101100\p"
	.string "01101111 01110011 01110100 00100000\n"
	.string "01110101 01110010 00100000 01110100\p"
	.string "01101001 01101101 01100101 00100000\n"
	.string "01100100 01100101 01100011 01101111\p"
	.string "01100100 01101001 01101110 01100111\n"
	.string "00100000 01110100 01101000 01101001\l"
	.string "01110011.$"

