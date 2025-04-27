LiamCave_R1_MapScripts::
	.byte 0

    @ Game Corner prices
	.set TM_DOUBLE_TEAM_COINS, 1500
	.set TM_PSYCHIC_COINS, 3500
	.set TM_FLAMETHROWER_COINS, 4000
	.set TM_THUNDERBOLT_COINS, 4000
	.set TM_DAZZLING_GLEAM_COINS, 4000
	.set DOLL_COINS, 1000

LiamCave_GameCorner_EventScript_NeedCoinCase::
	msgbox LiamCave_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
	release
	end

LiamCave_GameCorner_EventScript_PrizeCornerTMs::
	lock
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, LiamCave_GameCorner_EventScript_NoCoinCase
	msgbox LiamCave_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, LiamCave_GameCorner_EventScript_ChooseTMPrizeMessage
	release
	end

LiamCave_GameCorner_EventScript_ChooseTMPrizeMessage::
	message LiamCave_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto LiamCave_GameCorner_EventScript_ChooseTMPrize

LiamCave_GameCorner_EventScript_ChooseTMPrize::
	multichoice 12, 0, MULTI_LIAM_GAME_CORNER_TMS, FALSE
	switch VAR_RESULT
	case 0, LiamCave_GameCorner_EventScript_TMDoubleTeam
	case 1, LiamCave_GameCorner_EventScript_TMPsychic
	case 2, LiamCave_GameCorner_EventScript_TMFlamethrower
	case 3, LiamCave_GameCorner_EventScript_TMThunderbolt
	case 4, LiamCave_GameCorner_EventScript_TMDazzlingGleam
	case 5, LiamCave_GameCorner_EventScript_CancelTMSelect
	goto LiamCave_GameCorner_EventScript_CancelTMSelect
	end

LiamCave_GameCorner_EventScript_ConfirmTMPrize::
	special BufferTMHMMoveName
	msgbox LiamCave_GameCorner_Text_SoYourChoiceIsTheTMX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LiamCave_GameCorner_EventScript_CancelTMSelect
	switch VAR_TEMP_1
	case 1, LiamCave_GameCorner_EventScript_BuyTMDoubleTeam
	case 2, LiamCave_GameCorner_EventScript_BuyTMPsychic
	case 3, LiamCave_GameCorner_EventScript_BuyTMFlamethrower
	case 4, LiamCave_GameCorner_EventScript_BuyTMThunderbolt
	case 5, LiamCave_GameCorner_EventScript_BuyTMDazzlingGleam
	end

LiamCave_GameCorner_Text_SoYourChoiceIsTheTMX:
	.string "So your choice is\n"
	.string "the {STR_VAR_1} {STR_VAR_2}?$"

LiamCave_GameCorner_EventScript_BuyTMDoubleTeam::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_DOUBLE_TEAM_COINS, LiamCave_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_DOUBLE_TEAM
	goto_if_eq VAR_RESULT, FALSE, LiamCave_GameCorner_EventScript_NoRoomForTM
	removecoins TM_DOUBLE_TEAM_COINS
	additem ITEM_TM_DOUBLE_TEAM
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox LiamCave_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto LiamCave_GameCorner_EventScript_ReturnToChooseTMPrize
	end

LiamCave_GameCorner_EventScript_BuyTMPsychic::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_PSYCHIC_COINS, LiamCave_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_PSYCHIC
	goto_if_eq VAR_RESULT, FALSE, LiamCave_GameCorner_EventScript_NoRoomForTM
	removecoins TM_PSYCHIC_COINS
	additem ITEM_TM_PSYCHIC
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox LiamCave_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto LiamCave_GameCorner_EventScript_ReturnToChooseTMPrize
	end

LiamCave_GameCorner_EventScript_BuyTMFlamethrower::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_FLAMETHROWER_COINS, LiamCave_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_FLAMETHROWER
	goto_if_eq VAR_RESULT, FALSE, LiamCave_GameCorner_EventScript_NoRoomForTM
	removecoins TM_FLAMETHROWER_COINS
	additem ITEM_TM_FLAMETHROWER
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox LiamCave_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto LiamCave_GameCorner_EventScript_ReturnToChooseTMPrize
	end

