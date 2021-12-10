#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;
class SuperString
{
public:
    string s;
    int pos;
    SuperString(string _s)
    {
        s = _s;
        // pos = _pos;
    }
};
void printMS(vector<SuperString> &display);
void printMS(vector<string> &display);
bool comp(SuperString a, SuperString b);
vector<SuperString> removeChar(SuperString a, SuperString b);
vector<SuperString> removeChar(SuperString a, SuperString b, SuperString c);
vector<SuperString> removeChar(SuperString a, SuperString b, SuperString c, SuperString d);
vector<SuperString> removeCharEqualsTo(SuperString a, SuperString b, SuperString cToRemove);
vector<SuperString> removeCharEqualsTo(SuperString a, SuperString b, SuperString c, SuperString cToRemove);
int removeOneEmpty(vector<SuperString> &v);
float displayParser(const vector<string> displayFixed, const vector<string> activeSegments);

int main()
{
    freopen("input.txt", "r", stdin);
    string line;
    int tk, size, rmEl;
    int p = 0;
    int digitsCount = 0;
    vector<SuperString> displayNumbers = {};
    vector<string> activeSegments = {};
    vector<string> displayFixed = {"", "", "", "", "", "", "", "", "", ""};
    float total = 0;
    while (getline(cin, line))
    {
        p = 0;
        displayNumbers.clear();
        activeSegments.clear();
        for (int i = 0; i < 10; i++)
        {
            tk = line.find(" ", p);

            displayNumbers.push_back(line.substr(p, tk - p));
            p = tk + 1;
        }
        sort(displayNumbers.begin(), displayNumbers.end(), comp);
        for (int i = 0; i < displayNumbers.size(); i++)
        {
            displayNumbers[i].pos = i;
        }
        // 1 -> [0] 7 -> [1] 4 -> [2]  2,3,5 -> [3-5] 0,6,9 -> [6-8] 8 -> [9]
        // store the numbers we know by default
        displayFixed = {"", displayNumbers[0].s, "", "", displayNumbers[2].s, "", "", displayNumbers[1].s, displayNumbers[9].s, ""};

        vector<SuperString> step = removeChar(displayNumbers[1], displayNumbers[0]); // returns a
        step = removeChar(displayNumbers[3], displayNumbers[4], displayNumbers[5]);
        step = removeCharEqualsTo(step[0], step[1], step[2], displayNumbers[0]);
        displayFixed[3] = displayNumbers[removeOneEmpty(step)].s; // stores number 3

        step = removeCharEqualsTo(step[0], step[1], displayNumbers[2]);
        displayFixed[5] = displayNumbers[removeOneEmpty(step)].s; // stores number 5
        displayFixed[2] = displayNumbers[step[0].pos].s;          // stores number 2

        step = removeCharEqualsTo(displayNumbers[6], displayNumbers[7], displayNumbers[8], displayFixed[3]);
        sort(step.begin(), step.end(), comp);
        displayFixed[9] = displayNumbers[step[0].pos].s;

        step = removeCharEqualsTo(displayNumbers[step[1].pos], displayNumbers[step[2].pos], displayFixed[1]);
        sort(step.begin(), step.end(), comp);
        displayFixed[0] = displayNumbers[step[0].pos].s;
        displayFixed[6] = displayNumbers[step[1].pos].s;

        tk = line.find("| ", p);
        p = tk + 2;
        while (tk != -1)
        {
            tk = line.find(" ", p);
            activeSegments.push_back(line.substr(p, tk - p));
            p = tk + 1;
        }

        total += displayParser(displayFixed, activeSegments);
    }
    printf("%.0f\n", total);
}

float displayParser(const vector<string> displayFixed, const vector<string> activeSegments)
{
    float out = 0;
    string a, b;
    // cout << "len: " << activeSegments.size() << "\n";
    for (int i = 0; i < activeSegments.size(); i++)
    {
        // cout << i << "\n";
        for (int j = 0; j < displayFixed.size(); j++)
        {
            a = activeSegments[i];
            b = displayFixed[j];
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            // cout << a << " == " << b << "\n";
            if (a == b)
            {
                // cout << "here\n";
                out += j * pow(10, (activeSegments.size() - 1) - i);
                // cout << j * pow(10, (activeSegments.size() - 1) - i) << "\n";
                break;
            }
        }
    }
    return out;
}

