#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

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
    int input;
    cout << "Enter position : ";
    cin >> input;
    for (int i = 1; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (layout[i][j] == input + '0') {
          layout[i][j] = 'X';
        }
      }
    }
    showlayout(layout, 0);
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
