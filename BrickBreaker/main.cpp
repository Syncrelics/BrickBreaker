#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional> 
#include <string> 
#include <fstream> // Required for reading and writing the highscore file

using namespace std;

// --- GLOBAL CONSTANTS ---
const int ROWS = 5;
const int COLS = 10;
const float BRICK_WIDTH = 70.0f;
const float BRICK_HEIGHT = 20.0f;
const float BRICK_SPACING = 2.0f;
const float OFFSET_X = 40.0f;
const float OFFSET_Y = 50.0f;
const float PADDLE_WIDTH = 100.0f;
const float PADDLE_HEIGHT = 20.0f;
const float BALL_RADIUS = 10.0f;

// --- FUNCTION DEFINITIONS ---

void setupGrid(int bricks[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 && j % 2 == 0) bricks[i][j] = 3;
            else if (i == 1) bricks[i][j] = 2;
            else if (i == 2 && j % 3 == 1) bricks[i][j] = 4;
            else if (i == 0) bricks[i][j] = 1;
            else bricks[i][j] = 1;
        }
    }
}

// Resets all variables when a new game starts
void resetGame(int bricks[ROWS][COLS], float& ballX, float& ballY, float& ballSpeedX, float& ballSpeedY, float& paddleX, int& lives, int& score) {
    setupGrid(bricks);
    ballX = 390.0f;
    ballY = 520.0f;
    ballSpeedX = 5.0f;
    ballSpeedY = -5.0f;
    paddleX = 350.0f;
    lives = 3;
    score = 0;
}

void handleInput(float& paddleX, float paddleSpeed) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        paddleX = paddleX - paddleSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        paddleX = paddleX + paddleSpeed;
    }

    if (paddleX < 0.0f) paddleX = 0.0f;
    if (paddleX + PADDLE_WIDTH > 800.0f) paddleX = 800.0f - PADDLE_WIDTH;
}

void updatePhysics(float& ballX, float& ballY, float& ballSpeedX, float& ballSpeedY, int& lives, int& score, int bricks[ROWS][COLS], int& gameState, bool& isWin) {
    ballX = ballX + ballSpeedX;
    ballY = ballY + ballSpeedY;

    if (ballX <= 0.0f || ballX + (BALL_RADIUS * 2) >= 800.0f) {
        ballSpeedX = -ballSpeedX;
    }
    if (ballY <= 0.0f) {
        ballSpeedY = -ballSpeedY;
    }

    if (ballY + (BALL_RADIUS * 2) >= 600.0f) {
        lives = lives - 1;

        if (lives <= 0) {
            gameState = 2; // Move to End Screen
            isWin = false; // Player lost
        }
        else {
            ballX = 390.0f;
            ballY = 520.0f;
            ballSpeedY = -5.0f;
        }
    }

    // Check for Win Condition (Are all breakable bricks gone?)
    bool bricksLeft = false;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // If the brick is not broken (>0) and not unbreakable (!=3)
            if (bricks[i][j] > 0 && bricks[i][j] != 3) {
                bricksLeft = true;
            }
        }
    }

    if (bricksLeft == false) {
        gameState = 2; // Move to End Screen
        isWin = true;  // Player won
    }
}

