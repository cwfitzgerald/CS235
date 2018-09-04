#include "Customer.hpp"
#include <string>
#include <utility>

// Use an initalizer expressions to initalize the class
Customer::Customer() : wait_time_(0) {}

// Use an initalizer expressions to initalize the class
Customer::Customer(std::string name, std::string device, int wait_time) :
    name_(std::move(name)),               // Move to save a copy
    defective_device_(std::move(device)), // Move to save a copy
    wait_time_(wait_time) {}

std::string Customer::getName() {
	// Retun value
	return name_;
}

std::string Customer::getDevice() {
	// Return value
	return defective_device_;
}

int Customer::getWaitTime() {
	// Return value
	return wait_time_;
}

void Customer::updateWaitTime(int new_wait_time) {
	// Set value
	wait_time_ = new_wait_time;
}
