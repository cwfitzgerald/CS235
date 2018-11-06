#include "MazeSolver.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstring>

MazeSolver::MazeSolver(std::string input_file) {
	std::ifstream stream(input_file);
	if (!stream) {
		throw std::invalid_argument("File " + input_file + " not found.");
	}

	fillMaze(stream);
}

MazeSolver::~MazeSolver() {
	for (std::size_t x = 0; x < this->maze_rows_; ++x) {
		delete[] maze_[x];
		delete[] solution_[x];
	}
	delete[] maze_;
	delete[] solution_;
}

bool MazeSolver::mazeIsReady() {
	return this->maze_ready;
}

bool MazeSolver::solveMaze() {
	auto const get = [&](Position p) -> char& {
		return this->maze_[p.row][p.column];
	};

	get({ 0, 0 }) = '>';

	extendPath({0, 0});

	Position cur_pos{ 0, 0 };
	while (!this->backtrack_stack_.empty()) {
		if (get(cur_pos) == '$') {
			std::cout << "Found the exit!!!\n";
			return true;
		}
		bool const movable = this->extendPath(cur_pos);
		if (movable) {
			get(cur_pos) = '>';
			cur_pos = this->backtrack_stack_.top();
		}
		else {
			get(cur_pos) = '@';
			this->backtrack_stack_.pop();
			if (!this->backtrack_stack_.empty()) {
				cur_pos = this->backtrack_stack_.top();
			}
		}
	}
	get({ 0, 0 }) = '@';
	std::cout << "This maze has no solution.\n";
	return false;
}

void MazeSolver::printSolution() {
	std::cout << "The solution to this maze is:\n";

	for (std::size_t row = 0; row < this->maze_rows_; ++row) {
		for (std::size_t col = 0; col < this->maze_columns_; ++col) {
			std::cout << this->maze_[row][col];
			if (col != this->maze_columns_ - 1) {
				std::cout << ' ';
			}
		}
		std::cout << '\n';
	}
}

void MazeSolver::initializeMaze(int rows, int columns) {
	this->maze_ = new char*[rows];
	this->solution_ = new char*[rows];

	for (std::size_t x = 0; x < rows; ++x) {
		this->maze_[x] = new char[columns];
		this->solution_[x] = new char[columns];
	}
}

void MazeSolver::fillMaze(std::ifstream& input_stream) {
	input_stream >> this->maze_rows_;
	input_stream >> this->maze_columns_;

	initializeMaze(this->maze_rows_, this->maze_columns_);

	for (std::size_t row = 0; row < this->maze_rows_; ++row) {
		for (std::size_t col = 0; col < this->maze_columns_; ++col) {
			// Skip whitespace
			input_stream.get();
			this->maze_[row][col] = input_stream.get();
		}
	}

	this->maze_ready = true;
}

void MazeSolver::initializeSolution() {
	// no-op, this function is silly
}

void MazeSolver::copyMazetoSolution() {
	for (std::size_t row = 0; row < this->maze_rows_; ++row) {
		std::memcpy(solution_[row], maze_[row], this->maze_columns_);
	}
}

bool MazeSolver::extendPath(Position current_position) {
	auto south = Position{ current_position.row + 1, current_position.column };
	auto east = Position{ current_position.row, current_position.column + 1};

	bool modified = false;

	if (south.row < this->maze_rows_ && south.column < this->maze_columns_) {
		if (maze_[south.row][south.column] == '_' || maze_[east.row][east.column] == '$') {
			modified = true;
			this->backtrack_stack_.emplace(std::move(south));
		}
	}
	if (east.row < this->maze_rows_ && east.column < this->maze_columns_) {
		if (maze_[east.row][east.column] == '_' || maze_[east.row][east.column] == '$') {
			modified = true;
			this->backtrack_stack_.emplace(std::move(east));
		}
	}

	return modified;
}

Position MazeSolver::getNewPosition(Position old_position, direction dir) {
	// no-op, inline
	(void) old_position;
	(void) dir;
	return Position{};
}

bool MazeSolver::isExtensible(Position current_position, direction dir) {
	// no-op, inline
	(void) current_position;
	(void) dir;
	return false;
}
