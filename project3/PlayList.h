// Assignment: CSCI 235, Fall 2018, Project 3
// Name: Connor Fitzgerald
// Date: 2018-10-02
// File Name: PlayList.h

#pragma once
#include "LinkedSet.h"
#include "Song.h"

class PlayList : public LinkedSet<Song> {
  private:
	Node<Song>* tail_ptr_; // Pointer to last node

  public:
	PlayList();                            // default constructor
	PlayList(const Song& a_song);          // parameterized constructor
	PlayList(const PlayList& a_play_list); // copy constructor
	~PlayList();                           // Destructor

	Node<Song>* getPointerToLastNode() const;
	bool add(const Song& new_song) override;
	bool remove(const Song& a_song) override;
	void loop();
	void unloop();
	void displayPlayList();

  private:
	Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const;
	void loopImpl(bool loop) const noexcept;
	bool unloopImpl()const noexcept;
};