void checkCollisions(float& ballX, float& ballY, float& ballSpeedX, float& ballSpeedY, float paddleX, float paddleY, int bricks[ROWS][COLS], int& score) {

    // 1. Paddle Collision
    if (ballX + (BALL_RADIUS * 2) >= paddleX &&
        ballX <= paddleX + PADDLE_WIDTH &&
        ballY + (BALL_RADIUS * 2) >= paddleY &&
        ballY <= paddleY + PADDLE_HEIGHT) {

        ballSpeedY = -ballSpeedY;
        ballY = paddleY - (BALL_RADIUS * 2); // Push out of paddle
    }

    // 2. Brick Collision
    bool collisionOccurred = false;

    for (int i = 0; i < ROWS; i++) {
        if (collisionOccurred) break;

        for (int j = 0; j < COLS; j++) {
            if (bricks[i][j] > 0) {
                float currentBrickX = OFFSET_X + (j * (BRICK_WIDTH + BRICK_SPACING));
                float currentBrickY = OFFSET_Y + (i * (BRICK_HEIGHT + BRICK_SPACING));

                if (ballX + (BALL_RADIUS * 2) >= currentBrickX &&
                    ballX <= currentBrickX + BRICK_WIDTH &&
                    ballY + (BALL_RADIUS * 2) >= currentBrickY &&
                    ballY <= currentBrickY + BRICK_HEIGHT) {

                    // Find the exact center of the ball
                    float ballCenterX = ballX + BALL_RADIUS;
                    float ballCenterY = ballY + BALL_RADIUS;

                    // Determine which side was hit and push the ball out
                    if (ballCenterX < currentBrickX) {
                        // Hit Left Side
                        ballSpeedX = -ballSpeedX;
                        ballX = currentBrickX - (BALL_RADIUS * 2);
                    }
                    else if (ballCenterX > currentBrickX + BRICK_WIDTH) {
                        // Hit Right Side
                        ballSpeedX = -ballSpeedX;
                        ballX = currentBrickX + BRICK_WIDTH;
                    }
                    else if (ballCenterY < currentBrickY) {
                        // Hit Top Side
                        ballSpeedY = -ballSpeedY;
                        ballY = currentBrickY - (BALL_RADIUS * 2);
                    }
                    else {
                        // Hit Bottom Side
                        ballSpeedY = -ballSpeedY;
                        ballY = currentBrickY + BRICK_HEIGHT;
                    }

                    // Handle brick breaking logic
                    if (bricks[i][j] == 1) {
                        bricks[i][j] = 0;
                        score = score + 10;
                    }
                    else if (bricks[i][j] == 2) {
                        bricks[i][j] = 1;
                        score = score + 5;
                    }
                    else if (bricks[i][j] == 3) {
                        // Unbreakable - Do nothing, just let it bounce
                    }
                    else if (bricks[i][j] == 4) {
                        bricks[i][j] = 0;
                        score = score + 10;

                        // Explosive logic
                        for (int r = i - 1; r <= i + 1; r++) {
                            for (int c = j - 1; c <= j + 1; c++) {
                                if (r >= 0 && r < ROWS && c >= 0 && c < COLS) {
                                    if (bricks[r][c] > 0 && bricks[r][c] != 3) {
                                        bricks[r][c] = 0;
                                        score = score + 10;
                                    }
                                }
                            }
                        }
                    }

                    collisionOccurred = true;
                    break;
                }
            }
        }
    }
}

void renderFrame(sf::RenderWindow& window, sf::Font& font, sf::RectangleShape& paddle, sf::CircleShape& ball, sf::RectangleShape& brickShape, int bricks[ROWS][COLS], int score, int lives, int gameState, bool isWin, int highScore) {

    window.clear(sf::Color::Black);

    if (gameState == 0) {
        // --- TITLE SCREEN ---
        sf::Text titleText(font);
        titleText.setString("BREAK BREAKER");
        titleText.setCharacterSize(50);
        titleText.setFillColor(sf::Color::White);
        titleText.setPosition({ 200.0f, 150.0f });

        sf::Text hsText(font);
        hsText.setString("Highscore: " + to_string(highScore));
        hsText.setCharacterSize(30);
        hsText.setFillColor(sf::Color::Yellow);
        hsText.setPosition({ 300.0f, 250.0f });

        sf::Text promptText(font);
        promptText.setString("Press ENTER to Play");
        promptText.setCharacterSize(25);
        promptText.setFillColor(sf::Color::White);
        promptText.setPosition({ 270.0f, 400.0f });

        window.draw(titleText);
        window.draw(hsText);
        window.draw(promptText);
    }
    else if (gameState == 1) {
        // --- PLAYING SCREEN ---
        sf::Text scoreText(font);
        scoreText.setString("Score: " + to_string(score));
        scoreText.setCharacterSize(20);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition({ 10.0f, 10.0f });

        sf::Text livesText(font);
        livesText.setString("Lives: " + to_string(lives));
        livesText.setCharacterSize(20);
        livesText.setFillColor(sf::Color::White);
        livesText.setPosition({ 700.0f, 10.0f });

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (bricks[i][j] > 0) {

                    if (bricks[i][j] == 1) brickShape.setFillColor(sf::Color::Red);
                    else if (bricks[i][j] == 2) brickShape.setFillColor(sf::Color::Green);
                    else if (bricks[i][j] == 3) brickShape.setFillColor(sf::Color(128, 128, 128));
                    else if (bricks[i][j] == 4) brickShape.setFillColor(sf::Color::Yellow);

                    float currentBrickX = OFFSET_X + (j * (BRICK_WIDTH + BRICK_SPACING));
                    float currentBrickY = OFFSET_Y + (i * (BRICK_HEIGHT + BRICK_SPACING));

                    brickShape.setPosition({ currentBrickX, currentBrickY });
                    window.draw(brickShape);
                }
            }
        }

        window.draw(paddle);
        window.draw(ball);
        window.draw(scoreText);
        window.draw(livesText);
    }
    else if (gameState == 2) {
        // --- END SCREEN ---
        sf::Text endText(font);
        if (isWin) {
            endText.setString("YOU WIN!");
            endText.setFillColor(sf::Color::Green);
        }
        else {
            endText.setString("YOU LOSE!");
            endText.setFillColor(sf::Color::Red);
        }
        endText.setCharacterSize(60);
        endText.setPosition({ 250.0f, 200.0f });

        sf::Text finalScoreText(font);
        finalScoreText.setString("Final Score: " + to_string(score));
        finalScoreText.setCharacterSize(30);
        finalScoreText.setFillColor(sf::Color::White);
        finalScoreText.setPosition({ 300.0f, 300.0f });

        sf::Text promptText(font);
        promptText.setString("Press ENTER to return to Menu");
        promptText.setCharacterSize(25);
        promptText.setFillColor(sf::Color::White);
        promptText.setPosition({ 220.0f, 400.0f });

        window.draw(endText);
        window.draw(finalScoreText);
        window.draw(promptText);
    }

    window.display();
}


