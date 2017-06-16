#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <tchar.h>
using namespace std;
int x = 1;
int y = 1;
int level = 1;
int money = 0;
bool paused = false;
char Level1[31][31] =
{
    "##############################",
    "# #!                         #",
    "# #      #    $              #",
    "# #      #                   #",
    "# ########################## #",
    "#            #               #",
    "#            #  $            #",
    "#            #               #",
    "#         $  #               #",
    "#            #               #",
    "#            #               #",
    "#            #               #",
    "#            #               #",
    "#            #               #",
    "#            #               #",
    "# ########################## #",
    "#            #               #",
    "#            #   $           #",
    "#            #               #",
    "#            #               #",
    "#            ######## ########",
    "#     $      #               #",
    "#            #               #",
    "#            #               #",
    "#            #               #",
    "#            #               #",
    "#            #            $  #",
    "#            #               #",
    "#                            #",
    "##############################"
};
char Level2[31][31] =
{
    "##############################",
    "#                            #",
    "#                    #       #",
    "#                    #       #",
    "############################ #",
    "#              #     #       #",
    "#              #     #       #",
    "#         $    #     #  $    #",
    "#              #     #       #",
    "#              #     #       #",
    "#                    #       #",
    "# ######################## ###",
    "#           #                #",
    "#           #            #   #",
    "#   $       #            # $ #",
    "#           #      $     #   #",
    "#           #            #####",
    "#           #                #",
    "#           #                #",
    "########### #                #",
    "#           #                #",
    "#           ######### ########",
    "#           #                #",
    "#           #                #",
    "#           #                #",
    "#           #                #",
    "#                            #",
    "#           #                #",
    "#           #                #",
    "##############################"
};
void clearScreen()
{
    short x = 0;
    short y = 0;
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void collectRandomMoney(int a, int b)
{
    int number = rand() % b + a;
    money += number;
}
int main()
{
    system("cls");
    SetConsoleTitle(_T("Dungeon Crawler"));
    for( ; ; )
    {
        if(GetAsyncKeyState('R') && paused == true)
        {
            paused = false;
        }
        while(paused == false)
        {
            if(GetAsyncKeyState('P') && paused == false)
            {
                paused = true;
            }
            clearScreen();
            if(level == 1)
            {
                Level1[y][x] = '@';
            }
            else if(level == 2)
            {
                Level2[y][x] = '@';
            }
            if(GetAsyncKeyState(VK_UP))
            {
                if(level == 1)
                {
                    switch(Level1[y-1][x])
                    {
                    case ' ':
                    {
                        y -= 1;
                        Level1[y+1][x] = ' ';
                        Level1[y][x] = '@';
                        break;
                    }
                    case '$':
                    {
                        collectRandomMoney(2, 7);
                        y -= 1;
                        Level1[y+1][x] = ' ';
                        Level1[y][x] = '@';
                        break;
                    }
                    case '!':
                    {
                        system("cls");
                        x = 1;
                        y = 1;
                        level++;
                    }
                    }
                }
                else if(level == 2)
                {
                    switch(Level2[y-1][x])
                    {
                    case ' ':
                    {
                        y -= 1;
                        Level2[y+1][x] = ' ';
                        Level2[y][x] = '@';
                        break;
                    }
                    case '$':
                    {
                        collectRandomMoney(2, 7);
                        y -= 1;
                        Level2[y+1][x] = ' ';
                        Level2[y][x] = '@';
                        break;
                    }
                    case '!':
                    {
                        system("cls");
                        x = 1;
                        y = 1;
                        level++;
                    }
                    }
                }
            }
            else if(GetAsyncKeyState(VK_DOWN))
            {
                if(level == 1)
                {
                    switch(Level1[y+1][x])
                    {
                    case ' ':
                    {
                        y += 1;
                        Level1[y-1][x] = ' ';
                        Level1[y][x] = '@';
                        break;
                    }
                    case '$':
                    {
                        collectRandomMoney(2, 7);
                        y += 1;
                        Level1[y-1][x] = ' ';
                        Level1[y][x] = '@';
                        break;
                    }
                    case '!':
                    {
                        system("cls");
                        x = 1;
                        y = 1;
                        level++;
                    }
                    }
                }
                else if(level == 2)
                {
                    switch(Level2[y+1][x])
                    {
                    case ' ':
                    {
                        y += 1;
                        Level2[y-1][x] = ' ';
                        Level2[y][x] = '@';
                        break;
                    }
                    case '$':
                    {
                        collectRandomMoney(2, 7);
                        y += 1;
                        Level2[y-1][x] = ' ';
                        Level2[y][x] = '@';
                        break;
                    }
                    case '!':
                    {
                        system("cls");
                        x = 1;
                        y = 1;
                        level++;
                    }
                    }
                }
            }
            else if(GetAsyncKeyState(VK_RIGHT))
            {
                if(level == 1)
                {
                    switch(Level1[y][x+1])
                    {
                    case ' ':
                    {
                        x += 1;
                        Level1[y][x-1] = ' ';
                        Level1[y][x] = '@';
                        break;
                    }
                    case '$':
                    {
                        collectRandomMoney(2, 7);
                        x += 1;
                        Level1[y][x-1] = ' ';
                        Level1[y][x] = '@';
                        break;
                    }
                    case '!':
                    {
                        system("cls");
                        x = 1;
                        y = 1;
                        level++;
                    }
                    }
                }
                else if(level == 2)
                {
                    switch(Level2[y][x+1])
                    {
                    case ' ':
                    {
                        x += 1;
                        Level2[y][x-1] = ' ';
                        Level2[y][x] = '@';
                        break;
                    }
                    case '$':
                    {
                        collectRandomMoney(2, 7);
                        x += 1;
                        Level2[y][x-1] = ' ';
                        Level2[y][x] = '@';
                        break;
                    }
                    case '!':
                    {
                        system("cls");
                        x = 1;
                        y = 1;
                        level++;
                    }
                    }
                }
            }
            else if(GetAsyncKeyState(VK_LEFT))
            {
                if(level == 1)
                {
                    switch(Level1[y][x-1])
                    {
                    case ' ':
                    {
                        x -= 1;
                        Level1[y][x+1] = ' ';
                        Level1[y][x] = '@';
                        break;
                    }
                    case '$':
                    {
                        collectRandomMoney(2, 7);
                        x -= 1;
                        Level1[y][x+1] = ' ';
                        Level1[y][x] = '@';
                        break;
                    }
                    case '!':
                    {
                        system("cls");
                        x = 1;
                        y = 1;
                        level++;
                    }
                    }
                }
                else if(level == 2)
                {
                    switch(Level2[y][x-1])
                    {
                    case ' ':
                    {
                        x -= 1;
                        Level2[y][x+1] = ' ';
                        Level2[y][x] = '@';
                        break;
                    }
                    case '$':
                    {
                        collectRandomMoney(2, 7);
                        x -= 1;
                        Level2[y][x+1] = ' ';
                        Level2[y][x] = '@';
                        break;
                    }
                    case '!':
                    {
                        system("cls");
                        x = 1;
                        y = 1;
                        level++;
                    }
                    }
                }
            }
            if(level == 1)
            {
                for(int y = 0; y < 31; y++)
                {
                    cout << Level1[y] << endl;
                }
            }
            else if(level == 2)
            {
                for(int y = 0; y < 31; y++)
                {
                    cout << Level2[y] << endl;
                }
            }
            cout << "\nMoney: " << money << endl;
            Sleep(100);
        }

    }
}
