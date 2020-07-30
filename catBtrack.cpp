#include<iostream>
using namespace std;

bool ratInAMaze(char maze[4][4], int sr, int sc, int er, int ec, int sol[4][4]) {
	//BASE CASE
	if (sr == er and sc == ec) {
		// PRINT
		sol[er][ec] = 1;
		for (int i = 0; i <= er; i++) {
			for (int j = 0; j <= ec; j++) {
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}
		cout << "*****************" << endl;

		return true;
	}

	if (sr > er or sc > ec) {
		return false;
	}

	if (maze[sr][sc] == 'X') {
		return false;
	}

	sol[sr][sc] = 1;

	// RECURSIVE CASE
	bool rightMove = ratInAMaze(maze, sr, sc + 1, er, ec, sol);
	bool downMove = ratInAMaze(maze, sr + 1, sc, er, ec, sol);

	// sol[sr][sc] = 0; // backtracking

	if (rightMove or downMove) {
		return true;
	}

	return false;
}

void printRatInAMaze(char maze[4][4], int sr, int sc, int er, int ec, int sol[4][4]) {
	if (sr == er and sc == ec) {
		// PRINT
		sol[er][ec] = 1;

		for (int i = 0; i <= er; i++) {
			for (int j = 0; j <= ec; j++) {
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}
		cout << "*****************" << endl;

		return;
	}

	if (sr > er or sc > ec) {
		return;
	}

	if (maze[sr][sc] == 'X') {
		return;
	}

	sol[sr][sc] = 1;

	// RECURSIVE CASE
	printRatInAMaze(maze, sr, sc + 1, er, ec, sol);
	printRatInAMaze(maze, sr + 1, sc, er, ec, sol);

	// my right and down work is done now thats why i'm here
	sol[sr][sc] = 0;
}

int main() {

	// int board[4][4] = {0};
	// int n = 4;

	// cout << NQueens(board, 0, n) << endl;

	int n = 4;
	char maze[4][4] = { {'0', '0', '0', '0'},
		{'0', '0', 'X', '0'},
		{'0', '0', '0', '0'},
		{'X', '0', '0', '0'}
	};

	int sol[4][4] = {0};

	cout << ratInAMaze(maze, 0, 0, n - 1, n - 1, sol) << endl;
	// printRatInAMaze(maze, 0, 0, n - 1, n - 1, sol);
	return 0;
}