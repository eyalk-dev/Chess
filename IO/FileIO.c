
#include "FileIO.h"


void loadFile(ChessGame* game, const char filePath[]) {

    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
		printMsgForSettingsState(MSG_SETTINGS_CMD_LOADFILE_FILEERR, __func__);
    }

    skipLine(file); //skip intro XML line
    skipLine(file); //skip game line

    game->currPlayer = (Color) parseDigit(file);
    game->settings.gameModeUsersNum = parseDigit(file);

    if (game->settings.gameModeUsersNum == PLAYER_VS_COMP) {
    	game->settings.difLevel= parseDigit(file);
        game->settings.user1Color = (Color) parseDigit(file);
        skipLine(file); // skip <board> line
    }
    else { // difficulty & user_color are irrelevant, so we need to skip them
        char tag[MAX_TAG] = {'\0'};
        do {
            getTag(file, tag);
        } while (strcmp(tag, T_BOARD) != 0);
    }

    char table[CHESS_N_ROWS][CHESS_N_COLUMNS];

    for (int i = CHESS_N_ROWS-1; i >= 0; i--) { // the board is from row8 to row1
        parseRow(file, table[i], CHESS_N_COLUMNS);
    }

    loadTable(game, table);

    setKings(game);

    fclose(file);
    
    ArrayListClear(game->history);
}



void saveFile(const ChessGame* game, const char filePath[]) {

    FILE *file = fopen(filePath, "w");
    if (file == NULL) {
		printMsgForSettingsState(MSG_SETTINGS_CMD_LOADFILE_FILEERR, __func__);
    }

    char current = digitToChar(game->currPlayer);
	char game_mode = digitToChar(game->settings.gameModeUsersNum);


    printLine(file, T_FIRST_XML_LINE, false, NULL_CHAR, 0);

    printLine(file, T_GAME, false, NULL_CHAR, 0);

    printLine(file, T_TURN, true, current, 1);
    printLine(file, T_GAME_MODE, true, game_mode, 1);

    if (game->settings.gameModeUsersNum == PLAYER_VS_COMP) {
    	char difficulty = digitToChar(game->settings.difLevel);
    	char userColor = digitToChar(game->settings.user1Color);
        printLine(file, T_DIFFICULTY, true, difficulty, 1);
        printLine(file, T_USER_COLOR, true, userColor, 1);
    }

    printLine(file, T_BOARD, false, NULL_CHAR, 1);

    char* rows[CHESS_N_ROWS] = ROWS;
    for (int i = CHESS_N_ROWS-1; i >= 0; i--) { // the board is from row_8 to row_1
        parserPutChar(TAB_CHAR, file); parserPutChar(TAB_CHAR, file); // twice tabs
        printTag(file, rows[i], false);
        for (int j = 0; j < CHESS_N_COLUMNS; j++) {
        	Piece* piece = game->gameBoard.board[j][i].piece;
            parserPutChar(getPieceChar(piece),file);
		}
        printTag(file, rows[i], CLOSING);
        parserPutChar(END_LINE, file);
    }

    parserPutChar(TAB_CHAR, file); printTag(file, T_BOARD, CLOSING); parserPutChar(END_LINE, file);

    printTag(file, T_GAME, CLOSING); parserPutChar(END_LINE, file);

    fclose(file);
}

