template<class T>
int Set<T>::getCurrentSize() const {
	// Getter
	return item_count_;
}

template<class T>
bool Set<T>::isEmpty() const {
	// Getter
	return item_count_ == 0;
}

template<class T>
bool Set<T>::add(T const &newEntry) {
	// Preconditions
	if (item_count_ >= max_items_) {
		return false;
	}

	// Check if it exists already
	if(getIndexOf(newEntry) != -1) {
		return false;
	}

	items_[item_count_] = newEntry;

	item_count_ += 1;

	return true;
}

template<class T>
bool Set<T>::remove(T const &anEntry) {
	// Preconditions
	if (item_count_ == 0) {
		return false;
	}

	// Swap
	items_[getIndexOf(anEntry)] = std::move(items_[item_count_ - 1]);

	item_count_ -= 1;

	return true;
}

template<class T>
void Set<T>::clear() {
	// Clear
	item_count_ = 0;
}

template<class T>
bool Set<T>::contains(T const &anEntry) const {
	// Getter
	return getIndexOf(anEntry) != -1;
}

template<class T>
std::vector<T> Set<T>::toVector() const {
	// Use constructor
	return std::vector<T>(std::begin(items_), std::begin(items_) + item_count_);
}

template<class T>
int Set<T>::getIndexOf(T const &target) const {
	// this is just std::find
	for(int i = 0; i < item_count_; ++i) {
		if (target == items_[i]) {
			return i;
		}
	}
	return -1;
}

template<class T>
Set<T>::Set() {
	// Empty
}
