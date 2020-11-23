#include <stdio.h>

    //player starting stats
    static int player_hp = 10;
    static int player_max_hp = 10;
    static int player_atk = 4;
    static int player_lvl = 1;  //is equivalent to count to monsters encountered
    static int player_is_blocking = 1; // 1 = not blocking, 2 = blocking
    static int player_shield_lvl = 1; // 1

    //enemy starting stats
    static int enemy_hp = 2;
    static int enemy_atk = 1;

    //method prototypes
    void displayStatusOfAll();
    void playerActs();
    void enemyDies();
    void enemyAttacks();
    void endOfCombatSelection();
    void goTown();

int main(void)
{
        // array for monster names
        const char* a[11] = {
            a[0] = "nothing", // player level starts at 1 so you never fight an enemy at index 0
            a[1] = "rat",
            a[2] = "boar",
            a[3] = "slime",
            a[4] = "goblin",
            a[5] = "skeleton",
            a[6] = "ogre",
            a[7] = "demon",
            a[8] = "giant",
            a[9] = "dragon",
            a[10] = "god"
    };



    //each while loop represents one round of combat between player and the current enemy
    //it will end once either the player dies or when the player has defeated 10 enemies
    do {

        printf("You are engaged in combat with a %s!\n", a[player_lvl]);//, array_monster_name[lvl]);
        displayStatusOfAll();
        playerActs();

        if (enemy_hp <= 0)
            enemyDies();
        else
            enemyAttacks();

    } while (player_hp > 0 && player_lvl <= 10);

    if (player_hp <= 0){
        printf("You have died to the %s...\n", a[player_lvl]);
        printf("You died at level %d. Try to make it to level 11 next time! \n", player_lvl);
    }
    else
        printf("Congratulations, Hero!!");
    return 0;
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
    printf("---Enter your action: [1] = attack(deal full attack), [2] = defensive charge(deal half and receive less damage)\n");
    scanf("%d", &userActionID);

    if (userActionID == 1)
    {
        enemy_hp -= player_atk; // player attacks
        printf("\n--You deal %d damage to the monster\n", player_atk);
    }

    //When blocking, user deals half damage and receives less damage
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


}

//Will reduce player health depending on enemy attack damage and if player is attacking
//input: if enemy is blocking
void enemyAttacks() {

    player_hp -= (enemy_atk / (player_is_blocking * player_shield_lvl)); // player takes damage from monster based on the level of their shield and if they are blocking
    printf("--You take %d damage from the monster\n", (enemy_atk / (player_is_blocking * player_shield_lvl)));
    player_is_blocking = 1;

}

//When player dies, player gains a level and a new monster appears
void enemyDies() {

    printf("---------You have slain the enemy!\n\n");
    player_lvl++;

    endOfCombatSelection();

    //Set enemy stats to arbitrary values
    enemy_hp = player_lvl*3;
    enemy_atk = player_lvl*2;

    if (player_lvl % 3 == 0)
        goTown();
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
        player_max_hp+=5;
        player_hp+=5;
        printf("--Your body feels sturdier\n");
    }

    else
    {
        printf("--You don't stop and start running deeper\n");
    }
}

void goTown() {
    int userActionID;   //stores value of what player plans to do

    //Get user plan of action
    printf("---Enter your action: [1] = buy a weapon, [2] = buy a shield \n");
    scanf("%d", &userActionID);

    if (userActionID == 1)
    {
        player_atk += player_lvl; // player gets an increase to their damage equal to the level, this is so it scales as the game progresses
        printf("\n--You purchase a stronger weapon. Your attack is now %d.\n", player_atk);
    }

    else if (userActionID == 2)
    {
        player_shield_lvl += 1; // this increases your defense so you take less damage, especially while blocking
        printf("\n--You purchase a better shield.\n");
    }

    else
    {

        printf("--You decide to leave without purchasing anything\n");

    }


}

