#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


class CoreGame
{
	public:
		int pitchlocation, pitchguess, hitresult, strikes, battersonbase;
	int running, outs, hits, cpuhits;
	int offense(int, int, int);
	int defense(int, int, int);
};


int CoreGame::offense(int inning,int humanpoints, int cpupoints)
{
	CoreGame Offense;
	//redeclaring potentially problematic variables
	Offense.strikes = 0;
	Offense.pitchlocation = 0;
	Offense.pitchguess = 0;
	Offense.outs = 0;
	Offense.running = 0;
	Offense.hits = 0;
	Offense.hitresult = 0;
	Offense.battersonbase = 0;

	do {
		printf("***************\n Inning #: %d\nHuman Score: %d\nCPU Score: %d\n***************\n", inning, humanpoints, cpupoints);
		srand(time(NULL));
		Offense.pitchlocation = rand() % 6 + 1;
		int outmethod = 0;
		outmethod = rand() % 2 + 1;

		std::cout << "Get Ready for the pitch! ||" << "Strikes:" << Offense.strikes <<
			"|| " << "||Outs:" << Offense.outs << "||" << "\nType a location (number from 1 to 6) to guess where the defense will pitch" << "\n";
		std::cin >> (Offense.pitchguess);

		if (Offense.pitchguess == Offense.pitchlocation)
		{
			std::cout << "Swing and a hit!\n";
			Offense.hitresult = rand() % 4 + 0;

			switch (Offense.hitresult)
			{
				case 0:
					Offense.outs++;
					if (outmethod == 1)
					{
						std::cout << "The batter's hit was caught. " << "OUT #: " << Offense.outs << "\n ";
						if (Offense.outs == 3)
						{
							std::cout << "Offense Over! The side is retired. || Total Hits: " << Offense.hits << " ||\n";
							Offense.running++;
						}
					}
					if (outmethod == 2)
					{
						std::cout << "The batter hit a ground ball. Defense got the ball to first base before the runner could make it. " << "OUT #: " << Offense.outs << "\n";
						if (Offense.outs == 3)
						{
							std::cout << "Offense Over! The side is retired. || Total Hits: " << Offense.hits << " ||\n";
							Offense.running++;
						}
					}
					Offense.strikes = 0;
					break;

				case 1:
					std::cout << "The batter got a single base hit\n";
					battersonbase++;
					Offense.hits++;
					Offense.strikes = 0;
					break;

				case 2:
					std::cout << "The batter got a double\n";
					if (battersonbase != 0)
					{
						printf("a run came home to score!\n");
						humanpoints++;
					}
					battersonbase++;
					Offense.hits++;
					Offense.strikes = 0;
					break;

				case 3:
					std::cout << "The batter got a triple\n";
					if (battersonbase != 0)
					{
						printf("a run came home to score!\n");
						humanpoints++;
					}
					battersonbase++;
					Offense.hits++;
					Offense.strikes = 0;
					break;

				case 4:
					std::cout << "The batter got a home run!\n";
					humanpoints = humanpoints + battersonbase;
					Offense.hits++;
					Offense.strikes = 0;
					break;
			}
		}

		else
		{
			if (Offense.pitchguess > 6 || Offense.pitchguess < 1)
			{
				std::cout << "Invalid Input. Skipping to next inning.\n";
				//fixing input buffer for reuse
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				Offense.running++;
			}
			else
			{
				std::cout << "Swing and a miss\n";
				Offense.strikes = Offense.strikes + 1;
				if (Offense.strikes == 3)
				{
					Offense.outs++;
					std::cout << "Out #" << Offense.outs << "!\n";
					Offense.strikes = 0;
				}
				if (Offense.outs == 3)
				{
					std::cout << "Offense Over! The side is retired. || Total Hits: " << Offense.hits << " ||\n";
					Offense.running++;
				}
			}
		}
	}
	while (Offense.running == 0);
	return humanpoints;
}


int CoreGame::defense(int inning, int humanpoints, int cpupoints)
{
	CoreGame Defense;
	Defense.strikes = 0;
	Defense.pitchlocation = 0;
	Defense.outs = 0;
	Defense.running = 0;
	Defense.cpuhits = 0;

	do {
		printf("***************\n Inning #: %d\nHuman Score: %d\nCPU Score: %d\n***************\n", inning, humanpoints, cpupoints);
		srand(time(NULL));
		Defense.pitchguess = rand() % 6 + 1;
		int outmethod = 0;
		outmethod = rand() % 2 + 1;

		std::cout << "Get Ready to pitch! ||" << "Strikes:" << Defense.strikes <<
			"||" << "||Outs:" << Defense.outs << "||""\nType a location (number from 1 to 6) to choose a location to pitch." << "\n";
		std::cin >> Defense.pitchlocation;

		if (Defense.pitchguess == Defense.pitchlocation)
		{
			std::cout << "Swing and a hit!\n";
			Defense.hitresult = rand() % 4 + 0;
			switch (Defense.hitresult)
			{
				case 0:
					Defense.outs++;
					if (outmethod == 1)
					{
						std::cout << "The batter's hit was caught. " << "OUT #: " << Defense.outs << "\n ";
						if (Defense.outs == 3)
						{
							std::cout << "Offense Over! The side is retired. || Total Hits: " << Defense.hits << " ||\n";
							Defense.running++;
						}
					}
					if (outmethod == 2)
					{
						std::cout << "The batter hit a ground ball. Defense got the ball to first base before the runner could make it. " << "OUT #: " << Defense.outs << "\n";
						if (Defense.outs == 3)
						{
							std::cout << "Offense Over! The side is retired. || Total Hits: " << Defense.hits << " ||\n";
							Defense.running++;
						}
					}
					Defense.strikes = 0;
					break;

				case 1:
					std::cout << "The batter got a single base hit\n";
					battersonbase++;
					Defense.cpuhits++;
					Defense.strikes = 0;
					break;

				case 2:
					std::cout << "The batter got a double\n";
					if (battersonbase != 0)
					{
						printf("a run came home to score!\n");
						cpupoints++;
					}
					battersonbase++;
					Defense.cpuhits++;
					Defense.strikes = 0;
					break;

				case 3:
					std::cout << "The batter got a triple\n";
					if (battersonbase != 0)
					{
						printf("a run came home to score!\n");
						cpupoints++;
					}
					battersonbase++;
					Defense.cpuhits++;
					Defense.strikes = 0;
					break;

				case 4:
					std::cout << "The batter got a home run!\n";
					cpupoints = cpupoints + battersonbase;
					Defense.cpuhits++;
					Defense.strikes = 0;
					break;
			}
		}

		else
		{
			if (Defense.pitchlocation > 6 || Defense.pitchlocation < 1)
			{
				std::cout << "Invalid Input. Skipping to next inning.\n";
				//fixing input buffer for reuse
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				Defense.running++;
			}
			else
			{
				std::cout << "Swing and a miss\n";
				Defense.strikes = Defense.strikes + 1;
				if (Defense.strikes == 3)
				{
					Defense.outs++;
					std::cout << "Out #" << Defense.outs << "!\n";
					Defense.strikes = 0;
				}
				if (Defense.outs == 3)
				{
					std::cout << "Defense Over! The side is retired. || Total Hits: " << Defense.cpuhits << " ||\n";
					Defense.running++;
				}
			}
		}
	}
	while (Defense.running == 0);
	return cpupoints;
}