#include <stdio.h>

    static int player_hp = 10;
    static int player_atk = 3;
    static int player_lvl = 1;


int main(void)
{
    while (player_hp > 0 && player_lvl <= 3)
    {
        basic_enemy(player_lvl);
    }
}

void basic_enemy(int monster_level)
{
    int enemy_hp = 5; // either set or an algorithm based on level
    int enemy_atk = 6; // ^
    int block = 1; // 1 = not blocking, 2 = blocking
    int num = 0;

    // array of strings (array of chars) that contains monster names,

    printf("You are approached by a monster\n");//, array_monster_name[lvl]);

    while (enemy_hp > 0 && player_hp > 0)
    {
    printf("Enter your action: [1] = attack, [2] = block, etc. . .\n");
    scanf("%d", &num);
    if (num == 1)
    {
        enemy_hp -= player_atk; // player attacks
        printf("You deal %d damage to the monster\n", player_atk);
    }
    else if (num == 2)
    {
        block = 2;
    }
    // else if etc. more actions

    // monster attacks player
    if (enemy_hp > 0)
    {
        player_hp -= (enemy_atk / block); // player takes damage from monster
        printf("You take %d damage from the monster\n", (enemy_atk / block));
        block = 1;
    }
    }

    if (enemy_hp <= 0)
    {
    printf("You have slain the monster\n");//, array_monster_name[lvl]);
    player_lvl++;
    }
    if (player_hp <= 0)
    {
    printf("You have died to the monster\n");//, array_monster_name[lvl]);
    }

}
/*
TODO:
make array of monster names corresponding to level and then format to show the monster name
[0] = 'r', 'a', 't'
[1] = 'g', 'o', etc.

possibly add RNG to the game and add algorithms to make damage random

add more actions besides attack and block (useless)

add a finished ending if you i.e defeat 10 monsters

you get gold for killing monsters

shop/village every 3 monsters where you can spend gold on weapons (boost atk), potions(replenish health), shield (affects shield coefficient)

more flavor text

more enemy actions than attack

possibly character customization (name, maybe race, etc.)


*/
