#include <bits/stdc++.h>
using namespace std;

class TTT
{
private:
    vector<vector<char>> v = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    set<int> s;
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
    int in;
    while (true)
    {
        cout << players[p].name << "'s Turn: ";
        cin >> in;
        if (s.count(in) == 1)
        {
            cout << "Your input already taken in this game!" << endl;
            continue;
        }
        if (in <= 0 || in > 9)
        {
            cout << "Your input is out of range!" << endl;
            continue;
        }

        v[m1[in].first][m1[in].second] = players[p].ch;
        players[p].set(in);
        s.insert(in);
        display();
        if (players[p].v.size() >= 3 && players[p].isWinner())
        {
            cout << players[p].name << " won the game." << endl;
            return false;
        }
        return true;
    }
}