// --- MAIN FUNCTION ---

int main() {
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Break Breaker");
    window.setFramerateLimit(90);

    sf::Font font;
    if (!font.openFromFile("arial.ttf")) {
        cout << "Error loading font!" << endl;
        return -1;
    }

    // --- GAME STATE VARIABLES ---
    int gameState = 0; // 0 = Title, 1 = Play, 2 = End Screen
    bool isWin = false;
    int highScore = 0;

    // Load highscore from file if it exists
    ifstream inputFile("highscore.txt");
    if (inputFile.is_open()) {
        inputFile >> highScore;
        inputFile.close();
    }

    // --- PLAY VARIABLES ---
    int score = 0;
    int lives = 3;
    int bricks[ROWS][COLS];
    float paddleX = 350.0f;
    float paddleY = 550.0f;
    float paddleSpeed = 8.0f;
    float ballX = 390.0f;
    float ballY = 520.0f;
    float ballSpeedX = 5.0f;
    float ballSpeedY = -5.0f;

    // Shapes
    sf::RectangleShape brickShape({ BRICK_WIDTH, BRICK_HEIGHT });
    sf::RectangleShape paddle({ PADDLE_WIDTH, PADDLE_HEIGHT });
    paddle.setFillColor(sf::Color::Blue);
    sf::CircleShape ball(BALL_RADIUS);
    ball.setFillColor(sf::Color::White);

    setupGrid(bricks);

    // Main Game Loop
    while (window.isOpen()) {
        while (const optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        // --- STATE LOGIC ---
        if (gameState == 0) {
            // Wait for ENTER to start
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
                resetGame(bricks, ballX, ballY, ballSpeedX, ballSpeedY, paddleX, lives, score);
                gameState = 1;
                sf::sleep(sf::milliseconds(200)); // Prevent instant double-press
            }
        }
        else if (gameState == 1) {
            // Run normal gameplay
            handleInput(paddleX, paddleSpeed);
            updatePhysics(ballX, ballY, ballSpeedX, ballSpeedY, lives, score, bricks, gameState, isWin);

            // We only check collisions if the game hasn't ended during updatePhysics
            if (gameState == 1) {
                checkCollisions(ballX, ballY, ballSpeedX, ballSpeedY, paddleX, paddleY, bricks, score);

                paddle.setPosition({ paddleX, paddleY });
                ball.setPosition({ ballX, ballY });
            }
        }
        else if (gameState == 2) {
            // Save highscore if the current score is higher
            if (score > highScore) {
                highScore = score;
                ofstream outputFile("highscore.txt");
                if (outputFile.is_open()) {
                    outputFile << highScore;
                    outputFile.close();
                }
            }

            // Wait for ENTER to return to menu
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
                gameState = 0;
                sf::sleep(sf::milliseconds(200));
            }
        }

        renderFrame(window, font, paddle, ball, brickShape, bricks, score, lives, gameState, isWin, highScore);
    }

    return 0;
}