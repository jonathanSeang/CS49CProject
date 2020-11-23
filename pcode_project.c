#include <stdio.h>

    //player starting stats
    static int player_hp = 10;
    static int player_max_hp = 10;
    static int player_atk = 4;
    static int player_lvl = 1;  //is equivalent to count to monsters encountered
    static int player_is_blocking = 1; // 1 = not blocking, 2 = blocking

    //enemy starting stats
    static int enemy_hp = 2;
    static int enemy_atk = 1;

    //method prototypes
    void displayStatusOfAll();
    void playerActs();
    void enemyDies();
    void enemyAttacks();
    void endOfCombatSelection();

int main(void)
{

    printf("You are approached by a monster!\n");//, array_monster_name[lvl]);


    //each while loop represents one round of combat between player and the current enemy
    //it will end once either the player dies or when the player has defeated 10 enemies
    do {

        displayStatusOfAll();
        playerActs();

        if (enemy_hp <= 0)
            enemyDies();
        else
            enemyAttacks();

        //TODO: if (3rd round) open shop

    } while (player_hp > 0);

    printf("You have died to the monster...\n");//, array_monster_name[lvl]);

}

void displayStatusOfAll() {

    printf("\n------------A new round of combat begins------------");
    printf("\nPlayer:\n hp: %d/%d\n attack: %d\n level: %d\n", player_hp, player_max_hp, player_atk, player_lvl);
    printf("\nEnemy:\n hp: %d\n attack: %d\n", enemy_hp, enemy_atk);
    printf("-----------------------------------------------------\n\n");

}

void playerActs() {

    int userActionID;   //stores value of what player plans to do

    //Get user plan of action
    printf("---Enter your action: [1] = attack(deal full attack), [2] = defensive charge(deal half and receive half damage)\n");
    scanf("%d", &userActionID);

    if (userActionID == 1)
    {
        enemy_hp -= player_atk; // player attacks
        printf("\n--You deal %d damage to the monster\n", player_atk);
    }

    //When blocking, user deals half damage and recieves half damage
    else if (userActionID == 2)
    {
        enemy_hp -= (player_atk/2);
            printf("\n--You deal %d damage to the monster\n", player_atk/2);
        player_is_blocking = 2;
    }

    else
    {

        printf("--You stumble and fail to decide a correct action\n");

    }

    return player_is_blocking;

}

//Will reduce player health depending on enemy attack damage and if player is attacking
//input: if enemy is blocking
void enemyAttacks() {

    player_hp -= (enemy_atk / player_is_blocking); // player takes damage from monster
    printf("--You take %d damage from the monster\n", (enemy_atk / player_is_blocking));
    player_is_blocking = 1;

}

//When player dies, player gains a level and a new monster appears
void enemyDies() {

    printf("---------You have slain the enemy!\n\n");
    player_lvl++;

    endOfCombatSelection();

    //Set enemy stats to arbitrary values
    enemy_hp = player_lvl*2;
    enemy_atk = player_lvl;

    printf("---------A new enemy appears before you!\n");
}

//Player gets to choose out of three options after slaying the enemy
void endOfCombatSelection() {

    int userActionID = 0;
    printf("---Enter your action: [1] = rest (restore to full hp), [2] = train muscles(increase attack by one), [3] = train body(increase max health by two)\n");
    scanf("%d", &userActionID);

    if (userActionID == 1)
    {
        player_hp = player_max_hp;
        printf("--You feel well rested\n");
    }

    else if (userActionID == 2)
    {
        player_atk++;
        printf("--Your muscles grow stronger\n");
    }

    else if (userActionID == 3)
    {
        player_max_hp+=2;
        printf("--Your body feels sturdier\n");
    }

    else
    {
        printf("--You don't stop and start running deeper\n");
    }
}

/*
TODO:
make array of monster names corresponding to level and then format to show the monster name
[0] = 'r', 'a', 't'
[1] = 'g', 'o', etc.

possibly add RNG to the game and add algorithms to make damage random

give both player and enemy an armor value

add more actions besides attack and block (maybe give player spell damage and enemy magic resistance)

add a finished ending if you i.e defeat 10 monsters

you get gold for killing monsters

shop/village every 3 monsters where you can spend gold on weapons (boost atk), potions(replenish health), shield (affects shield coefficient)

more flavor text (output more information so that user knows what's going on)

more enemy actions than attack

possibly character customization (name, maybe race, etc.)


*/
