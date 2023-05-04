#include <bits/stdc++.h>
using namespace std;

class TTT
{
private:

public:
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
    TTT()
    {
        cout << "HERE THE GAME BEGINS:" << endl;
    }
    void display();
};

void TTT::display()
{
    cout << "HERE THE GAME BEGINS:" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << ((j != 2) ? " | " : "");
        }
        cout << "\n"
             << ((i != 2) ? "---------" : "") << "\n";
    }
}