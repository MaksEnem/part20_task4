#include <iostream>
#include <fstream>
#include <ctime>


enum banknote_denomination {

	five_thousent,
	two_thousent,
	one_thousent,
	five_hundred,
	one_hundred

};

void initialization_number_of_banknotes(int number_of_banknotes[]) {

	for (int i = 0; i < 5; ++i) {

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
	int number_of_banknotes[5];
	int total_sum = 0;

	initialization_number_of_banknotes(number_of_banknotes);
	initialization_of_ATM(number_of_banknotes_in_an_ATM, number_of_banknotes, total_sum);

	





	for (int i = 0; i < 5; ++i) {

		std::cout << number_of_banknotes[i] << " ";

	}

	int withdrawal_amount;
	int denomination;

	std::cout << "The maximum amount you can withdraw:" << total_sum << " rub.\n";
	std::cout << "The amount you can withdraw must be a multiple of 100 rubles.\n";
	std::cout << "------------------------------------------------------\n";

	std::cout << "Enter the amount you want to withdraw: ";
	std::cin >> withdrawal_amount;

	if (withdrawal_amount > total_sum || withdrawal_amount % 100 > 0) {
		std::cout << "Requested amount is incorrect!!!";
	}
	else if ((number_of_banknotes[one_hundred] == 0) && (withdrawal_amount % 500 > 0)) {		

		do {

			std::cout << "There are no banknotes of 100 rubles in the ATM. Enter an amount that is a multiple of 500 rubles.\n";

			std::cout << "The maximum amount you can withdraw:" << total_sum << " rub.\n";
			std::cout << "The amount you can withdraw must be a multiple of 100 rubles.\n";
			std::cout << "------------------------------------------------------\n";

			std::cout << "Enter the amount you want to withdraw: ";
			std::cin >> withdrawal_amount;

		} while (withdrawal_amount > total_sum && withdrawal_amount % 500 > 0);

	}
	
	else if (withdrawal_amount >= 5000) {

		denomination = withdrawal_amount / 5000;

		if (number_of_banknotes[five_thousent] >= denomination) {

			withdrawal_amount -= (denomination * 5000);
			std::cout << "Number of banknotes 5000 rub. - " << denomination << "\n";
			number_of_banknotes[five_thousent] -= denomination;
		}
		else if(number_of_banknotes[five_thousent] > 0){


			withdrawal_amount -= (number_of_banknotes[five_thousent] * 5000);
			std::cout << "Number of banknotes 5000 rub. - " << number_of_banknotes[five_thousent] << "\n";
			number_of_banknotes[five_thousent] = 0;
			
		}
	}
	if (withdrawal_amount >= 2000) {

		denomination = withdrawal_amount / 2000;

		if (number_of_banknotes[two_thousent] >= denomination) {

			withdrawal_amount -= (denomination * 2000);
			std::cout << "Number of banknotes 2000 rub. - " << denomination << "\n";
			number_of_banknotes[two_thousent] -= denomination;
		}
		else if (number_of_banknotes[two_thousent] > 0) {

			withdrawal_amount -= (number_of_banknotes[two_thousent] * 2000);
			std::cout << "Number of banknotes 2000 rub. - " << number_of_banknotes[two_thousent] << "\n";
			number_of_banknotes[two_thousent] = 0;
			
		}

	}
	if (withdrawal_amount >= 1000) {

		denomination = withdrawal_amount / 1000;

		if (number_of_banknotes[one_thousent] >= denomination) {

			withdrawal_amount -= (denomination * 1000);
			std::cout << "Number of banknotes 1000 rub. - " << denomination << "\n";
			number_of_banknotes[one_thousent] -= denomination;
		}
		else if (number_of_banknotes[one_thousent] > 0) {

			withdrawal_amount -= (number_of_banknotes[one_thousent] * 1000);
			std::cout << "Number of banknotes 1000 rub. - " << number_of_banknotes[one_thousent] << "\n";
			number_of_banknotes[one_thousent] = 0;
			
		}
	}
	if (withdrawal_amount >= 500) {

		denomination = withdrawal_amount / 500;

		if (number_of_banknotes[five_hundred] >= denomination) {

			withdrawal_amount -= (denomination * 500);
			std::cout << "Number of banknotes 500 rub. - " << denomination << "\n";
			number_of_banknotes[five_hundred] -= denomination;
		}
		else if (number_of_banknotes[five_hundred] > 0) {

			withdrawal_amount -= (number_of_banknotes[five_hundred] * 500);
			std::cout << "Number of banknotes 500 rub. - " << number_of_banknotes[five_hundred] << "\n";
			number_of_banknotes[five_hundred] = 0;
			
		}

	}
	
	if (withdrawal_amount >= 100) {

		denomination = withdrawal_amount / 100;

		if (number_of_banknotes[one_hundred] >= denomination) {

			withdrawal_amount -= (denomination * 100);
			std::cout << "Number of banknotes 100 rub. - " << denomination << "\n";
			number_of_banknotes[one_hundred] -= denomination;
		}
		else if (number_of_banknotes[one_hundred] > 0) {

			withdrawal_amount -= (number_of_banknotes[one_hundred] * 100);
			std::cout << "Number of banknotes 100 rub. - " << number_of_banknotes[one_hundred] << "\n";
			number_of_banknotes[one_hundred] = 0;
			std::cout << "There are no banknotes of 100 rubles in the ATM.Download ATM.\n";
			
		}
	}
	
	std::cout << std::endl;
	for (int i = 0; i < 5; ++i) {

		std::cout << number_of_banknotes[i] << " ";

	}
	
}