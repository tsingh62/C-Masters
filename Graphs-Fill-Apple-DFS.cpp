#include<iostream>
#include<map>
#include<queue>
#include<list>
#include<cstring>
using namespace std;

int r;
int c;

void printMat(char input[][50])
{
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			cout << input[i][j];
		}
		cout << endl;
	}
}

//W,N,E,S
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

// Ch is the character to be replaced
// Color is the character to be added
void floodFill(char mat[][50], int i, int j, char ch, char color)
{
	// Base case - r=row/ c=col - Matrix Bounds
	if(i<0||j<0||i>=r||j>=c) // if it does not exceed the boundaries
	{
		return;
	}

	// Figure - Boundary condition
	if(mat[i][j]!=ch) // ch is the character to be replaced 
	{
		return;
	}
	// Recursive Call
	// 4 nbr approach
	mat[i][j]=color; // paint it with which ever color i want
	// for 4 directions
	for(int k=0; k<4; k++)
	{
		floodFill(mat,i+dx[k], j+dy[k],ch, color);// trying for every position
	}

}
int main()
{
	cin >> r >> c;
	char input[15][50];
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			cin >> input[i][j];
		}

	}

	printMat(input);
						//'.' is the char to be replaced
	floodFill(input, 8,13,'.','r'); // r is the color red
					//co-ordinates-cell for the fill
	printMat(input);
	return 0;
}

//g++ sample.cpp -std=c++11