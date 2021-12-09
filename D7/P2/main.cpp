#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void parser(vector<int> &crabs, string input);
void printCrabs(vector<int> crabs);
double gas(vector<int> &crabs, double mean);

int main()
{
    freopen("input.txt", "r", stdin);
    string line;
    vector<int> crabs = {};
    getline(cin, line);
    parser(crabs, line);
    unsigned int low = ~0;
    int mean = 0;
    int ca = 0;

    for (int i = 0; i < crabs.at(crabs.size() - 1) + 1; i++)
    {
        ca = gas(crabs, i);
        if (ca < low)
        {
            low = ca;
            mean = i;
        }
    }
    cout << low << "\n";
    // cout << mean << "\n";
}
double gas(vector<int> &crabs, double mean)
{
    double totalGas = 0;
    double dist;
    for (int &a : crabs)
    {
        dist = abs(a - mean);
        totalGas += dist * (dist + 1) / 2;
        // cout << abs(a - mean) << "\n";
    }
    return totalGas;
}

void parser(vector<int> &crabs, string input)
{
    int tk = 0;
    int p = 0;
    while (tk != -1)
    {
        tk = input.find(",", p);
        crabs.push_back(stoi(input.substr(p, tk - p)));
        p = tk + 1;
    }
    sort(crabs.begin(), crabs.end());
}

void printCrabs(vector<int> crabs)
{
    for (int &f : crabs)
    {
        cout << f << " ";
    }
    cout << "\n";
}