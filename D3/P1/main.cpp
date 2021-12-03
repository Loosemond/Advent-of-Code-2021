#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class BinaryArray
{
public:
    int countOne[5] = {0, 0, 0, 0, 0};
};

int main()
{

    freopen("input.txt", "r", stdin);

    string line;
    unsigned int gamma;
    BinaryArray reading;
    vector<vector<int>> store = {};
    vector<int> countOne = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    unsigned int mask = 1; //  00001
    int binNumb;
    int count = 0;

    while (getline(cin, line))

    {
        binNumb = stoi(line, nullptr, 2);
        for (int i = 11; i >= 0; i--)
        {
            countOne[i] = countOne[i] + (mask & binNumb);
            binNumb = binNumb >> 1;
        }
        store.push_back(countOne);
        count++;
    }
    unsigned int answer = 0;
    for (int &i : countOne)
    {
        if (i > count - i)
        {
            answer = (answer << 1) + 1;
        }
        else
        {
            answer = (answer << 1) + 0;
        }
    }
    unsigned int invert = 0b111111111111;

    cout << answer << "\n";
    cout << answer * (invert ^ answer) << "\n";
}