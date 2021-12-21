#include <iostream>
#include <fstream>
#include <string>
#include <array>

#define N 10

using namespace std;

void pLevel(array<array<int, N>, N> &eLevel);
void addOne(array<array<int, N>, N> &eLevel);
int explosion(array<array<int, N>, N> &eLevel);
int steper(array<array<int, N>, N> &eLevel, int nSteps);

/* Store the initial input in a matrix

step 1 (iterates every member to check its value)
    Add one to all members
step 2 (iterates every member to check its value)
    if octopus > 9 explode
    Explosion 
        add one up down left right and all diagonals
        if its 0 dont add (an attempt to avoid overlaping)
    Go back to step 2 till there are no more explosions of light
    
*/
int main()
{
    freopen("input.txt", "r", stdin);
    string line;
    array<array<int, N>, N> eLevel = {};
    int lineN = 0;
    while (getline(cin, line))
    {
        for (int i = 0; i < N; i++)
        {
            eLevel[lineN][i] = (line[i] - '0');
        }
        lineN++;
    }
    // pLevel(eLevel);

    cout << steper(eLevel, 100) << "\n";
}

int steper(array<array<int, N>, N> &eLevel, int nSteps)
{
    int flashes = 0;
    for (nSteps > 0; nSteps--;)
    {
        addOne(eLevel);
        // cout << "after adding 1\n";
        // pLevel(eLevel);
        flashes += explosion(eLevel);
        // cout << "after explosion\n";
        // pLevel(eLevel);
    }
    return flashes;
}

int explosion(array<array<int, N>, N> &eLevel) // its going to be recursive !! ;D
{
    int expCount = 0;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (eLevel[y][x] > 9) // explode cond
            {
                expCount++;
                // need to check if its out of bounds!!
                // need to reset!
                eLevel[y][x] = 0;
                if (eLevel[y + 1][x] != 0 && y + 1 < N)
                    eLevel[y + 1][x]++;

                if (eLevel[y][x + 1] != 0 && x + 1 < N)
                    eLevel[y][x + 1]++;

                if (eLevel[y - 1][x] != 0 && y - 1 >= 0)
                    eLevel[y - 1][x]++;

                if (eLevel[y][x - 1] != 0 && x - 1 >= 0)
                    eLevel[y][x - 1]++;

                // diagonals

                if (eLevel[y + 1][x + 1] != 0 && y + 1 < N && x + 1 < N)
                    eLevel[y + 1][x + 1]++;

                if (eLevel[y - 1][x - 1] != 0 && y - 1 >= 0 && x - 1 >= 0)
                    eLevel[y - 1][x - 1]++;

                if (eLevel[y - 1][x + 1] != 0 && y - 1 >= 0 && x + 1 < N)
                    eLevel[y - 1][x + 1]++;

                if (eLevel[y + 1][x - 1] != 0 && y + 1 < N && x - 1 >= 0)
                    eLevel[y + 1][x - 1]++;
            }
        }
    }

    if (expCount > 0)
    {
        expCount += explosion(eLevel);
    }
    return expCount;
}

void addOne(array<array<int, N>, N> &eLevel)
{
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            eLevel[y][x]++;
        }
    }
}

void pLevel(array<array<int, N>, N> &eLevel)
{
    for (array<int, N> line : eLevel)
    {
        for (int a : line)
        {
            cout << a;
        }
        cout << "\n";
    }
    cout << "\n";
}

/*

34543
40004
50005
40004
34543

45654
51115
61116
51115
45654

*/