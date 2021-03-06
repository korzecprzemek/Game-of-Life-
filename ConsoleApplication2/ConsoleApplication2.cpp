// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<windows.h>
#include<cstdlib>

using namespace std;

const int SIZE_X = 7;
const int SIZE_Y = 7;

void createNextGeneration(bool currentGeneration[SIZE_X][SIZE_Y], bool nextGeneration[SIZE_X][SIZE_Y]);

int countNeighbours(int x, int y, bool currentGeneration[SIZE_X][SIZE_Y]);

bool applyDefaultRules(int numberOfNeighbours, bool isCurrentlyAlive);

void printGrid(bool currentGeneration[SIZE_X][SIZE_Y]);

void printCell(bool cell);

int main()
{
	bool currGen[SIZE_X][SIZE_Y] = {
		{ 0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0 },
		{ 0,0,0,1,0,0,0 },
		{ 0,0,0,1,1,0,0 },
		{ 0,0,0,1,1,0,0 },
		{ 0,0,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0 },
	};
	bool nextGen[SIZE_X][SIZE_Y];
	
	for (int i = 0; i < SIZE_X; i++)
	{
		for (int j = 0; j < SIZE_Y; j++)
		{
			printCell(currGen[i][j]);
		}
		cout << endl;
	}

	while (true)
	{	
		createNextGeneration(currGen, nextGen);

		Sleep(500);
		system("CLS");
		for (int i = 0; i < SIZE_X; i++)
		{
			for (int j = 0; j < SIZE_Y; j++)
			{
				printCell(nextGen[i][j]);
			}
			cout << endl;	
		}
		
		// snapshot...
		for (int i = 0; i < SIZE_X; i++) {
			for (int j = 0; j < SIZE_Y; j++) {
				currGen[i][j] = nextGen[i][j];
			}
		}
	}
	
	system("pause");
	return 0;
}

void printCell(bool cell) {
	if (cell)
	{
		cout << " * ";
	}
	else
	{
		cout << "  ";
	}

}
void createNextGeneration(bool currentGeneration[SIZE_X][SIZE_Y], bool nextGeneration[SIZE_X][SIZE_Y]) {
	for (int x = 0; x < SIZE_X; x++) {
		for (int y = 0; y < SIZE_Y; y++) {
			int numberOfNeighbours = countNeighbours(x, y, currentGeneration);
			
			bool isCurrentlyAlive = currentGeneration[x][y];
			bool isCellAlive = applyDefaultRules(numberOfNeighbours, isCurrentlyAlive);

			nextGeneration[x][y] = isCellAlive;
		}
	}
}

int countNeighbours(int x, int y, bool currentGeneration[SIZE_X][SIZE_Y]) {
	int cnt = 0;
	/*int row = SIZE_X;
	int col = SIZE_Y;*/
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (i == x && j == y) { // we do not want to check ourself
				continue;
			}

			bool isNeighboursAlive = currentGeneration[(i + SIZE_X) % SIZE_X][(j + SIZE_Y) % SIZE_Y];
			if (isNeighboursAlive) 
			{
				++cnt;
			}
		}
	}

	return cnt;
}

bool applyDefaultRules(int numberOfNeighbours, bool isCurrentlyAlive) {
	if ((numberOfNeighbours == 3) || (isCurrentlyAlive && (numberOfNeighbours == 2))) {
		return true;
	}
	else {
		return false;
	}
}
void printGrid(bool currentGeneration[SIZE_X][SIZE_Y]) {
	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			if (currentGeneration[a][b] == true)
			{
				cout << " 🔥 ";
			}
			else
			{
				cout << " . ";
			}
			if (b == 3 - 1)
			{
				cout << endl;
			}
		}
	}
}

