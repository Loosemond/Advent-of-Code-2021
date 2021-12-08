#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void parser(vector<int> &fishes, string input);
void printFish(vector<int> fishes);
int aging(vector<int> fishes, int years);

int main()
{
    freopen("input.txt", "r", stdin);
    string input;
    getline(cin, input);
    vector<int> fishes = {};
    parser(fishes, input);
    // printFish(fishes);
    aging(fishes, 80);
}

int aging(vector<int> fishes, int gen)
{
    for (int days = 0; days < gen; days++)
    {
        // cout << "day\n";
        int eggs = 0;
        for (int i = 0; i < fishes.size(); i++)
        {
            fishes[i]--;
            if (fishes[i] < 0)
            {
                fishes[i] = 6;
                eggs++;
            }
        }
        for (int i = 0; i < eggs; i++)
        {
            fishes.push_back(8);
        }
        // printFish(fishes);
    }

    cout << fishes.size() << "\n";
    return fishes.size();
}

void parser(vector<int> &fishes, string input)
{
    int tk = 0;
    int p = 0;
    while (tk != -1)
    {
        tk = input.find(",", p);
        fishes.push_back(stoi(input.substr(p, tk - p)));
        p = tk + 1;
    }
}

void printFish(vector<int> fishes)
{
    for (int &f : fishes)
    {
        cout << f << " ";
    }
    cout << "\n";
}