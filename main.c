#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int i;
    char map[10][21];
    int x = 10, y = 5;
    char key;
    int ox, oy;
    int ax = 5, ay = 3;
    int score = 0;
    int level = 0;
    int speed = 1;
    srand(time(NULL));

    do{
        sprintf(map[0], "####################");
        for(i = 1; i < 9; i++)
            sprintf(map[i], "#                  #");
        sprintf(map[9], "####################");

        map[y][x] = '@';
        map[ay][ax] = '*';

        system("cls");
        for(int i = 0; i < 10; i++)
        {
            printf("%s\n", map[i]);
        }
        printf("score: %d\n", score);
        printf("level: %d\n", level);

        if(level == 1 && score < 2)
        {
            printf("Level 1!!!");
        }

        key = getch();

        ox = x;
        oy = y;
        if(key == 'w') y -= speed;
        if(key == 'a') x -= speed;
        if(key == 's') y += speed;
        if(key == 'd') x += speed;

        if(map[y][x] == '#')
        {
            x = ox;
            y = oy;
        }
        if((x == ax) && (y == ay))
        {
            ax = rand() * 1.0 / RAND_MAX * 18 + 1;
            ay = rand() * 1.0 / RAND_MAX * 8 + 1;
            score++;
        }

        if(score >= 10)
        {
            level++;
            score = 0;
        }

    }
    while(key != 'e');
}
