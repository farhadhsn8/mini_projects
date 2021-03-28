// eight queen easy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
int p(int i, int j, int n) {
	return n - fabs(i - j);
}
int q(int i, int j, int n) {
	return n + fabs(i - j);
}



int main()
{
	int A[8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (A[i] == A[j]) continue;
			for (int k = 0; k < 8; k++) {
				if (A[i] == A[k]) continue;
				if (A[j] == A[k]) continue;
				for (int l = 0; l < 8; l++) {
					if (A[i] == A[l]) continue;
					if (A[j] == A[l]) continue;
					if (A[k] == A[l]) continue;

					for (int m = 0; m < 8; m++) {
						if (A[i] == A[m]) continue;
						if (A[j] == A[m]) continue;
						if (A[k] == A[m]) continue;
						if (A[l] == A[m]) continue;

						for (int n = 0; n < 8; n++) {
							if (A[i] == A[n]) continue;
							if (A[j] == A[n]) continue;
							if (A[k] == A[n]) continue;
							if (A[l] == A[n]) continue;
							if (A[m] == A[n]) continue;

							for (int o = 0; o < 8; o++) {
								if (A[i] == A[o]) continue;
								if (A[j] == A[o]) continue;
								if (A[k] == A[o]) continue;
								if (A[l] == A[o]) continue;
								if (A[m] == A[o]) continue;
								if (A[n] == A[o]) continue;

								for (int p = 0; p < 8; p++) {
									if (A[i] == A[p]) continue;
									if (A[j] == A[p]) continue;
									if (A[k] == A[p]) continue;
									if (A[l] == A[p]) continue;
									if (A[m] == A[p]) continue;
									if (A[n] == A[p]) continue;
									if (A[o] == A[p]) continue;


								}
							}
						}
					}
				}
			}
		}
	}
		

    return 0;
}

