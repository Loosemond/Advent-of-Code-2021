#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class MVSum
{
public:
    int nums[3] = {-1, -1, -1};
    int point = 0;

    MVSum()
    {
    }

    void add(string line)
    {
        int num = stoi(line);
        nums[point] = num;
        point++;
        if (point > 2)
        {
            point = 0;
        }
    }

    int sum()
    {
        int total = 0;
        for (int &i : nums)
        {
            if (i == -1)
            {
                return -1;
            }
            total = total + i;
        }
        return total;
    }
};

int main()
{
    string line;
    freopen("input.txt", "r", stdin);
    int last = 0;
    int count = 0;
    int current = 0;
    MVSum mvSum, mvSumlast;

    while (getline(cin, line))
    {

        mvSum.add(line);
        current = mvSum.sum();
        last = mvSumlast.sum();
        if (current != -1 & last != -1)

        {
            if (current > last)
            {
                count++;
            }
        }
        mvSumlast.add(line);
    }

    cout << count << "\n";
}
