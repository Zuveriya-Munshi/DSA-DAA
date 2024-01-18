#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <graphics.h>

using namespace std;

// Constants
const int screenWidth = 640;
const int screenHeight = 480;
const int ballSize = 10;
const int paddleWidth = 10;
const int paddleHeight = 80;
const int paddleSpeed = 5;
const int ballSpeed = 5;
const int maxScore = 5;
const string scoresFilename = "scores.txt";

// Structs
struct Ball
{
    int x;
    int y;
    int dx;
    int dy;
    int size;

    Ball(int x, int y, int dx, int dy, int size)
    {
        this->x = x;
        this->y = y;
        this->dx = dx;
        this->dy = dy;
        this->size = size;
    }

    void move()
    {
        x += dx;
        y += dy;
    }

    void changeDirection(int dx, int dy)
    {
        this->dx = dx;
        this->dy = dy;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    int getSize()
    {
        return size;
    }

    int getDx()
    {
        return dx;
    }

    int getDy()
    {
        return dy;
    }
};

struct Paddle
{
    int x;
    int y;
    int width;
    int height;
    int score;

    Paddle(int x, int y, int width, int height)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->score = 0;
    }

    void moveUp()
    {
        y -= paddleSpeed;
    }

    void moveDown()
    {
        y += paddleSpeed;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    int getWidth()
    {
        return width;
    }

    int getHeight()
    {
        return height;
    }

    int getScore()
    {
        return score;
    }

    void incrementScore()
    {
        score++;
    }

    void resetScore()
    {
        score = 0;
    }
};

// Function prototypes
void drawMenu();
void drawInstructions();
void drawHighScores();
void playGame();
void resetGame();
void resetPaddles();
void resetBall();
void saveHighScore(Paddle player);
vector<string> readHighScores();
void writeHighScores(vector<string> scores);

// Global variables
Paddle player1(20, screenHeight / 2 - paddleHeight / 2, paddleWidth, paddleHeight);
Paddle player2(screenWidth - 20 - paddleWidth, screenHeight / 2 - paddleHeight / 2, paddleWidth, paddleHeight);
Ball ball(screenWidth / 2, screenHeight / 2, ballSpeed, ballSpeed, ballSize);

int main()
{
    // Initialize graphics
    initwindow(screenWidth, screenHeight, "Ping Pong");

    // Seed random number generator
    srand(time(NULL));

    // Show the menu
    drawMenu();

    // Close the graphics window
    closegraph();

    return 0;
}

void drawMenu()
{
    while (true)
    {
        // Clear the screen
        cleardevice();
        // Draw the title
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
        setbkcolor(LIGHTBLUE);
        setcolor(RED);
        outtextxy(screenWidth / 2 - 140, 50, "Ping Pong");

        // Draw the menu options
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(screenWidth / 2 - 80, 200, "1. Play Game");
        outtextxy(screenWidth / 2 - 80, 250, "2. Instructions");
        outtextxy(screenWidth / 2 - 80, 300, "3. High Scores");
        outtextxy(screenWidth / 2 - 80, 350, "4. Quit");

        // Wait for user input
        int input;
        do
        {
            input = getch();
        } while (input < '1' || input > '4');

        // Process user input
        switch (input)
        {
        case '1':
            playGame();
            break;
        case '2':
            drawInstructions();
            break;
        case '3':
            drawHighScores();
            break;
        case '4':
            return;
        }
    }
}

void drawInstructions()
{
    // Clear the screen
    cleardevice();
    // Draw the title
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
    outtextxy(screenWidth / 2 - 140, 50, "Instructions");

    // Draw the instructions
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(50, 150, "Use the up and down arrow keys to move your paddle.");
    outtextxy(50, 200, "The first player to reach 5 points wins the game.");
    outtextxy(50, 250, "If the ball hits the wall behind a paddle, the other player scores a point.");
    outtextxy(50, 300, "If the ball hits the top or bottom wall, it bounces off.");
    // Clear the screen
    cleardevice();
    // Draw the title
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
    outtextxy(screenWidth / 2 - 200, 50, "Instructions");

    // Draw the instructions
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(50, 100, "Player 1: Use W and S to move up and down");
    outtextxy(50, 130, "Player 2: Use Up and Down arrow keys to move up and down");
    outtextxy(50, 160, ("The first player to score " + to_string(maxScore) + " points wins!").c_str());
    outtextxy(50, 190, "Press any key to return to the menu");

    // Wait for a key press
    getch();

    // Return to the menu
    drawMenu();
}

void drawHighScores()
{
    // Clear the screen
    cleardevice();
    // Draw the title
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
    outtextxy(screenWidth / 2 - 120, 50, "High Scores");

    // Read the high scores from the file
    vector<string> scores = readHighScores();

    // Draw the scores
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    int y = 100;

    for (string score : scores)
    {
        outtextxy(50, y, score.c_str());
        y += 30;
    }

    // Wait for a key press
    getch();

    // Return to the menu
    drawMenu();

    // Clear the screen
    cleardevice();
    // Draw the title
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
    outtextxy(screenWidth / 2 - 140, 50, "High Scores");

    // Read the high scores from file
    scores = readHighScores();

    // Draw the high scores
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    y = 150;
    for (int i = 0; i < (int)scores.size(); i++)
    {
        outtextxy(screenWidth / 2 - 80, y, scores[i].c_str());
        y += 50;
    }

    // Wait for user input
    while (getch() == 0)
    {
    }

    // Return to the menu
    drawMenu();
    // Wait for user input
    while (getch() == 0)
    {
    }

    // Return to the menu
    drawMenu();
}

void playGame()
{
    // Reset the game
    resetGame();
    // Main game loop
    while (true)
    {
        // Check for game over
        if (player1.getScore() == maxScore || player2.getScore() == maxScore)
        {
            // Save the high score if necessary
            if (player1.getScore() == maxScore)
            {
                saveHighScore(player1);
            }
            else
            {
                saveHighScore(player2);
            }

            // Return to the menu
            drawMenu();
            return;
        }

        // Clear the screen
        cleardevice();
        // Move the ball
        ball.move();

        // Check for collisions with the top and bottom walls
        if (ball.getY() - ball.getSize() / 2 <= 0 || ball.getY() + ball.getSize() / 2 >= screenHeight)
        {
            ball.changeDirection(ball.getDx(), -ball.getDy());
        }

        // Check for collisions with the left paddle
        if (ball.getX() - ball.getSize() / 2 <= player1.getX() + player1.getWidth() &&
            ball.getY() + ball.getSize() / 2 >= player1.getY() &&
            ball.getY() - ball.getSize() / 2 <= player1.getY() + player1.getHeight())
        {
            ball.changeDirection(ball.getDx(), -ball.getDy());
        }

        // Check for collisions with the right paddle
        if (ball.getX() + ball.getSize() / 2 >= player2.getX() &&
            ball.getY() + ball.getSize() / 2 >= player2.getY() &&
            ball.getY() - ball.getSize() / 2 <= player2.getY() + player2.getHeight())
        {
            ball.changeDirection(ball.getDx(), -ball.getDy());
        }

        // Check for ball going out of bounds
        if (ball.getX() - ball.getSize() / 2 <= 0 || ball.getX() + ball.getSize() / 2 >= screenWidth)
        {
            if (ball.getX() - ball.getSize() / 2 <= 0)
            {
                player2.incrementScore();
            }
            else
            {
                player1.incrementScore();
            }

            resetBall();
        }

        // Move the paddles
        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            player2.moveUp();
        }

        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            player2.moveDown();
        }

