#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Meat_Tests
#include <boost/test/unit_test.hpp>
#include <sstream>
#include <iostream>
#include "../include/Meat.hpp"
#include "../src/Meat.cpp"

BOOST_AUTO_TEST_CASE( MeatInputTest )
{
	BOOST_TEST_MESSAGE( "Testing class Meat:" );
	std::istringstream is("Parówki\nSokołów\n3.1\n12.5\n"); //Arguemnty dla konstruktora
	std::ostringstream os; //Zmienna przechowuje komunikaty konstruktora domyślnie wyświetlane w konsoli 
	Meat meat(is, os);
	Meat meat2(is, os);
	BOOST_CHECK(meat.get_name() == "Parówki");
	BOOST_CHECK(meat.get_producer() == "Sokołów");
	BOOST_WARN_EQUAL(meat.get_price_per_mass(), 3.1);
	BOOST_WARN_EQUAL(meat.get_mass(), 12.5); 
	BOOST_CHECK_EQUAL(meat.get_meat_quantity(), 2);
}
