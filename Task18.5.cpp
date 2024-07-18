#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;

class Player
{
private:
	string NamePlay;
	int ScorePlay;
public:
	Player() : NamePlay("Name"), ScorePlay(0)
	{}
	Player(string _NamePlay, int _ScorePlay) : NamePlay(_NamePlay), ScorePlay(_ScorePlay)
	{}
	void Show()
	{
		cout << "Player name: " << NamePlay << "Player score: " << ScorePlay << endl;
	}

	int GetScore()
	{
		return ScorePlay;
	}

	void SetScore(int newScore)
	{
		ScorePlay = newScore;
	}
	string GetNamePlay()
	{
		return NamePlay;
	}

	void GetName(string newNamePlay)
	{
		NamePlay = newNamePlay;
	}

	void setPlay(string newNamePlay, int newScore)
	{
		NamePlay = newNamePlay;
		ScorePlay = newScore;
	}
};

void SelectionSort(Player* pl, int size)
{
	int j;
	Player tmp;
	for (int i = 0; i < size; i++)
	{
		j = i;
		for (int k = i; k < size; k++)
		{
			if (pl[j].GetScore() > pl[k].GetScore())
			{
				j = k;
			}
		}
		tmp = pl[i];
		pl[i] = pl[j];
		pl[j] = tmp;
	}
}

int main()
{
	int size;
	cout << "Enter the number of players: ";
	cin >> size;

	string arrName;
	int arrScore;
	Player* pl = new Player[size];
	for (int i = 0, j = 0; i < size; i++, j++)
	{
		string y;
		int x;
		cout << "Enter Player: ";
		cin >> y;
		arrName = y;
		cout << "Enter Score: ";
		cin >> x;
		arrScore = x;

		pl[i].setPlay(arrName, arrScore);
	}

	cout << "\nYou enter: \n";
	for (int i = 0; i < size; i++)
	{
		pl[i].Show();
	}

	SelectionSort(pl, size);
	cout << endl;
}