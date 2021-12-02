#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string line;
    freopen("input.txt", "r", stdin);
    int horizontal = 0;
    int depth = 0;
    int aim = 0;
    string name;
    int move;
    while (getline(cin, line))
    {
        name = line.substr(0, line.find(" "));
        move = stoi(line.substr(line.find(" "), line.length()));

        if (name == "forward")
        {
            horizontal = horizontal + move;
            depth = move * aim + depth;
        }
        else if (name == "up")
        {
            aim = aim - move;
        }
        else if (name == "down")
        {
            aim = aim + move;
        }
    }

    cout
        << "depth: " << depth << " horizontal: " << horizontal << "\n";
    cout << depth * horizontal << "\n";
}