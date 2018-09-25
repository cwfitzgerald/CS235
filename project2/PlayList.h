#pragma once

#include "Set.h"
#include "Song.h"

class PlayList {
  private:
	Set<Song> playlist_;

  public:
	PlayList();

	explicit PlayList(const Song& a_song);
	int getNumberOfSongs() const;

	bool isEmpty() const;

	bool addSong(const Song& new_song);

	bool removeSong(const Song& a_song);

	void clearPlayList();

	void displayPlayList() const;
};