#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>

using namespace std;

/*



<<< Create a class Node >>>

A node will contain:
    Name
    Connected nodes
    Type (Big or small cave) 

Option 1:
    Allow to recursively create the nodes
    1 - Needs to check if node already exists else it creates a new node
    2 - After Checking if nodes exist needs to create them without connections only name and type
    3 - Add the connections to the nodes
    ex: (DONT GET ADD START AND END CONNECTIONS)
        line 1 -> A-c
        Will create node A and c
        then it will add the connection c to node A and connection A to node c

        line 2 -> A-b
        Finds Node A and creates node b
        adds connection b to node A and connection A to node A


<<< Search  all paths >>>


We just need to have a counter with how many successfully completed paths!!!!!


Option 1: Brute ce (Kinda)
    Apply some rules while constructing the path
    problem 1 -> How to avoid trying the same path twice?
    Answer 1 -> add a counter to each cave to know if it has ben used (this counter must start at 0 when starting a new path)
    Problem 1.1 -> We can only increment if the path is legal 
    Answer 1.1 -> have a way to reverse in case of a imposible path ?? 

Option 1.1: Recursive

Option 1.2: Pipe
    pipe contains paths left to check (witch can genarete more paths to check)

    We start from the point start.
    Add all the nodes start has to the pipe (we could add the route to the node in case we needed to store successful routes)
    select the last node to "explore"
    in that node add all the possible paths select the last.
    If its a dead end on the end point e try the next cave in the pype

    move function -> we can only move to a small once!



Option 2: Brute ce!!! -- NOPE wont work !
    Try every combination!
    Have a function that checks if the path is legal!
    add a counter to each cave to know if it has ben used (this counter must start at 0 wen starting a new path)


*/

class Node
{
    // small cave type = 0 big cave type = 1
public:
    string name;
    char type;
    // use a stack !
    mutable set<set<Node>::iterator> connections; // we will just be accessing it no setters

    Node(string _name) : name{_name}
    {
        type = isCaps(_name[0]); // we assume if the 1s string is caps them all of them ar caps
    }

    void setName(string _name)
    {
        name = _name;
        type = isCaps(_name[0]);
    }

    bool operator==(Node &_node) const
    {
        if (_node.name == name)
        {
            return true;
        }
        else
            return false;
    }

    bool operator<(const Node &_node) const
    {
        // sorts by alphabetical order
        if (_node.name < name)
        {
            return true;
        }
        else
            return false;
    }

private:
    bool isCaps(char &c)
    {
        if (c >= 'A' && c <= 'Z')
            return 1;
        else
            return 0;
    }
};

void populate(vector<Node> caves, string nodeName)
{
    // need to check its type by verifing if its in caps
}

struct UniqueStack
{
    // vectors are faster  linear search then queues
    // thou sets are even faster  search So its better to have a comb of set and stack in a case were we dont want duplicate elements
    std::stack<set<Node>::iterator> q;
    // use an unordered set ?? witch one is faster  this case?
    // we have a set pointing to our stack ?? ??
    std::set<Node> s;

    void push(Node &x)
    {

        // try to add. If its successful returns true and adds the element to the set
        auto result = s.insert(x);
        if (result.second)
        { // add the element to the stack
            q.push(result.first);
            // cout << result.first->name << "\n";
        }
    }

    void pop()
    {
        s.erase(*q.top());
        q.pop();
    }

    void printStack()
    {
        if (q.empty())
        {
            return;
        }

        set<Node>::iterator cache = q.top();
        q.pop();

        cout << cache->name << "\n";

        printStack();

        q.push(cache);
    }

    void printSet()
    {
        for (set<Node>::iterator iter = s.begin(); iter != s.end(); ++iter)
        {
            cout << (iter->name) << "\n";
        }
    }
};

pair<string, string> parser(string &line)
{

    int tk = line.find("-", 0);
    pair result(line.substr(0, tk), line.substr(tk + 1, -1));
    return result;
}

void updateNodes(set<Node> &nodes, pair<string, string> input)
{
    auto addA = nodes.emplace(input.first).first;
    auto addB = nodes.emplace(input.second).first;
    addA->connections.emplace(addB);
    addB->connections.emplace(addA);
}

// void printSet(set<Node> &s)
// {
//     for (set<Node>::iterator iter = s.begin(); iter != s.end(); ++iter)
//     {
//         cout << (iter->name) << "\n";
//     }
// }

int main()
{
    freopen("testInput.txt", "r", stdin);
    string line;
    UniqueStack caves;
    // a set is faster at finding elements and cant have duplicates
    set<Node> nodes;

    while (getline(cin, line))
    {
        updateNodes(nodes, parser(line));
    }

    // printSet(nodes);
}

//TODO remove the set from the node class and use vector to simplify
