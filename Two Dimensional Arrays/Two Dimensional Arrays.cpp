#include <iostream>



void transposeOfMatrix(int arr[][4], int idx);
bool searchMatrix(int arr[][4], int idx,int key);
int squareMatrix[4][4] = {
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,16}
};


using namespace std;
int main() {
	//transposeOfMatrix(squareMatrix, 4);
	cout << (searchMatrix(squareMatrix, 4, 14)?"element found":"element not found");
	return 0;
}

void transposeOfMatrix(int arr[][4], int idx) {
	int **transpose = new int*[idx];
	for (int i = 0; i < idx; i++)
	{
		transpose[i] = new int[idx];
	}
	for (int i = 0; i< idx; i++)
	{
		for (int j = 0; j < idx; j++)
		{
			transpose[i][j] = arr[j][i];
		}
	}
	cout << "transpose of array is :" << endl;
	for (int i = 0; i < idx; i++)
	{
		for (int j = 0; j < idx; j++) {
			cout << transpose[i][j] << " ";
		}
		cout << endl;
	}
	// Deallocate memory
	for (int i = 0; i < idx; i++) {
		delete[] transpose[i];
	}
	delete[] transpose;
}

//matrix search with optimized code
//for this purpose the array should be sorted from column and row both sides
bool searchMatrix(int arr[][4], int idx,int key) {
	int r = 0;
	int c = idx-1;
	while (r<idx && c>=0)
	{
		if (arr[r][c] == key) {
			return true;
		}
		else if (arr[r][c]>key)
		{
			c--;
		}
		else
		{
			r++;
		}
	}
	return false;
}