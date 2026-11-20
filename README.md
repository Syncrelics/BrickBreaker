# Break Breaker

A 2D arcade game inspired by the classic Brick Breaker, built in **C++** using **SFML 3.0.2** for my Programming Fundamentals course project.

Control a paddle to bounce a ball, clear the brick grid, rack up points, and beat your saved high score without running out of lives.

---

## Features

### Implemented
* **Paddle & Ball Physics:** Smooth keyboard-controlled paddle movement with wall, paddle, and directional brick collision detection.
* **4 Brick Types:** Normal, Strong, Unbreakable, and Explosive bricks stored and managed via a 2D array.
* **Scoring & Lives System:** Real-time HUD displaying current score and remaining lives (starts with 3 lives).
* **Game States:** Includes a Title Screen, Active Gameplay Screen, and Win/Lose End Screen.
* **Persistent High Scores:** Automatically saves and loads the highest score locally using `highscore.txt`.

### Planned / In Progress
* Gradually increasing ball speed over time
* Falling power-ups (enlarged paddle, slower ball, extra lives, multi-ball)
* Negative effects (smaller paddle, faster ball, reversed controls)
* Multiple handcrafted levels with increasing difficulty
* Pause menu

---

## Brick Types

| Brick Type | Color | Behavior | Points |
| :--- | :--- | :--- | :--- |
| **Normal** | Red | Breaks in 1 hit | +10 |
| **Strong** | Green | Takes 2 hits (turns into a Normal brick after the first hit) | +5 on first hit, +10 on break |
| **Unbreakable** | Gray | Cannot be destroyed; deflects the ball | 0 |
| **Explosive** | Yellow | Destroys itself and all surrounding breakable bricks in a 3×3 area | +10 per brick destroyed |

---

## Controls

| Key | Action |
| :--- | :--- |
| `Left Arrow` | Move paddle left |
| `Right Arrow` | Move paddle right |
| `Enter` | Start game / Return to main menu |

---

## Tech Stack & Requirements

* **Language:** C++ (C++17 or newer recommended for SFML 3)
* **Library:** [SFML 3.0.2](https://www.sfml-dev.org/)
* **IDE:** Visual Studio 2022 (or any C++ compiler configured with SFML 3.0.2)

---

## Setup & Running the Game

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/your-username/break-breaker.git](https://github.com/your-username/break-breaker.git)
   cd break-breaker
