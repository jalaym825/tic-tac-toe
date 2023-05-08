#include <bits/stdc++.h>
#include "Player.h"
#include "TTT.h"
using namespace std;

int main()
{
    TTT t;
    int i = 1;
    while (t.s.size() <= 9)
    {
        i = !i;
        if (!t.NextTurn(i))
            break;
    }
    if (i == 9)
        cout << "Tie!!!!" << endl;
}