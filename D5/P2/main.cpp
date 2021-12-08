#include <iostream>
#include <fstream>
#include <array>

#define N 1000
using namespace std;

int checkHMov(array<int, 2> _ar1, array<int, 2> _ar2)
{
    array<int, 2> sub;
    for (int i = 0; i < _ar1.size(); i++)
    {
        sub[i] = _ar1[i] - _ar2[i];
    }

    if (sub[0] == 0 && sub[1] != 0)
    {
        // Horizontal movement

        return 2;
    }
    else if (sub[1] == 0 && sub[0] != 0)
    {
        // Vertical movement

        return 1;
    }
    else
    {
        // Diagonal movement
        return 3;
    }
}

void recordMov(array<array<int, N>, N> &matrix, array<int, 2> arrS, array<int, 2> arrF, int &count)
{
    int mov = checkHMov(arrS, arrF);

    if (mov == 2)
    {
        // Horizontal movement

        int xDiff = arrS[1] - arrF[1];
        int xDir = 1;
        (xDiff > 0) ? xDir = -1 : xDir = 1;
        for (int i = 0; i <= abs(xDiff); i++)
        {
            matrix[arrS[0]][arrS[1] + (i * xDir)]++;
            if (matrix[arrS[0]][arrS[1] + (i * xDir)] == 2)
            {
                count++;
            }
        }
    }
    else if (mov == 1)
    {
        // Vertical movement
        int yDiff = arrS[0] - arrF[0];
        int yDir = 1;
        (yDiff > 0) ? yDir = -1 : yDir = 1;
        for (int i = 0; i <= abs(yDiff); i++)
        {
            matrix[arrS[0] + (i * yDir)][arrS[1]]++;
            if (matrix[arrS[0] + (i * yDir)][arrS[1]] == 2)
            {
                count++;
            }
        }
    }
    else if (mov == 3)
    {
        // Diagonal movement
        int xDiff = arrS[1] - arrF[1];
        int yDiff = arrS[0] - arrF[0];
        int xDir = 1;
        int yDir = 1;
        (yDiff > 0) ? yDir = -1 : yDir = 1;
        (xDiff > 0) ? xDir = -1 : xDir = 1;
        // i is the steps
        // We are only considering 45 degrees movement!
        for (int i = 0; i <= abs(xDiff); i++)
        {
            matrix[arrS[0] + (i * yDir)][arrS[1] + (i * xDir)]++;
            if (matrix[arrS[0] + (i * yDir)][arrS[1] + (i * xDir)] == 2)
            {
                count++;
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    string line;
    array<array<int, N>, N> matrix = {};
    int p = 0;
    int tk = 0;
    array<int, 2> start = {};
    array<int, 2> finish = {};
    int count = 0;
    while (getline(cin, line))
    {
        p = 0;
        tk = line.find(",", p);
        start[0] = stoi(line.substr(p, tk - p));
        p = tk + 1;
        tk = line.find(" ", p);

        start[1] = stoi(line.substr(p, tk - p));
        p = tk + 1;
        p = line.find("-> ", p) + 3;
        // cout << p << "\n";
        tk = line.find(",", p);
        // cout << line.substr(p, tk - p) << "\n";
        finish[0] = stoi(line.substr(p, tk - p));
        p = tk + 1;
        tk = line.find("\n", p);
        finish[1] = stoi(line.substr(p, tk - p));
        recordMov(matrix, start, finish, count);
    }
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         //OPS its FLIPPED!
    //         cout << matrix[j][i] << "";
    //     }
    //     cout << "\n";
    // }
    cout << count << "\n";
}
