//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/battle_partners.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'src/data/battle_partners.h' to remove #line markers.
//


    [PARTNER_NONE] =
    {
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender = 
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
    [PARTNER_STEVEN] =
    {
        .trainerName = _("LILYPAD"),
        .trainerClass = TRAINER_CLASS_RIVAL,
        .trainerPic = TRAINER_BACK_PIC_WALLY,
        .encounterMusic_gender = 
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_LUDICOLO,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .ev = TRAINER_PARTY_EVS(0, 252, 252, 0, 6, 0),
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 41,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .ability = ABILITY_RAIN_DISH,
            .moves = {
                MOVE_RAIN_DANCE,
                MOVE_SCALD,
                MOVE_ENERGY_BALL,
                MOVE_ICE_BEAM,
            },
            },
            {
            .species = SPECIES_FLOATZEL,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 6, 252),
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 42,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .ability = ABILITY_SWIFT_SWIM,
            .friendship = 255,
            .moves = {
                MOVE_AQUA_JET,
                MOVE_PURSUIT,
                MOVE_RETURN,
                MOVE_ENCORE,
            },
            },
            {
            .species = SPECIES_SAMUROTT,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 252, 6),
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
            .lvl = 43,
            .nature = NATURE_ADAMANT,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_AQUA_JET,
                MOVE_ENCORE,
                MOVE_REVENGE,
                MOVE_SCALD,
            },
            },
        },
    },