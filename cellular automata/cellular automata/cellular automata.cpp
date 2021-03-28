// cellular automata.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main() {

	//Number of rows and columns   
	const char live = '*';
	const char dead = ' ';
	const int rows = 10;
	const int cols = 10;
	char life[rows][cols];
	char life1[rows][cols];

	int ans = 0;


	//create initial generation randomly

	srand(time(NULL));
	int cell;


	for (int r = 0; r<rows; r++) {

		for (int c = 0; c<cols; c++) {

			cell = rand() % 10;
			if (cell >= 5) {
				life[r][c] = live;
			}
			else {
				life[r][c] = dead;
			}

		}
	}


	for (int r = 0; r < rows; r++) {
		for (int c = 0; c<cols; c++) {
			cout << life[r][c] << " ";
		}
		cout << endl;
	}

	for (int k = 0; k <10; k++) {
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c<cols; c++) {
				if (life[r][c] == live) {
					if ((c - 1) >= 1 && (life[r][c - 1] == live))
						ans++;
					if (c<cols && (life[r][c + 1] == live))
						ans++;
					if (c<cols && r<rows && (life[r + 1][c + 1] == live))
						ans++;
					if (r<rows && (life[r + 1][c] == live))
						ans++;
					if (c<cols && c >= 0 && (life[r + 1][c - 1] == live))
						ans++;
					if (r >= 0 && c >= 0 && (life[r - 1][c - 1] == live))
						ans++;
					if (r >= 0 && (life[r - 1][c] == live))
						ans++;
					if (r >= 0 && c<cols && (life[r - 1][c + 1] == live))
						ans++;
					if (ans == 2 || ans == 3)
						life[r][c] = live;
					if (ans>3)
						life[r][c] = dead;
					if (ans<2)
						life[r][c] = live;

				}
				else {
					if (life[r][c] == dead) {
						if (c >= 0 && (life[r][c - 1] == dead))
							ans++;
						if (c<cols && (life[r][c + 1] == dead))
							ans++;
						if (r<rows && c<cols && (life[r + 1][c + 1] == dead))
							ans++;
						if (r<rows && (life[r][c] == life[r + 1][c]))
							ans++;
						if (r<rows && c>0 && (life[r][c] == life[r + 1][c - 1]))
							ans++;
						if (r >= 0 && c >= 0 && (life[r][c] == life[r - 1][c - 1]))
							ans++;
						if (r >= 0 && (life[r][c] == life[r - 1][c]))
							ans++;
						if (r >= 0 && c<cols && (life[r][c] == life[r - 1][c + 1]))
							ans++;
						if (ans == 3)
							life[r][c] = live;

					}
				}
			}
		}

		for (int r = 0; r<rows; r++) {
			for (int c = 0; c< cols; c++) {
				life[r][c] = life1[r][c];
			}
		}

		for (int r = 0; r<rows; r++) {
			for (int c = 0; c<cols; c++) {
				cout << life[r][c] << " ";

			}
			cout << endl;
		}
	}

	return 0;
}


