#pragma once

#include "Set.h"
#include "Song.h"

class PlayList {
  private:
	Set<Song> playlist_;

  public:
	// Constructor
	PlayList();

	// Explicit Constructor
	explicit PlayList(const Song& a_song);

	// Getter
	int getNumberOfSongs() const;

	// Getter
	bool isEmpty() const;

	// Adds a song
	bool addSong(const Song& new_song);

	// Removes a song
	bool removeSong(const Song& a_song);

	// Clears Playlist
	void clearPlayList();

	// Prints playlist to stdout
	void displayPlayList() const;
};