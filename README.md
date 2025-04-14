KARTIKEYA AGRAWAL - 24BCE10375::
KARUNYA PANDEY - 24BCE10825::
KABIR PANDEY - 24BCE10855::
PAL KHARE - 24BCE11214


🎮 TREASURE HUNT — GAME SUMMARY (C++ Text-Based Game)

🧩 Concept: You’re navigating a hidden grid, starting at position (0, 0), trying to find a randomly placed treasure. Along the way, you must avoid:

Obstacles (blocks movement)

Traps (reduce life)

Wrong directions (if you move away from the treasure, you lose a life!)

You have only 3 lives per level. If you lose all of them — 💀 Game Over. Find the treasure, and the game levels up with a larger map!

📦 Structure Overview: The game is built using a class TreasureHunt, encapsulating all game logic and state.

📦 2. Class: TreasureHunt Encapsulates all gameplay elements: player, treasure, traps, obstacles, lives, and game loop.

Key Member Variables:

gridSize → current level's grid dimension (e.g. 5x5)

player → current position of the player

treasure → randomly placed position

traps → vector of trap positions

obstacles → vector of obstacle positions

moves → total moves made

lives → remaining lives (start at 3)

🧠 3. Game Initialization Constructor sets up the grid, player, treasure, and generates traps and obstacles:

🎲 4. Random Position Generator Ensures traps, obstacles, and treasure are placed at valid random positions:

🧱 5. Obstacles & Traps Randomly generated positions that affect gameplay:

Obstacles block the player from moving into that cell

Traps deduct 1 life

🗺️ 6. getDirectionHint() Gives player a clue on which direction to move:

📐 7. getDistance() Returns Manhattan distance between player and treasure:

🕹️ 8. playGame() The main game loop:

Shows hints

Accepts move input (W/A/S/D)

Moves the player and handles traps/obstacles

Deducts life if you:

step on a trap

move in the wrong direction (away from treasure)

Ends game if lives = 0

Calls resetGame() if player reaches treasure

✨ Gameplay Flow Summary:

Grid is created

Player starts at (0,0), treasure is randomly placed

Obstacles and traps are placed

Player gets hint + enters move

If player steps into trap → lose life

If player moves in wrong direction → lose life

If life == 0 → game ends

If treasure is found → game levels up with a bigger map
