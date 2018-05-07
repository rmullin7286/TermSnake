/*	TermSnake: A game by Michael Dandrea
 *	Last Updated: 10/20/17
 *	Description: This game will ultimately be a version of the classic Snake game to be played in terminal
 */

#include <ncurses.h>

int main(void)
{
	WINDOW *board;
	int rows, cols, inity, initx, size;

	// Initializing the curses environment for the game
	initscr(); 
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	refresh();

	// Calculate the size of the board
	getmaxyx(stdscr, rows, cols);
	if(rows <= 50 || cols <= 100)
	{
		if(rows < (cols / 2))
			size = rows;
		else
			size = (cols / 2);
	}
	else
		size = 50;

	initx = (cols / 2) - size;
	inity = (rows - size) / 2;
	board = newwin(size, size * 2, inity, initx);
	box(board, 0, 0);
	mvwprintw(board, (size / 2) - 1, size - 13, "Welcome to TermSnake v0.0!");
	mvwprintw(board, (size / 2), size - 10, "Nothing to do yet :/");
	wrefresh(board);

	getch();
	
	endwin();
	return 0;
}
