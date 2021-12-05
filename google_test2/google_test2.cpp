#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> Matrix;


void matrixKiir(const Matrix& matrix) {
	cout << "\t -.- Matrix -.-" << endl;
	for (int y = 0; y < matrix.size(); y++)
	{
		cout << "\t";
		for (int x = 0; x < matrix[y].size(); x++) {
				cout << matrix[x][y] << ", ";
		}
		cout << endl;
	}
	cout << endl;
}

void borderKiir(const map<int, int>& islands) {
	cout << "Border Islands: " << endl;
	for (auto elem : islands)
	{
		cout << "[" << elem.first / 10 << "," << elem.first % 10 << "] " << elem.second << "; ";
	}
	cout << endl;
}

bool checkIfRelevant(int x, int y, const Matrix& matrix) {
	int mSize = matrix.size() - 1;
	if (x < 0 || x > mSize || y < 0 || y > mSize) {
		return false;
	}
	else if (matrix[x][y] == 0) {
		return false;
	}
	return true;
}

void addToBorderIsland(int x, int y, map<int, int>& islands, const Matrix& matrix) {
	auto reference = islands.insert(make_pair((y * 10 + x), matrix[x][y]));
	if (!reference.second)
		return;
	else {
		if (checkIfRelevant(x - 1, y, matrix)) addToBorderIsland(x - 1, y, islands, matrix);
		if (checkIfRelevant(x + 1, y, matrix)) addToBorderIsland(x + 1, y, islands, matrix);
		if (checkIfRelevant(x, y - 1, matrix)) addToBorderIsland(x, y - 1, islands, matrix);
		if (checkIfRelevant(x, y + 1, matrix)) addToBorderIsland(x, y + 1, islands, matrix);
	}
}

int main()
{
	const int MSIZE = 6;
	/*
	vector<vector<int>> matrix = {{1, 0, 0, 0, 0, 0 },
								  {0, 1, 0, 1, 1, 1 },
								  {0, 0, 1, 0, 0, 0},
								  {1, 0, 0, 0, 1, 0 },
								  {1, 0, 1, 0, 1, 0},
								  {1, 0, 1, 0, 0, 1}};
	*/

	vector<vector<int>> matrix = {{1, 0, 0, 0, 0, 0 },
								  {0, 1, 0, 1, 1, 1 },
								  {0, 0, 1, 0, 1, 0},
								  {1, 1, 0, 0, 1, 0 },
								  {1, 0, 1, 1, 0, 0},
								  {1, 0, 0, 0, 0, 1}};

	cout << "\t-.- Input data -.-" << endl;
	matrixKiir(matrix);

	map<int, int> borderIslands;
	for (int i = 0; i < matrix.size(); i++) {
		if (matrix[i][0] == 1) addToBorderIsland(i, 0, borderIslands, matrix);
		if (matrix[i][MSIZE - 1] == 1) addToBorderIsland(i, 5, borderIslands, matrix);
		if (matrix[0][i] == 1) addToBorderIsland(0, i, borderIslands, matrix);
		if (matrix[MSIZE - 1][i] == 1) addToBorderIsland(5, i, borderIslands, matrix);
	}

	//borderKiir(borderIslands);

	vector<vector<int>> result(MSIZE, vector<int>(6));
	for (auto it : borderIslands) {
		result[it.first % 10][it.first / 10] = 1;
	}

	cout << endl << "\t-Algorithm result-" << endl;
	matrixKiir(result);
}
