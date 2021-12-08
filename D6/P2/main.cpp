#include <iostream>
#include <vector>
#include <fstream>
#include <array>
#include <cstring>
#define N 9

using namespace std;

void parser(array<double, N> &fishes, string input);
void printFish(array<double, N> fishes);
double aging(array<double, N> fishes, int years);

// create a vector with 8 stages
// record how many are in each stage

int main()
{
    freopen("input.txt", "r", stdin);
    string input;
    getline(cin, input);
    array<double, N> fishes = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    parser(fishes, input);
    // printFish(fishes);
    printf("%.0f\n", aging(fishes, 256));
}

double aging(array<double, N> fishes, int gen)
{
    for (int days = 0; days < gen; days++)
    {
        array<double, N> nextGen = {};
        double cache, eggs;
        int p = 0;
        for (int i = 0; i < fishes.size(); i++)
        {

            p = i - 1;
            if (p < 0)
            {
                nextGen[8] += fishes[i];
                eggs = fishes[i];
            }
            else
            {
                nextGen[p] += fishes[i];
            }
            if (p == 6)
            {
                nextGen[6] += eggs;
            }
        }
        for (int i = 0; i < fishes.size(); i++)
        {
            fishes[i] = nextGen[i];
        }
        // printFish(fishes);
    }
    double sum = 0;
    for (double &i : fishes)
    {
        sum += i;
    }
    return sum;
}

void parser(array<double, N> &fishes, string input)
{
    int tk = 0;
    int p = 0;
    while (tk != -1)
    {
        tk = input.find(",", p);
        fishes[stoi(input.substr(p, tk - p))]++;
        p = tk + 1;
    }
}

void printFish(array<double, N> fishes)
{
    for (int i = 0; i < fishes.size(); i++)
    {
        cout << i << ": " << fishes[i] << "\n";
    }
    cout << "\n";
}