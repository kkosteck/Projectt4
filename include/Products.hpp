#ifndef PRODUCTS_HPP
#define PRODUCTS_HPP

#include "Drinks.hpp"
#include "Meat.hpp"
#include "Cheese.hpp"
#include <vector>

class Products //super klasa trzymajaca produkty w jednym obiekcie i zarzadzajaca nimi
{
	private:			//wskazniki na tablice wskaznikow na dane obiekty (tablica wskaznikow jest wymagana przy dynamicznej alokacji)
		Cheese  **cheese;
		Meat   **meat;
		std::vector<AllDrinks *> drinks;
	public:
		//kazdy produkt ma metode wywolujaca konstruktora i alokujaca miejsce na nowy produkty
		//kazdy produkt ma metode zwracajaca wskaznik na tablice wskaznikow (np przy wyswietlaniu jednej kategorii)
		Products();
		~Products();
		
		Cheese **get_cheese();
		void add_cheese();
		void rm_cheese();

		Meat **get_meat();
		void add_meat();
		void rm_meat();

		std::vector<AllDrinks *> get_drinks();
		void add_drinks();
		void rm_drinks();

		void clean();	//funkcja dealokujaca cala pamiec zajeta przez produkty
};

#endif
