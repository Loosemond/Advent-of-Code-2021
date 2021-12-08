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
        return 2;
    }
    else if (sub[1] == 0 && sub[0] != 0)
    {
        // horizontal movement

        return 1;
    }
}

void recordMov(array<array<int, N>, N> &matrix, array<int, 2> arrS, array<int, 2> arrF, int &count)
{
    int mov = checkHMov(arrS, arrF);
    int dir = 1;

    if (mov == 2)
    {
        if (arrS[1] > arrF[1])
        {
            for (int i = arrS[1]; i >= arrF[1]; i--)
            {
                matrix[arrS[0]][i]++;
                if (matrix[arrS[0]][i] == 2)
                {
                    count++;
                }
            }
        }
        else
        {
            for (int i = arrS[1]; i <= arrF[1]; i++)
            {
                matrix[arrS[0]][i]++;
                if (matrix[arrS[0]][i] == 2)
                {
                    count++;
                }
            }
        }
    }
    else if (mov == 1)
    {
        if (arrS[0] > arrF[0])
        {
            for (int i = arrS[0]; i >= arrF[0]; i--)
            {
                matrix[i][arrS[1]]++;
                if (matrix[i][arrS[1]] == 2)
                {
                    count++;
                }
            }
        }
        else
        {
            for (int i = arrS[0]; i <= arrF[0]; i++)
            {
                matrix[i][arrS[1]]++;
                if (matrix[i][arrS[1]] == 2)
                {
                    count++;
                }
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
    //         cout << matrix[j][i] << "";
    //     }
    //     cout << "\n";
    // }
    cout << count << "\n";
}
