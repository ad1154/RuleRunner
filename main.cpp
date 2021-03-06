/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   RuleRunner.cpp
* Author: Adi
*
* Created on December 14, 2015, 12:17 PM
*/

#include <cstdlib>
#include <iostream>
#include <iterator>

using namespace std;

class rule {
private:
	int integerArray[100], arrayIndex, ruleCheck = 0, NumberOfRules = 3;
public:
	bool RunTests(int* input, int arraySize)
	{
		copy(&input[0], &input[arraySize], integerArray);
		arrayIndex = arraySize;
		if (RuleA() == 1)
		{
			cout << "\nRule RuleA has passed\n";
			ruleCheck++;
		}
		else
		{
			cout << "\nRule RuleA has failed\n";
		}
		if (RuleB() == 1)
		{
			cout << "\nRule RuleB has passed\n";
			ruleCheck++;
		}
		else
		{
			cout << "\nRule RuleB has failed\n";
		}

		if (RuleC() == 1)
		{
			cout << "\nRule RuleC has passed\n";
			ruleCheck++;
		}
		else
		{
			cout << "\nRule RuleC has failed\n";
		}

		if (ruleCheck == NumberOfRules)
		{
			return 1;
		}
                if (ruleCheck == 0)
                {
                    cout << "\nALL rules failed\n";
                }
		return 0;
	}

private:
	bool RuleA(void)
	{
		for (int i = 1; i < arrayIndex; i++)
		{
			if ((integerArray[i - 1] + integerArray[i]) >= 1000)
			{
				return 1;
			}
		}
		return 0;
	}
	bool RuleB(void)
	{
		for (int i = 1; i < arrayIndex; i++)
		{
			if (((integerArray[i] - integerArray[i - 1]) >= 500))
			{
				return 1;
			}
		}
		return 0;
	}

	bool RuleC(void)
	{
		int avg, accumulator = 0;
		for (int i = 0; i < arrayIndex; i++)
		{
			accumulator += integerArray[i];
		}
		avg = accumulator / (arrayIndex);
		if (avg >= 500)
		{
			return 1;
		}
		return 0;
	}
};


int main(int argc, char* argv[])
{
	if (argc > 1) // Check if input arguments exist
	{

		int input[100];
		rule Myrule;
		for (int i = 1; i < argc; i++)
		{
			input[i - 1] = atol(argv[i]);
		}

		if (Myrule.RunTests(&input[0], argc - 1) == 1)
		{
			cout << "\nALL rules passed\n";
			return 0;
		}
	}
	else
	{
		cout << "\nNo input arguments\n";
		return 0;
	}
	return 0;
}





