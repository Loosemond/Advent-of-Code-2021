#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string line;
    freopen("input.txt", "r", stdin);
    int last = 99999;
    int count = 0;
    int current = 0;

    while (getline(cin, line))
    {
        current = stoi(line);
        if (current > last)
        {
            count++;
        }
        last = current;
    }
    cout << count << "\n";
}