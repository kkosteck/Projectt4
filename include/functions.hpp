#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include "Products.hpp"

void display(class Products prod); //wyswietla cala zawartosc klasy produkty (czyli 4 tablice konkretnych produktow)
void display(class Cheese **ch);	//3 przeciazone wersje dla wyswietlania jednej kategorii produktow
void display(class Meat **me);
template <typename T>						//znowu szablon -> cialo ma w tym samym pliku
void display(Drinks<T> **dr)
{
	if(dr==NULL)
		std::cout << "Brak napoi" << std::endl<<std::endl;
	else
		for (int i=0; i< Drinks<T>::get_drinks_quantity(); i++)
			std::cout <<"Element: "<< i <<std::endl<< *dr[i] <<std::endl;
}
std::ostream & operator<< (std::ostream &end, class Cheese &ch);
std::ostream & operator<< (std::ostream &end, class Meat &mt);


#endif
