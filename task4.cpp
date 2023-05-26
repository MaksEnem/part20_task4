#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

enum banknote_denomination {

	one_hundred,
	two_hundred,
	five_hundred,
	one_thousent,
	two_thousent,
	five_thousent

};

void initialization_number_of_banknotes(int number_of_banknotes[]) {

	for (int i = 0; i < 6; ++i) {

		number_of_banknotes[i] = 0;

	}

}


void initialization_of_ATM(int number_of_banknotes_in_an_ATM[], int number_of_banknotes[], int& sum) {	

	std::ofstream out_storage;
	out_storage.open("D:\\Skillbox\\C++\\working\\Practice 20 (Writing to files)\\task4\\storage.txt");

	for (int i = 0; i < 1000; ++i) {

		number_of_banknotes_in_an_ATM[i] = std::rand() % 6;

		if (number_of_banknotes_in_an_ATM[i] == 0) {

			number_of_banknotes_in_an_ATM[i] = 100;
			sum += number_of_banknotes_in_an_ATM[i];
			++number_of_banknotes[one_hundred];
		}
		else if (number_of_banknotes_in_an_ATM[i] == 1) {

			number_of_banknotes_in_an_ATM[i] = 200;
			sum += number_of_banknotes_in_an_ATM[i];
			++number_of_banknotes[two_hundred];
		}
		else if (number_of_banknotes_in_an_ATM[i] == 2) {

			number_of_banknotes_in_an_ATM[i] = 500;
			sum += number_of_banknotes_in_an_ATM[i];
			++number_of_banknotes[five_hundred];
		}
		else if (number_of_banknotes_in_an_ATM[i] == 3) {

			number_of_banknotes_in_an_ATM[i] = 1000;
			sum += number_of_banknotes_in_an_ATM[i];
			++number_of_banknotes[one_thousent];
		}
		else if (number_of_banknotes_in_an_ATM[i] == 4) {

			number_of_banknotes_in_an_ATM[i] = 2000;
			sum += number_of_banknotes_in_an_ATM[i];
			++number_of_banknotes[two_thousent];
		}
		else if (number_of_banknotes_in_an_ATM[i] == 5) {

			number_of_banknotes_in_an_ATM[i] = 5000;
			sum += number_of_banknotes_in_an_ATM[i];
			++number_of_banknotes[five_thousent];
		}

		out_storage << number_of_banknotes_in_an_ATM[i] << std::endl;

	}

	out_storage.close();
}


int main() {

	std::srand(std::time(nullptr));

	int number_of_banknotes_in_an_ATM[1000];	
	int number_of_banknotes[6];
	int total_sum = 0;

	initialization_number_of_banknotes(number_of_banknotes);
	initialization_of_ATM(number_of_banknotes_in_an_ATM, number_of_banknotes, total_sum);

	





	for (int i = 0; i < 6; ++i) {

		std::cout << number_of_banknotes[i] << " ";

	}
}