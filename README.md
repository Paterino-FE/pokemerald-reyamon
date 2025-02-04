# pokemerald-reyamon

How to edit Trainers:

Important File Paths, where you can adjust or find necessary values
>src/data/trainers.h | The file where trainers will be adjusted, including their teams
>
>src/data/pokemon/species_info/gen_*_families | Here you can find every Pokemon. They are sorted by Gen
>
>src/data/abilities.h | Here you can find all abilities in the game
>
>src/data/pokemon/trainer_class_lookups.h | Here you can find all trainer classes or the trainer picture in the game
>
>include/constants/moves.h | here are all pokemon attack moves defined

Lets look what the lines of a trainer mean and what possibilities we have:

 >This is a unique name, dont change at all cost

    [TRAINER_PATERINO] = 
    
 >Here you must change the name in "" to the actual trainer name. It can be "Paterino", "Bob" or "Dirkling". Anything
 
    {
        .trainerName = _("PATERINO"), 
        
 >Here the class of the trainer will be defined > Look into trainer_class_lookups.h
 
        .trainerClass = TRAINER_CLASS_RIVAL, 
        
 >Here the picture/sprite of the trainer will be defined > Look into trainer_class_lookups.h
 
        .trainerPic = TRAINER_PIC_WALLY, 
        
 >Here the battle music can be adjusted, its recommened to leave it at base
 
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE, 
        
 >False = No double battle, True = This is a double battle
 
        .doubleBattle = FALSE, 
        
 >Here the number pokemon in the trainers party are defined. They need to be the exact same to the number of pokemon he should have
 
        .partySize = 1, 
        
 >The species of the Pokemon get defined here. Check src/data/pokemon/species_info/gen_*_families, if you dont find the right species ID
 
        .party = (const struct TrainerMon[])
        {
            {
            .species = SPECIES_VULPIX, 
            
 >Gender gets assigned here, either TRAINER_MON_MALE, TRAINER_MON_FEMALE or TRAINER_MON_RANDOM_GENDER
 
            .gender = TRAINER_MON_RANDOM_GENDER, 
            
 >IVs can be adjusted here, leave them to what is already written inside there
 
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0), 
            
 >Level of the Pokemon
 
            .lvl = 5, 
            
 >Pokemon Nature, it's exactly written as the nature. NATURE_MODEST = Modest
 
            .nature = NATURE_HARDY, 
            
 >We dont use this. Leave it as it is
 
            .dynamaxLevel = MAX_DYNAMAX_LEVEL, 
            
 >This value sets a trainer pokemon to be shiny. Only insert this, if the community member specified that his pokemon is shiny
 
            .isShiny = 1, 
            
>Here you can set the ability of the pokemon. They are usually written exactly how they are, but if you feel unsure, then check the pokemon in src/data/pokemon/species_info/gen_*_families
 
            .ability = ABILITY_DROUGHT, 
            
 > .moves needs to be set to have a customized moveset, instead of a level up moveset. You find all defined moves in here include/constants/moves.h. There can only be 4 moves.
 
            .moves = { 
                MOVE_POUND,
                MOVE_GROWL,
            },
            },
        },
    },

>Here is an example how to insert a new Pokemon

Start from here

            { 
            .species = SPECIES_POOCHYENA,
            .gender = TRAINER_MON_RANDOM_GENDER,
            .iv = TRAINER_PARTY_IVS(0, 0, 0, 0, 0, 0),
            .lvl = 26,
            .nature = NATURE_HARDY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
                MOVE_POUND,
                MOVE_GROWL,
            },
            },
            
And End here
You can copy this and use it as a blueprint. Adjust the values as written up there and you're good to go
