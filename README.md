# Brick Breaker (C++ & SFML 3.0)

A classic arcade Brick Breaker game built in C++ using **SFML 3.0**, featuring 5 custom levels, 6 distinct brick types, 7 falling power-ups, dynamic ball heat trails, frostbite freeze effects, background music, and persistent score tracking.

---

## Features

* **5 Distinct Levels:** Gradually increasing difficulty with unique layouts, air gaps, and defensive formations:
  1. *Level 1: Classic Intro*
  2. *Level 2: Checkerboard*
  3. *Level 3: Twin Towers*
  4. *Level 4: The Bunker*
  5. *Level 5: The Final Vault*
* **6 Brick Types:**
  * **Red Brick:** Standard 1-hit brick.
  * **Green Brick:** Heavy 4-hit brick with progressive hit-flash and darkening damage states.
  * **Gray Brick:** Unbreakable steel obstacle.
  * **Yellow Brick (Bomb):** Explodes on impact, clearing adjacent bricks in a 3×3 radius with an expanding fireball animation.
  * **Blue Brick (Frostbite):** Awards bonus points and freezes the ball in an icy crystal shell for 3 seconds (slowing it by 25%) before shattering into ice shards.
  * **Orange Brick (Laser):** Fires an animated horizontal red laser beam that clears every breakable brick in that row.
* **7 Falling Power-Ups:** Wide Paddle, Extra Life, Slow Ball, Shrink Paddle, Fast Ball, Reversed Controls, and Multi-Ball (up to 5 active balls simultaneously).
* **Dynamic Visual Effects:** Speed-reactive ball trail that shifts from white to flickering fire at high speeds, combo multipliers, and staggered floating status popups.
* **Persistent High Scores & Settings:** Saves both `Best Score` and `Previous Score` to `highscore.txt`, plus toggleable difficulty (`Normal` / `Hard`) and paddle speed (`Normal` / `Fast`).

---

## Controls

| Action | Key / Input |
| :--- | :--- |
| **Menu Navigation** | `Up` / `Down` Arrows + `Enter`, or `Left Click` |
| **Move Paddle** | `Left` / `Right` Arrow Keys |
| **Launch Ball** | `Space` |
| **Pause / Resume** | `P` |
| **Return to Main Menu** | `M` or `Esc` |
| **Settings Toggles** | `1` (Difficulty), `2` (Paddle Speed) |

---

## Project Structure & Required Assets

Ensure all 12 asset files sit in the same directory as the executable (or root project folder when running from Visual Studio):

```text
Brick-Breaker/
├── main.cpp
├── README.md
├── arial.ttf
├── theme.ogg
├── title.jpg
├── background.jpg
├── Ball.png
├── Paddle.png
├── Brick-Red.png
├── Brick-Green.png
├── Brick-Gray.png
├── Brick-Yellow.png
├── Brick-Blue.png
└── Brick-Orange.png
