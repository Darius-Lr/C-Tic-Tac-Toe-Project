#include <iostream>
using namespace std;
void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

  
    while (running)   
    {

        // Players turn
        playerMove(spaces, player);

            cout<<"\n";
            cout<<"\n";
            cout<<"    Your  move:\n";
            cout<<"\n";

        drawBoard(spaces);

        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        else if (checkTie(spaces))
        {
            running = false;
            break;
        }

        // Computers turn
        cout<<"\n";
        cout<<"\n";
        cout<<"   Computers  move:\n";
        cout<<"\n";
        computerMove(spaces, computer);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        else if (checkTie(spaces))
        {
            running = false;
            break;
        }

    }

    return 0;
}

void drawBoard(char *spaces)
{
    cout << "  _TIC___TAC___TOE_ \n";
    cout << " |1    |2    |3    |\n";
    cout << " |  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  |\n";
    cout << " |_____|_____|_____|\n";
    cout << " |4    |5    |6    |\n";
    cout << " |  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  |\n";
    cout << " |_____|_____|_____|\n";
    cout << " |7    |8    |9    |\n";
    cout << " |  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  |\n";
    cout << " |_____|_____|_____|\n";

}

void playerMove(char *spaces, char player)
{
    int number;
    do
    {
        cout<<"\n";
        cout << " Enter the tile on the grid where you would like to place your marker (1-9): \n";
        cin >> number;
        number--;
        if (spaces[number] == ' ')
        {
            spaces[number] = player;
            break;
        }
    }
    while (!number >= 0 || !number <= 8);
}

void computerMove(char *spaces, char computer)
{

    int number;

    do
    {
        number = rand() % 9;
    }
    while (spaces[number] != ' ');

    spaces[number] = computer;
}

bool checkWinner(char *spaces, char player, char computer)
{
    char tiles[] = {player, computer};
    for (char tile : tiles)
    {
        if (
            // Horizontal lines of 3
            spaces[0] == tile && spaces[0] == spaces[1] && spaces[1] == spaces[2] ||
            spaces[3] == tile && spaces[3] == spaces[4] && spaces[4] == spaces[5] ||
            spaces[6] == tile && spaces[6] == spaces[7] && spaces[7] == spaces[8] ||
            // Vertical lines of 3
            spaces[0] == tile && spaces[0] == spaces[3] && spaces[3] == spaces[6] ||
            spaces[1] == tile && spaces[1] == spaces[4] && spaces[4] == spaces[7] ||
            spaces[2] == tile && spaces[2] == spaces[5] && spaces[5] == spaces[8] ||
            // Diagonal lines of 3
            spaces[0] == tile && spaces[0] == spaces[4] && spaces[4] == spaces[8] ||
            spaces[6] == tile && spaces[6] == spaces[4] && spaces[4] == spaces[2]
        )
        {
            if (tile == player)
            {
                cout<<"\n";
                cout << " You win this round!\n";
            }
            else
            {
                cout<<"\n";
                cout << " You lose this round!\n";
            }

            return true;
        }
    }

    return false;
}

bool checkTie(char *spaces)
{
    int counter = 0;
    for (int i = 0; i <= 8; i++)
    {
        if (spaces[i] == ' ')
        {
            counter++;
        }
    }

    if (counter == 0)
    {
        cout<<"\n";
        cout << " This round is a tie!\n";
        return true;
    }
    else
    {
        return false;
    }
}
