#include <iostream>
#include <windows.h> // for Sleep function
#include <conio.h>   // for _getch function

using namespace std;

const int WIDTH = 50;  // width of the game screen
const int HEIGHT = 20; // height of the game screen
const int MAX_ENEMIES = 5; // maximum number of enemies on the screen
const int ENEMY_SPEED = 1; // speed of the enemies

int playerX, playerY; // coordinates of the player
int score;            // player's score
bool gameOver;        // flag to indicate if the game is over

struct enemy
{
    int x, y;
    bool active;
};

enemy enemies[MAX_ENEMIES]; // array to hold the enemies

void setup()
{
    // initialize the player and enemies
    playerX = WIDTH / 2;
    playerY = HEIGHT - 1;
    score = 0;
    gameOver = false;

    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        enemies[i].x = rand() % WIDTH;
        enemies[i].y = rand() % HEIGHT;
        enemies[i].active = true;
    }
}

void draw()
{
    system("cls"); // clear the console

    // draw the player
    for (int i = 0; i < playerX; i++)
    {
        cout << " ";
    }
    cout << "A" << endl;

    // draw the enemies
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (enemies[i].active)
        {
            for (int j = 0; j < enemies[i].x; j++)
            {
                cout << " ";
            }
            cout << "O" << endl;
        }
    }

    // draw the score
    cout << "Score: " << score << endl;
}

void input()
{
    // move the player left or right
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            playerX--;
            break;
        case 'd':
            playerX++;
            break;
        case 'q':
            gameOver = true;
            break;
        }
    }

    // make sure the player stays within the screen boundaries
    if (playerX < 0)
    {
        playerX = 0;
    }
    if (playerX >= WIDTH)
    {
        playerX = WIDTH - 1;
    }
}

void update()
{
    // move the enemies down
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (enemies[i].active)
        {
            enemies[i].y += ENEMY_SPEED;
        }
    }

    // check for collisions between the player and enemies
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (enemies[i].active && enemies[i].x == playerX && enemies[i].y == playerY)
        {
            gameOver = true;
        }
    }

    // check for collisions between the enemies and the bottom of the screen
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (enemies[i].active && enemies[i].y >= HEIGHT)
        {
            enemies[i].active = false;
            score++;
        }
    }

    // check if the game is over
    if (score >= MAX_ENEMIES)
    {
        gameOver = true;
    }
}
int main()
{
    setup();

    while (!gameOver)
    {
        draw();
        input();
        update();
        Sleep(50); // pause for 50 milliseconds
    }

    cout << "Game over!" << endl;
    cout << "Your score: " << score << endl;

    return 0;
}

