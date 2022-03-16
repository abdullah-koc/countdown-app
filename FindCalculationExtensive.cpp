// FindCalculationExtensive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdlib> 
#include <ctime> 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;



void FindCalculation(int* digits, int quarter, int desiredNumber) {
	string operations[4] = { "+", "-", "*", "/" }; //all operations
	int mergedNumbers[6]; //digits + quarter
	int digitsNew[6]; //used for each permutation

	//all possible permutations of mergedNumbers
	int** permutations = new int*[720]; 
	for (int i = 0; i < 720; ++i) 
	{
		permutations[i] = new int[6];
	}
	int index = 0; //permutation index

	//making digits + quarter
	for (int i = 0; i < 5; ++i) 
	{
		mergedNumbers[i] = digits[i];
	}
	mergedNumbers[5] = quarter;

	//saving all permutations
	do {
		for (int i = 0; i < 6; ++i)
		{
			permutations[index][i] = mergedNumbers[i];
		}
		index++;
	} while (next_permutation(mergedNumbers, mergedNumbers + 6));
	
	//for each permutation, calculate if there is a valid result
	for (int x = 0; x < 720; ++x) {

		//digitsNew is the array which will be used for a permutation
		for (int c = 0; c < 6; ++c)
		{
			digitsNew[c] = permutations[x][c];
		}

		for (int i = 0; i < 4; ++i)
		{
			int temp1;
			if (operations[i] == "+")
			{
				temp1 = digitsNew[0] + digitsNew[1];
			}
			else if (operations[i] == "-")
			{
				temp1 = digitsNew[0] - digitsNew[1];
			}
			else if (operations[i] == "*")
			{
				temp1 = digitsNew[0] * digitsNew[1];
			}
			else
			{
				temp1 = digitsNew[0] / digitsNew[1];
			}

			if (temp1 == desiredNumber) {
				cout << digitsNew[0] << operations[i] << digitsNew[1];

				//freeing permutation array memory
				for (int p = 0; p < 720; ++p)
				{
					delete[] permutations[p];
				}
				delete[] permutations;

				return;
			}
			for (int j = 0; j < 4; ++j)
			{
				int temp2;
				if (operations[j] == "+")
				{
					temp2 = temp1 + digitsNew[2];
				}
				else if (operations[j] == "-")
				{
					temp2 = temp1 - digitsNew[2];
				}
				else if (operations[j] == "*")
				{
					temp2 = temp1 * digitsNew[2];
				}
				else
				{
					temp2 = temp1 / digitsNew[2];
				}
				if (temp2 == desiredNumber) {
					cout << digitsNew[0] << operations[i] << digitsNew[1] << operations[j] << digitsNew[2];

					//freeing permutation array memory
					for (int p = 0; p < 720; ++p)
					{
						delete[] permutations[p];
					}
					delete[] permutations;

					return;
				}
				for (int k = 0; k < 4; ++k)
				{
					int temp3;
					if (operations[k] == "+")
					{
						temp3 = temp2 + digitsNew[3];
					}
					else if (operations[k] == "-")
					{
						temp3 = temp2 - digitsNew[3];
					}
					else if (operations[k] == "*")
					{
						temp3 = temp2 * digitsNew[3];
					}
					else
					{
						temp3 = temp2 / digitsNew[3];
					}
					if (temp3 == desiredNumber) {
						cout << digitsNew[0] << operations[i] << digitsNew[1] << operations[j] << digitsNew[2] << operations[k]
							<< digitsNew[3];

						//freeing permutation array memory
						for (int p = 0; p < 720; ++p)
						{
							delete[] permutations[p];
						}
						delete[] permutations;

						return;
					}
					for (int a = 0; a < 4; ++a)
					{
						int temp4;
						if (operations[a] == "+")
						{
							temp4 = temp3 + digitsNew[4];
						}
						else if (operations[a] == "-")
						{
							temp4 = temp3 - digitsNew[4];
						}
						else if (operations[a] == "*")
						{
							temp4 = temp3 * digitsNew[4];
						}
						else
						{
							temp4 = temp3 / digitsNew[4];
						}
						if (temp4 == desiredNumber) {
							cout << digitsNew[0] << operations[i] << digitsNew[1] << operations[j] << digitsNew[2] << operations[k]
								<< digitsNew[3] << operations[a] << digitsNew[4];

							//freeing permutation array memory
							for (int p = 0; p < 720; ++p)
							{
								delete[] permutations[p];
							}
							delete[] permutations;

							return;
						}
						for (int b = 0; b < 4; ++b)
						{
							int temp5;
							if (operations[b] == "+")
							{
								temp5 = temp4 + digitsNew[5];
							}
							else if (operations[b] == "-")
							{
								temp5 = temp4 - digitsNew[5];
							}
							else if (operations[b] == "*")
							{
								temp5 = temp4 * digitsNew[5];
							}
							else
							{
								temp5 = temp4 / digitsNew[5];
							}
							if (temp5 == desiredNumber) {
								cout << digitsNew[0] << operations[i] << digitsNew[1] << operations[j] << digitsNew[2] << operations[k]
									<< digitsNew[3] << operations[a] << digitsNew[4] << operations[b] << digitsNew[5];

								//freeing permutation array memory
								for (int p = 0; p < 720; ++p)
								{
									delete[] permutations[p];
								}
								delete[] permutations;

								return;
							}
						}
					}
				}

			}
		}
	}

	//freeing permutation array memory
	for (int p = 0; p < 720; ++p)
	{
		delete[] permutations[p];
	}
	delete[] permutations;

	cout << "No possible combination found.";
}

int main()
{
	srand(time(0));
	int digits[5];


	for (int i = 0; i < 5; ++i)
	{
		digits[i] = (rand() % 9) + 1;
	}

	int quarters[3] = { 25, 50, 75 };
	int selectedQuarter = quarters[(rand() % 2)];
	int desiredNumber = (rand() % 899) + 100;

	cout << "Digits: ";
	for (int i = 0; i < 5; ++i)
	{
		cout << digits[i] << " ";
	}
	cout << ", Quarter: " << selectedQuarter << " , Desired Number: " << desiredNumber << endl;

	FindCalculation(digits, selectedQuarter, desiredNumber);
	cout << endl;
}