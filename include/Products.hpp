#ifndef PRODUCTS_HPP
#define PRODUCTS_HPP

#include "Meat.hpp"
#include "Drinks.hpp"
#include "Cheese.hpp"

class Products //super klasa trzymajaca produkty w jednym obiekcie i zarzadzajaca nimi
{
	private:			//wskazniki na tablice wskaznikow na dane obiekty (tablica wskaznikow jest wymagana przy dynamicznej alokacji)
		Cheese  **cheese;
		Meat   **meat;
		Drinks<float> **f_drinks;
		Drinks<double> **d_drinks;
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

		//szablon klasy ma za zadanie dzielic napoje na luksusowe i standardowe, luksusowe moga miec wieksze ceny z wieksza dokladnoscia (double)
		Drinks<float> **get_f_drinks();
		Drinks<double> **get_d_drinks();
		void add_drink();
		void rm_drink();

		void clean();	//funkcja dealokujaca cala pamiec zajeta przez produkty
};

#endif
