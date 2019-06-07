#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello
#include <boost/test/unit_test.hpp>
#include <meat.hpp>


BOOST_AUTO_TEST_CASE( quantityTest )
{
	Meat meat;
	
	BOOST_CHECK( meat.get_meat_quantity() == 1);
}
