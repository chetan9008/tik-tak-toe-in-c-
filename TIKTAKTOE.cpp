#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

namespace variables
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD CursorPosition;

    char board[3][3] = {'1', '2', '3',
                        '4', '5', '6',
                        '7', '8', '9'};
    bool draw = false;
    int row;
    int col;
    char choice;
    char turn = 'X';
    string first_p, second_p;
}

using namespace variables;

namespace functions
{

    void gotoxy(int x, int y)
    {
        CursorPosition.X = x;
        CursorPosition.Y = y;
        SetConsoleCursorPosition(console, CursorPosition);
    }

    void player_name()
    {
        gotoxy(32, 2);
        cout << "----------------------------";
        gotoxy(32, 3);
        cout << "------TIK TAK TOE GAME------";
        gotoxy(32, 4);
        cout << "----------------------------";

        gotoxy(30, 6);
        cout << "Enter the first Player name :";
        cin >> first_p;
        gotoxy(30, 8);
        cout << "Enter the second Player name :";
        cin >> second_p;
        system("cls");
    }

    bool gameover()
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            {
                return false;
            }
        }

        if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[2][0] == board[1][1] && board[2][0] == board[0][2])
        {
            return false;
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] != 'X' && board[i][j] != 'O')
                {
                    return true;
                }
            }
        }

        draw = true;
        return false;
    }
    void display_board()
    {
        gotoxy(40, 2);
        cout << "TIK TAK TOE";
        gotoxy(38, 3);
        cout << "FOR TWO PLAYERS";

        gotoxy(34, 9);
        cout << "     |       |     ";
        gotoxy(35, 10);
        cout << board[0][0] << "   "
             << "|"
             << "   " << board[0][1] << "   "
             << "|"
             << "   " << board[0][2] << "   ";
        gotoxy(34, 11);
        cout << "_____|_______|_____";
        gotoxy(34, 12);
        cout << "     |       |     ";
        gotoxy(35, 13);
        cout << board[1][0] << "   "
             << "|"
             << "   " << board[1][1] << "   "
             << "|"
             << "   " << board[1][2] << "   ";
        gotoxy(34, 14);
        cout << "_____|_______|_____";
        gotoxy(34, 15);
        cout << "     |       |     ";
        gotoxy(35, 16);
        cout << board[2][0] << "   "
             << "|"
             << "   " << board[2][1] << "   "
             << "|"
             << "   " << board[2][2] << "   ";
        gotoxy(34, 17);
        cout << "     |       |     ";
    }
    void player_turn()
    {
        if (turn == 'X')
        {
            gotoxy(32, 5);
            cout << "-----------------";
            gotoxy(32, 6);
            cout << first_p << " turn :";
            cin >> choice;
            gotoxy(32, 7);
            cout << "-----------------";
        }
        if (turn == 'O')
        {
            gotoxy(32, 5);
            cout << "-----------------";
            gotoxy(32, 6);
            cout << second_p << " turn :";
            cin >> choice;
            gotoxy(32, 7);
            cout << "-----------------";
        }

        if (choice == '1')
        {
            row = 0;
            col = 0;
        }
        else if (choice == '2')
        {
            row = 0;
            col = 1;
        }
        else if (choice == '3')
        {
            row = 0;
            col = 2;
        }
        else if (choice == '4')
        {
            row = 1;
            col = 0;
        }
        else if (choice == '5')
        {
            row = 1;
            col = 1;
        }
        else if (choice == '6')
        {
            row = 1;
            col = 2;
        }
        else if (choice == '7')
        {
            row = 2;
            col = 0;
        }
        else if (choice == '8')
        {
            row = 2;
            col = 1;
        }
        else if (choice == '9')
        {
            row = 2;
            col = 2;
        }
        if (choice == 'e')
        {
            exit(0);
        }
        else
        {
            gotoxy(30, 19);
            cout << "-----------------------------";
            gotoxy(30, 20);
            cout << "Please choose correct option!";
            gotoxy(30, 21);
            cout << "-----------------------------";
            player_turn();
        }

        if (turn == 'X' && board[row][col] != 'X' && board[row][col] != 'O')
        {
            board[row][col] = 'X';
            turn = 'O';
        }
        else if (turn == 'O' && board[row][col] != 'X' && board[row][col] != 'O')
        {
            board[row][col] = 'O';
            turn = 'X';
        }
        else
        {
            gotoxy(30, 19);
            cout << "-------------------------------------------";
            gotoxy(30, 20);
            cout << "Box already filled!n Please choose another!";
            gotoxy(30, 21);
            cout << "-------------------------------------------";
            player_turn();
        }

        display_board();
    }
}

using namespace functions;

int main()
{
    system("Color A0");

    player_name();

    while (gameover())
    {
        display_board();
        player_turn();
    }

    if (turn == 'X' && draw == false)
    {
        gotoxy(30, 19);
        cout << "----------------------------";
        gotoxy(30, 20);
        cout << "Congratulations " << second_p << " wins                       ";
        gotoxy(30, 21);
        cout << "----------------------------";
    }
    else if (turn == 'O' && draw == false)
    {
        gotoxy(30, 19);
        cout << "----------------------------";
        gotoxy(30, 20);
        cout << "Congratulations " << first_p << " wins                          ";
        gotoxy(30, 21);
        cout << "----------------------------";
    }
    else
    {
        gotoxy(30, 19);
        cout << "-----------------------";
        gotoxy(30, 20);
        cout << "Well play! Game is draw                       ";
        gotoxy(30, 21);
        cout << "-----------------------";
    }
    return 0;
}