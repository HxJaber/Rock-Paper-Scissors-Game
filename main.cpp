#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

enum enGameChoice { Rock = 1, Paper = 2, Scissors = 3 };
enum enWinner { User = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice User = enGameChoice::Rock;
	enGameChoice Computer = enGameChoice::Rock;
	enWinner Winner = enWinner::Draw;
	string WinnerName;
};

struct stGameResults
{
	short TotalRounds = 0;
	short UserWinTimes = 0;
	short ComputerWinTimes = 0; 
	short DrawTimes = 0;
	enWinner Winner;
	string WinnerName = "";
};

short ReadUserChoice(string Message)
{
	short Number = 0;

	do
	{
		cout << Message;
		cin >> Number;

	} while (Number < 1 || Number > 3);

	return Number;
}

int RandNumber(int From, int To)
{
	int Random = rand() % (To - From + 1) + From;
	return Random;
}

enGameChoice GetComputerChoice()
{
	return enGameChoice(RandNumber(1, 3));
}

enGameChoice UserChoice()
{
	return enGameChoice(ReadUserChoice("Please Enter Your Choice [1]:Rock, [2]:Paper, [3]:Scissors ? "));
}

short ReadHowManyRounds()
{
	short GameRounds = 0;
	do
	{
		cout << "\nHow Many Rounds You Want To Play (From 1 To 10 ) ? ";
		cin >> GameRounds;

	} while (GameRounds < 1 || GameRounds > 10);

	return GameRounds;
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo) 
{
	if (RoundInfo.User == RoundInfo.Computer)
	{
		return enWinner::Draw;
	}

	switch (RoundInfo.User)
	{
	case enGameChoice::Rock:
		if (RoundInfo.Computer == enGameChoice::Paper)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Paper:
		if (RoundInfo.Computer == enGameChoice::Scissors)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Scissors:
		if (RoundInfo.Computer == enGameChoice::Rock)
		{
			return enWinner::Computer;
		}
		break;
	}

	return enWinner::User;
}

void SetRoundScreenColorAndAudio(enWinner Winner) 
{
	switch (Winner)
	{
	case (enWinner::User):
		system("color 2F");
		break;

	case (enWinner::Computer):
		system("color 4F");
		cout << "\a";
		break;

	case (enWinner::Draw):
		system("color 6F");
		break;
	}
}

string ChoiceName(enGameChoice Choice)
{
	string GameChoice[3] = { "Rock", "Paper", "Scissors" };
	return GameChoice[Choice - 1];
}

string WinnerName(enWinner winner)
{
	string Winner[3] = { "User", "Computer", "Draw" };
	return Winner[winner - 1];
}

void PrintRoundResult(stRoundInfo RoundInfo)
{
	cout << "\n____________ Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
	cout << "Player1 Choice: " << ChoiceName(RoundInfo.User) << endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.Computer) << endl;
	cout << "Round Winner   : [" << RoundInfo.WinnerName << "]\n";
	cout << "________________________________________\n" << endl;
}

enWinner WhoWonTheGame(short UserWinTimes, short ComputerWinTimes)
{
	if (UserWinTimes > ComputerWinTimes)
		return enWinner::User;
	else if (ComputerWinTimes > UserWinTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}

stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short UserWinTimes = 0;
	short ComputerWinTimes = 0;
	short DrawTimes = 0;

	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] Begins " << endl;
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.User = UserChoice();
		RoundInfo.Computer = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner::User)
		{
			UserWinTimes++;
		}
		else if (RoundInfo.Winner == enWinner::Computer)
		{
			ComputerWinTimes++;
		}
		else
		{
			DrawTimes++;
		}

		SetRoundScreenColorAndAudio(RoundInfo.Winner);
		PrintRoundResult(RoundInfo);
	}

	return
	{
		HowManyRounds,
		UserWinTimes,
		ComputerWinTimes,
		DrawTimes,
		WhoWonTheGame(UserWinTimes, ComputerWinTimes),
		WinnerName(WhoWonTheGame(UserWinTimes, ComputerWinTimes))
	};
}

void PrintGameResults(stGameResults GameResults)
{
	cout << "\n_____________________ [ Game Results ] _____________________\n\n";
	cout << "Game Rounds        : " << GameResults.TotalRounds << endl;
	cout << "Player1 Won Times  : " << GameResults.UserWinTimes << endl;
	cout << "Computer Won Times : " << GameResults.ComputerWinTimes << endl; // تعديل التسمية
	cout << "Draw Times         : " << GameResults.DrawTimes << endl;
	cout << "Final Winner       : " << GameResults.WinnerName << endl;
	cout << "____________________________________________________________\n";
}

void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		system("cls");
		system("color 0F");

		stGameResults GameResults = PlayGame(ReadHowManyRounds());

		PrintGameResults(GameResults);

		cout << "\nDo you want to play again? (Y/N): ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');

	system("cls");
	system("color 0F");
}

int main()
{
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}
