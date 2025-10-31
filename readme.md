<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>5x5 Tic-Tac-Toe in C - README</title>
    <style>
        body {
            font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Helvetica, Arial, sans-serif, "Apple Color Emoji", "Segoe UI Emoji";
            line-height: 1.6;
            background-color: #f6f8fa;
            color: #24292e;
            margin: 0;
            padding: 0;
        }

        .container {
            max-width: 800px;
            margin: 20px auto;
            background-color: #ffffff;
            border: 1px solid #d1d5da;
            border-radius: 6px;
            padding: 24px;
        }

        h1, h2, h3 {
            border-bottom: 1px solid #eaecef;
            padding-bottom: .3em;
            margin-top: 24px;
            margin-bottom: 16px;
            font-weight: 600;
        }

        h1 { font-size: 2em; }
        h2 { font-size: 1.5em; }
        h3 { font-size: 1.25em; }

        p {
            margin-bottom: 16px;
        }

        /* Code block styling */
        pre {
            background-color: #f6f8fa;
            border: 1px solid #d1d5da;
            border-radius: 6px;
            padding: 16px;
            overflow: auto;
            font-family: "SFMono-Regular", Consolas, "Liberation Mono", Menlo, Courier, monospace;
            font-size: 14px;
        }

        /* Inline code */
        code {
            background-color: rgba(27,31,35,.05);
            border-radius: 3px;
            padding: .2em .4em;
            margin: 0;
            font-family: "SFMono-Regular", Consolas, "Liberation Mono", Menlo, Courier, monospace;
            font-size: 85%;
        }

        pre code {
            background-color: transparent;
            padding: 0;
            margin: 0;
            font-size: 1em;
        }
        
        ul, ol {
            padding-left: 20px;
            margin-bottom: 16px;
        }

        li {
            margin-bottom: 8px;
        }

        /* Special style for the terminal demo */
        .terminal-demo {
            background-color: #24292e; /* Dark background */
            color: #f0f0f0; /* Light text */
            border: 1px solid #444;
            box-shadow: 0 4px 10px rgba(0,0,0,0.2);
            font-family: "SFMono-Regular", Consolas, "Liberation Mono", Menlo, Courier, monospace;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>5x5 Tic-Tac-Toe in C</h1>
        <p>This is a complete, console-based Tic-Tac-Toe game written in standard C. It enhances the classic game by moving to a <strong>5x5 grid</strong> and requiring <strong>4 in a row</strong> to win, leading to more complex and strategic gameplay.</p>
        <p>The project is contained in a single C file, is fully commented, and includes robust input validation.</p>

        <h2>Game Preview</h2>
        <p>Here is what the game looks like in action:</p>
        <pre class="terminal-demo">
   === 5x5 TIC TAC TOE (4 in a row wins) ===

     1   2   3   4   5   
   +---+---+---+---+---+
 1 | - | - | - | - | - |
   +---+---+---+---+---+
 2 | - | - | X | - | - |
   +---+---+---+---+---+
 3 | - | - | O | - | - |
   +---+---+---+---+---+
 4 | - | - | X | O | - |
   +---+---+---+---+---+
 5 | - | - | - | - | X |
   +---+---+---+---+---+

Player O, enter row and column (1-5): 
        </pre>

        <h2>Features</h2>
        <ul>
            <li><strong>5x5 Grid:</strong> A larger board for more challenging matches.</li>
            <li><strong>4-in-a-Row to Win:</strong> Players must get four of their marks in a row (horizontally, vertically, or diagonally).</li>
            <li><strong>Two-Player Mode:</strong> A classic hot-seat game for two human players (Player 'X' and Player 'O').</li>
            <li><strong>Robust Input Validation:</strong> The game intelligently handles invalid inputs, such as:
                <ul>
                    <li>Non-numeric entries (e.g., "abc").</li>
                    <li>Out-of-bounds coordinates (e.g., "9 9").</li>
                    <li>Attempts to play on an already occupied spot.</li>
                </ul>
            </li>
            <li><strong>Clear Console UI:</strong> The board is reprinted after every move, and the screen is cleared for a clean user experience.</li>
            <li><strong>Win/Draw Detection:</strong> The game correctly identifies when a player wins or when the board is full, resulting in a draw.</li>
        </ul>

        <h2>How to Compile and Run</h2>
        <p>This program is written in standard C and can be compiled with <code>gcc</code> or any other C compiler. The code includes conditional compilation for screen clearing on both Windows (<code>system("cls")</code>) and Linux/macOS (<code>system("clear")</code>).</p>
        
        <h3>On Linux / macOS</h3>
        <pre><code># 1. Compile the program
gcc 5x5_tic_tac_toe.c -o tictactoe

# 2. Run the compiled game
./tictactoe</code></pre>

        <h3>On Windows (with MinGW/GCC)</h3>
        <pre><code># 1. Compile the program
gcc 5x5_tic_tac_toe.c -o tictactoe.exe

# 2. Run the compiled game
tictactoe.exe</code></pre>
        <p><em>(Note: You will need to replace <code>5x5_tic_tac_toe.c</code> with the actual name of your C file.)</em></p>

        <h2>How to Play</h2>
        <ol>
            <li>The game starts with Player 'X'.</li>
            <li>Players take turns entering their move.</li>
            <li>To make a move, enter the <strong>row number</strong>, followed by a <strong>space</strong>, followed by the <strong>column number</strong>. (e.g., <code>3 3</code> for the center square).</li>
            <li>The first player to get <strong>4 of their marks</strong> in a continuous line (horizontal, vertical, or diagonal) wins!</li>
            <li>If the entire 5x5 board fills up with no winner, the game ends in a draw.</li>
        </ol>

        <h2>Code Overview</h2>
        <p>The code is structured modularly with several key functions:</p>
        <ul>
            <li><code>main()</code>: Contains the main game loop, handles player turn-switching, and calls other functions to run the game.</li>
            <li><code>setupBoard(board)</code>: Initializes the 5x5 <code>board</code> array with <code>'-'</code> characters to represent empty spots.</li>
            <li><code>printBoard(board)</code>: Clears the console and prints the current state of the board in a user-friendly format.</li>
            <li><code>playerMove(board, player)</code>: Prompts the current <code>player</code> for their move (row and column) and performs all necessary input validation.</li>
            <li><code>isBoardFull(board)</code>: Scans the board to see if any <code>'-'</code> characters are left. Returns <code>1</code> (true) if the board is full (a draw), and <code>0</code> (false) otherwise.</li>
            <li><code>checkWin(board, player)</code>: The core win-checking logic. It iterates through all possible 4-in-a-row combinations for the current <code>player</code>:
                <ul>
                    <li>Horizontal (<code>—</code>)</li>
                    <li>Vertical (<code>|</code>)</li>
                    <li>Down-Right Diagonal (<code>↘</code>)</li>
                    <li>Up-Right Diagonal (<code>↗</code>)</li>
                </ul>
                Returns <code>1</code> (true) if a win is found, and <code>0</code> (false) otherwise.
            </li>
        </ul>

    </div>
</body>
</html>
