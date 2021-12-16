#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

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

int findMatch(string_view s, int &p, int &errorPoints);
char oppositeChar(const char &c);
int pointsCalc(const char &c);
bool isClosed(const char &c);

int main()
{

    freopen("input.txt", "r", stdin);
    string line;
    int p;
    Payload decode;
    int errorPoints = 0;
    int total = 0;

    while (getline(cin, line))
    {
        p = 0;
        errorPoints = 0;

        findMatch(line, p, errorPoints);
        // if (errorPoints != 0)
        // {
        //     cout << "line: " << line << " points: " << errorPoints << "\n";
        // }
        total += errorPoints;
    }
    cout << total << "\n";
}
int iterateLine()
{
}

int findMatch(string_view s, int &p, int &errorPoints)
{

    /* read the 1s string
if open
    read next string
        if open calls it self
        if closed and the same type ends successfully 
        if closed and different type end with error and returns error points
if closed and the same type ends successfully 
if closed and different type end with error and returns error points

*/

    const char c = oppositeChar(s[p]);
    int nOcur = 0;
    int closeP; // may not work

    // cout << s[p] << "\n";
    while (p < s.length() && !isClosed(s[p + 1]) && errorPoints == 0) // we dont want to find all the errors
    {
        p++;
        findMatch(s, p, errorPoints);
    }
    if (s[p + 1] == c)
    { // if closes and is the same type
        p += 1;
        return 0;
    }
    // case it closes and is a different type Ends loop
    if (p < s.length() && errorPoints == 0)
    {
        errorPoints += pointsCalc(s[p + 1]);
    }
    return 0;
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
        return 3;
    case ']':
        return 57;
    case '}':
        return 1197;
    case '>':
        return 25137;
    default:
        return 0;
    }
}
