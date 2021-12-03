#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>

using namespace std;

class LifeSuport
{
public:
    vector<unsigned int> store = {};
    int bitSize = 5;
    LifeSuport(int _bitSize)
    {
        bitSize = _bitSize;
    }

    int elementRemover(unsigned int pos, bool bit)
    {
        unsigned int mask = 1 << pos;
        int size = store.size();
        int count = 0;

        if (bit)
        {
            for (auto it = store.begin(); it != store.end();)
            {

                if (!(*it & mask))
                {
                    // cout << bitset<5>(*it) << "\n";
                    store.erase(it);
                }
                else
                {
                    it++;
                }
            }
        }
        else
        {
            for (auto it = store.begin(); it != store.end();)
            {

                if (*it & mask)
                {
                    // cout << bitset<5>(*it) << "\n";
                    store.erase(it);
                }
                else
                {
                    it++;
                }
            }
        }
    }

    bool bitcounter(unsigned int pos, bool bit)
    {
        unsigned int mask = 1 << pos;
        int bitCounter = 0;
        if (bit)
        {
            for (unsigned int &i : store)
            {
                if (i & mask)
                {
                    bitCounter++;
                }
            }
            if (bitCounter >= store.size() - bitCounter)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            for (unsigned int &i : store)
            {
                if (!(i & mask))
                {
                    bitCounter++;
                }
            }
            if (bitCounter <= store.size() - bitCounter)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }

    int o2Rating()
    {
        int counter = bitSize - 1;
        while (counter >= 0)
        {
            elementRemover(counter, bitcounter(counter, 0b1));
            counter--;
        }
        return store.at(0);
    }

    int co2Scrubber()
    {
        int counter = bitSize - 1;
        while (counter >= 0 && store.size() > 1)
        {
            elementRemover(counter, bitcounter(counter, 0b0));
            counter--;
        }
        return store.at(0);
    }

    void print()
    {
        for (auto &i : store)
        {
            cout << bitset<5>(i) << "\n";
        }
        cout << "\n";
    }
};

int main()
{

    freopen("input.txt", "r", stdin);

    string line;
    unsigned int gamma;
    LifeSuport lifeSuport(12);
    LifeSuport lifeSuport2(12);

    int binNumb;
    int count = 0;

    while (getline(cin, line))

    {
        count++;
        binNumb = stoi(line, nullptr, 2);
        lifeSuport.store.push_back(binNumb);
    }
    lifeSuport2 = lifeSuport;
    cout << lifeSuport.o2Rating() * lifeSuport2.co2Scrubber() << "\n";
}
