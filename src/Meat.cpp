#include "../include/Meat.hpp"
#include <iostream>

int Meat::meat_quantity = 0;

Meat::Meat()
{
  meat_quantity++;
  std::string str;
  float flt;
  std::cout << "Podaj nazwę mięsa:  "; std::cin >> str;  name = str;
  std::cout << "Podaj producenta mięsa:  "; std::cin >> str;  producer = str;
  std::cout << "Podaj cenę za opakowanie mięsa: (float) "; std::cin >> flt;  price_per_mass = flt;
  std::cout << "Podaj ilość (kg) mięsa: (float) "; std::cin>>flt; mass = flt;
}
Meat::~Meat()
{
  meat_quantity--;
}
int Meat::get_meat_quantity() {return meat_quantity;}

std::string Meat::get_name() {return name;}
std::string Meat::get_producer() {return producer;}
float Meat::get_price_per_mass() {return price_per_mass;}
float Meat::get_mass() {return mass;}
