//#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
//#include <iostream>
//#include <optional> 
//#include <string> 
//#include <fstream>
//#include <cstdlib>
//#include <ctime>
//
//using namespace std;
//
//const int ROWS = 7;
//const int COLS = 10;
//const int MAX_POWERUPS = 10;
//const int MAX_BALLS = 5;
//const int MAX_LEVELS = 5;
//const int MAX_EXPLOSIONS = 5;
//const int MAX_LASERS = 5;
//const int MAX_SHARDS = 30;
//const int MAX_MSGS = 5;
//const int TRAIL_LENGTH = 12;
//const float BRICK_WIDTH = 70.0f;
//const float BRICK_HEIGHT = 20.0f;
//const float BRICK_SPACING = 2.0f;
//const float OFFSET_X = 40.0f;
//const float OFFSET_Y = 60.0f;
//const float DEFAULT_PADDLE_WIDTH = 100.0f;
//const float PADDLE_HEIGHT = 20.0f;
//const float BALL_RADIUS = 10.0f;
//const float MAX_BALL_SPEED = 9.0f;
//
//const float WALL_LEFT = 28.0f;
//const float WALL_RIGHT = 772.0f;
//const float WALL_TOP = 22.0f;
//
//const float btnX[4] = { 298.0f, 246.0f, 278.0f, 323.0f };
//const float btnY[4] = { 298.0f, 352.0f, 400.0f, 448.0f };
//const float btnW[4] = { 204.0f, 308.0f, 244.0f, 154.0f };
//const float btnH[4] = { 40.0f,  38.0f,  38.0f,  38.0f };
//
//const string levelNames[MAX_LEVELS] = {
//    "LEVEL 1: CLASSIC INTRO",
//    "LEVEL 2: CHECKERBOARD",
//    "LEVEL 3: TWIN TOWERS",
//    "LEVEL 4: THE BUNKER",
//    "LEVEL 5: THE FINAL VAULT"
//};
//
//
//void saveScores(int highScore, int prevScore) {
//    ofstream outputFile("highscore.txt");
//    if (outputFile.is_open()) {
//        outputFile << highScore << endl;
//        outputFile << prevScore << endl;
//        outputFile.close();
//    }
//}
//
//void drawStyledText(sf::RenderWindow& window, sf::Font& font, string textStr, int size, sf::Color color, float x, float y, unsigned char alpha = 255) {
//    sf::Text shadow(font);
//    shadow.setString(textStr);
//    shadow.setCharacterSize(size);
//    shadow.setStyle(sf::Text::Bold);
//    shadow.setFillColor(sf::Color(0, 0, 0, (unsigned char)(alpha * 0.7f)));
//    shadow.setPosition({ x + 3.0f, y + 3.0f });
//    window.draw(shadow);
//
//    sf::Text mainText(font);
//    mainText.setString(textStr);
//    mainText.setCharacterSize(size);
//    mainText.setStyle(sf::Text::Bold);
//    mainText.setFillColor(sf::Color(color.r, color.g, color.b, alpha));
//    mainText.setOutlineColor(sf::Color(0, 0, 0, alpha));
//    mainText.setOutlineThickness(2.0f);
//    mainText.setPosition({ x, y });
//    window.draw(mainText);
//}
//
//void spawnMessage(string text, sf::Color color, string msgText[MAX_MSGS], int msgTimer[MAX_MSGS], float msgY[MAX_MSGS], sf::Color msgColor[MAX_MSGS]) {
//    int activeCount = 0;
//    for (int i = 0; i < MAX_MSGS; i++) {
//        if (msgTimer[i] > 0) {
//            activeCount = activeCount + 1;
//        }
//    }
//
//    for (int i = 0; i < MAX_MSGS; i++) {
//        if (msgTimer[i] <= 0) {
//            msgText[i] = text;
//            msgColor[i] = color;
//            msgTimer[i] = 90;
//            msgY[i] = 300.0f + (activeCount * 35.0f);
//            break;
//        }
//    }
//}
//
//void initBallTrail(int b, float x, float y, float trailX[MAX_BALLS][TRAIL_LENGTH], float trailY[MAX_BALLS][TRAIL_LENGTH]) {
//    for (int t = 0; t < TRAIL_LENGTH; t++) {
//        trailX[b][t] = x;
//        trailY[b][t] = y;
//    }
//}
//
//void spawnExplosion(float x, float y, bool expActive[MAX_EXPLOSIONS], float expX[MAX_EXPLOSIONS], float expY[MAX_EXPLOSIONS], int expTimer[MAX_EXPLOSIONS]) {
//    for (int i = 0; i < MAX_EXPLOSIONS; i++) {
//        if (!expActive[i]) {
//            expActive[i] = true;
//            expX[i] = x;
//            expY[i] = y;
//            expTimer[i] = 20;
//            break;
//        }
//    }
//}
//
//void spawnLaser(float y, bool laserActive[MAX_LASERS], float laserY[MAX_LASERS], int laserTimer[MAX_LASERS]) {
//    for (int i = 0; i < MAX_LASERS; i++) {
//        if (!laserActive[i]) {
//            laserActive[i] = true;
//            laserY[i] = y;
//            laserTimer[i] = 18;
//            break;
//        }
//    }
//}
//
//void spawnIceShatter(float x, float y, bool shardActive[MAX_SHARDS], float shardX[MAX_SHARDS], float shardY[MAX_SHARDS], float shardVX[MAX_SHARDS], float shardVY[MAX_SHARDS], int shardTimer[MAX_SHARDS]) {
//    float dirX[10] = { 3.5f, -3.5f, 0.0f, 0.0f, 2.6f, -2.6f, 2.6f, -2.6f, 4.0f, -4.0f };
//    float dirY[10] = { 0.0f, 0.0f, 3.5f, -3.5f, 2.6f, 2.6f, -2.6f, -2.6f, -1.5f, 1.5f };
//
//    int spawned = 0;
//    for (int i = 0; i < MAX_SHARDS; i++) {
//        if (!shardActive[i]) {
//            shardActive[i] = true;
//            shardX[i] = x;
//            shardY[i] = y;
//            shardVX[i] = dirX[spawned];
//            shardVY[i] = dirY[spawned];
//            shardTimer[i] = 22;
//            spawned = spawned + 1;
//            if (spawned == 10) break;
//        }
//    }
//}
//
//void setupGrid(int bricks[ROWS][COLS], int hitFlash[ROWS][COLS], int level) {
//    for (int i = 0; i < ROWS; i++) {
//        for (int j = 0; j < COLS; j++) {
//            bricks[i][j] = 0;
//            hitFlash[i][j] = 0;
//        }
//    }
//
//    if (level == 1) {
//        for (int i = 0; i < ROWS; i++) {
//            for (int j = 0; j < COLS; j++) {
//                if (i == 0 && j >= 1 && j <= 8) bricks[i][j] = 2;
//                else if (i == 1 && (j == 1 || j == 8)) bricks[i][j] = 6;
//                else if (i == 2 && (j == 2 || j == 7)) bricks[i][j] = 4;
//                else if (i == 4 && (j == 4 || j == 5)) bricks[i][j] = 7;
//                else if (i >= 1 && i <= 5 && j >= 1 && j <= 8) bricks[i][j] = 1;
//            }
//        }
//    }
//    else if (level == 2) {
//        for (int i = 0; i < ROWS; i++) {
//            for (int j = 0; j < COLS; j++) {
//                if ((i + j) % 2 == 0) {
//                    if (i == 0 && (j == 0 || j == 8)) bricks[i][j] = 3;
//                    else if (i == 0 || i == 1) bricks[i][j] = 2;
//                    else if (i == 2 && (j == 2 || j == 6)) bricks[i][j] = 4;
//                    else if (i == 3 && j == 5) bricks[i][j] = 7;
//                    else if (i == 4 && (j == 2 || j == 8)) bricks[i][j] = 6;
//                    else if (i == 5 && j == 3) bricks[i][j] = 4;
//                    else bricks[i][j] = 1;
//                }
//            }
//        }
//    }
//    else if (level == 3) {
//        for (int i = 0; i < ROWS; i++) {
//            for (int j = 0; j < COLS; j++) {
//                if (j == 4 || j == 5) {
//                    if (i == 0 && j == 4) bricks[i][j] = 7;
//                    else if (i == 0 && j == 5) bricks[i][j] = 6;
//                    else if (i == 3 && (j == 4 || j == 5)) bricks[i][j] = 4;
//                }
//                else {
//                    if (i == 6 && (j == 3 || j == 6)) bricks[i][j] = 3;
//                    else if (i == 0 || i == 1 || i == 2) bricks[i][j] = 2;
//                    else if (i == 3 && (j == 1 || j == 8)) bricks[i][j] = 4;
//                    else if (i == 4 && (j == 2 || j == 7)) bricks[i][j] = 6;
//                    else if (i == 5 && (j == 0 || j == 9)) bricks[i][j] = 7;
//                    else bricks[i][j] = 1;
//                }
//            }
//        }
//    }
//    else if (level == 4) {
//        for (int i = 0; i < ROWS; i++) {
//            for (int j = 0; j < COLS; j++) {
//                if (i == 6 && (j == 1 || j == 2 || j == 7 || j == 8)) bricks[i][j] = 3;
//                else if (i == 5 && (j == 0 || j == 9)) bricks[i][j] = 0;
//                else if (i == 1 && (j == 0 || j == 9)) bricks[i][j] = 7;
//                else if (i == 3 && (j == 0 || j == 9)) bricks[i][j] = 6;
//                else if (i == 2 && (j == 3 || j == 6)) bricks[i][j] = 4;
//                else if (i == 4 && (j == 4 || j == 5)) bricks[i][j] = 4;
//                else if (i == 3 && (j == 4 || j == 5)) bricks[i][j] = 6;
//                else if (i <= 3 && j >= 2 && j <= 7) bricks[i][j] = 2;
//                else if (i >= 4 && i <= 5 && j >= 1 && j <= 8) bricks[i][j] = 1;
//            }
//        }
//    }
//    else if (level == 5) {
//        for (int i = 0; i < ROWS; i++) {
//            for (int j = 0; j < COLS; j++) {
//                if (i == 6 && (j == 0 || j == 1 || j == 4 || j == 5 || j == 8 || j == 9)) bricks[i][j] = 3;
//                else if (i == 6) bricks[i][j] = 0;
//                else if (i == 0 && (j == 0 || j == 9)) bricks[i][j] = 7;
//                else if (i == 0 || i == 1) bricks[i][j] = 2;
//                else if (i == 2 && (j == 2 || j == 7)) bricks[i][j] = 4;
//                else if (i == 2 && (j == 4 || j == 5)) bricks[i][j] = 6;
//                else if (i == 2) bricks[i][j] = 2;
//                else if (i == 3 && (j == 1 || j == 8)) bricks[i][j] = 6;
//                else if (i == 3 && (j == 4 || j == 5)) bricks[i][j] = 7;
//                else if (i == 3) bricks[i][j] = 2;
//                else if (i == 4 && (j == 3 || j == 6)) bricks[i][j] = 4;
//                else if (i == 5 && (j == 2 || j == 7)) bricks[i][j] = 6;
//                else bricks[i][j] = 1;
//            }
//        }
//    }
//}
//
//void spawnPowerUp(float x, float y, int brickType, bool powerActive[MAX_POWERUPS], float powerX[MAX_POWERUPS], float powerY[MAX_POWERUPS], int powerType[MAX_POWERUPS], int powerBrickType[MAX_POWERUPS]) {
//    if (rand() % 100 < 40) {
//        for (int i = 0; i < MAX_POWERUPS; i++) {
//            if (!powerActive[i]) {
//                powerActive[i] = true;
//                powerX[i] = x;
//                powerY[i] = y;
//                powerType[i] = (rand() % 7) + 1;
//                powerBrickType[i] = brickType;
//                break;
//            }
//        }
//    }
//}
//
//void spawnExtraBalls(bool ballActive[MAX_BALLS], float ballX[MAX_BALLS], float ballY[MAX_BALLS], float ballSpeedX[MAX_BALLS], float ballSpeedY[MAX_BALLS], int ballFrostTimer[MAX_BALLS], float trailX[MAX_BALLS][TRAIL_LENGTH], float trailY[MAX_BALLS][TRAIL_LENGTH], float paddleX, float paddleY, float paddleWidth, float baseBallSpeed) {
//    int spawned = 0;
//    for (int i = 0; i < MAX_BALLS; i++) {
//        if (!ballActive[i]) {
//            ballActive[i] = true;
//            ballFrostTimer[i] = 0;
//            ballX[i] = paddleX + (paddleWidth / 2.0f) - BALL_RADIUS;
//            ballY[i] = paddleY - (BALL_RADIUS * 2) - 5.0f;
//            initBallTrail(i, ballX[i], ballY[i], trailX, trailY);
//
//            if (spawned == 0) {
//                ballSpeedX[i] = baseBallSpeed;
//                ballSpeedY[i] = -baseBallSpeed;
//            }
//            else {
//                ballSpeedX[i] = -baseBallSpeed;
//                ballSpeedY[i] = -baseBallSpeed;
//            }
//            spawned = spawned + 1;
//            if (spawned == 2) break;
//        }
//    }
//}
//
//void resetGame(int bricks[ROWS][COLS], int hitFlash[ROWS][COLS], int& currentLevel, bool ballActive[MAX_BALLS], float ballX[MAX_BALLS], float ballY[MAX_BALLS], float ballSpeedX[MAX_BALLS], float ballSpeedY[MAX_BALLS], int ballFrostTimer[MAX_BALLS], float trailX[MAX_BALLS][TRAIL_LENGTH], float trailY[MAX_BALLS][TRAIL_LENGTH], float& paddleX, float& paddleWidth, int& lives, int& score, int& combo, int& speedTimer, int& levelClearTimer, int& levelIntroTimer, bool& reverseControls, int& reverseTimer, int& paddleTimer, int& ballEffectTimer, int& ballEffectType, bool& ballStuck, int msgTimer[MAX_MSGS], bool powerActive[MAX_POWERUPS], bool expActive[MAX_EXPLOSIONS], bool laserActive[MAX_LASERS], bool shardActive[MAX_SHARDS], float baseBallSpeed) {
//    currentLevel = 1;
//    setupGrid(bricks, hitFlash, currentLevel);
//
//    paddleWidth = DEFAULT_PADDLE_WIDTH;
//    paddleX = 400.0f - (paddleWidth / 2.0f);
//
//    for (int i = 0; i < MAX_BALLS; i++) {
//        ballActive[i] = false;
//        ballFrostTimer[i] = 0;
//    }
//    ballActive[0] = true;
//    ballX[0] = paddleX + (paddleWidth / 2.0f) - BALL_RADIUS;
//    ballY[0] = 550.0f - (BALL_RADIUS * 2);
//    ballSpeedX[0] = baseBallSpeed;
//    ballSpeedY[0] = -baseBallSpeed;
//    initBallTrail(0, ballX[0], ballY[0], trailX, trailY);
//
//    lives = 3;
//    score = 0;
//    combo = 0;
//    speedTimer = 0;
//    levelClearTimer = 0;
//    levelIntroTimer = 120;
//    reverseControls = false;
//    reverseTimer = 0;
//    paddleTimer = 0;
//    ballEffectTimer = 0;
//    ballEffectType = 0;
//    ballStuck = true;
//
//    for (int i = 0; i < MAX_MSGS; i++) msgTimer[i] = 0;
//    for (int i = 0; i < MAX_POWERUPS; i++) powerActive[i] = false;
//    for (int i = 0; i < MAX_EXPLOSIONS; i++) expActive[i] = false;
//    for (int i = 0; i < MAX_LASERS; i++) laserActive[i] = false;
//    for (int i = 0; i < MAX_SHARDS; i++) shardActive[i] = false;
//}
//
//void loadNextLevel(int bricks[ROWS][COLS], int hitFlash[ROWS][COLS], int& currentLevel, bool ballActive[MAX_BALLS], float ballX[MAX_BALLS], float ballY[MAX_BALLS], float ballSpeedX[MAX_BALLS], float ballSpeedY[MAX_BALLS], int ballFrostTimer[MAX_BALLS], float trailX[MAX_BALLS][TRAIL_LENGTH], float trailY[MAX_BALLS][TRAIL_LENGTH], float& paddleX, float& paddleWidth, int& combo, int& speedTimer, int& levelClearTimer, int& levelIntroTimer, bool& reverseControls, int& reverseTimer, int& paddleTimer, int& ballEffectTimer, int& ballEffectType, bool& ballStuck, int msgTimer[MAX_MSGS], bool powerActive[MAX_POWERUPS], bool expActive[MAX_EXPLOSIONS], bool laserActive[MAX_LASERS], bool shardActive[MAX_SHARDS], float baseBallSpeed) {
//    currentLevel = currentLevel + 1;
//    setupGrid(bricks, hitFlash, currentLevel);
//
//    paddleWidth = DEFAULT_PADDLE_WIDTH;
//    paddleX = 400.0f - (paddleWidth / 2.0f);
//
//    for (int i = 0; i < MAX_BALLS; i++) {
//        ballActive[i] = false;
//        ballFrostTimer[i] = 0;
//    }
//    ballActive[0] = true;
//    ballX[0] = paddleX + (paddleWidth / 2.0f) - BALL_RADIUS;
//    ballY[0] = 550.0f - (BALL_RADIUS * 2);
//
//    float levelSpeed = baseBallSpeed + (currentLevel - 1) * 0.45f;
//    if (levelSpeed > MAX_BALL_SPEED) levelSpeed = MAX_BALL_SPEED;
//    ballSpeedX[0] = levelSpeed;
//    ballSpeedY[0] = -levelSpeed;
//    initBallTrail(0, ballX[0], ballY[0], trailX, trailY);
//
//    combo = 0;
//    speedTimer = 0;
//    levelClearTimer = 0;
//    levelIntroTimer = 120;
//    reverseControls = false;
//    reverseTimer = 0;
//    paddleTimer = 0;
//    ballEffectTimer = 0;
//    ballEffectType = 0;
//    ballStuck = true;
//
//    for (int i = 0; i < MAX_MSGS; i++) msgTimer[i] = 0;
//    for (int i = 0; i < MAX_POWERUPS; i++) powerActive[i] = false;
//    for (int i = 0; i < MAX_EXPLOSIONS; i++) expActive[i] = false;
//    for (int i = 0; i < MAX_LASERS; i++) laserActive[i] = false;
//    for (int i = 0; i < MAX_SHARDS; i++) shardActive[i] = false;
//}
//
//void handleInput(float& paddleX, float paddleWidth, float paddleSpeed, bool reverseControls) {
//    if (!reverseControls) {
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
//            paddleX = paddleX - paddleSpeed;
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
//            paddleX = paddleX + paddleSpeed;
//        }
//    }
//    else {
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
//            paddleX = paddleX + paddleSpeed;
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
//            paddleX = paddleX - paddleSpeed;
//        }
//    }
//
//    if (paddleX < WALL_LEFT) paddleX = WALL_LEFT;
//    if (paddleX + paddleWidth > WALL_RIGHT) paddleX = WALL_RIGHT - paddleWidth;
//}
//
//void updatePowerUps(bool powerActive[MAX_POWERUPS], float powerX[MAX_POWERUPS], float powerY[MAX_POWERUPS], int powerType[MAX_POWERUPS], float paddleX, float paddleY, float& paddleWidth, int& lives, bool ballActive[MAX_BALLS], float ballX[MAX_BALLS], float ballY[MAX_BALLS], float ballSpeedX[MAX_BALLS], float ballSpeedY[MAX_BALLS], int ballFrostTimer[MAX_BALLS], float trailX[MAX_BALLS][TRAIL_LENGTH], float trailY[MAX_BALLS][TRAIL_LENGTH], bool& reverseControls, int& reverseTimer, int& paddleTimer, int& ballEffectTimer, int& ballEffectType, string msgText[MAX_MSGS], int msgTimer[MAX_MSGS], float msgY[MAX_MSGS], sf::Color msgColor[MAX_MSGS], float baseBallSpeed) {
//    for (int i = 0; i < MAX_MSGS; i++) {
//        if (msgTimer[i] > 0) {
//            msgTimer[i] = msgTimer[i] - 1;
//            msgY[i] = msgY[i] - 0.4f;
//        }
//    }
//
//    if (reverseControls) {
//        reverseTimer = reverseTimer - 1;
//        if (reverseTimer <= 0) {
//            reverseControls = false;
//        }
//    }
//
//    if (paddleTimer > 0) {
//        paddleTimer = paddleTimer - 1;
//        if (paddleTimer == 0) {
//            paddleWidth = DEFAULT_PADDLE_WIDTH;
//        }
//    }
//
//    if (ballEffectTimer > 0) {
//        ballEffectTimer = ballEffectTimer - 1;
//        if (ballEffectTimer == 0) {
//            for (int b = 0; b < MAX_BALLS; b++) {
//                if (ballActive[b]) {
//                    if (ballEffectType == 1) {
//                        ballSpeedX[b] = ballSpeedX[b] / 0.8f;
//                        ballSpeedY[b] = ballSpeedY[b] / 0.8f;
//                    }
//                    else if (ballEffectType == 2) {
//                        ballSpeedX[b] = ballSpeedX[b] / 1.25f;
//                        ballSpeedY[b] = ballSpeedY[b] / 1.25f;
//                    }
//                }
//            }
//            ballEffectType = 0;
//        }
//    }
//
//    for (int i = 0; i < MAX_POWERUPS; i++) {
//        if (powerActive[i]) {
//            powerY[i] = powerY[i] + 3.0f;
//
//            if (powerY[i] > 600.0f) {
//                powerActive[i] = false;
//            }
//            else if (powerX[i] + BRICK_WIDTH >= paddleX &&
//                powerX[i] <= paddleX + paddleWidth &&
//                powerY[i] + BRICK_HEIGHT >= paddleY &&
//                powerY[i] <= paddleY + PADDLE_HEIGHT) {
//
//                if (powerType[i] == 1) {
//                    paddleWidth = 150.0f;
//                    paddleTimer = 300;
//                    spawnMessage("WIDE PADDLE!", sf::Color::Cyan, msgText, msgTimer, msgY, msgColor);
//                }
//                else if (powerType[i] == 2) {
//                    lives = lives + 1;
//                    spawnMessage("EXTRA LIFE!", sf::Color::Green, msgText, msgTimer, msgY, msgColor);
//                }
//                else if (powerType[i] == 3) {
//                    for (int b = 0; b < MAX_BALLS; b++) {
//                        if (ballActive[b]) {
//                            if (ballEffectType == 2) {
//                                ballSpeedX[b] = ballSpeedX[b] / 1.25f;
//                                ballSpeedY[b] = ballSpeedY[b] / 1.25f;
//                            }
//                            if (ballEffectType != 1) {
//                                ballSpeedX[b] = ballSpeedX[b] * 0.8f;
//                                ballSpeedY[b] = ballSpeedY[b] * 0.8f;
//                            }
//                        }
//                    }
//                    ballEffectType = 1;
//                    ballEffectTimer = 300;
//                    spawnMessage("SLOW BALL!", sf::Color(100, 180, 255), msgText, msgTimer, msgY, msgColor);
//                }
//                else if (powerType[i] == 4) {
//                    paddleWidth = 60.0f;
//                    paddleTimer = 300;
//                    spawnMessage("SHRINK PADDLE!", sf::Color::Magenta, msgText, msgTimer, msgY, msgColor);
//                }
//                else if (powerType[i] == 5) {
//                    for (int b = 0; b < MAX_BALLS; b++) {
//                        if (ballActive[b]) {
//                            if (ballEffectType == 1) {
//                                ballSpeedX[b] = ballSpeedX[b] / 0.8f;
//                                ballSpeedY[b] = ballSpeedY[b] / 0.8f;
//                            }
//                            if (ballEffectType != 2) {
//                                if (ballSpeedX[b] > -MAX_BALL_SPEED && ballSpeedX[b] < MAX_BALL_SPEED) ballSpeedX[b] = ballSpeedX[b] * 1.25f;
//                                if (ballSpeedY[b] > -MAX_BALL_SPEED && ballSpeedY[b] < MAX_BALL_SPEED) ballSpeedY[b] = ballSpeedY[b] * 1.25f;
//                            }
//                        }
//                    }
//                    ballEffectType = 2;
//                    ballEffectTimer = 300;
//                    spawnMessage("FAST BALL!", sf::Color(255, 165, 0), msgText, msgTimer, msgY, msgColor);
//                }
//                else if (powerType[i] == 6) {
//                    reverseControls = true;
//                    reverseTimer = 300;
//                    spawnMessage("CONTROLS REVERSED!", sf::Color::Red, msgText, msgTimer, msgY, msgColor);
//                }
//                else if (powerType[i] == 7) {
//                    spawnExtraBalls(ballActive, ballX, ballY, ballSpeedX, ballSpeedY, ballFrostTimer, trailX, trailY, paddleX, paddleY, paddleWidth, baseBallSpeed);
//                    spawnMessage("MULTI-BALL!", sf::Color::White, msgText, msgTimer, msgY, msgColor);
//                }
//
//                powerActive[i] = false;
//            }
//        }
//    }
//}
//
//void updatePhysics(bool ballActive[MAX_BALLS], float ballX[MAX_BALLS], float ballY[MAX_BALLS], float ballSpeedX[MAX_BALLS], float ballSpeedY[MAX_BALLS], int ballFrostTimer[MAX_BALLS], float trailX[MAX_BALLS][TRAIL_LENGTH], float trailY[MAX_BALLS][TRAIL_LENGTH], bool shardActive[MAX_SHARDS], float shardX[MAX_SHARDS], float shardY[MAX_SHARDS], float shardVX[MAX_SHARDS], float shardVY[MAX_SHARDS], int shardTimer[MAX_SHARDS], float& paddleX, float paddleY, float paddleWidth, bool& ballStuck, int& lives, int& combo, int bricks[ROWS][COLS], int& gameState, bool& isWin, int& speedTimer, int& levelClearTimer, int& levelIntroTimer, int currentLevel) {
//    if (levelIntroTimer > 0) {
//        levelIntroTimer = levelIntroTimer - 1;
//    }
//
//    if (ballStuck) {
//        paddleX = 400.0f - (paddleWidth / 2.0f);
//        ballX[0] = paddleX + (paddleWidth / 2.0f) - BALL_RADIUS;
//        ballY[0] = paddleY - (BALL_RADIUS * 2);
//        initBallTrail(0, ballX[0], ballY[0], trailX, trailY);
//
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
//            ballStuck = false;
//        }
//        return;
//    }
//
//    speedTimer = speedTimer + 1;
//    if (speedTimer >= 300) {
//        speedTimer = 0;
//        for (int b = 0; b < MAX_BALLS; b++) {
//            if (ballActive[b]) {
//                if (ballSpeedX[b] > -MAX_BALL_SPEED && ballSpeedX[b] < MAX_BALL_SPEED) {
//                    ballSpeedX[b] = ballSpeedX[b] * 1.05f;
//                }
//                if (ballSpeedY[b] > -MAX_BALL_SPEED && ballSpeedY[b] < MAX_BALL_SPEED) {
//                    ballSpeedY[b] = ballSpeedY[b] * 1.05f;
//                }
//            }
//        }
//    }
//
//    int activeCount = 0;
//    float lastSpeedX = 5.0f;
//    float lastSpeedY = -5.0f;
//
//    for (int b = 0; b < MAX_BALLS; b++) {
//        if (ballActive[b]) {
//            if (ballFrostTimer[b] > 0) {
//                ballFrostTimer[b] = ballFrostTimer[b] - 1;
//                if (ballFrostTimer[b] == 0) {
//                    ballSpeedX[b] = ballSpeedX[b] / 0.75f;
//                    ballSpeedY[b] = ballSpeedY[b] / 0.75f;
//                    if (ballSpeedX[b] > MAX_BALL_SPEED) ballSpeedX[b] = MAX_BALL_SPEED;
//                    if (ballSpeedX[b] < -MAX_BALL_SPEED) ballSpeedX[b] = -MAX_BALL_SPEED;
//                    if (ballSpeedY[b] > MAX_BALL_SPEED) ballSpeedY[b] = MAX_BALL_SPEED;
//                    if (ballSpeedY[b] < -MAX_BALL_SPEED) ballSpeedY[b] = -MAX_BALL_SPEED;
//
//                    spawnIceShatter(ballX[b] + BALL_RADIUS, ballY[b] + BALL_RADIUS, shardActive, shardX, shardY, shardVX, shardVY, shardTimer);
//                }
//            }
//
//            for (int t = TRAIL_LENGTH - 1; t > 0; t--) {
//                trailX[b][t] = trailX[b][t - 1];
//                trailY[b][t] = trailY[b][t - 1];
//            }
//            trailX[b][0] = ballX[b];
//            trailY[b][0] = ballY[b];
//
//            ballX[b] = ballX[b] + ballSpeedX[b];
//            ballY[b] = ballY[b] + ballSpeedY[b];
//
//            if (ballX[b] <= WALL_LEFT) {
//                ballX[b] = WALL_LEFT;
//                ballSpeedX[b] = -ballSpeedX[b];
//            }
//            else if (ballX[b] + (BALL_RADIUS * 2) >= WALL_RIGHT) {
//                ballX[b] = WALL_RIGHT - (BALL_RADIUS * 2);
//                ballSpeedX[b] = -ballSpeedX[b];
//            }
//            if (ballY[b] <= WALL_TOP) {
//                ballY[b] = WALL_TOP;
//                ballSpeedY[b] = -ballSpeedY[b];
//            }
//
//            if (ballY[b] + (BALL_RADIUS * 2) >= 600.0f) {
//                if (ballFrostTimer[b] > 0) {
//                    ballSpeedX[b] = ballSpeedX[b] / 0.75f;
//                    ballSpeedY[b] = ballSpeedY[b] / 0.75f;
//                    ballFrostTimer[b] = 0;
//                }
//                lastSpeedX = ballSpeedX[b];
//                lastSpeedY = ballSpeedY[b];
//                ballActive[b] = false;
//            }
//            else {
//                activeCount = activeCount + 1;
//            }
//        }
//    }
//
//    if (activeCount == 0 && levelClearTimer == 0) {
//        lives = lives - 1;
//        combo = 0;
//
//        if (lives <= 0) {
//            gameState = 2;
//            isWin = false;
//        }
//        else {
//            paddleX = 400.0f - (paddleWidth / 2.0f);
//            ballActive[0] = true;
//            ballFrostTimer[0] = 0;
//            ballStuck = true;
//            ballX[0] = paddleX + (paddleWidth / 2.0f) - BALL_RADIUS;
//            ballY[0] = paddleY - (BALL_RADIUS * 2);
//            ballSpeedX[0] = lastSpeedX;
//            ballSpeedY[0] = lastSpeedY;
//            if (ballSpeedY[0] > 0.0f) {
//                ballSpeedY[0] = -ballSpeedY[0];
//            }
//            initBallTrail(0, ballX[0], ballY[0], trailX, trailY);
//        }
//    }
//
//    bool bricksLeft = false;
//    for (int i = 0; i < ROWS; i++) {
//        for (int j = 0; j < COLS; j++) {
//            if (bricks[i][j] > 0 && bricks[i][j] != 3) {
//                bricksLeft = true;
//            }
//        }
//    }
//
//    if (bricksLeft == false) {
//        if (levelClearTimer == 0) {
//            levelClearTimer = 60;
//        }
//        else {
//            levelClearTimer = levelClearTimer - 1;
//            if (levelClearTimer == 1) {
//                levelClearTimer = 0;
//                if (currentLevel < MAX_LEVELS) {
//                    gameState = 4;
//                }
//                else {
//                    gameState = 2;
//                    isWin = true;
//                }
//            }
//        }
//    }
//}
//
//void checkCollisions(bool ballActive[MAX_BALLS], float ballX[MAX_BALLS], float ballY[MAX_BALLS], float ballSpeedX[MAX_BALLS], float ballSpeedY[MAX_BALLS], int ballFrostTimer[MAX_BALLS], float paddleX, float paddleY, float paddleWidth, int bricks[ROWS][COLS], int hitFlash[ROWS][COLS], int& score, int& combo, bool powerActive[MAX_POWERUPS], float powerX[MAX_POWERUPS], float powerY[MAX_POWERUPS], int powerType[MAX_POWERUPS], int powerBrickType[MAX_POWERUPS], bool expActive[MAX_EXPLOSIONS], float expX[MAX_EXPLOSIONS], float expY[MAX_EXPLOSIONS], int expTimer[MAX_EXPLOSIONS], bool laserActive[MAX_LASERS], float laserY[MAX_LASERS], int laserTimer[MAX_LASERS]) {
//
//    for (int b = 0; b < MAX_BALLS; b++) {
//        if (!ballActive[b]) continue;
//
//        if (ballX[b] + (BALL_RADIUS * 2) >= paddleX &&
//            ballX[b] <= paddleX + paddleWidth &&
//            ballY[b] + (BALL_RADIUS * 2) >= paddleY &&
//            ballY[b] <= paddleY + PADDLE_HEIGHT) {
//
//            float overlapLeft = (ballX[b] + (BALL_RADIUS * 2)) - paddleX;
//            float overlapRight = (paddleX + paddleWidth) - ballX[b];
//            float overlapTop = (ballY[b] + (BALL_RADIUS * 2)) - paddleY;
//            float overlapBottom = (paddleY + PADDLE_HEIGHT) - ballY[b];
//
//            float minOverlapX = overlapLeft;
//            if (overlapRight < minOverlapX) minOverlapX = overlapRight;
//
//            float minOverlapY = overlapTop;
//            if (overlapBottom < minOverlapY) minOverlapY = overlapBottom;
//
//            if (minOverlapX < minOverlapY) {
//                if (overlapLeft < overlapRight) {
//                    ballX[b] = paddleX - (BALL_RADIUS * 2);
//                    if (ballSpeedX[b] > 0.0f) ballSpeedX[b] = -ballSpeedX[b];
//                }
//                else {
//                    ballX[b] = paddleX + paddleWidth;
//                    if (ballSpeedX[b] < 0.0f) ballSpeedX[b] = -ballSpeedX[b];
//                }
//            }
//            else {
//                if (overlapTop < overlapBottom) {
//                    ballY[b] = paddleY - (BALL_RADIUS * 2);
//                    if (ballSpeedY[b] > 0.0f) ballSpeedY[b] = -ballSpeedY[b];
//                }
//                else {
//                    ballY[b] = paddleY + PADDLE_HEIGHT;
//                    if (ballSpeedY[b] < 0.0f) ballSpeedY[b] = -ballSpeedY[b];
//                }
//            }
//
//            combo = 0;
//        }
//
//        bool collisionOccurred = false;
//
//        for (int i = 0; i < ROWS; i++) {
//            if (collisionOccurred) break;
//
//            for (int j = 0; j < COLS; j++) {
//                if (bricks[i][j] > 0) {
//                    float currentBrickX = OFFSET_X + (j * (BRICK_WIDTH + BRICK_SPACING));
//                    float currentBrickY = OFFSET_Y + (i * (BRICK_HEIGHT + BRICK_SPACING));
//
//                    if (ballX[b] + (BALL_RADIUS * 2) >= currentBrickX &&
//                        ballX[b] <= currentBrickX + BRICK_WIDTH &&
//                        ballY[b] + (BALL_RADIUS * 2) >= currentBrickY &&
//                        ballY[b] <= currentBrickY + BRICK_HEIGHT) {
//
//                        float overlapLeft = (ballX[b] + (BALL_RADIUS * 2)) - currentBrickX;
//                        float overlapRight = (currentBrickX + BRICK_WIDTH) - ballX[b];
//                        float overlapTop = (ballY[b] + (BALL_RADIUS * 2)) - currentBrickY;
//                        float overlapBottom = (currentBrickY + BRICK_HEIGHT) - ballY[b];
//
//                        float minOverlapX = overlapLeft;
//                        if (overlapRight < minOverlapX) minOverlapX = overlapRight;
//
//                        float minOverlapY = overlapTop;
//                        if (overlapBottom < minOverlapY) minOverlapY = overlapBottom;
//
//                        if (minOverlapX < minOverlapY) {
//                            if (overlapLeft < overlapRight) {
//                                ballX[b] = currentBrickX - (BALL_RADIUS * 2);
//                                if (ballSpeedX[b] > 0.0f) ballSpeedX[b] = -ballSpeedX[b];
//                            }
//                            else {
//                                ballX[b] = currentBrickX + BRICK_WIDTH;
//                                if (ballSpeedX[b] < 0.0f) ballSpeedX[b] = -ballSpeedX[b];
//                            }
//                        }
//                        else {
//                            if (overlapTop < overlapBottom) {
//                                ballY[b] = currentBrickY - (BALL_RADIUS * 2);
//                                if (ballSpeedY[b] > 0.0f) ballSpeedY[b] = -ballSpeedY[b];
//                            }
//                            else {
//                                ballY[b] = currentBrickY + BRICK_HEIGHT;
//                                if (ballSpeedY[b] < 0.0f) ballSpeedY[b] = -ballSpeedY[b];
//                            }
//                        }
//
//                        if (bricks[i][j] == 1) {
//                            bricks[i][j] = 0;
//                            combo = combo + 1;
//                            score = score + 10 + (combo * 5);
//                            spawnPowerUp(currentBrickX, currentBrickY, 1, powerActive, powerX, powerY, powerType, powerBrickType);
//                        }
//                        else if (bricks[i][j] == 2) {
//                            bricks[i][j] = 8;
//                            hitFlash[i][j] = 6;
//                            combo = combo + 1;
//                            score = score + 5 + (combo * 5);
//                        }
//                        else if (bricks[i][j] == 8) {
//                            bricks[i][j] = 9;
//                            hitFlash[i][j] = 6;
//                            combo = combo + 1;
//                            score = score + 5 + (combo * 5);
//                        }
//                        else if (bricks[i][j] == 9) {
//                            bricks[i][j] = 10;
//                            hitFlash[i][j] = 6;
//                            combo = combo + 1;
//                            score = score + 5 + (combo * 5);
//                        }
//                        else if (bricks[i][j] == 10) {
//                            bricks[i][j] = 0;
//                            combo = combo + 1;
//                            score = score + 15 + (combo * 5);
//                            spawnPowerUp(currentBrickX, currentBrickY, 2, powerActive, powerX, powerY, powerType, powerBrickType);
//                        }
//                        else if (bricks[i][j] == 3) {
//                            hitFlash[i][j] = 6;
//                        }
//                        else if (bricks[i][j] == 4) {
//                            bricks[i][j] = 0;
//                            combo = combo + 1;
//                            score = score + 10 + (combo * 5);
//                            spawnPowerUp(currentBrickX, currentBrickY, 4, powerActive, powerX, powerY, powerType, powerBrickType);
//                            spawnExplosion(currentBrickX + (BRICK_WIDTH / 2.0f), currentBrickY + (BRICK_HEIGHT / 2.0f), expActive, expX, expY, expTimer);
//
//                            for (int r = i - 1; r <= i + 1; r++) {
//                                for (int c = j - 1; c <= j + 1; c++) {
//                                    if (r >= 0 && r < ROWS && c >= 0 && c < COLS) {
//                                        if (bricks[r][c] > 0 && bricks[r][c] != 3) {
//                                            bricks[r][c] = 0;
//                                            score = score + 10;
//                                        }
//                                    }
//                                }
//                            }
//                        }
//                        else if (bricks[i][j] == 6) {
//                            bricks[i][j] = 0;
//                            combo = combo + 1;
//                            score = score + 25 + (combo * 5);
//                            spawnPowerUp(currentBrickX, currentBrickY, 6, powerActive, powerX, powerY, powerType, powerBrickType);
//
//                            if (ballFrostTimer[b] == 0) {
//                                ballSpeedX[b] = ballSpeedX[b] * 0.75f;
//                                ballSpeedY[b] = ballSpeedY[b] * 0.75f;
//                            }
//                            ballFrostTimer[b] = 180;
//                        }
//                        else if (bricks[i][j] == 7) {
//                            bricks[i][j] = 0;
//                            combo = combo + 1;
//                            score = score + 10 + (combo * 5);
//                            spawnPowerUp(currentBrickX, currentBrickY, 7, powerActive, powerX, powerY, powerType, powerBrickType);
//                            spawnLaser(currentBrickY + (BRICK_HEIGHT / 2.0f), laserActive, laserY, laserTimer);
//
//                            for (int c = 0; c < COLS; c++) {
//                                if (bricks[i][c] > 0 && bricks[i][c] != 3) {
//                                    bricks[i][c] = 0;
//                                    score = score + 10;
//                                }
//                            }
//                        }
//
//                        collisionOccurred = true;
//                        break;
//                    }
//                }
//            }
//        }
//    }
//}
//
//void renderFrame(sf::RenderWindow& window, sf::Font& font, sf::RectangleShape& titleBgShape, sf::RectangleShape& bgShape, sf::RectangleShape& paddle, sf::CircleShape& ballShape, sf::RectangleShape& brickShape, sf::RectangleShape& powerShape, sf::Texture& redTex, sf::Texture& greenTex, sf::Texture& grayTex, sf::Texture& yellowTex, sf::Texture& blueTex, sf::Texture& orangeTex, int bricks[ROWS][COLS], int hitFlash[ROWS][COLS], bool ballActive[MAX_BALLS], float ballX[MAX_BALLS], float ballY[MAX_BALLS], float ballSpeedX[MAX_BALLS], int ballFrostTimer[MAX_BALLS], float trailX[MAX_BALLS][TRAIL_LENGTH], float trailY[MAX_BALLS][TRAIL_LENGTH], bool powerActive[MAX_POWERUPS], float powerX[MAX_POWERUPS], float powerY[MAX_POWERUPS], int powerBrickType[MAX_POWERUPS], bool expActive[MAX_EXPLOSIONS], float expX[MAX_EXPLOSIONS], float expY[MAX_EXPLOSIONS], int expTimer[MAX_EXPLOSIONS], bool laserActive[MAX_LASERS], float laserY[MAX_LASERS], int laserTimer[MAX_LASERS], bool shardActive[MAX_SHARDS], float shardX[MAX_SHARDS], float shardY[MAX_SHARDS], float shardVX[MAX_SHARDS], float shardVY[MAX_SHARDS], int shardTimer[MAX_SHARDS], int score, int combo, int lives, int currentLevel, int levelClearTimer, int levelIntroTimer, int gameState, int menuOption, bool hardMode, bool fastPaddle, bool isWin, int highScore, int prevScore, bool reverseControls, bool ballStuck, string msgText[MAX_MSGS], int msgTimer[MAX_MSGS], float msgY[MAX_MSGS], sf::Color msgColor[MAX_MSGS]) {
//
//    window.clear(sf::Color::Black);
//
//    if (gameState == 0) {
//        window.draw(titleBgShape);
//
//        sf::RectangleShape highlight({ btnW[menuOption], btnH[menuOption] });
//        highlight.setPosition({ btnX[menuOption], btnY[menuOption] });
//        highlight.setFillColor(sf::Color(255, 255, 255, 45));
//        highlight.setOutlineColor(sf::Color::Yellow);
//        highlight.setOutlineThickness(4.0f);
//        window.draw(highlight);
//    }
//    else {
//        window.draw(bgShape);
//
//        if (gameState == 1) {
//            drawStyledText(window, font, "Score: " + to_string(score), 20, sf::Color::White, 38.0f, 26.0f);
//            drawStyledText(window, font, "Level: " + to_string(currentLevel), 20, sf::Color::Cyan, 200.0f, 26.0f);
//            drawStyledText(window, font, "Lives: " + to_string(lives), 20, sf::Color::White, 675.0f, 26.0f);
//
//            if (combo > 1) {
//                drawStyledText(window, font, "Combo: x" + to_string(combo), 20, sf::Color::Yellow, 530.0f, 26.0f);
//            }
//
//            if (reverseControls) {
//                drawStyledText(window, font, "REVERSED!", 20, sf::Color::Red, 340.0f, 26.0f);
//            }
//
//            if (ballStuck) {
//                drawStyledText(window, font, "Press SPACE to Launch", 26, sf::Color::Yellow, 245.0f, 365.0f);
//            }
//
//            for (int i = 0; i < ROWS; i++) {
//                for (int j = 0; j < COLS; j++) {
//                    if (bricks[i][j] > 0) {
//                        if (hitFlash[i][j] > 0) {
//                            brickShape.setTexture(nullptr);
//                            brickShape.setFillColor(sf::Color::White);
//                            hitFlash[i][j] = hitFlash[i][j] - 1;
//                        }
//                        else {
//                            brickShape.setFillColor(sf::Color::White);
//                            if (bricks[i][j] == 1) brickShape.setTexture(&redTex);
//                            else if (bricks[i][j] == 2) {
//                                brickShape.setTexture(&greenTex);
//                                brickShape.setFillColor(sf::Color(255, 255, 255));
//                            }
//                            else if (bricks[i][j] == 8) {
//                                brickShape.setTexture(&greenTex);
//                                brickShape.setFillColor(sf::Color(210, 210, 210));
//                            }
//                            else if (bricks[i][j] == 9) {
//                                brickShape.setTexture(&greenTex);
//                                brickShape.setFillColor(sf::Color(165, 165, 165));
//                            }
//                            else if (bricks[i][j] == 10) {
//                                brickShape.setTexture(&greenTex);
//                                brickShape.setFillColor(sf::Color(120, 120, 120));
//                            }
//                            else if (bricks[i][j] == 3) brickShape.setTexture(&grayTex);
//                            else if (bricks[i][j] == 4) brickShape.setTexture(&yellowTex);
//                            else if (bricks[i][j] == 6) brickShape.setTexture(&blueTex);
//                            else if (bricks[i][j] == 7) brickShape.setTexture(&orangeTex);
//                        }
//
//                        float currentBrickX = OFFSET_X + (j * (BRICK_WIDTH + BRICK_SPACING));
//                        float currentBrickY = OFFSET_Y + (i * (BRICK_HEIGHT + BRICK_SPACING));
//
//                        brickShape.setPosition({ currentBrickX, currentBrickY });
//                        window.draw(brickShape);
//                    }
//                }
//            }
//
//            sf::CircleShape expShape;
//            for (int i = 0; i < MAX_EXPLOSIONS; i++) {
//                if (expActive[i]) {
//                    float progress = 1.0f - (float)expTimer[i] / 20.0f;
//
//                    float outerR = 15.0f + (progress * 80.0f);
//                    unsigned char outerAlpha = (unsigned char)(220 * (1.0f - progress));
//                    expShape.setRadius(outerR);
//                    expShape.setFillColor(sf::Color(255, 120, 0, outerAlpha));
//                    expShape.setPosition({ expX[i] - outerR, expY[i] - outerR });
//                    window.draw(expShape);
//
//                    float innerR = 10.0f + (progress * 45.0f);
//                    unsigned char innerAlpha = (unsigned char)(255 * (1.0f - progress));
//                    expShape.setRadius(innerR);
//                    expShape.setFillColor(sf::Color(255, 255, 100, innerAlpha));
//                    expShape.setPosition({ expX[i] - innerR, expY[i] - innerR });
//                    window.draw(expShape);
//
//                    expTimer[i] = expTimer[i] - 1;
//                    if (expTimer[i] <= 0) {
//                        expActive[i] = false;
//                    }
//                }
//            }
//
//            sf::RectangleShape laserBeam;
//            for (int i = 0; i < MAX_LASERS; i++) {
//                if (laserActive[i]) {
//                    float ratio = (float)laserTimer[i] / 18.0f;
//                    float beamWidth = WALL_RIGHT - WALL_LEFT;
//
//                    float outerH = 16.0f * ratio;
//                    unsigned char outerAlpha = (unsigned char)(230 * ratio);
//                    laserBeam.setSize({ beamWidth, outerH });
//                    laserBeam.setFillColor(sf::Color(255, 30, 30, outerAlpha));
//                    laserBeam.setPosition({ WALL_LEFT, laserY[i] - (outerH / 2.0f) });
//                    window.draw(laserBeam);
//
//                    float innerH = 6.0f * ratio;
//                    unsigned char innerAlpha = (unsigned char)(255 * ratio);
//                    laserBeam.setSize({ beamWidth, innerH });
//                    laserBeam.setFillColor(sf::Color(255, 220, 220, innerAlpha));
//                    laserBeam.setPosition({ WALL_LEFT, laserY[i] - (innerH / 2.0f) });
//                    window.draw(laserBeam);
//
//                    laserTimer[i] = laserTimer[i] - 1;
//                    if (laserTimer[i] <= 0) {
//                        laserActive[i] = false;
//                    }
//                }
//            }
//
//            sf::RectangleShape shardShape;
//            for (int i = 0; i < MAX_SHARDS; i++) {
//                if (shardActive[i]) {
//                    shardX[i] = shardX[i] + shardVX[i];
//                    shardY[i] = shardY[i] + shardVY[i];
//                    shardVY[i] = shardVY[i] + 0.15f;
//
//                    float ratio = (float)shardTimer[i] / 22.0f;
//                    float sz = 6.0f * ratio;
//                    unsigned char alpha = (unsigned char)(255 * ratio);
//
//                    shardShape.setSize({ sz, sz });
//                    shardShape.setFillColor(sf::Color(170, 240, 255, alpha));
//                    shardShape.setOutlineColor(sf::Color(255, 255, 255, alpha));
//                    shardShape.setOutlineThickness(1.0f);
//                    shardShape.setPosition({ shardX[i] - (sz / 2.0f), shardY[i] - (sz / 2.0f) });
//                    window.draw(shardShape);
//
//                    shardTimer[i] = shardTimer[i] - 1;
//                    if (shardTimer[i] <= 0) {
//                        shardActive[i] = false;
//                    }
//                }
//            }
//
//            for (int i = 0; i < MAX_POWERUPS; i++) {
//                if (powerActive[i]) {
//                    powerShape.setFillColor(sf::Color::White);
//                    if (powerBrickType[i] == 1) powerShape.setTexture(&redTex);
//                    else if (powerBrickType[i] == 2) powerShape.setTexture(&greenTex);
//                    else if (powerBrickType[i] == 4) powerShape.setTexture(&yellowTex);
//                    else if (powerBrickType[i] == 6) powerShape.setTexture(&blueTex);
//                    else if (powerBrickType[i] == 7) powerShape.setTexture(&orangeTex);
//
//                    powerShape.setPosition({ powerX[i], powerY[i] });
//                    window.draw(powerShape);
//                }
//            }
//
//            sf::CircleShape trailShape;
//            sf::CircleShape iceShell(BALL_RADIUS + 3.0f, 6);
//            for (int b = 0; b < MAX_BALLS; b++) {
//                if (ballActive[b]) {
//                    bool isFrozen = (ballFrostTimer[b] > 0);
//
//                    float speed = ballSpeedX[b];
//                    if (speed < 0.0f) speed = -speed;
//
//                    float heat = (speed - 5.5f) / 3.0f;
//                    if (heat < 0.0f) heat = 0.0f;
//                    if (heat > 1.0f) heat = 1.0f;
//
//                    for (int t = TRAIL_LENGTH - 1; t > 0; t--) {
//                        for (int step = 0; step < 3; step++) {
//                            float frac = (float)step / 3.0f;
//                            float interpX = trailX[b][t] + (trailX[b][t - 1] - trailX[b][t]) * frac;
//                            float interpY = trailY[b][t] + (trailY[b][t - 1] - trailY[b][t]) * frac;
//
//                            float ratio = 1.0f - ((float)t - frac) / TRAIL_LENGTH;
//
//                            if (isFrozen) {
//                                float r = BALL_RADIUS * 0.85f * ratio;
//                                unsigned char alpha = (unsigned char)(70 * ratio * ratio);
//                                trailShape.setRadius(r);
//                                trailShape.setFillColor(sf::Color(130, 225, 255, alpha));
//                                trailShape.setPosition({ interpX + BALL_RADIUS - r, interpY + BALL_RADIUS - r });
//                                window.draw(trailShape);
//                            }
//                            else {
//                                float r = BALL_RADIUS * (0.75f + heat * 0.4f) * ratio;
//
//                                float jitterX = 0.0f;
//                                float jitterY = 0.0f;
//                                if (heat > 0.15f) {
//                                    jitterX = ((rand() % 7) - 3) * heat;
//                                    jitterY = ((rand() % 7) - 3) * heat;
//                                }
//
//                                unsigned char red = 255;
//                                unsigned char green = (unsigned char)(255 - heat * (1.0f - ratio * 0.55f) * 210);
//                                unsigned char blue = (unsigned char)(255 - heat * 255);
//                                unsigned char alpha = (unsigned char)((45 + heat * 45) * ratio * ratio);
//
//                                trailShape.setRadius(r);
//                                trailShape.setFillColor(sf::Color(red, green, blue, alpha));
//
//                                float centerX = interpX + BALL_RADIUS + jitterX;
//                                float centerY = interpY + BALL_RADIUS + jitterY;
//                                trailShape.setPosition({ centerX - r, centerY - r });
//                                window.draw(trailShape);
//                            }
//                        }
//                    }
//
//                    if (!isFrozen && heat > 0.2f) {
//                        float glowR = BALL_RADIUS * (1.1f + heat * 0.45f) + (rand() % 3);
//                        unsigned char glowAlpha = (unsigned char)(100 * heat);
//                        trailShape.setRadius(glowR);
//                        trailShape.setFillColor(sf::Color(255, 110, 0, glowAlpha));
//                        trailShape.setPosition({ ballX[b] + BALL_RADIUS - glowR, ballY[b] + BALL_RADIUS - glowR });
//                        window.draw(trailShape);
//                    }
//
//                    if (isFrozen) {
//                        ballShape.setFillColor(sf::Color(160, 230, 255));
//                    }
//                    else {
//                        ballShape.setFillColor(sf::Color::White);
//                    }
//
//                    ballShape.setPosition({ ballX[b], ballY[b] });
//                    window.draw(ballShape);
//
//                    if (isFrozen) {
//                        iceShell.setFillColor(sf::Color(150, 235, 255, 120));
//                        iceShell.setOutlineColor(sf::Color(220, 250, 255, 220));
//                        iceShell.setOutlineThickness(2.0f);
//                        iceShell.setPosition({ ballX[b] - 3.0f, ballY[b] - 3.0f });
//                        window.draw(iceShell);
//                    }
//                }
//            }
//
//            window.draw(paddle);
//
//            for (int i = 0; i < MAX_MSGS; i++) {
//                if (msgTimer[i] > 0) {
//                    unsigned char fadeAlpha = (unsigned char)(255.0f * ((float)msgTimer[i] / 90.0f));
//                    float centerX = 400.0f - (msgText[i].length() * 9.0f);
//                    drawStyledText(window, font, msgText[i], 28, msgColor[i], centerX, msgY[i], fadeAlpha);
//                }
//            }
//
//            if (levelIntroTimer > 0) {
//                unsigned char introAlpha = 255;
//                if (levelIntroTimer > 90) {
//                    introAlpha = (unsigned char)(255.0f * (120 - levelIntroTimer) / 30.0f);
//                }
//                else if (levelIntroTimer < 30) {
//                    introAlpha = (unsigned char)(255.0f * levelIntroTimer / 30.0f);
//                }
//
//                string title = levelNames[currentLevel - 1];
//                float centerX = 400.0f - (title.length() * 10.5f);
//                drawStyledText(window, font, title, 34, sf::Color::Cyan, centerX, 275.0f, introAlpha);
//            }
//
//            if (levelClearTimer > 0) {
//                drawStyledText(window, font, "LEVEL CLEAR!", 45, sf::Color::Green, 235.0f, 260.0f);
//            }
//        }
//        else if (gameState == 2) {
//            if (isWin) {
//                drawStyledText(window, font, "YOU WIN!", 60, sf::Color::Green, 240.0f, 190.0f);
//            }
//            else {
//                drawStyledText(window, font, "YOU LOSE!", 60, sf::Color::Red, 230.0f, 190.0f);
//            }
//            drawStyledText(window, font, "Final Score: " + to_string(score), 30, sf::Color::White, 285.0f, 300.0f);
//            drawStyledText(window, font, "Press ENTER to return to Menu", 24, sf::Color::Yellow, 210.0f, 400.0f);
//        }
//        else if (gameState == 3) {
//            drawStyledText(window, font, "PAUSED", 60, sf::Color::Yellow, 270.0f, 180.0f);
//            drawStyledText(window, font, "Press P to Resume", 26, sf::Color::White, 275.0f, 300.0f);
//            drawStyledText(window, font, "Press M for Main Menu", 26, sf::Color::Cyan, 250.0f, 355.0f);
//        }
//        else if (gameState == 4) {
//            drawStyledText(window, font, "LEVEL " + to_string(currentLevel) + " COMPLETE!", 44, sf::Color::Green, 165.0f, 160.0f);
//            drawStyledText(window, font, "Score: " + to_string(score), 30, sf::Color::White, 315.0f, 250.0f);
//            drawStyledText(window, font, "Press ENTER for Next Level", 25, sf::Color::Yellow, 225.0f, 340.0f);
//            drawStyledText(window, font, "Press M for Main Menu", 25, sf::Color::White, 255.0f, 395.0f);
//        }
//        else if (gameState == 5) {
//            drawStyledText(window, font, "HIGH SCORES", 52, sf::Color::Yellow, 215.0f, 135.0f);
//            drawStyledText(window, font, "Best Score: " + to_string(highScore), 34, sf::Color::White, 255.0f, 245.0f);
//            drawStyledText(window, font, "Previous Score: " + to_string(prevScore), 30, sf::Color::Cyan, 230.0f, 315.0f);
//            drawStyledText(window, font, "Press M or ESC to go Back", 24, sf::Color::Yellow, 235.0f, 435.0f);
//        }
//        else if (gameState == 6) {
//            drawStyledText(window, font, "SETTINGS", 52, sf::Color::Cyan, 265.0f, 130.0f);
//
//            string diffStr = "NORMAL";
//            if (hardMode) diffStr = "HARD (Fast Ball)";
//
//            string padStr = "NORMAL";
//            if (fastPaddle) padStr = "FAST";
//
//            drawStyledText(window, font, "Press 1 - Difficulty: " + diffStr, 26, sf::Color::Yellow, 175.0f, 250.0f);
//            drawStyledText(window, font, "Press 2 - Paddle Speed: " + padStr, 26, sf::Color::White, 175.0f, 320.0f);
//            drawStyledText(window, font, "Press M or ESC to go Back", 24, sf::Color::Cyan, 235.0f, 440.0f);
//        }
//    }
//
//    window.display();
//}
//
//int main() {
//    srand(time(0));
//
//    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Brick Breaker");
//    window.setFramerateLimit(60);
//
//    sf::Font font;
//    if (!font.openFromFile("arial.ttf")) {
//        cout << "Error loading font!" << endl;
//        return -1;
//    }
//
//    sf::Texture titleTex, bgTex, ballTex, paddleTex, redTex, greenTex, grayTex, yellowTex, blueTex, orangeTex;
//    if (!titleTex.loadFromFile("title.jpg")) cout << "Error loading title.jpg" << endl;
//    if (!bgTex.loadFromFile("background.jpg")) cout << "Error loading background.jpg" << endl;
//    if (!ballTex.loadFromFile("Ball.png")) cout << "Error loading Ball.png" << endl;
//    if (!paddleTex.loadFromFile("Paddle.png")) cout << "Error loading Paddle.png" << endl;
//    if (!redTex.loadFromFile("Brick-Red.png")) cout << "Error loading Brick-Red.png" << endl;
//    if (!greenTex.loadFromFile("Brick-Green.png")) cout << "Error loading Brick-Green.png" << endl;
//    if (!grayTex.loadFromFile("Brick-Gray.png")) cout << "Error loading Brick-Gray.png" << endl;
//    if (!yellowTex.loadFromFile("Brick-Yellow.png")) cout << "Error loading Brick-Yellow.png" << endl;
//    if (!blueTex.loadFromFile("Brick-Blue.png")) cout << "Error loading Brick-Blue.png" << endl;
//    if (!orangeTex.loadFromFile("Brick-Orange.png")) cout << "Error loading Brick-Orange.png" << endl;
//
//    sf::Music bgm;
//    if (!bgm.openFromFile("theme.ogg")) {
//        cout << "Error loading theme.ogg" << endl;
//    }
//    else {
//        bgm.setLooping(true);
//        bgm.setVolume(40.0f);
//        bgm.play();
//    }
//    int gameState = 0;
//    int menuOption = 0; 
//    bool hardMode = false;
//    bool fastPaddle = false;
//    bool isWin = false;
//    int highScore = 0;
//    int prevScore = 0;
//    bool scoreSaved = false;
//    int currentLevel = 1;
//
//    ifstream inputFile("highscore.txt");
//    if (inputFile.is_open()) {
//        inputFile >> highScore;
//        inputFile >> prevScore;
//        inputFile.close();
//    }
//
//    int score = 0;
//    int combo = 0;
//    int lives = 3;
//    int speedTimer = 0;
//    int levelClearTimer = 0;
//    int levelIntroTimer = 0;
//    bool reverseControls = false;
//    int reverseTimer = 0;
//    int paddleTimer = 0;
//    int ballEffectTimer = 0;
//    int ballEffectType = 0;
//    bool ballStuck = true;
//
//    string msgText[MAX_MSGS];
//    int msgTimer[MAX_MSGS];
//    float msgY[MAX_MSGS];
//    sf::Color msgColor[MAX_MSGS];
//    for (int i = 0; i < MAX_MSGS; i++) {
//        msgText[i] = "";
//        msgTimer[i] = 0;
//        msgY[i] = 300.0f;
//        msgColor[i] = sf::Color::White;
//    }
//
//    int bricks[ROWS][COLS];
//    int hitFlash[ROWS][COLS];
//    float paddleX = 350.0f;
//    float paddleY = 550.0f;
//    float paddleWidth = DEFAULT_PADDLE_WIDTH;
//
//    bool ballActive[MAX_BALLS];
//    float ballX[MAX_BALLS];
//    float ballY[MAX_BALLS];
//    float ballSpeedX[MAX_BALLS];
//    float ballSpeedY[MAX_BALLS];
//    int ballFrostTimer[MAX_BALLS];
//    float trailX[MAX_BALLS][TRAIL_LENGTH];
//    float trailY[MAX_BALLS][TRAIL_LENGTH];
//    for (int i = 0; i < MAX_BALLS; i++) {
//        ballActive[i] = false;
//        ballSpeedX[i] = 5.0f;
//        ballSpeedY[i] = -5.0f;
//        ballFrostTimer[i] = 0;
//        initBallTrail(i, 390.0f, 520.0f, trailX, trailY);
//    }
//
//    bool powerActive[MAX_POWERUPS];
//    float powerX[MAX_POWERUPS];
//    float powerY[MAX_POWERUPS];
//    int powerType[MAX_POWERUPS];
//    int powerBrickType[MAX_POWERUPS];
//    for (int i = 0; i < MAX_POWERUPS; i++) {
//        powerActive[i] = false;
//        powerBrickType[i] = 1;
//    }
//
//    bool expActive[MAX_EXPLOSIONS];
//    float expX[MAX_EXPLOSIONS];
//    float expY[MAX_EXPLOSIONS];
//    int expTimer[MAX_EXPLOSIONS];
//    for (int i = 0; i < MAX_EXPLOSIONS; i++) {
//        expActive[i] = false;
//    }
//
//    bool laserActive[MAX_LASERS];
//    float laserY[MAX_LASERS];
//    int laserTimer[MAX_LASERS];
//    for (int i = 0; i < MAX_LASERS; i++) {
//        laserActive[i] = false;
//    }
//
//    bool shardActive[MAX_SHARDS];
//    float shardX[MAX_SHARDS];
//    float shardY[MAX_SHARDS];
//    float shardVX[MAX_SHARDS];
//    float shardVY[MAX_SHARDS];
//    int shardTimer[MAX_SHARDS];
//    for (int i = 0; i < MAX_SHARDS; i++) {
//        shardActive[i] = false;
//    }
//
//    sf::RectangleShape titleBgShape({ 800.0f, 600.0f });
//    titleBgShape.setTexture(&titleTex);
//
//    sf::RectangleShape bgShape({ 800.0f, 600.0f });
//    bgShape.setTexture(&bgTex);
//
//    sf::RectangleShape brickShape({ BRICK_WIDTH, BRICK_HEIGHT });
//    sf::RectangleShape powerShape({ BRICK_WIDTH, BRICK_HEIGHT });
//
//    sf::RectangleShape paddle({ paddleWidth, PADDLE_HEIGHT });
//    paddle.setTexture(&paddleTex);
//    paddle.setFillColor(sf::Color::White);
//
//    sf::CircleShape ballShape(BALL_RADIUS);
//    ballShape.setTexture(&ballTex);
//    ballShape.setFillColor(sf::Color::White);
//
//    setupGrid(bricks, hitFlash, currentLevel);
//
//    while (window.isOpen()) {
//        while (const optional<sf::Event> event = window.pollEvent()) {
//            if (event->is<sf::Event::Closed>()) {
//                window.close();
//            }
//        }
//
//        float baseBallSpeed = 5.0f;
//        if (hardMode) baseBallSpeed = 6.5f;
//
//        float paddleSpeed = 8.0f;
//        if (fastPaddle) paddleSpeed = 11.0f;
//
//        if (gameState == 0) {
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
//                menuOption = menuOption - 1;
//                if (menuOption < 0) menuOption = 3;
//                sf::sleep(sf::milliseconds(150));
//            }
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
//                menuOption = menuOption + 1;
//                if (menuOption > 3) menuOption = 0;
//                sf::sleep(sf::milliseconds(150));
//            }
//
//            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//            bool mouseClicked = false;
//            for (int i = 0; i < 4; i++) {
//                if (mousePos.x >= btnX[i] && mousePos.x <= btnX[i] + btnW[i] &&
//                    mousePos.y >= btnY[i] && mousePos.y <= btnY[i] + btnH[i]) {
//                    menuOption = i;
//                    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
//                        mouseClicked = true;
//                    }
//                }
//            }
//
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) || mouseClicked) {
//                if (menuOption == 0) {
//                    resetGame(bricks, hitFlash, currentLevel, ballActive, ballX, ballY, ballSpeedX, ballSpeedY, ballFrostTimer, trailX, trailY, paddleX, paddleWidth, lives, score, combo, speedTimer, levelClearTimer, levelIntroTimer, reverseControls, reverseTimer, paddleTimer, ballEffectTimer, ballEffectType, ballStuck, msgTimer, powerActive, expActive, laserActive, shardActive, baseBallSpeed);
//                    scoreSaved = false;
//                    gameState = 1;
//                }
//                else if (menuOption == 1) {
//                    gameState = 5;
//                }
//                else if (menuOption == 2) {
//                    gameState = 6;
//                }
//                else if (menuOption == 3) {
//                    window.close();
//                }
//                sf::sleep(sf::milliseconds(200));
//            }
//        }
//        else if (gameState == 1) {
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {
//                bgm.pause();
//                gameState = 3;
//                sf::sleep(sf::milliseconds(200));
//            }
//            else {
//                if (!ballStuck) {
//                    handleInput(paddleX, paddleWidth, paddleSpeed, reverseControls);
//                }
//                updatePhysics(ballActive, ballX, ballY, ballSpeedX, ballSpeedY, ballFrostTimer, trailX, trailY, shardActive, shardX, shardY, shardVX, shardVY, shardTimer, paddleX, paddleY, paddleWidth, ballStuck, lives, combo, bricks, gameState, isWin, speedTimer, levelClearTimer, levelIntroTimer, currentLevel);
//
//                if (gameState == 1) {
//                    if (!ballStuck) {
//                        checkCollisions(ballActive, ballX, ballY, ballSpeedX, ballSpeedY, ballFrostTimer, paddleX, paddleY, paddleWidth, bricks, hitFlash, score, combo, powerActive, powerX, powerY, powerType, powerBrickType, expActive, expX, expY, expTimer, laserActive, laserY, laserTimer);
//                    }
//                    updatePowerUps(powerActive, powerX, powerY, powerType, paddleX, paddleY, paddleWidth, lives, ballActive, ballX, ballY, ballSpeedX, ballSpeedY, ballFrostTimer, trailX, trailY, reverseControls, reverseTimer, paddleTimer, ballEffectTimer, ballEffectType, msgText, msgTimer, msgY, msgColor, baseBallSpeed);
//
//                    paddle.setSize({ paddleWidth, PADDLE_HEIGHT });
//                    paddle.setPosition({ paddleX, paddleY });
//                }
//            }
//        }
//        else if (gameState == 2) {
//            if (!scoreSaved) {
//                prevScore = score;
//                if (score > highScore) {
//                    highScore = score;
//                }
//                saveScores(highScore, prevScore);
//                scoreSaved = true;
//            }
//
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
//                gameState = 0;
//                sf::sleep(sf::milliseconds(200));
//            }
//        }
//        else if (gameState == 3) {
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {
//                bgm.play();
//                gameState = 1;
//                sf::sleep(sf::milliseconds(200));
//            }
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M)) {
//                bgm.play();
//                gameState = 0;
//                sf::sleep(sf::milliseconds(200));
//            }
//        }
//        else if (gameState == 4) {
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
//                loadNextLevel(bricks, hitFlash, currentLevel, ballActive, ballX, ballY, ballSpeedX, ballSpeedY, ballFrostTimer, trailX, trailY, paddleX, paddleWidth, combo, speedTimer, levelClearTimer, levelIntroTimer, reverseControls, reverseTimer, paddleTimer, ballEffectTimer, ballEffectType, ballStuck, msgTimer, powerActive, expActive, laserActive, shardActive, baseBallSpeed);
//                gameState = 1;
//                sf::sleep(sf::milliseconds(200));
//            }
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M)) {
//                prevScore = score;
//                if (score > highScore) {
//                    highScore = score;
//                }
//                saveScores(highScore, prevScore);
//                gameState = 0;
//                sf::sleep(sf::milliseconds(200));
//            }
//        }
//        else if (gameState == 5) {
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
//                gameState = 0;
//                sf::sleep(sf::milliseconds(200));
//            }
//        }
//        else if (gameState == 6) {
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) {
//                hardMode = !hardMode;
//                sf::sleep(sf::milliseconds(200));
//            }
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) {
//                fastPaddle = !fastPaddle;
//                sf::sleep(sf::milliseconds(200));
//            }
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
//                gameState = 0;
//                sf::sleep(sf::milliseconds(200));
//            }
//        }
//
//        renderFrame(window, font, titleBgShape, bgShape, paddle, ballShape, brickShape, powerShape, redTex, greenTex, grayTex, yellowTex, blueTex, orangeTex, bricks, hitFlash, ballActive, ballX, ballY, ballSpeedX, ballFrostTimer, trailX, trailY, powerActive, powerX, powerY, powerBrickType, expActive, expX, expY, expTimer, laserActive, laserY, laserTimer, shardActive, shardX, shardY, shardVX, shardVY, shardTimer, score, combo, lives, currentLevel, levelClearTimer, levelIntroTimer, gameState, menuOption, hardMode, fastPaddle, isWin, highScore, prevScore, reverseControls, ballStuck, msgText, msgTimer, msgY, msgColor);
//    }
//
//    return 0;
//}