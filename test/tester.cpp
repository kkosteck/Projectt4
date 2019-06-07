#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Meat_Tests
#include <boost/test/unit_test.hpp>

#include "../include/Meat.hpp"

#include "../src/Meat.cpp"

BOOST_AUTO_TEST_CASE( quantityTest )
{
	Meat meat;
	
	BOOST_CHECK( meat.get_meat_quantity() == 1);
}
