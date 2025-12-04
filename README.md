  OBSTACLE GAME-(objective 1)

1- game overview

 this project contains a simple console game written in c.In this game the main idea
 is that player stays at the bottom of the screen and tries to avoid the obstacle.if 
 obstacle reaches the same lane as player the game ends

 2-code flow

 Variables are set for player position (`x`), obstacle lane (`obstaclePos`), and vertical step (`step`).
 A random lane is chosen for the obstacle using `rand() % 3`.

 3-input handling
 the code was desingned so the player could move left and right using arrow keys.
 in the original version input handing was incomplete so the player did not move correctly
 the program checks for key presses with `_kbhit()` and reads them with `getch()`.

4-Drawing Routine
Each frame clears the screen with `system("cls")`.
The board is printed row by row.
When the loop index equals `step`, the obstacle is drawn in its lane.
The bottom row prints the player in their current lane.


 5-Collision Detection
 When `step == 10` (obstacle reaches the bottom):
 If `x == obstaclePos`, collision occurs.
The game prints “GAME OVER!” and exits.

6-Timing**
`Sleep(120)` controls the speed of the game loop.
`step++` moves the obstacle down one row each frame.
 When the obstacle passes the bottom, `step` resets and a new random lane is chosen.

7- Observations
The logic is simple and easy to follow.
Input, drawing, and collision are separated clearly.
Only one obstacle appears at a time.
There is no score or lives in the original version.
Player movement was intended but did not work properly with arrow keys until fixed later.

8- How to Run
Compile the code with a C compiler (e.g., GCC or MSVC).(i have used embarcadero dev c++)
Run the program in a Windows console.

Add Objective 1 README analysis

 Objective 2 — Modified Game (gamemodify.c)

 1-new features-
 Score system: Player earns points for avoiding obstacles.
 Player lives: Game continues until all 3 lives are lost.
 Restart option: After game over, press 'Y' to restart.
Improved controls: Supports both arrow keys and A/D for movement.

 2-shifting left right-
 Fixed arrow key movement using double `getch()`.
 Improved input handling with `_kbhit()` and `getch()` for smoother gameplay.

3- How to Run
Compile `gamemodify.c` using Embarcadero Dev-C++ or any C compiler.
Run in Windows console.
Use arrow keys or A/D to move left/right.
Avoid obstacles to increase score.
Game ends when lives reach zero; press 'Y' to restart.





 

