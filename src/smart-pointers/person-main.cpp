// Note, specific namespace members are imported into the global namespace which is
// better practice than importing all of the members
// eg: "using std::string;", "using std::unique_ptr;" etc. rather than "using namespace std;"

#include <memory> // required for smart pointers
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

#include <string>
#include <iostream>
using std::string;
using std::endl;
using std::cout;

#include "Person.h"

Person printName()
{
	Person thabo{"Thabo",12};
	cout << thabo.name() << endl;
	return thabo;
}//1(A) thabo goes out of scope

shared_ptr<Person> printName2()
{
	auto maryanne_ptr = make_shared<Person>("Maryanne",12);
	cout << maryanne_ptr->name() << endl;
	return maryanne_ptr;
}//1(B) maryanne_ptr goes out of scope

void printName3(shared_ptr<Person> person_ptr)
{
	cout << person_ptr->name() << endl;
	return;
}//1(c) person_ptr goes out scope


int main()
{
    auto sandile_ptr = make_unique<Person>("Sandile",15);    

    auto thabo_in_main = printName();
    cout << thabo_in_main.name() << endl;

    auto person_ptr_in_main = printName2();
    printName3(person_ptr_in_main);

    sandile_ptr = make_unique<Person>("Sandile2",11);  
    cout << sandile_ptr->age() << endl;

    return 0;
}//1(D) sandile_ptr goes out of scope
 //1(E) thabo_in_main goes out of scope
 //1(F) person_ptr_in_main goes out of scope
 
 //Question 2
 /*
  * make_unique<Person>("Sandile",15) is released in line 50
  * make_unique<Person>("Sandile2",11) is released in line 54
  * Person thabo{"Thabo",12} is released in line 54
  * make_shared<Person>("Maryanne",12)
  * 
 **/
 
 //Question 3
 /*
  * in line 33 void printName3(shared_ptr<Person> person_ptr)
  * in line 48 printName3(person_ptr_in_main), person_ptr_in_main is passed by value
 **/
 
 //Question 4
 // they will be deleted at the same time, because they are in the same scope
 
 


