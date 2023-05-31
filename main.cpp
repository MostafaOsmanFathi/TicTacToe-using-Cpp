#include <iostream>
using namespace std;
#ifdef _WIN32
//for windows
#define ClearScreen system("cls");
#define StopScreen  system("pause");
#else
// for linux
#define ClearScreen system("clear");
#define StopScreen  system("echo press any key ; read");
#endif
char judge(char arr[]) {
#define WinnerCondition(a,b,c) (arr[a]==arr[b]&&arr[a]==arr[c]&&arr[b]==arr[c])
    if (WinnerCondition(0, 1, 2))
        return arr[0];
    else if (WinnerCondition(3, 4, 5))
        return arr[3];
    else if (WinnerCondition(6, 7, 8))
        return arr[6];
        ///==============================
    else if (WinnerCondition(0, 3, 6))
        return arr[0];
    else if (WinnerCondition(1, 4, 7))
        return arr[1];
    else if (WinnerCondition(2, 5, 8))
        return arr[2];
        ///==============================
    else if (WinnerCondition(0, 4, 8))
        return arr[1];
    else if (WinnerCondition(2, 4, 6))
        return arr[2];
    else
        return 'N';
}

void printScreen(char arr[]) {
    cout << endl;
    cout << "  " << arr[0] << "   |   " << arr[1] << "  |  " << arr[2] << "   \n";
    cout << "______|______|_____\n";
    cout << "  " << arr[3] << "   |   " << arr[4] << "  |  " << arr[5] << "   \n";

    cout << "______|______|_____\n";
    cout << "  " << arr[6] << "   |   " << arr[7] << "  |  " << arr[8] << "   \n";
}

int Game(const string& Player1 = "Player1", const string& Player2 = "Player2") {
    char arr[10]{ "123456789" };
    bool is_X_Turn{ true };
    int loops{ 9 };
    while (loops--) {
        ClearScreen
        ///=============
        printScreen(arr);
        ///=========
        cout << "enter your place from 1 to 9 " << "Player (" << ((is_X_Turn) ? "X" : "O") << ") turn: ";
        unsigned short int choice; cin >> choice;
        if ((arr[choice - 1] == 'X' || arr[choice - 1] == 'O') || (choice > 9 || choice < 1)) {
            //    ClearScreen
            ++loops;
            continue;

        }
        else {
            arr[choice - 1] = ((is_X_Turn) ? 'X' : 'O');
            is_X_Turn = !is_X_Turn;
            char decision = judge(arr);
            if ( decision != 'N') {
                ClearScreen
                printScreen(arr);
                cout << "Winner is Player ( " << decision << ")=(" << ((decision == 'X') ? Player1 : Player2) << ")" << endl;
                StopScreen
                return ((decision == 'X') ? 1 : 2);
            }
        }
        //ClearScreen

    }
    cout << "Draw no one win\n";
    return 0;
}

void Interface() {
    string name1, name2;
    int laps, Player1Score{ 0 }, Player2Score{ 0 };
    cout << "first Player is (X) Name: "; cin >> name1;
    cout << "second Player is (y) Name: "; cin >> name2;
    cout << "How may laps do you want:"; cin >> laps;
    while (laps--) {
        int decision = Game(name1, name2);
        if ( decision == 1)
            ++Player1Score;
        else if (decision == 2)++Player2Score;

        ClearScreen
        cout << "lap result " << name1 << ": " << Player1Score << " || " << name2 << ": " << Player2Score << endl;
        cout << "to continue press any key\n";
        StopScreen
    }

    ClearScreen
    if (Player1Score > Player2Score)cout << name1 << " is the Winner" << endl;
    else if (Player1Score < Player2Score)cout << name2 << " is the Winner" << endl;
    else cout << "draw no Winner" << endl;
    StopScreen
    ClearScreen

    cout << "do you want to play again or end the game press :(Y or y): ";
    char ch; cin >> ch;
    if (ch == 'y' || ch == 'Y') { Interface(); }
    else return;
}
int main() {
    ClearScreen
    cout << "Welcome to Tic Tac Toe Game:\n";
    Interface();
    cout << "program finished" << endl;
    return 0;
}
