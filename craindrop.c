#include <ncurses.h>

int main(int argc, char * argv[]){
  initscr();
  //printw(); //use instead of printf()
  //getch(); //program wait for input
  //refresh(); //show the results
  endwin(); //IMPORTANT: prevents crash
  return 0;
}
