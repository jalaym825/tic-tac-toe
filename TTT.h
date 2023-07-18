#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <signal.h>

using namespace std;

class TTT
{
private:
    vector<vector<char>> v = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    map<int, pair<int, int>> m1 = {
        {1, {0, 0}},
        {2, {0, 1}},
        {3, {0, 2}},
        {4, {1, 0}},
        {5, {1, 1}},
        {6, {1, 2}},
        {7, {2, 0}},
        {8, {2, 1}},
        {9, {2, 2}},
    };
    Player players[2];

public:
    set<int> s;
    TTT()
    {
        cout << "HERE THE GAME BEGINS:" << endl;
        players[0].get();
        players[1].get();
    }
    void display();
    bool NextTurn(int);
};

void TTT::display()
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << ((j != 2) ? " | " : "");

        cout << "\n"
             << ((i != 2) ? "---------" : "") << "\n";
    }
    cout << endl;
}

bool TTT::NextTurn(int p)
{
    // int waitSecond = 10; // it'll wait for half of it's
    int in;
    // cout << players[p].name << "'s Turn: ";
    while (true)
    {
        // while (1)
        // {
        //     if (kbhit())
        //     {
        //         cin >> in;
        //         break;
        //     }

        //     Sleep(500); // sleep for 1/2 sec ;
        //     --waitSecond;

        //     if (waitSecond == 0) // wait complete.
        //     {
        //         system("cls");
        //         display();
        //         cout << players[p].name << "'s turn has been skipped!" << endl;
        //         // cout << players[p].name << "'s Turn: ";
        //         return true;
        //     }
        // }
        cout << players[p].name << "'s Turn: ";
        cin >> in;

        if (s.count(in) == 1)
        {
            system("cls");
            display();
            cout << "Your input already taken in this game!" << endl;
            continue;
        }
        if (in <= 0 || in > 9)
        {
            system("cls");
            display();
            cout << "Your input is out of range!" << endl;
            continue;
        }

        v[m1[in].first][m1[in].second] = players[p].ch;
        players[p].set(in);
        s.insert(in);
        system("cls");
        display();
        if (players[p].v.size() >= 3 && players[p].isWinner())
        {
            cout << players[p].name << " won the game." << endl;
            return false;
        }
        return true;
    }
}