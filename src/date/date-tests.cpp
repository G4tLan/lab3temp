#include "date.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Exercise 2.1
// Comment out this test after inspecting the output.
// Tests which require manual verification should not be lumped
// with tests which are automatically verified!
/*
TEST_CASE("Date has uninitialised state") {	 
    // make some prior memory allocations - which will be the case in a typical program
    auto i = {1.0,1.3,1.4,1.5,1.6,1.7,1.8,1.9,10.2,11.0,1.2,1.3,1.23};
    auto i2 = 1.0;
    
    Date today;	
    std::cout << "Today is: " << endl;
    printDate(today);
}*/

// Write code to make this test pass
TEST_CASE("Valid Date is initialised correctly") {
	Date heritage_day{24, Month::September, 2000};
	CHECK(heritage_day.day() == 24);
	CHECK(heritage_day.month() == Month::September);
	CHECK(heritage_day.year() == 2000);
}


// Exercise 2.2
// Supply additional tests for the constructor here, which
// verify that an exception is thrown when an attempt is made
// to construct an invalid date. Think carefully about which
// invalid dates to test.
TEST_CASE("Check invalid date, if day is out of range"){
	CHECK_THROWS_AS(Date testday(-10,Month::January,1),DateException);
	CHECK_THROWS_AS(Date testday(0,Month::January,1),DateException);
	CHECK_THROWS_AS(Date testday(45,Month::January,1),DateException);
}

TEST_CASE("Check invalid date, if year is invalid"){
	CHECK_THROWS_AS(Date testday(-10,Month::January,-1),DateException);
}

// Exercise 2.3
TEST_CASE("Identical Dates are Equal") {
    Date date_1(1, Month::January, 2000);
    Date date_2(1, Month::January, 2000);

    CHECK(date_1 == date_2);
}

// Supply at least three additional tests for
// the equality operator here, to ensure that
// it is working correctly.
TEST_CASE("Different dates are not equal") {
    Date date_1(2, Month::January, 2000);
    Date date_2(1, Month::January, 2000);

    CHECK_FALSE(date_1 == date_2);
}

TEST_CASE("Different dates are not equal") {
    Date date_1(2, Month::February, 2000);
    Date date_2(1, Month::January, 2000);

    CHECK_FALSE(date_1 == date_2);
}

TEST_CASE("Different dates are not equal") {
    Date date_1(2, Month::January, 2000);
    Date date_2(1, Month::January, 2090);

    CHECK_FALSE(date_1 == date_2);
}

// Exercise 2.4
// Provide tests for a new member function of the Date class
// which will increase the date by one day.
TEST_CASE("add 1 day to date, day must change"){
	Date date_1(26, Month::July, 2017);
	Date date_2(27, Month::July, 2017);
	
	date_1.addDay();
	CHECK(date_1 == date_2);
}

TEST_CASE("add 1 day to date, Month and day must change"){
	Date date_1(31, Month::July, 2017);
	Date date_2(1, Month::August, 2017);
	
	date_1.addDay();
	CHECK(date_1 == date_2);
}

TEST_CASE("add 1 day to date, year,Month and day must change"){
	Date date_1(31, Month::December, 2017);
	Date date_2(1, Month::January, 2018);
	
	date_1.addDay();
	CHECK(date_1 == date_2);
}
// Exercise 2.5
// Write tests for the new default constructor and the
// setDefaultDate method.
TEST_CASE("Check default date is correct"){
	Date default_date(1, Month::January, 1900);
	
	CHECK(default_date == Date::getDefaultDate());
}

TEST_CASE("default date must change for all Date objects"){
	Date object1(1, Month::July, 2050);
	Date object2(5, Month::October, 2050);
	Date object3(10, Month::July, 50);
	
	Date::setDefaultDate(1, Month::July, 2050);
	CHECK(object1 == Date::getDefaultDate());
	
	Date::setDefaultDate(5, Month::October, 2050);
	CHECK(object2 == Date::getDefaultDate());
	
	Date::setDefaultDate(10, Month::July, 50);
	CHECK(object3 == Date::getDefaultDate());
}
TEST_CASE("Date object is set to the default date"){
	Date date;
	CHECK(date == Date::getDefaultDate());
}