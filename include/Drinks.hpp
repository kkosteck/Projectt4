#ifndef DRINKS_HPP
#define DRINKS_HPP

#include <iostream>
class AllDrinks //klasa bazowa umożliwiająca zapisywanie różnych wariantów szablonu klasy Drinks do jednego kontenera
{
	public: 
		virtual ~AllDrinks() {};
		virtual void get_drink() const = 0;
};

template <typename T>
class Drinks : public AllDrinks		//soki, mleko etc...tanie,		trunki drogie
{
	private: //analogicznie jak w Cheese.hpp tylko cena stanowi element szablonu ktorym roznia sie konkretne klasy
		std::string name;
		std::string producer;
		T price_per_bottle;
		std::string exp_date;
		std::string type;

	public:
		//szablon klasy musi miec ciala funkcji w tym samym pliku
		//funkcje sa analogiczne do Cheese.hpp (zwracanie konkretnych wartosci, wyswietlanie przez przeciazenie)
		Drinks(int choice2)
		{
			T choice; std::string str;
			std::cout << "nazwa napoju: "; std::cin >> str; name=str;
			std::cout << "nazwa producenta: "; std::cin >> str; producer=str;
			std::cout << "cena za butelkę: "; std::cin >> choice; price_per_bottle = choice;
			std::cout << "data ważnośći napoju: "; std::cin >> str; exp_date=str;
			if(choice2 == 1)
				type = "zwykły";
			else
				type = "ekskluzywny";
		}
		std::string get_name() {return name;}
		std::string get_producer() {return producer;}
		std::string get_exp_date() {return exp_date;}
		std::string get_type() {return type;}
		
		T get_price_per_bottle() {return price_per_bottle;}
		
		virtual void get_drink() const 	//funkcja analogiczna do operatora << klas cheese i meat
		{
			std::cout<< "Napoj: " << name;
			std::cout<< "  Typ: " << type << std::endl;
			std::cout<< "Producent: " << producer << std::endl;
			std::cout<< "Cena: " << price_per_bottle;
			std::cout<< "  Ilość: " << exp_date <<std::endl;
		}
};

#endif
