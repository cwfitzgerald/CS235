#include "Song.h"
#include <iostream>

void Song::setTitle(std::string title) {
	title_ = std::move(title);
}

void Song::setAuthor(std::string author) {
	author_ = std::move(author);
}

void Song::setAlbum(std::string album) {
	album_ = std::move(album);
}

std::string Song::getTitle() const {
	return title_;
}

std::string Song::getAuthor() const {
	return author_;
}

std::string Song::getAlbum() const {
	return album_;
}

bool operator==(const Song &lhs, const Song &rhs) {
	return lhs.title_ == rhs.title_ && lhs.album_ == rhs.album_ && lhs.author_ == rhs.author_;
}

std::ostream &operator<<(std::ostream &os, Song const &song) {
	os << "* Title: " <<  song.title_ << " * Author: " << song.author_ << " * Album: " << song.album_ << " * ";
	return os;
}

Song::Song(const std::string &title, std::string const &author, std::string const &album)  : title_(title), author_(author), album_(album) {}

Song::Song() : title_(), author_(), album_() {}
