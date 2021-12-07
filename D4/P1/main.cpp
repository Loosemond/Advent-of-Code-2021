#include <iostream>
#include <fstream>
#include <vector>
#include <array>

#define N 5
using namespace std;

class Bingo
{
public:
	vector<int> rng = {};
	vector<array<array<int, N>, N>> boards = {};

	Bingo(string _rng)
	{
		int tk = 0;
		int p = 0;

		while (tk != -1)
		{
			tk = _rng.find(",", p);
			rng.push_back(stoi(_rng.substr(p, tk)));
			p = tk + 1;
		}
	}

	void printAllRng()
	{
		for (int &i : rng)
		{
			cout << i << "\n";
		}
	}

	void printAll()
	{
		for (auto &a : boards)
		{
			for (auto &b : a)
			{
				for (auto &c : b)
				{
					cout << c << " ";
				}
				cout << "\n";
			}
			cout << "\n";
		}
	}

	int finalAnser(int boardNumber, int finalRound)
	{
		int sum = 0;
		int f = 0;
		int cache;
		for (int l = 0; l < N; l++)
		{
			for (int c = 0; c < N; c++)
			{
				f = 0;
				cache = boards.at(boardNumber)[l][c];
				for (int round = 0; round <= finalRound; round++)
				{
					if (cache == rng.at(round))
					{
						f = 1;
						round = finalRound;
					}
				}
				if (f == 0)
				{
					sum = sum + cache;
				}
			}
		}

		return sum * rng.at(finalRound);
	}
	int checkWinRound()
	{
		vector<int> ansers(rng);
		array<array<int, N>, N> beans = {};
		array<int, N> lBeans = {};
		array<int, N> cBeans = {};

		int allSum = 0;
		int lineWin = 0;
		int beansNum = 0;
		int boardNum = 0;
		int WinnerBoard = 0;
		int lowestNRounds = 999999;
		// cout << "Number of Boards: " << boards.size() << "\n";
		for (auto &board : boards)
		{

			for (int round = 0; round < ansers.size(); round++)
			// for each round i will check if the board has the number
			{
				for (int l = 0; l < N; l++)
				{
					for (int c = 0; c < N; c++)
					{
						if (board[l][c] == ansers.at(round))
						{
							lBeans[l]++;
							cBeans[c]++;
							if (lBeans[l] == 5 || cBeans[c] == 5)
							{
								if (round < lowestNRounds)
								{
									lowestNRounds = round;
									WinnerBoard = boardNum;
									// cout << "Board Number: " << boardNum
									// 	 << " Number: " << ansers.at(round) << " Round: " << round << "\n";
									goto NEXTBOARD;
								}
							}
						}
					}
				}
			}
		NEXTBOARD:
			lBeans = {};
			cBeans = {};
			boardNum++;
		}

		return finalAnser(WinnerBoard, lowestNRounds);
	}
};
int main()
{
	freopen("input.txt", "r", stdin);
	string line;
	string rng;
	getline(cin, line);
	Bingo bingo(line);
	int cardL = 0;
	array<array<int, N>, N> card = {};
	int p = 0;
	int tk = 0;
	int cardC = 0;
	string subs;
	getline(cin, line);
	while (getline(cin, line))
	{
		if (line != "")
		{

			while (cardC < N && tk != -1)
			{
				// some numbers have a space before like  " 8"
				tk = line.find(" ", p);
				subs = line.substr(p, tk - p);
				if (subs.length() != 0)
				{
					card[cardL][cardC] = stoi(subs);
					cardC++;
				}

				p = tk + 1;
			}
			cardC = 0;
			p = 0;
			tk = 0;
			cardL++;
		}
		else
		{
			bingo.boards.push_back(card);
			cardL = 0;
		}
	}
	bingo.boards.push_back(card);

	// bingo.printAll();

	cout << bingo.checkWinRound() << "\n";
}
