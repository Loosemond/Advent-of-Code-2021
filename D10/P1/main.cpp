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

Payload findMatch(string_view s);
char oppositeChar(const char &c);
int pointsCalc(const char &c);

int main()
{

    freopen("testInput.txt", "r", stdin);
    string line;
    int p;
    int start = 0;
    Payload decode;
    int errorPoints = 0;
    while (getline(cin, line))
    {
        start = 0;

        while (line.size() - start > 0)
        {
            decode = findMatch(line.substr(start, line.size() - start));
            start = decode.right;
            errorPoints += decode.left;
        }
    }
    cout << errorPoints << "\n";
}
int iterateLine()
{
}

Payload findMatch(string_view s)
{

    // will receive a character and a string
    // will search the matching closing character
    // need to count the numer of times we find the same simboll wile searching
    // Find the first illegal character in each corrupted line of the navigation subsystem.
    // What is the total syntax error score for those errors?
    // needs to be recursive
    // wile we still s =! null we can keep iterating smaller and smaller substrings
    // if we find a match e call another findMatch till we cant call any more in that case we should return 0
    // if we dont find a match we can stop everything and return the the error value

    // we need to check ir a block outside the block we are checking does not close (if i use the stratagie defined up we check this)
    // left score
    // right the right most closed loop ??

    const char c = oppositeChar(s[0]);
    int nOcur = 0;
    int closeP; // may not work
    Payload ret;
    int i = 1;
    while (i < s.size())
    {

        if (s[i] == s[0]) // found a nother matching signal open
        {
            nOcur++;
        }
        else if (s[i] == c)
        {
            nOcur--;
            if (nOcur == -1)
            {
                if (i - 2 > 0)                           // we remove the 1s and last char
                {                                        // check if the substring isn't null
                    ret = findMatch(s.substr(1, i - 1)); // in this case we just want to find the first occurrance
                    closeP = i;
                    break;
                }
                if (i == 1) // Check this
                {
                    ret = findMatch(s.substr(2, s.size() - 2)); // in this case we just want to find the first occurrance
                    closeP = i;
                    break;
                }

                // return pointsCalc(s[0]);
            }
        }
        i++;
    }
    if (i == s.size())
        return Payload(pointsCalc(s[0]), closeP);
    return Payload(ret.left, ret.right);
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

int pointsCalc(const char &c)
{
    switch (c)
    {
    case '(':
        return 3;
    case '{':
        return 57;
    case '[':
        return 1197;
    case '<':
        return 25137;
    default:
        return 0;
    }
}