int removeOneEmpty(vector<SuperString> &v)
{
    /* 
    Returns the number of the element that was removed;
    */
    int cache;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].s == "")
        {
            cache = v[i].pos;
            v.erase(v.begin() + i);
            return cache;
        }
    }
    return -1;
}

vector<SuperString> removeChar(SuperString a, SuperString b)
{
    string cut = "";
    vector<SuperString> out = {};
    for (char &p : a.s)
    {
        // get the chars that persist in all of them
        if (b.s.find(p) != -1)
        {
            cut.push_back(p);
        }
    }

    for (char &p : cut)
    {
        a.s.erase(remove(a.s.begin(), a.s.end(), p), a.s.end());
        b.s.erase(remove(b.s.begin(), b.s.end(), p), b.s.end());
    }
    out.push_back(a);
    out.push_back(b);

    return out;
}

vector<SuperString> removeChar(SuperString a, SuperString b, SuperString c)
{
    string cut = "";
    vector<SuperString> out = {};

    for (char &p : a.s)
    {
        // get the chars that persist in all of them
        if (b.s.find(p) != -1 && c.s.find(p) != -1)
        {
            cut.push_back(p);
        }
    }
    for (char &p : cut)
    {
        a.s.erase(remove(a.s.begin(), a.s.end(), p), a.s.end());
        b.s.erase(remove(b.s.begin(), b.s.end(), p), b.s.end());
        c.s.erase(remove(c.s.begin(), c.s.end(), p), c.s.end());
    }
    out.push_back(a);
    out.push_back(b);
    out.push_back(c);

    return out;
}

vector<SuperString> removeChar(SuperString a, SuperString b, SuperString c, SuperString d)
{
    string cut = "";
    vector<SuperString> out = {};

    for (char &p : a.s)
    {
        // get the chars that persist in all of them
        if (b.s.find(p) != -1 && c.s.find(p) != -1 && d.s.find(p) != -1)
        {
            cut.push_back(p);
        }
    }
    for (char &p : cut)
    {
        a.s.erase(remove(a.s.begin(), a.s.end(), p), a.s.end());
        b.s.erase(remove(b.s.begin(), b.s.end(), p), b.s.end());
        c.s.erase(remove(c.s.begin(), c.s.end(), p), c.s.end());
        d.s.erase(remove(d.s.begin(), d.s.end(), p), d.s.end());
    }
    out.push_back(a);
    out.push_back(b);
    out.push_back(c);
    out.push_back(d);

    return out;
}

vector<SuperString> removeCharEqualsTo(SuperString a, SuperString b, SuperString c, SuperString cToRemove)
{
    string cut = "";
    vector<SuperString> out = {};

    for (char &p : cToRemove.s)
    {
        a.s.erase(remove(a.s.begin(), a.s.end(), p), a.s.end());
        b.s.erase(remove(b.s.begin(), b.s.end(), p), b.s.end());
        c.s.erase(remove(c.s.begin(), c.s.end(), p), c.s.end());
    }
    out.push_back(a);
    out.push_back(b);
    out.push_back(c);

    return out;
}

vector<SuperString> removeCharEqualsTo(SuperString a, SuperString b, SuperString cToRemove)
{
    string cut = "";
    vector<SuperString> out = {};

    for (char &p : cToRemove.s)
    {
        a.s.erase(remove(a.s.begin(), a.s.end(), p), a.s.end());
        b.s.erase(remove(b.s.begin(), b.s.end(), p), b.s.end());
    }
    out.push_back(a);
    out.push_back(b);

    return out;
}

void printMS(vector<SuperString> &display)
{
    for (SuperString &s : display)
    {
        cout << s.s << " ";
    }
    cout << "\n";
}

void printMS(vector<string> &display)
{
    for (string &s : display)
    {
        cout << s << " ";
    }
    cout << "\n";
}

bool comp(SuperString a, SuperString b)
{
    if (a.s.size() != b.s.size())
        return a.s.size() < b.s.size();
    return a.s < b.s;
}
