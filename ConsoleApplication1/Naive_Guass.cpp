
#include "stdafx.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

void naive_gauss(int n, vector<vector<float>> MatA, float MatB[], float *MatX);

void main()
{
	cout << fixed << setprecision(6);

    vector<vector<float>> Matrix_A = 
	{
		{-5,2,1,-3},
		{7,1,2,4},
		{-3,-1,6,11},
		{7,9,8,-4}
	};
	float Matrix_B[4] = { -35,13,-1,-85 };
	float Matrix_C[4] = { 0,0,0,0 };


	cout << "Matrix A\t\t\t\t\t\t\tMatrixB\n";
	for(int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << Matrix_A[i][j] << "\t";

			if(j == 3)
			{
				cout << "|" <<Matrix_B[i] << "\n";
			}
		}
	}
	cout << "\n\n";
	
	naive_gauss(4, Matrix_A, Matrix_B, Matrix_C);

	cin.ignore();
}


void naive_gauss(int n, vector<vector<float>> MatA, float MatB[], float *MatX)
{
	n--;
	cout << fixed << setprecision(6);
	for(int k = 0; k < n; k++)
	{
		cout << "Line " << k + 1 << endl;;
		for (int i = (k+1); i <= n; i++)
		{
			const float xmult = MatA[i][k] / MatA[k][k];
			MatA[i][k] = xmult;

			for(int j = (k+1); j <= n; j++)
			{
				MatA[i][j] = MatA[i][j] - (xmult*MatA[k][j]);
				cout << MatA[i][j] << "\t";
			}
			MatB[i] = MatB[i] - (xmult * MatB[k]);
			cout <<"|"<<MatB[i] << "\n";
		}
		cout << "\n\n";
	}

	MatX[n] = MatB[n] / MatA[n][n];
	cout << "\nVals:\n";

	for(int i = n; i >= 0; i--)
	{
		float sum = MatB[i];
		for(int j = i+1; j <= n; j++)
		{
			sum = sum - (MatA[i][j] * MatX[j]);
		}
		MatX[i] = sum / MatA[i][i];
		cout << fixed << setprecision(6) << "x" << i << ":\t" << MatX[i] << "\n";
	}

	
}


