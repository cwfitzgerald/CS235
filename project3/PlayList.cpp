// Assignment: CSCI 235, Fall 2018, Project 3
// Name: Connor Fitzgerald
// Date: 2018-10-16
// File Name: PlayList.cpp

#include "PlayList.h"
#include <cassert>
#include <iostream>
#include <utility>

template<class T, class U = T>
T exchange(T& obj, U&& new_value) {
	T old_value = std::move(obj);
	obj = std::forward<U>(new_value);
	return old_value;
}

PlayList::PlayList() : LinkedSet(), tail_ptr_(getPointerToLastNode()) {}

PlayList::PlayList(const Song &a_song) : LinkedSet(), tail_ptr_(getPointerToLastNode()) {
	PlayList::add(a_song);
}

PlayList::PlayList(const PlayList &a_play_list) : LinkedSet(a_play_list), tail_ptr_(getPointerToLastNode()) {}

PlayList::~PlayList() {
	unloop();
}

Node<Song>* PlayList::getPointerToLastNode() const {
	Node<Song>* last = head_ptr_;
	Node<Song>* cur = last;
	if (last == nullptr) {
		return last;
	}
	cur = last->getNext();

	while(cur && cur != head_ptr_) {
		last = exchange(cur, cur->getNext());
	}

	return last;
}

bool PlayList::add(const Song& new_song) {
	Node<Song>* end = tail_ptr_;

	auto *newend = new Node<Song>(new_song);
	if (end) {
		if (LinkedSet::getPointerTo(new_song)) {
			// Do nothing
			return false;
		}
		auto *oldnext = end->getNext();
		end->setNext(newend);
		newend->setNext(oldnext);
	}
	else {
		head_ptr_ = newend;
	}

	tail_ptr_ = newend;

	item_count_ += 1;

	return true;
}

bool PlayList::remove(const Song& a_song) {
	Node<Song>* prev;
	Node<Song>* cur = getPointerTo(a_song, prev);

	// Fix tail pointer in all cases
	if (cur == tail_ptr_) {
		tail_ptr_ = prev;
	}

	// Head pointer is a special case
	if (cur == head_ptr_) {
		head_ptr_ = cur->getNext();

		item_count_ -= 1;
		
		delete cur;

		return true;
	}

	// All other cases
	prev->setNext(cur->getNext());

	delete cur;

	item_count_ -= 1;

	return true;
}

void PlayList::loop() {
	loopImpl(true);
}

void PlayList::unloop() {
	// ignoring value
	(void) unloopImpl();
}

static std::ostream& operator<<(std::ostream& os, Song const& song) {
	// Friend function, so I can touch internals
	os << "* Title: " << song.getTitle() << " * Author: " << song.getAuthor() << " * Album: " << song.getAlbum()
	   << " * ";
	return os;
}

void PlayList::displayPlayList() {
	auto const v = toVector();

	// Print output
	for (auto const& val : v) {
		std::cout << val << '\n';
	}

	std::cout << "End of playlist\n";
}

Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const {
	bool const looped = unloopImpl();

	Node<Song>* last = head_ptr_;
	Node<Song>* item = last;

	// Loop until end or until found
	while (item && !(item->getItem() == target)) {
		last = exchange(item, item->getNext());
	}

	assert(item != nullptr);

	loopImpl(looped);

	previous_ptr = last;
	return item;
}

void PlayList::loopImpl(bool const loop) const noexcept {
	if (loop && tail_ptr_) {
		tail_ptr_->setNext(head_ptr_);
	}
}

bool PlayList::unloopImpl() const noexcept {
	bool looped = false;

	if (tail_ptr_) {
		looped = tail_ptr_->getNext() != nullptr;
		tail_ptr_->setNext(nullptr);
	}

	return looped;
}
