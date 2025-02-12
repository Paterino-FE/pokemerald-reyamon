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

VictoryRoad_B1F_Text_SamuelIntro:
	.string "Vyral game me some tips on how\n"
	.string "to improve my team!$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "Aw man, atleast I'm still\n"
	.string "a great Dirkling...$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "Vyral will beat you up when\n"
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
	.string "This isn't the goal. It's only a place\n"
	.string "on the way to the POKéMON LEAGUE.$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "That's the way!$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "You'll do fine, for sure!\n"
	.string "Your POKéMON are all eager to go!$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "Oh, hi again! I look forward to\n"
	.string "a rematch!$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "Go become the Champion! Woweez$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "WOWEEZ$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "Now I mean it, it was your\n"
	.string "skill issue!$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "RNG gods were on ur side\n"
	.string "this time...$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "NO way I'm including all this\n"
	.string "lmao...$"

