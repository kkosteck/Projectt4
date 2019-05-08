//Rafał Bosko, PROI projekt 3, sklep spożywczy
#include <iostream>
#include "functions.hpp"
#include "Meat.hpp"
#include "Drinks.hpp"
#include "Cheese.hpp"
#include "Products.hpp"

using namespace std;

int main()
{
	Products products;
	int choice=1;
	while(choice)
	{
		cout << "\033[2J\033[1;1H";
		cout << "Menu sklepu spożywczego" << endl;
		cout << "[0] wyjdz" << endl;
		cout << "[1] wyswietl" << endl;
		cout << "[2] dodaj ser" << endl;
		cout << "[3] dodaj mieso" << endl;
		cout << "[4] dodaj napoj" << endl;
		cout << "[5] usun ser" << endl;
		cout << "[6] usun mieso" << endl;
		cout << "[7] usun napoj" << endl;
		cin >> choice;
		switch(choice)
		{
		case 0:
			products.clean();
			products.~Products();
			return 0;
		case 1:
			display(products);
			cout <<endl<< "Kliknij dowolny klawisz aby kontynuować..." << endl;
			getchar();
			getchar();
		break;
		case 2:
			products.add_cheese();
		break;
		case 3:
			products.add_meat();
		break;
		case 4:
			products.add_drink();
		break;
		case 5:
			products.rm_cheese();
		break;
		case 6:
			products.rm_meat();
		break;
		case 7:
			products.rm_drink();
		break;
		default:
		break;
		}
	}
	return 0;
}
