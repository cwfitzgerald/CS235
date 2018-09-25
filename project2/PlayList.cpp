#include "PlayList.h"
#include <iostream>

PlayList::PlayList(Song const& a_song) {
	// Delegate to addSong
	addSong(a_song);
}

int PlayList::getNumberOfSongs() const {
	// Forwarding function
	return playlist_.getCurrentSize();
}

bool PlayList::isEmpty() const {
	// Forwarding function
	return playlist_.isEmpty();
}

bool PlayList::addSong(const Song& new_song) {
	// Forwarding function
	return playlist_.add(new_song);
}

bool PlayList::removeSong(const Song& a_song) {
	// Forwarding function
	return playlist_.remove(a_song);
}

void PlayList::clearPlayList() {
	// Forwarding function
	return playlist_.clear();
}

void PlayList::displayPlayList() const {
	// Forwarding function
	auto&& list = playlist_.toVector();

	// Print output
	for (auto const& val : list) {
		std::cout << val << '\n';
	}

	std::cout << "End of playlist\n";
}

PlayList::PlayList() : playlist_() {
	// Empty constructor
}
