#include "Customer.hpp"
#include "GeniusBar.hpp"
#include <iostream>

int main() {
	// initialize a GeniusBar
	GeniusBar genius_bar;

	// create some customers
	Customer customer1("Lina", "iPhone");
	std::cout << customer1.getName() << " has problems with " << customer1.getDevice() << '\n';

	Customer customer2("Clay", "iPad");
	std::cout << customer2.getName() << " has problems with " << customer2.getDevice() << '\n';

	Customer customer3("Rory", "iMac");
	std::cout << customer3.getName() << " has problems with " << customer3.getDevice() << '\n';

	Customer customer4("Liam", "macBookPro");
	std::cout << customer4.getName() << " has problems with " << customer4.getDevice() << '\n';

	Customer customer5("Adri", "iPhone");
	std::cout << customer5.getName() << " has problems with " << customer5.getDevice() << '\n';

	Customer customer6("Sky", "macBookAir");
	std::cout << customer6.getName() << " has problems with " << customer6.getDevice() << '\n';

	std::cout << '\n' << "add customers to the geinus bar \n";
	std::cout << genius_bar.addWaitingCustomer(customer1) << '\n'; // true (1)
	std::cout << customer1.getName() << "'s wait time is now " << customer1.getWaitTime() << '\n';

	std::cout << genius_bar.addWaitingCustomer(customer2) << '\n'; // true (1)
	std::cout << customer2.getName() << "'s wait time is now " << customer2.getWaitTime() << '\n';

	std::cout << genius_bar.addWaitingCustomer(customer3) << '\n'; // true (1)
	std::cout << customer3.getName() << "'s wait time is now " << customer3.getWaitTime() << '\n';

	std::cout << genius_bar.addWaitingCustomer(customer4) << '\n'; // true (1)
	std::cout << customer4.getName() << "'s wait time is now " << customer4.getWaitTime() << '\n';

	std::cout << genius_bar.addWaitingCustomer(customer5) << '\n'; // true (1)
	std::cout << customer5.getName() << "'s wait time is now " << customer5.getWaitTime() << '\n';

	std::cout << genius_bar.addWaitingCustomer(customer6) << '\n'; // true (0)
	std::cout << customer6.getName() << "'s wait time is still " << customer6.getWaitTime()
	          << " because there is no more space at the genius bar \n";

	std::cout << "Sorry Sky please come back later!\n\n";

	std::cout << '\n' << "assigning geniuses to assist customers:" << '\n';

	std::cout << genius_bar.assignGeniusToCustomer() << '\n'; // true (1)
	std::cout << genius_bar.assignGeniusToCustomer() << '\n'; // true (1)
	std::cout << genius_bar.assignGeniusToCustomer() << '\n'; // true (1)
	std::cout << genius_bar.assignGeniusToCustomer() << '\n'; // true (0)

	std::cout << "Oops, no more available geniuses, the remaining customers must wait \n\n";
	std::cout << '\n'
	          << "release some geniuses from helping customers and make them available again \n";

	std::cout << genius_bar.releaseGenius() << '\n'; // true (1)
	std::cout << genius_bar.releaseGenius() << '\n'; // true (1)
	std::cout << genius_bar.releaseGenius() << '\n'; // true (1)
	std::cout << genius_bar.releaseGenius() << '\n'; // true (0)

	std::cout << "no more geniuses to be released \n\n";

	std::cout << "Oops, it's lunch time, our geniuses are going on lunch break, better update the "
	             "remaining customers' wait time \n";

	std::cout << genius_bar.updateCustomersWaitTime() << '\n'; // true (1)

	std::cout << '\n'
	          << "Ok, our geniuses are back from lunch, assign more geniuses to help the remaining "
	             "customers \n";

	std::cout << genius_bar.assignGeniusToCustomer() << '\n'; // true (1)
	std::cout << genius_bar.assignGeniusToCustomer() << '\n'; // true (1)
	std::cout << genius_bar.assignGeniusToCustomer() << '\n'; // true (0)

	std::cout << "no more customers in the store, all done for today!!! \n\n";

	std::cout << "do we need to tell any remaining customers that they need to wait unitl "
	             "tomorrow? \n";

	std::cout << genius_bar.updateCustomersWaitTime() << '\n'; // true (0)

	std::cout << "no we don't, good night!!! \n\n";
}