#include <bits/stdc++.h>
#include "Player.h"
#include "TTT.h"
using namespace std;

int main()
{
    TTT t;
    Player p1, p2;
    p1.get();
    p2.get();
    int in;
    int i;
    for (i = 0; i < 9; i++)
    {
        if (i % 2 == 0)
        {
            cout << p1.name << "'s Turn: ";
            cin >> in;
            t.v[t.m1[in].first][t.m1[in].second] = p1.ch;
            p1.set(in);
            t.display();
            if (p1.v.size() >= 3 && p1.isWinner())
            {
                cout << p1.name << " won the game." << endl;
                break;
            }
        }
        else
        {
            cout << p2.name << "'s Turn: ";
            cin >> in;
            t.v[t.m1[in].first][t.m1[in].second] = p1.ch == 'X' ? '0' : 'X';
            p2.set(in);
            t.display();
            if (p2.v.size() >= 3 && p2.isWinner())
            {
                cout << p2.name << " won the game." << endl;
                break;
            }
        }
    }
    if (i == 9)
        cout << "Tie!!!" << endl;
}