#include "MazeSolver.h"

int main(int argc, char* argv[]) {
	for (std::size_t i = 1; i < argc; ++i) {
		std::cout << "\nSolving Maze: " << argv[i] << '\n';
		MazeSolver solver(argv[i]);
		if (solver.mazeIsReady()) {
			solver.solveMaze();
			solver.printSolution();
		}
	}	
}