        if (GetAsyncKeyState('W') & 0x8000)
        {
            player1.moveUp();
        }

        if (GetAsyncKeyState('S') & 0x8000)
        {
            player1.moveDown();
        }

        // Draw the ball and paddles
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        fillellipse(ball.getX(), ball.getY(), ball.getSize() / 2, ball.getSize() / 2);

        bar(player1.getX(), player1.getY(), player1.getX() + player1.getWidth(), player1.getY() + player1.getHeight());
        bar(player2.getX(), player2.getY(), player2.getX() + player2.getWidth(), player2.getY() + player2.getHeight());

        // Draw the scores
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
        string scoreString = to_string(player1.getScore()) + " - " + to_string(player2.getScore());
        outtextxy(screenWidth / 2 - 30, 10, scoreString.c_str());

        // Delay for smoother animation
        delay(10);
    }
}
// Helper functions

void resetGame()
{
    resetPaddles();
    resetBall();
}

void resetPaddles()
{
    player1.resetScore();
    player2.resetScore();
    player1 = Paddle(20, screenHeight / 2 - paddleHeight / 2, paddleWidth, paddleHeight);
    player2 = Paddle(screenWidth - 20 - paddleWidth, screenHeight / 2 - paddleHeight / 2, paddleWidth, paddleHeight);
}

void resetBall()
{
    ball = Ball(screenWidth / 2, screenHeight / 2, ballSpeed * (rand() % 2 == 0 ? 1 : -1), ballSpeed * (rand() % 2 == 0 ? 1 : -1), ballSize);
}

void saveHighScore(Paddle player)
{
    // Read the existing high scores
    vector<string> scores = readHighScores();
    // Add the new score to the list
    scores.push_back(to_string(player.getScore()) + " " + to_string(time(NULL)));

    // Sort the scores in descending order
    sort(scores.rbegin(), scores.rend());

    // Keep only the top 10 scores
    if (scores.size() > 10)
    {
        scores.resize(10);
    }

    // Write the scores to the file
    writeHighScores(scores);
}

vector<string> readHighScores()
{
    vector<string> scores;
    ifstream scoresFile(scoresFilename);
    if (scoresFile.is_open())
    {
        string line;

        while (getline(scoresFile, line))
        {
            scores.push_back(line);
        }

        scoresFile.close();
    }

    return scores;
}

void writeHighScores(vector<string> scores)
{
    ofstream scoresFile(scoresFilename);
    if (scoresFile.is_open())
    {
        for (string score : scores)
        {
            scoresFile << score << endl;
        }

        scoresFile.close();
    }
}
//That's all of the code! To summarize, this program is a simple game of Pong written in C++. It allows two players to compete against each other, with the objective being to score points by hitting the ball past the opponent's paddle. The game ends when one player reaches the maximum score, at which point their score is saved to a file if it is a high score. The game can also be restarted from  the main menu.
