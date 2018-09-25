#include <iostream>
#include "PlayList.h"

PlayList::PlayList(Song const &a_song) {
	addSong(a_song);
}

int PlayList::getNumberOfSongs() const {
	return playlist_.getCurrentSize();
}

bool PlayList::isEmpty() const {
	return playlist_.isEmpty();
}

bool PlayList::addSong(const Song &new_song) {
	return playlist_.add(new_song);
}

bool PlayList::removeSong(const Song &a_song) {
	return playlist_.remove(a_song);
}

void PlayList::clearPlayList() {
	return playlist_.clear();
}

void PlayList::displayPlayList() const {
	auto&& list = playlist_.toVector();

	for (auto const& val : list) {
		std::cout << val << '\n';
	}

	std::cout << "End of playlist\n";
}

PlayList::PlayList() : playlist_(){}
