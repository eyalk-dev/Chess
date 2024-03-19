/**
 * HANDLES ALL FILE IO SERVICES
 */



#ifndef CHESSPROG_FILEIO_H
#define CHESSPROG_FILEIO_H


#include "Parser.h"
#include "../ChessGame/ChessGameBoard.h"
#include "../ChessGame/ChessGameViewOutput.h"

#define T_FIRST_XML_LINE "?xml version=\"1.0\" encoding=\"UTF-8\"?"
#define T_GAME "game"
#define T_TURN "current_turn"
#define T_BOARD "board"
#define MAX_TAG 24

#define ROWS {"row_1", "row_2", "row_3", "row_4", "row_5", "row_6", "row_7", "row_8"}


/**
 * load save in filePath to game
 * assume correction of the file format
 */
void loadFile(ChessGame* game, const char filePath[]);


/**
 * save current game to new file in filePath
 */
void saveFile(const ChessGame* game, const char filePath[]);










#endif //CHESSPROG_FILEIO_H
