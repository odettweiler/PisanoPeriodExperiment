#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using std::cout;
using std::cin;
using std::vector;
using std::string;

long * generateFibonacci() {
	static long sequence[100];

	sequence[0] = 1;
	sequence[1] = 1;

	for (int i = 2; i < 100; i++)
	{
		sequence[i] = sequence[i-1] + sequence[i-2];
	}

	return sequence;
}

vector<int> generatePisano(long *fibonacci, int divisor) {
	int convertedFibonacci[100];

	for (int i = 0; i < 100; i++)
	{
		convertedFibonacci[i] = fibonacci[i] % divisor;
	}

	int end_index = 100;

	for (int i = 0; i < 100; i++)
	{
		if (i > 1) {
			if (convertedFibonacci[i] == 0 && convertedFibonacci[i - 1] == 1) {
				end_index = i;
				break;
			}
		}
	}

	vector<int> final_sequence;

	for (int i = 0; i < end_index; i++)
	{
		final_sequence.push_back(convertedFibonacci[i]);
	}

	return final_sequence;
}

int main() {
	SetConsoleTitle(TEXT("PISANO PERIOD DEMONSTRATION"));

	long * fibonacci = generateFibonacci();

	int divisor = 0;

	bool run = true;
	string runStr;

	while (run) {
		system("cls"); // clear the console window
		cout << "Please enter the divisor you want: (divisor > 1) ";
		cin >> divisor;

		if (divisor <= 1) {
			cout << "Please enter a divisor that is greater than one." << std::endl;
			system("pause");
			continue;
		}

		vector<int> pisanoPeriod = generatePisano(fibonacci, divisor);

		cout << "PISANO                          FIBONACCI" << std::endl;

		for (int i = 0; i < pisanoPeriod.size(); i++)
		{
			cout << pisanoPeriod.at(i) << "                               " << fibonacci[i] << std::endl;
		}

		cout << std::endl << std::endl;

		cout << "The length of this pisano period is: " << pisanoPeriod.size() << std::endl;

		// ask if the user wants to try again
		while (true) {
			cout << "Would you like to continue? (y/n) ";
			cin >> runStr;
			if (runStr == "y" || runStr == "n") {
				if (runStr == "y") {
					run = true;
					break;
				}
				else {
					run = false;
					break;
				}
			}
			else {
				cout << "Please enter a valid input. (y/n)" << std::endl;
			}
		}
	}

	// wait for the user to press a key
	system("pause");
	return 0;
}