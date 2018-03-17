//MD Abir A. Choudhury
//031518
//Realtor Assist v2.0
//Homework A6

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void printReport();
void searchProperty(int maxPrice, int minBedroom);
void reducePrice(int reduction, int tempPropertyID);

struct Property {
	int propertyID;
	int bedroomNum;
	float askingPrice;
} propNew[20000];

int main() {
	int choice = 0;// holds the choice the user makes from the list
	int tempAskingPrice = 0;// holds a temp number
	int tempPropNum, tempBedroomNum = 0;
	int maxPrice = 0;// used for choice 3
	int minBedroom = 0;// used for choice 3
	int total = 0;// holds the total price for each property together
	int count = 0;// keeps track of the number of properties available
	float average = 0.0; // holds the average price for all properties together

	do {
		// Display the menu
		cout << "Welcome to the Realtor Assist v1.0\n"
			"==================================\n"
			"1 - New Property\n"
			"2 - Price Reduction\n"
			"3 - Search Property\n"
			"4 - Report\n"
			"0 - Exit\n"
			"Please choose an option:\n";
		cin >> choice; // User enters an choice
					   // choice 1 --> inputting in new property
		if (choice == 1) {
			//property number
			cout << "What is the property number? The number should be between 1 and 20,000.\n";
			cin >> tempPropNum;
			// check if the number is valid
			if (tempPropNum < 1 || tempPropNum > 20000) {
				cout << "You have entered an invalid number.\nPlease input a valid number: ";
				cin >> tempPropNum;
			}
			propNew[tempPropNum].propertyID = tempPropNum;

			//asking price
			cout << "How much is the asking price of the property?\n";
			cin >> tempAskingPrice;
			// check if the input is valid
			if (tempAskingPrice < 50000 || tempAskingPrice > 10000000) {
				cout << "Sorry we cannot accept that. Input a valid number between $50,000 and $10,000,000.\n";
				cin >> tempAskingPrice;
			}
			propNew[tempPropNum].askingPrice = tempAskingPrice;
			total += tempAskingPrice;
			count++;

			//number of bedrooms
			cout << "How many bedrooms do you need?\n";
			cin >> tempBedroomNum;
			//check for errors
			if (tempBedroomNum < 1) {
				cout << "The minimum number of bedrooms is 1.\nInput a valid number.\n";
				cin >> tempBedroomNum;
			}
			propNew[tempPropNum].bedroomNum = tempBedroomNum;
		}
		// choice 2 --> price reduction
		else if (choice == 2) {
			int reduction = 0;
			int tempPropertyID = 0;
			cout << "Which property do you want to reduce the price for?\n";
			cin >> tempPropertyID;
			cout << "By how much do you want to reduce the price?\n";
			cin >> reduction;
			reducePrice(reduction, tempPropertyID);
			total -= reduction; // reduces the total property price
		}
		// choice 3 --> search property
		else if (choice == 3) {
			cout << "What is the maximum price you are willing to pay?\n";
			cin >> maxPrice;
			cout << "What is the minimum number of bedroom?\n";
			cin >> minBedroom;
			searchProperty(maxPrice, minBedroom);
		}
		// choice 4 --> output report
		else if (choice == 4) {
			printReport();
			average = total / count;
			cout << setprecision(7) << "The average home price is: " << average << ".\n";
		}

	} while (choice != 0);

	system("PAUSE");
	return 0;
}



void searchProperty(int maxPrice, int minBedroom) {
	for (int i = 0; i < 20000; i++) {
		if (propNew[i].askingPrice != 0) {
			if (propNew[i].askingPrice <= maxPrice && propNew[i].bedroomNum >= minBedroom) {
				cout << setprecision(7) << "Property #" << i << " is priced at " << propNew[i].askingPrice << " and has " << propNew[i].bedroomNum << " bedrooms.\n";
			}
		}
		if (propNew[i].askingPrice == 0 && i == 0) {
			cout << "There are no such properties available.\n";
		}
	}
}

void reducePrice(int reduction, int tempPropertyID) {
	propNew[tempPropertyID].askingPrice -= reduction; // reduces askingprice by reduction
	cout << propNew[tempPropertyID].askingPrice << endl;
}

void printReport() {
	for (int i = 0; i < 20000; i++)
	{
		if (propNew[i].askingPrice != 0)
			cout << setprecision(7) << "The asking price of property " << i << " is " << propNew[i].askingPrice << endl;
		if (propNew[i].bedroomNum != 0)
			cout << setprecision(7) << "The number of bedrooms for property " << i << " is " << propNew[i].bedroomNum << endl;
	}
}