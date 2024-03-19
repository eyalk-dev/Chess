# Chess

A console-based chess program for two players or one player versus the computer.

The program represents the chessboard in the console, with rows between 1-8 and columns between A-H. Each board piece is represented with the letters:
- Pawn - m
- Bishop - b
- Rook - r
- Knight - n
- Queen - q
- King - k

The program uses lowercase for white pieces and uppercase for black pieces.

Hence, the starting board looks like this:

```
8| R N B Q K B N R |
7| M M M M M M M M |
6| _ _ _ _ _ _ _ _ |
5| _ _ _ _ _ _ _ _ |
4| _ _ _ _ _ _ _ _ |
3| _ _ _ _ _ _ _ _ |
2| m m m m m m m m |
1| r n b q k b n r |
  -----------------
   A B C D E F G H
```


## Code Architecture

The program is divided into several components.

### DataStructs

#### ArrayList

A generic container that represents a list with elements of the same type (same size). It can get, remove, and add elements by index.

### BoardGame

#### BoardGame

A semi-generic board that theoretically can support other games besides chess. The Board has cells, and each cell can contain a piece, which is part of a broader piecetype that defines its behavior and possible moves. Every move is divided into strides (a motion in a single direction), and every stride is divided into steps (a movement between two neighboring cells). For example, every knight's move contains two strides: the first in lengths of two steps and the second in length of one step only.

### ChessGame

#### ChessGameBoard

Implementation of BoardGame, with the specific table and piece types of chess, alongside their movement logic.

#### ChessGame

The main file. Creates the game and handles settings and playing commands, including moves.

#### ChessGameViewOutput

Prints the board, responses to commands, and error messages.

#### ChessAI

Decides moves for the computer. Uses a scoring system, with the minimax method in varying degrees of recursion based on move prediction (determined by set difficulty).

### IO

#### Parser

Parses players' commands in settings and game state.

#### FileIO

Saves the game state to a file or loads it.

#### BasicErrorsHandling

Prints basic errors that result from other functions' misbehavior.

## Commands for Users

There are two types of commands: in the setting state and in the game state.

### Settings State

The default game settings are 1 player, white, with a difficulty of 2.

- `start`: Start the game.
- `game_mode 1`: Set the game mode to one player versus the computer.
- `game_mode 2`: Set the game mode to two players.
- `difficulty x`: Set the difficulty to x between 1 and 4, only for 1-player.
- `user_color 0`: Set the player color to black, only for 1-player.
- `user_color 1`: Set the player color to white, only for 1-player.
- `load x`: Load game settings and state from the specified filepath x.
- `default`: Reset game settings.
- `print_settings`: Print current settings to the console.
- `quit`: Terminate the program.

### Game State

- `move <x,y> to <i,j>`: Move a piece from current location x,y to target location i,j. Where x,i represent row number (1-8), and y,j represent column letter (A-H).
- `save x`: Save the current game state to the specified filepath x.
- `undo`: Undo up to 3 last moves (only available in 1-player mode).
- `reset`: Return to the setting state.
- `quit`: Terminate the program.

## TODO

Implement the following options:
1. Expert difficulty (5), which would be more sophisticated than the current AI.
2. Command that returns the player all their possible moves.
3. Pawn Promotions.
4. Castling Move.