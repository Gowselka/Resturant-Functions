//Sinclair Community College
//Functions Coding Assignment
//Kevin Gowsell
//March 31st, 2019

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;


void menu()
{
	cout << "\n\t\tResturant Menu\n\n" << endl;
	cout << "1 - Gyro        $7.00" << endl;
	cout << "2 - Moussaka    $8.50" << endl;
	cout << "3 - Salad       $3.75" << endl;
	cout << "4 - Dolma       $2.00" << endl;
	cout << "5 - Soda        $2.80" << endl;
	cout << "6 - Coffee      $1.00" << endl;
	cout << "7 - Water       $2.00" << endl;
	cout << "8 - End Order" << endl;
}


void bill(double bill, double totalBill, double tax, double tip)
{
	std:cout << std::setprecision(2) << std::fixed;
	cout << "Bill = " << setprecision(2) << bill << endl;
	cout << "Tax = " << setprecision(2) << tax << endl;
	cout << "Tip = " << setprecision(2) << tip << endl;
	cout << "Total amount due = " << setprecision(2) << totalBill << endl;

}

void changeDue(double totalBill, double amountTend)
{
	double change;
	std:cout << std::setprecision(2) << std::fixed;

	change = amountTend - totalBill;

	cout << "Return " << change << endl;
}


int main()
{
	int choice = 0;
	const double taxAmount = 0.065;
	const double tipAmount = 0.20;
	double taxCharged;
	double tipCharged;
	double totalBill;
	double billAmount;
	double moneyRecieved;

	//accumulator for the bill
	double runningTotal = 0;

	//Constants for menu choices
	//const int Gyro = 1, Moussaka = 2, Salad = 3, Dolma = 4, 
		//Soda = 5, Coffee = 6, Water = 7, EndOrder = 8;

	//Constants for menu prices
	const double gyroPrice = 7.00, moussakaPrice = 8.50, saladPrice = 3.75,
		dolmaPrice = 2.00, sodaPrice = 2.80, coffeePrice = 1.00, waterPrice = 2.00;

	menu();
	
	
	do 
	{
		cout << "Please enter your choice: ";
		cin >> choice;

		//bulletproof choice
		while (choice < 1 || choice > 8)
		{
			cout << "Please enter a valid menu option: ";
			cin >> choice;
		}
		if (choice == 1)
		{
			runningTotal += gyroPrice;
		}
		else if (choice == 2)
		{
			runningTotal += moussakaPrice;
		}
		else if (choice == 3)
		{
			runningTotal += saladPrice;
		}
		else if (choice == 4)
		{
			runningTotal += dolmaPrice;
		}
		else if (choice == 5)
		{
			runningTotal += sodaPrice;
		}
		else if (choice == 6)
		{
			runningTotal += coffeePrice;
		}
		else if (choice == 7)
		{
			runningTotal += waterPrice;
		}
	} while (choice != 8);

	billAmount = runningTotal;
	taxCharged = runningTotal * taxAmount;
	runningTotal += taxCharged;
	tipCharged = runningTotal * tipAmount;
	runningTotal += tipCharged;
	totalBill = runningTotal;

	bill (billAmount, totalBill, taxCharged, tipCharged);

	cout << "Enter amount tendered: ";
	cin >> moneyRecieved;

	changeDue(totalBill, moneyRecieved);

	system("pause");
	return 0;
}