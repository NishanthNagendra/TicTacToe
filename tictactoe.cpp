#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

bool row(char layout[4][4]) {
  for (int i = 1; i < 4; i++) {
    if (layout[i][1] != " " && layout[i][1] == layout[i][2] &&
        layout[i][2] == layout[i][3]) {
      return true;
    }
  }
  return false;
}

bool column(char layout[4][4]) {
  for (int i = 1; i < 4; i++) {
    if (layout[1][i] != " " && layout[1][i] == layout[2][i] &&
        layout[2][i] == layout[3][i]) {
      return true;
    }
  }
  return false;
}

bool diagonal(char layout[4][4]) {
  if (layout[1][1] != " " && layout[1][1] == layout[2][2] &&
      layout[2][2] == layout[3][3]) {
    return true;
  } else if (layout[1][3] != " " && layout[1][3] == layout[2][2] &&
             layout[2][2] == layout[3][1]) {
    return true;
  }
  return false;
}

bool win(char layout[4][4]) {
  return (row(layout) || column(layout) || diagonal(layout));
}
// Function to show the board layout
void showlayout(char layout[4][4], int temp) {
  system("CLS");
  cout << "The board layout : \n";
  cout << "     |     |     "
       << "\n";
  cout << "  " << layout[1][1] << "  |  " << layout[1][2] << "  |  "
       << layout[1][3] << "\n";

  cout << "_____|_____|_____"
       << "\n";
  cout << "     |     |     "
       << "\n";

  cout << "  " << layout[2][1] << "  |  " << layout[2][2] << "  |  "
       << layout[2][3] << "\n";

  cout << "_____|_____|_____"
       << "\n";
  cout << "     |     |     "
       << "\n";

  cout << "  " << layout[3][1] << "  |  " << layout[3][2] << "  |  "
       << layout[3][3] << "\n";

  cout << "     |     |     "
       << "\n"
       << "\n";
  if (temp) {
    cout << "The game will begin shortly";
    Sleep(600);
    cout << ".";
    Sleep(600);
    cout << ".";
    Sleep(600);
    cout << ".";
    Sleep(600);
  }
}

void playgame(char layout[4][4], int choice) {
  system("CLS");
  showlayout(layout, 0);
  if (choice == 1) {
    int input, player = 1, compmoves[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    char symbolpos[4][4] = {" "};
    while (!win) {
      cout << "Enter position : ";
      cin >> input;
    repeat:
      for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
          if (player == 1) {
            if (layout[i][j] == input + '0') {
              symbolpos[i][j] = 'X';
              player--;
            }
          } else if (player == 0) {

            player++;
            goto repeat;
          }
        }
        showlayout(symbolpos, 0);
      }
    }
  } else {
  }
}

// Function to initialize positions on the board
void initialize(int choice) {
  char layout[4][4];
  int c = 1, i, j;

  for (i = 1; i < 4; i++) {
    for (j = 1; j < 4; j++) {
      char s = c + '0';
      layout[i][j] = s;
      c++;
      cout << layout[i][j] << "\n";
    }
  }
  showlayout(layout, 1);
  playgame(layout, choice);
}

int main() {
  int choice;
a:
  system("CLS");
  cout << "1. Single Player\n2. Multi-Player\nEnter your choice : ";
  cin >> choice;
  switch (choice) {
  case 1:
    initialize(choice);
    break;
  case 2:
    initialize(choice);
    break;
  default:
    cout << "Enter a valid choice";
    Sleep(1000);
    goto a;
    break;
  }
  return 0;
}
