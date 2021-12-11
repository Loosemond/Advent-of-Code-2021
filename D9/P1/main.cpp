#include <iostream>
#include <fstream>
#include <array>
#include <vector>

using namespace std;

#define N 10
// this could be solved with a very smart algorithm Not this case ;D
int main()
{
    freopen("input.txt", "r", stdin);
    string line;

    vector<string> matrix;

    while (getline(cin, line))
    {
        matrix.push_back(line);
    }
    int tDanger = 0;
    int vert = 0;
    int horiz = 0;
    // cout << matrix[0] << "\n";
    // need to convert Char to int

    for (int i = 0; i < matrix.size(); i++)
    {

        // cout << "\n";
        // vertical
        for (int j = 0; j < matrix[0].size(); j++)
        {
            // cout << matrix[i][j] - '0' << " ";
            vert = 0;
            // horizontal check in the top line
            if (i == 0)
            {
                // check bottom left
                if (matrix[i + 1][j] > matrix[i][j])
                {
                    vert = 1;
                }
            }
            // vertical check in the bottom line
            if (i == matrix.size() - 1)
            {
                // cout << "number: " << matrix[i][j] << "\n";
                // check bottom right
                if (matrix[i - 1][j] > matrix[i][j])
                {
                    vert = 1;
                }
            }
            // vertical check in the middle
            if (i != 0 && i != matrix.size() - 1)
            {
                if (matrix[i + 1][j] > matrix[i][j] &&
                    matrix[i - 1][j] > matrix[i][j])
                {
                    vert = 1;
                }
            }
            // on the left
            if (j == 0)
            {
                if (matrix[i][j + 1] > matrix[i][j] && vert == 1)
                {
                    tDanger += 1 + matrix[i][j] - '0';
                    // cout << matrix[i][j] << "\n";
                }
            }
            // on the right
            if (j == matrix[0].size() - 1)
            {
                if (matrix[i][j - 1] > matrix[i][j] && vert == 1)
                {
                    tDanger += 1 + matrix[i][j] - '0';
                    // cout << matrix[i][j] << "\n";
                }
            }

            // in the middle
            if (j != 0 && j != matrix[0].size() - 1)
            {
                if (matrix[i][j - 1] > matrix[i][j] && matrix[i][j + 1] > matrix[i][j] && vert == 1)
                {
                    tDanger += 1 + matrix[i][j] - '0';
                    // cout << matrix[i][j] << "\n";
                }
            }

            // at the bottom

            // 4 cornors ??
        }
    }

    cout << tDanger << "\n";
}