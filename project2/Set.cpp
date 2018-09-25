template<class T>
int Set<T>::getCurrentSize() const {
	return item_count_;
}

template<class T>
bool Set<T>::isEmpty() const {
	return item_count_ == 0;
}

template<class T>
bool Set<T>::add(T const &newEntry) {
	if (item_count_ >= max_items_) {
		return false;
	}

	if(getIndexOf(newEntry) != -1) {
		return false;
	}

	items_[item_count_] = newEntry;

	item_count_ += 1;

	return true;
}

template<class T>
bool Set<T>::remove(T const &anEntry) {
	if (item_count_ == 0) {
		return false;
	}

	items_[getIndexOf(anEntry)] = std::move(items_[item_count_ - 1]);

	item_count_ -= 1;

	return true;
}

template<class T>
void Set<T>::clear() {
	item_count_ = 0;
}

template<class T>
bool Set<T>::contains(T const &anEntry) const {
	return getIndexOf(anEntry) != -1;
}

template<class T>
std::vector<T> Set<T>::toVector() const {
	return std::vector<T>(std::begin(items_), std::begin(items_) + item_count_);
}

template<class T>
int Set<T>::getIndexOf(T const &target) const {
	for(int i = 0; i < item_count_; ++i) {
		if (target == items_[i]) {
			return i;
		}
	}
	return -1;
}

template<class T>
Set<T>::Set() {}
