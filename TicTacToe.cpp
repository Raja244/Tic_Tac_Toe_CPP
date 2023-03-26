#include <iostream>
#include <windows.h>
using namespace std;
char N = '\0';
void printTic(char TT[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << "-------------------" << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << "|  " << TT[i][j] << "  ";
            if (j == 2)
            {
                cout << "|";
            }
        }
        cout << endl;
        if (i == 2)
        {
            cout << "-------------------" << endl
                 << endl;
        }
    }
}
void gotNULL(char TT[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            TT[i][j] = '-';
        }
    }
}
bool isEmpty(char TT[3][3], int pos1, int pos2)
{
    if (TT[pos1 - 1][pos2 - 1] == '-')
        return true;
    return false;
}
int enterX(char TT[3][3], int pos1, int pos2)
{
    if (isEmpty(TT, pos1, pos2))
    {
        TT[pos1 - 1][pos2 - 1] = 'X';
        return 0;
    }
    else
    {
        cout << endl
             << "This Coordinates is already having value " << endl
             << endl;
        return 1;
    }
}
int enterO(char TT[3][3], int pos1, int pos2)
{
    if (isEmpty(TT, pos1, pos2))
    {
        TT[pos1 - 1][pos2 - 1] = 'O';
        return 0;
    }
    else
    {
        cout << endl
             << "This Coordinates is already having value " << endl
             << endl;
        return 1;
    }
}
char vertical(char TT[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (TT[0][i] == 'X' && TT[1][i] == 'X' && TT[2][i] == 'X')
        {
            return 'X';
        }
        else if (TT[0][i] == 'O' && TT[1][i] == 'O' && TT[2][i] == 'O')
        {
            return 'O';
        }
    }
    return N;
}
char horizontal(char TT[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (TT[i][0] == 'X' && TT[i][1] == 'X' && TT[i][2] == 'X')
        {
            return 'X';
        }
        else if (TT[i][0] == 'O' && TT[i][1] == 'O' && TT[i][2] == 'O')
        {
            return 'O';
        }
    }
    return N;
}
char cross(char TT[3][3])
{
    if (TT[0][0] == 'X' && TT[1][1] == 'X' && TT[2][2] == 'X' || TT[0][2] == 'X' && TT[1][1] == 'X' && TT[2][0] == 'X')
    {
        return 'X';
    }
    else if (TT[0][0] == 'O' && TT[1][1] == 'O' && TT[2][2] == 'O' || TT[0][2] == 'O' && TT[1][1] == 'O' && TT[2][0] == 'O')
    {
        return 'O';
    }
    else
    {
        return N;
    }
}
bool sizeCheck(int pos1, int pos2)
{
    if (pos1 < 1 || pos1 > 3 || pos2 < 1 || pos2 > 3)
    {
        cout << endl
             << "you have 1 to 3 coordinates please restart" << endl
             << endl;
        return false;
    }
    return true;
}
void putX(char TT[3][3], int pos1, int pos2, int i)
{
}
void putO(char TT[3][3], int pos1, int pos2, int i)
{
}
void exi()
{
    cout << endl
         << "Exit ";
    for (int i = 0; i < 15; i++)
    {
        cout << ". ";
        Sleep(500);
    }
}
int main(int argc, char const *argv[])
{
    char TT[3][3];
    int pos1, pos2, status = 0;
    gotNULL(TT);
    printTic(TT);
    for (int i = 1; i <= 9; i++)
    {
        if (i % 2 != 0)
        {
            cout << "X player Please enter Your Coordinates : ";
            cin >> pos1 >> pos2;
            putX(TT, pos1, pos2, i);
            try
            {
                if (0 < pos1 && 0 < pos2)
                {
                    if (!sizeCheck(pos1, pos2))
                        i -= 1;
                    else
                    {
                        i -= enterX(TT, pos1, pos2);
                        printTic(TT);
                    }
                }
                else
                {
                    throw 404;
                }
            }
            catch (...)
            {
                cout << endl
                     << "You Enter Something Really Wrong !!!" << endl;
                exi();
                exit(1);
            }
        }

        else
        {
            cout << "O player Please enter Your Coordinates : ";
            cin >> pos1 >> pos2;
            try
            {
                if (0 < pos1 && 0 < pos2)
                {
                    if (!sizeCheck(pos1, pos2))
                        i -= 1;
                    else
                    {
                        i -= enterO(TT, pos1, pos2);
                        printTic(TT);
                    }
                }
                else
                {
                    throw 404;
                }
            }
            catch (...)
            {
                cout << endl
                     << "You Enter Something Really Wrong !!!" << endl;
                exi();
                exit(1);
            }
        }
        if (horizontal(TT) || vertical(TT) || cross(TT) != N)
        {
            cout << horizontal(TT) << vertical(TT) << cross(TT) << " Wins !!!" << endl;
            status = 1;
            break;
        }
    }
    if (status == 0)
    {
        cout << "Draw !!!" << endl;
    }
    exi();
}
