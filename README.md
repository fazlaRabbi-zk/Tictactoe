# Tic-Tac-Toe... with a Twist! 👾

Welcome to my project! I wanted to take the classic game of Tic-Tac-Toe and make it a bit more challenging. So, I built this version in C.

Instead of the tiny 3x3 grid, this game is played on a **5x5 board**, and you need to get **four in a row** to win!

It was a really fun challenge to build from the ground up, and it's a great example of how 2D arrays, functions, and (most importantly) user input validation all come together to make a working game.

---

## How It Works 🛠️

The whole game is like a well-organized team. The `main()` function is the "boss," and it tells a few helper functions (the "specialists") exactly what to do and when.

Here's the team:

* **`main()` (The Boss 👔):**
    This function runs the main game loop. It's the one that keeps things moving turn after turn, calling on the other functions to do their jobs. It's responsible for starting the game, switching players, and stopping when someone wins or it's a draw.

* **`setupBoard()` (The Cleaner 🧹):**
    Before any game can start, this function gets the board ready. It "cleans" the 5x5 grid by going through every single spot and placing a dash (`-`) to show that it's empty.

* **`printBoard()` (The Artist 🎨):**
    This function's only job is to make the game look good. After every move, it clears the screen and neatly draws the entire 5x5 board in your terminal, complete with row and column numbers so you know where you're playing.

* **`playerMove()` (The Bouncer 🛡️):**
    This is one of the most important functions! It's the "bouncer" that guards the game against bad moves. It politely asks you where you want to play and checks your input for common mistakes:
    * Did you type letters instead of numbers?
    * Did you pick a spot that's already taken?
    * Did you try to play off the board (like row 9)?
    It will keep asking until you give a 100% valid move.

* **`isBoardFull()` (The Judge ⚖️):**
    A simple but crucial helper. If no one has won yet, `main()` asks this function to check for a draw. It quickly scans all 25 spots. The *moment* it finds even one empty (`-`) spot, it reports back "Keep playing!" If it finds no empty spots, it declares a tie.

* **`checkWin()` (The Referee 🏁):**
    This is the "brain" of the operation. After every single move, this function "blows the whistle" and checks the entire board to see if the last move won the game. It's built to find four-in-a-row in all four possible directions:
    1.  Horizontally (`—`)
    2.  Vertically (`|`)
    3.  Diagonally (top-left to bottom-right `\`)
    4.  Diagonally (bottom-left to top-right `/`)
    
    The instant it finds a winner, it tells the "boss" (`main()`) to stop the game.

It's a simple game, but it's pretty cool to see how all these parts have to work together perfectly to make it happen!
