#pragma once

#include "SetInterface.h"

template <class T>
class Set : public SetInterface<T> {
  public:
	Set();

	int getCurrentSize() const override;
	bool isEmpty() const override;
	bool add(T const& newEntry) override;
	bool remove(T const& anEntry) override;
	void clear() override;
	bool contains(T const& anEntry) const override;
	std::vector<T> toVector() const override;

  private:
	static const int DEFAULT_SET_SIZE = 4; // for testing purposes we will keep the set small
	T items_[DEFAULT_SET_SIZE];            // array of set items
	int item_count_ = 0;                   // current count of set items
	int max_items_ = DEFAULT_SET_SIZE;     // max capacity of the set

	// post: Either returns the index of target in the array items_
	// or -1 if the array does not contain the target
	int getIndexOf(T const& target) const;
};

// Include impl
#include "Set.cpp"