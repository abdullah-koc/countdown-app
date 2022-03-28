// FindCalculationExtensive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdlib> 
#include <ctime> 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

void Helper(int* digitsNew, int desiredNumber, char* operations, int temp1, int count, bool& isFound) {
	
	if (count == 6)
	{
		return;
	}
	for (int j = 0; j < 4; ++j)
	{
		int temp2;
		if (operations[j] == '+')
		{
			temp2 = temp1 + digitsNew[count];
		}
		else if (operations[j] == '-')
		{
			temp2 = temp1 - digitsNew[count];
		}
		else if (operations[j] == '*')
		{
			temp2 = temp1 * digitsNew[count];
		}
		else
		{
			temp2 = temp1 / digitsNew[count];
		}
		if (temp2 == desiredNumber) 
		{
			cout << temp1 << " " << operations[j] << " " << digitsNew[count] << endl;
			isFound = true;
			return;
		}
		else
		{
			if (isFound) 
			{
				cout << temp1 << " " << operations[j-1] << " " << digitsNew[count] << endl;
				return;
			}
			Helper(digitsNew, desiredNumber, operations, temp2, count + 1, isFound);
			
		}
	}
}



void FindCalculation(int* digits, int quarter, int desiredNumber) {
	char operations[4] = { '+', '-', '*', '/' }; //all operations
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
	do 
	{
		for (int i = 0; i < 6; ++i)
		{
			permutations[index][i] = mergedNumbers[i];
		}
		index++;
	} while (next_permutation(mergedNumbers, mergedNumbers + 6));
	
	bool isFound = false;
	//for each permutation, calculate if there is a valid result
	for (int x = 0; x < 720; ++x) {

		//digitsNew is the array which will be used for a permutation
		for (int c = 0; c < 6; ++c)
		{
			digitsNew[c] = permutations[x][c];
		}

		//recursive helper function
		Helper(digitsNew, desiredNumber, operations, digitsNew[0], 1, isFound);
		if (isFound) 
		{
			//freeing permutation array memory
			for (int p = 0; p < 720; ++p)
			{
				delete[] permutations[p];
			}
			delete[] permutations;
			return;
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
