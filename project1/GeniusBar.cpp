#include "GeniusBar.hpp"

// Initializers
GeniusBar::GeniusBar() :
    current_wait_time_(0),
    number_of_available_geniuses_(TOTAL_NUMBER_OF_GENIUSES),
    number_of_customers_(0) {}

//
bool GeniusBar::addWaitingCustomer(Customer& new_customer) {
	// Preconditions
	if (number_of_customers_ >= MAX_NUMBER_OF_CUSTOMERS) {
		return false;
	}

	current_wait_time_ += WAIT_TIME_INCREMENT;

	// This actually updates it because it is a reference.
	new_customer.updateWaitTime(current_wait_time_);

	genius_bar_[number_of_customers_++] = new_customer;

	return true;
}

bool GeniusBar::assignGeniusToCustomer() {
	// Preconditions
	if (number_of_customers_ <= 0 || number_of_available_geniuses_ <= 0) {
		return false;
	}

	number_of_available_geniuses_ -= 1;
	number_of_customers_ -= 1;

	return true;
}

bool GeniusBar::releaseGenius() {
	// Preconditions
	if (number_of_available_geniuses_ >= TOTAL_NUMBER_OF_GENIUSES) {
		return false;
	}

	// Do stuff
	number_of_available_geniuses_ += 1;

	return true;
}

bool GeniusBar::updateCustomersWaitTime() {
	// Preconditions
	if (number_of_customers_ <= 0) {
		return false;
	}

	// This doesn't actually do anything as the array
	// doesn't have references. Main function doesn't check it though... :shrug:
	for (int i = 0; i < number_of_customers_; ++i) {
		auto& customer = genius_bar_[i];
		customer.updateWaitTime(current_wait_time_ + WAIT_TIME_INCREMENT);
	}

	return true;
}
