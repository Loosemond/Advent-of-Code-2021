#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Payload
{
public:
    int left = 0;
    int right = 0;
    Payload(int _left, int _right) : left{_left}, right{_right}
    {
    }
    Payload(){};
};

void findMatch(string &s, int &p, double &errorPoints, int &layer);
char oppositeChar(const char &c);
int pointsCalc(const char &c);
bool isClosed(const char &c);

int main()
{

    freopen("input.txt", "r", stdin);
    string line;
    int p;
    Payload decode;
    double errorPoints = 0;
    int total = 0;
    vector<double> pointsStore = {};
    int layer;

    while (getline(cin, line))
    {
        p = 0;
        errorPoints = 0;
        while (p < line.size())
        {
            layer = 0;
            findMatch(line, p, errorPoints, layer);
        }

        // cout << "\n";
        if (errorPoints != 0)
        {
            pointsStore.emplace_back(errorPoints);
            // cout << "line: " << line << " points: " << errorPoints << "\n";
        }
    }
    sort(pointsStore.begin(), pointsStore.end());

    printf("%.0f\n", pointsStore[pointsStore.size() / 2]);
}

void findMatch(string &s, int &p, double &errorPoints, int &layer)
{

    layer++;
    const char c = oppositeChar(s[p]);

    while (p < s.length() && !isClosed(s[p + 1]))
    {
        // if next char is open calls it self
        p++;
        findMatch(s, p, errorPoints, layer);
    }
    if (s[p + 1] == c && p < s.length())
    { // if next char closes and is the same type
        p++;
        if (layer == 1)
        {
            // if we are at the top
            p += 1;
            // cout << " next char: " << s[p] << "\n";
        }
        layer--;
        return;
    }
    // case it closes and is a different type Ends loop
    // we must ignore this line
    if (p < s.length())
    {
        layer = -1;
        p = s.length();
        return;
    }
    else if (layer != -1)
    {
        // cout << c;
        errorPoints = (errorPoints * 5) + pointsCalc(c);
        layer--;
        return;
    }

    return;
}

char oppositeChar(const char &c)
{
    switch (c)
    {
    case '(':
        return ')';
    case '{':
        return '}';
    case '[':
        return ']';
    case '<':
        return '>';
    default:
        return c;
    }
}

bool isClosed(const char &c)
{
    switch (c)
    {
    case ')':
        return true;
    case '}':
        return true;
    case ']':
        return true;
    case '>':
        return true;
    default:
        return false;
    }
}

int pointsCalc(const char &c)
{
    switch (c)
    {
    case ')':
        return 1;
    case ']':
        return 2;
    case '}':
        return 3;
    case '>':
        return 4;
    default:
        return 0;
    }
}
