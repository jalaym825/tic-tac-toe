#include <bits/stdc++.h>
#include "Player.h"
#include "TTT.h"
using namespace std;

int main()
{
    TTT t;
    int i;
    for (i = 0; i < 9; i++)
    {
        if (!t.NextTurn(i % 2))
            break;
    }
    if (i == 9)
        cout << "Tie!!!" << endl;
}