#pragma once

#include <string>

class Song {
  public:
	Song();
	Song(const std::string& title, const std::string& author = "", const std::string& album = "");

	// A bunch of setters
	void setTitle(std::string title);
	void setAuthor(std::string author);
	void setAlbum(std::string album);
	// A bunch of getters
	std::string getTitle() const;
	std::string getAuthor() const;
	std::string getAlbum() const;

	// Friend
	friend bool operator==(const Song& lhs, const Song& rhs);

	// Output operator
	friend std::ostream& operator<<(std::ostream& os, Song const& song);

  private:
	// Private members
	std::string title_;
	std::string author_;
	std::string album_;
};

// Forward declared friend from above
bool operator==(const Song& lhs, const Song& rhs);
// Forward declared friend from above
std::ostream& operator<<(std::ostream& os, Song const& song);