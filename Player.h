#include<bits/stdc++.h>
using namespace std;

class Player
{
public:
    string name;
    char ch;
    static int x;
    vector<int> v;
    void get()
    {
        cout << "Enter player " << x << " name: ";
        cin >> name;
        if (x == 1)
        {
            cout << "Take X or 0:";
            cin >> ch;
        }
        else
            ch = (ch == 'X' ? '0' : 'X');
        x++;
    }
    void set(int y)
    {
        v.push_back(y);
    }
    bool isWinner()
    {
        sort(v.begin(), v.end());
        vector<vector<int>> combs = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {1, 4, 7},
            {2, 5, 8},
            {3, 6, 9},
            {1, 5, 9},
            {3, 5, 7}};
        for (int i = 0; i < v.size() - 2; i++)
        {
            for (int j = i + 1; j < v.size() - 1; j++)
            {
                for (int k = j + 1; k < v.size(); k++)
                {
                    vector<int> v1 = {v[i], v[j], v[k]};
                    for (auto it : combs)
                    {
                        if (v1 == it)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
int Player::x = 1;
