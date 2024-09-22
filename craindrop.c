#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#define PATTERNCONST 29

/*
  Available colors:
  COLOR_BLACK
  COLOR_RED
  COLOR_GREEN
  COLOR_YELLOW
  COLOR_BLUE
  COLOR_MAGENTA
  COLOR_CYAN
  COLOR_WHITE
*/

/*
creates the matrix then print the content
*/


int main(int argc, char * argv[]){
  setlocale(LC_ALL, "");
  initscr(); //init the screen
  start_color(); //init the colors
  curs_set(0); //hide cursor
  if(has_colors() == FALSE) {
    endwin();
    printf("Your terminal does not support color\n");
    exit(1);
  }
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, COLOR_BLUE);
  init_pair(3, COLOR_BLACK, COLOR_WHITE);
  init_pair(4, COLOR_RED, COLOR_MAGENTA);
  //setlocale(LC_ALL, ""); //set local charcaters
  //attron(COLOR_PAIR(COLOR_BLUE));
  attron(COLOR_PAIR(1));/*
  printw("lines= %d columns= %d\n", LINES, COLS); //dimension of console
  printw("a");
  printw("b");*/
  int i = 0;
  //wchar_t unichar = 0x2588;
  for(int k=2;TRUE;k++){
    clear();
    i = 0;
    while(i<LINES*COLS){
      if((i+(int)(i/COLS))%PATTERNCONST==(0+k%PATTERNCONST))
        printw("!"/*, unichar*/);
      else
        printw(" "/*, unichar*/);
      ++i;
    }
    napms(100); //wait millisecond
    refresh();
  }
  attroff(COLOR_PAIR(1));
  //printw(); //use instead of printf()
  //getch(); //program wait for input
  refresh(); //show the results
  getch(); //before exit
  endwin(); //IMPORTANT: prevents crash
  return 0;
}
