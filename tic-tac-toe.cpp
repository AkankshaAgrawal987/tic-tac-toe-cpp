#include <iostream>
#include <stdlib.h>
using namespace std;

char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int checkWin() {
  if (square[1] == square[2] && square[2] == square[3])
    return 1;
  else if (square[4] == square[5] && square[5] == square[6])
    return 1;
  else if (square[7] == square[8] && square[8] == square[9])
    return 1;
  else if (square[1] == square[4] && square[4] == square[7])
    return 1;
  else if (square[2] == square[5] && square[5] == square[8])
    return 1;
  else if (square[3] == square[6] && square[6] == square[9])
    return 1;
  else if (square[1] == square[5] && square[5] == square[9])
    return 1;
  else if (square[3] == square[5] && square[5] == square[7])
    return 1;
  else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
           square[4] != '4' && square[5] != '5' && square[6] != '6' &&
           square[7] != '7' && square[8] != '8' && square[9] != '9')
    return 0;
  else
    return -1;
}

void board() {
  system("clear");

  cout << "Player 1(X) - Player 2(O)" << endl << endl << endl;

  cout << "   |   |   " << endl;

  cout << " " << square[1] << " | " << square[2] << " | " << square[3] << endl;

  cout << "___|___|___" << endl;
  cout << "   |   |   " << endl;

  cout << " " << square[4] << " | " << square[5] << " | " << square[6] << endl;

  cout << "___|___|___" << endl;
  cout << "   |   |   " << endl;

  cout << " " << square[7] << " | " << square[8] << " | " << square[9] << endl;
  cout << "   |   |   " << endl;
}

int main() {
  int player = 1, i, choice, j = 1;
  char mark;
  do {
    board();
    player = player % 2 ? 1 : 2;

    cout << "Player, " << player << ", enter the number: ";
    cin >> choice;

    mark = player == 1 ? 'X' : 'O';

    if (choice == 1 && square[1] == '1')
      square[1] = mark;
    else if (choice == 2 && square[2] == '2')
      square[2] = mark;
    else if (choice == 3 && square[3] == '3')
      square[3] = mark;
    else if (choice == 4 && square[4] == '4')
      square[4] = mark;
    else if (choice == 5 && square[5] == '5')
      square[5] = mark;
    else if (choice == 6 && square[6] == '6')
      square[6] = mark;
    else if (choice == 7 && square[7] == '7')
      square[7] = mark;
    else if (choice == 8 && square[8] == '8')
      square[8] = mark;
    else if (choice == 9 && square[9] == '9')
      square[9] = mark;

    else {
      cout << "INVALID CHOICE!";

      player--;
      cin.ignore();
      cin.get();
    }
    i = checkWin();
    player++;
  } while (i == -1);
  board();
  if (i == 1)
    cout << "\a CONGRATULATIONS! PLAYER " << --player << " WINS!";
  else
    cout << "\a GAME DRAW!";

  cin.ignore();
  cin.get();
  return 0;
}