LiamCave_GameCorner_EventScript_BuyTMThunderbolt::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_THUNDERBOLT_COINS, LiamCave_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, LiamCave_GameCorner_EventScript_NoRoomForTM
	removecoins TM_THUNDERBOLT_COINS
	additem ITEM_TM_THUNDERBOLT
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox LiamCave_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto LiamCave_GameCorner_EventScript_ReturnToChooseTMPrize
	end

LiamCave_GameCorner_EventScript_BuyTMDazzlingGleam::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_DAZZLING_GLEAM_COINS, LiamCave_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_DAZZLING_GLEAM
	goto_if_eq VAR_RESULT, FALSE, LiamCave_GameCorner_EventScript_NoRoomForTM
	removecoins TM_DAZZLING_GLEAM_COINS
	additem ITEM_TM_DAZZLING_GLEAM
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox LiamCave_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto LiamCave_GameCorner_EventScript_ReturnToChooseTMPrize
	end

LiamCave_GameCorner_Text_HereYouGo:
	.string "Here you go!$"

LiamCave_GameCorner_EventScript_NotEnoughCoinsForTM::
	msgbox LiamCave_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto LiamCave_GameCorner_EventScript_ReturnToChooseTMPrize
	end

LiamCave_GameCorner_EventScript_NoRoomForTM::
	call Common_EventScript_BagIsFull
	goto LiamCave_GameCorner_EventScript_ReturnToChooseTMPrize
	end

LiamCave_GameCorner_EventScript_CancelTMSelect::
	msgbox LiamCave_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

LiamCave_GameCorner_EventScript_ReturnToChooseTMPrize::
	message LiamCave_GameCorner_Text_WhichPrize
	waitmessage
	goto LiamCave_GameCorner_EventScript_ChooseTMPrize

LiamCave_GameCorner_Text_WhichPrize:
	.string "Which prize would you like?$"

LiamCave_GameCorner_Text_NotEnoughCoins:
	.string "You don't have enough COINS.$"

LiamCave_GameCorner_EventScript_TMDoubleTeam::
	setvar VAR_TEMP_1, 1
	bufferitemname STR_VAR_1, ITEM_TM_DOUBLE_TEAM
	setvar VAR_0x8004, ITEM_TM_DOUBLE_TEAM
	goto LiamCave_GameCorner_EventScript_ConfirmTMPrize

LiamCave_GameCorner_EventScript_TMPsychic::
	setvar VAR_TEMP_1, 2
	bufferitemname STR_VAR_1, ITEM_TM_PSYCHIC
	setvar VAR_0x8004, ITEM_TM_PSYCHIC
	goto LiamCave_GameCorner_EventScript_ConfirmTMPrize

LiamCave_GameCorner_EventScript_TMFlamethrower::
	setvar VAR_TEMP_1, 3
	bufferitemname STR_VAR_1, ITEM_TM_FLAMETHROWER
	setvar VAR_0x8004, ITEM_TM_FLAMETHROWER
	goto LiamCave_GameCorner_EventScript_ConfirmTMPrize

LiamCave_GameCorner_EventScript_TMThunderbolt::
	setvar VAR_TEMP_1, 4
	bufferitemname STR_VAR_1, ITEM_TM_THUNDERBOLT
	setvar VAR_0x8004, ITEM_TM_THUNDERBOLT
	goto LiamCave_GameCorner_EventScript_ConfirmTMPrize

LiamCave_GameCorner_EventScript_TMDazzlingGleam::
	setvar VAR_TEMP_1, 5
	bufferitemname STR_VAR_1, ITEM_TM_DAZZLING_GLEAM
	setvar VAR_0x8004, ITEM_TM_DAZZLING_GLEAM
	goto LiamCave_GameCorner_EventScript_ConfirmTMPrize

LiamCave_GameCorner_EventScript_SlotMachine0::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, LiamCave_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

LiamCave_GameCorner_EventScript_SlotMachine1::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, LiamCave_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

LiamCave_GameCorner_EventScript_SlotMachine2::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, LiamCave_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

LiamCave_GameCorner_EventScript_SlotMachine3::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, LiamCave_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

LiamCave_GameCorner_EventScript_NoCoinCase::
	msgbox LiamCave_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
	releaseall
	end

