#include "Song.h"
#include <iostream>

void Song::setTitle(std::string title) {
	// Setter
	title_ = std::move(title);
}

void Song::setAuthor(std::string author) {
	// Setter
	author_ = std::move(author);
}

void Song::setAlbum(std::string album) {
	// Setter
	album_ = std::move(album);
}

std::string Song::getTitle() const {
	// Getter
	return title_;
}

std::string Song::getAuthor() const {
	// Getter
	return author_;
}

std::string Song::getAlbum() const {
	// Getter
	return album_;
}

bool operator==(const Song& lhs, const Song& rhs) {
	// Getter
	return lhs.title_ == rhs.title_ && lhs.album_ == rhs.album_ && lhs.author_ == rhs.author_;
}

std::ostream& operator<<(std::ostream& os, Song const& song) {
	// Friend function, so I can touch internals
	os << "* Title: " << song.title_ << " * Author: " << song.author_ << " * Album: " << song.album_
	   << " * ";
	return os;
}

Song::Song(const std::string& title, std::string const& author, std::string const& album) :
    title_(title),
    author_(author),
    album_(album) {}

Song::Song() : title_(), author_(), album_() {
	// Empty constructor
}
