#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    string line;
    int tk, size;
    int p = 0;
    int digitsCount = 0;
    while (getline(cin, line))
    {
        p = 0;
        tk = line.find("| ", p);
        p = tk + 2;
        while (tk != -1)
        {
            tk = line.find(" ", p);
            size = line.substr(p, tk - p).size();
            // cout << line.substr(p, tk - p) << " ";
            if (size >= 2 && size <= 4 || size == 7)
            {
                digitsCount++;
            }
            p = tk + 1;
        }

        // cout << "\n";
    }

    cout << digitsCount << "\n";
}