LiamCave_GameCorner_Text_CantPlayWithNoCoinCase:
	.string "LIAM: You can't play, {PLAYER}, \n"
	.string "if you don't have a COIN CASE...\p"
	.string "You can get one in MAUVILLE CITY.\p"
	.string "There was a girl in one of the\n"
	.string "houses who stopped to gamba.$"

LiamCave_GameCorner_Text_ExchangeCoinsForPrizes:
	.string "LIAM: Hey {PLAYER}!\p"
	.string "This is my little comfy home.\n"
	.string "Play for some cool prizes.\p"
	.string "Talk to my plush to buy\n"
	.string "some coins!$"

LiamCave_GameCorner_Text_NeedCoinCaseForCoins:
	.string "Okay, you wanted some COINS for\n"
	.string "the games?\p"
	.string "But you don't have a COIN CASE for\n"
	.string "stowing the COINS.$"

LiamCave_GameCorner_Text_OhIsThatSo:
	.string "Oh, is that so? \n"
	.string "You need to save some COINS before\l"
	.string "coming back here.$"

LiamCave_GameCorner_Text_DontHaveEnoughMoney:
	.string "Um… You don't appear to have\n"
	.string "enough money…$"

LiamCave_GameCorner_Text_WereYouLookingForCoins:
	.string "Were you looking for COINS?\p"
	.string "It's ¥1000 for 50 COINS.\n"
	.string "Would you like some?$"

LiamCave_GameCorner_Text_ThisIsMauvilleGameCorner:
	.string "This is LIAM's little gamba\n"
	.string "cave!$"

LiamCave_GameCorner_Text_DontNeedCoinsThen:
	.string "Oh… You don't need COINS, then?\n"
	.string "Good luck on your adventure!$"

LiamCave_GameCorner_EventScript_NotEnoughMoney::
	msgbox LiamCave_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

LiamCave_GameCorner_EventScript_CoinsClerk::
	lock
	faceplayer
	msgbox LiamCave_GameCorner_Text_ThisIsMauvilleGameCorner, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, LiamCave_GameCorner_EventScript_NeedCoinCase
	message LiamCave_GameCorner_Text_WereYouLookingForCoins
	waitmessage
	showmoneybox 0, 0
	showcoinsbox 1, 6
	goto LiamCave_GameCorner_EventScript_ChooseCoinsDefault50

LiamCave_GameCorner_EventScript_ChooseCoinsDefault50::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
	switch VAR_RESULT
	case 0, LiamCave_GameCorner_EventScript_Buy50Coins
	case 1, LiamCave_GameCorner_EventScript_Buy500Coins
	goto LiamCave_GameCorner_EventScript_CancelBuyCoins
	end

@ Unused
LiamCave_GameCorner_EventScript_ChooseCoinsDefault500::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, FALSE
	switch VAR_RESULT
	case 0, LiamCave_GameCorner_EventScript_Buy50Coins
	case 1, LiamCave_GameCorner_EventScript_Buy500Coins
	goto LiamCave_GameCorner_EventScript_CancelBuyCoins
	end

LiamCave_GameCorner_EventScript_CancelBuyCoins::
	msgbox LiamCave_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

LiamCave_GameCorner_EventScript_Buy50Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), LiamCave_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_50
	goto_if_eq VAR_RESULT, FALSE, LiamCave_GameCorner_EventScript_NotEnoughMoney
	addcoins 50
	removemoney COINS_PRICE_50
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox LiamCave_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

LiamCave_GameCorner_EventScript_Buy500Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), LiamCave_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_500
	goto_if_eq VAR_RESULT, FALSE, LiamCave_GameCorner_EventScript_NotEnoughMoney
	addcoins 500
	removemoney COINS_PRICE_500
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox LiamCave_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

LiamCave_GameCorner_Text_ThankYouHereAreYourCoins:
	.string "Thank you very much!\n"
	.string "Here are your COINS!$"

LiamCave_GameCorner_EventScript_NoRoomForCoins::
	msgbox LiamCave_GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

LiamCave_GameCorner_Text_CoinCaseIsFull:
	.string "Oh?\n"
	.string "Your COIN CASE is full.$"

