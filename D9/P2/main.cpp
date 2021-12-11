#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <set>
#include <bits/stdc++.h>

using namespace std;

#define N 10
// this could be solved with a very smart algorithm Not this case ;D

int search(vector<string> &matrix, const array<int, 2> pos, set<array<int, 2>> &CheckedPos);
int main()
{
    freopen("input.txt", "r", stdin);
    string line;

    vector<string> matrix;
    array<int, 2> pos;
    set<array<int, 2>> CheckedPos = {};
    while (getline(cin, line))
    {
        matrix.push_back(line);
    }
    int vert = 0;
    int horiz = 0;
    int count = 0;
    int high = 0;
    array<int, 3> top3 = {};

    // pos[0] = 2;
    // pos[1] = 2;
    // count = search(matrix, pos, CheckedPos);

    // cout << "\n"
    //      << count << "\n";

    for (int i = 0; i < matrix.size(); i++)
    {

        // vertical
        for (int j = 0; j < matrix[0].size(); j++)
        {
            CheckedPos.clear();
            pos[0] = i;
            pos[1] = j;
            count = search(matrix, pos, CheckedPos);
            if (count > top3[0])
            {
                top3[0] = count;
                sort(top3.begin(), top3.end());
            }
            // cout << count << " ";
        }
        // cout << "\n";
    }

    cout << top3[0] * top3[1] * top3[2] << "\n";
}

void printVector(const set<array<int, 2>> &v)
{
    for (auto &i : v)
    {
        cout << "(" << i[0] << "," << i[1] << ") ";
    }
    cout << "\n";
}

int search(vector<string> &matrix, const array<int, 2> pos, set<array<int, 2>> &CheckedPos)
{
    // cout << matrix[pos[0]][pos[1]] - '0' << " ";
    array<int, 2> next = {};
    int count = 0;
    CheckedPos.insert(pos).second;
    // horizontal check in the top line
    if (pos[0] == 0)
    {
        // check bottom left
        if (matrix[pos[0] + 1][pos[1]] > matrix[pos[0]][pos[1]] && matrix[pos[0] + 1][pos[1]] != '9')
        {
            next[0] = pos[0] + 1;
            next[1] = pos[1];
            // cout << "in: " << matrix[pos[0]][pos[1]] << " going down to check " << matrix[next[0]][next[1]] << "\n";
            // printVector(CheckedPos);
            search(matrix, next, CheckedPos);
        }
    }
    // vertical check in the bottom line
    if (pos[0] == matrix.size() - 1)
    {
        // check bottom right
        if (matrix[pos[0] - 1][pos[1]] > matrix[pos[0]][pos[1]] && matrix[pos[0] - 1][pos[1]] != '9')
        {
            next[0] = pos[0] - 1;
            next[1] = pos[1];
            // cout << "in: " << matrix[pos[0]][pos[1]] << " going up to check " << matrix[next[0]][next[1]] << "\n";
            // printVector(CheckedPos);
            search(matrix, next, CheckedPos);
        }
    }
    // vertical check in the middle
    if (pos[0] != 0 && pos[0] != matrix.size() - 1)
    {
        if (matrix[pos[0] + 1][pos[1]] > matrix[pos[0]][pos[1]] && matrix[pos[0] + 1][pos[1]] != '9')
        {
            next[0] = pos[0] + 1;
            next[1] = pos[1];
            // cout << "in: " << matrix[pos[0]][pos[1]] << " going down to check " << matrix[next[0]][next[1]] << "\n";
            // printVector(CheckedPos);
            search(matrix, next, CheckedPos);
        }

        if (matrix[pos[0] - 1][pos[1]] > matrix[pos[0]][pos[1]] && matrix[pos[0] - 1][pos[1]] != '9')
        {
            next[0] = pos[0] - 1;
            next[1] = pos[1];
            // cout << "in: " << matrix[pos[0]][pos[1]] << " going up to check " << matrix[next[0]][next[1]] << "\n";
            // printVector(CheckedPos);
            search(matrix, next, CheckedPos);
        }
    }
    // on the right
    if (pos[1] == 0)
    {
        if (matrix[pos[0]][pos[1] + 1] > matrix[pos[0]][pos[1]] && matrix[pos[0]][pos[1] + 1] != '9')
        {
            next[0] = pos[0];
            next[1] = pos[1] + 1;
            // cout << "in: " << matrix[pos[0]][pos[1]] << " going right to check " << matrix[next[0]][next[1]] << "\n";
            // printVector(CheckedPos);
            search(matrix, next, CheckedPos);
        }
    }
    // on the left
    if (pos[1] == matrix[0].size() - 1)
    {
        if (matrix[pos[0]][pos[1] - 1] > matrix[pos[0]][pos[1]] && matrix[pos[0]][pos[1] - 1] != '9')
        {
            next[0] = pos[0];
            next[1] = pos[1] - 1;
            // cout << "in: " << matrix[pos[0]][pos[1]] << " going left to check " << matrix[next[0]][next[1]] << "\n";
            // printVector(CheckedPos);
            search(matrix, next, CheckedPos);
        }
    }

    // in the middle
    if (pos[1] != 0 && pos[1] != matrix[0].size() - 1)
    {
        if (matrix[pos[0]][pos[1] - 1] > matrix[pos[0]][pos[1]] && matrix[pos[0]][pos[1] - 1] != '9')
        {
            next[0] = pos[0];
            next[1] = pos[1] - 1;
            // cout << "in: " << matrix[pos[0]][pos[1]] << " going left to check " << matrix[next[0]][next[1]] << "\n";
            // printVector(CheckedPos);
            search(matrix, next, CheckedPos);
        }

        if (matrix[pos[0]][pos[1] + 1] > matrix[pos[0]][pos[1]] && matrix[pos[0]][pos[1] + 1] != '9')
        {

            next[0] = pos[0];
            next[1] = pos[1] + 1;
            // cout << "in: " << matrix[pos[0]][pos[1]] << " going right to check " << matrix[next[0]][next[1]] << "\n";
            // printVector(CheckedPos);
            search(matrix, next, CheckedPos);
        }
    }

    return CheckedPos.size();
}
