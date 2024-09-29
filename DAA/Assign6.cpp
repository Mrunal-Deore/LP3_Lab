/*Design 8-Queens matrix having first Queen placed. Use backtracking to place remaining
Queens to generate the final 8-queen’s matrix.*/

//Time complexity = O(N!)

#include <bits/stdc++.h>
using namespace std;
int N=0;
void printSolution(int board[100][100]){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++)
		if(board[i][j]){
			cout << "Q ";
		}
		else{ cout<<". ";};
		printf("\n");
	}
	cout << endl;
}

bool isSafe(int board[100][100], int row, int col){
	int i, j;
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;
	return true;
}

bool solveNQUtil(int board[100][100], int col){
	if (col >= N){
			printSolution(board);
			return true;
		}
	bool isValid = false;
	for (int i = 0; i < N; i++){
		if (isSafe(board, i, col)) {
			board[i][col] = 1;
			isValid = isValid | solveNQUtil(board, col + 1);
			board[i][col] = 0; 
		}
	}
	return isValid;
}

bool solveNQ(){
	cout<<"Enter value number of queens:"<<endl;
	cin>>N;
	int board[100][100];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			board[i][j]=0;
		}		
	}	
	if (solveNQUtil(board, 0) == false){
		cout << "Solution does not exist\n";
		return false;
	}
	return true;
}

int main(){
	solveNQ();
	return 0;
}


/*
OUTPUT

Enter value number of queens:
5
Q . . . .
. . . Q .
. Q . . .
. . . . Q
. . Q . .

Q . . . .
. . Q . .
. . . . Q
. Q . . .
. . . Q .

. . Q . .
Q . . . .
. . . Q .
. Q . . .
. . . . Q

. . . Q .
Q . . . .
. . Q . .
. . . . Q
. Q . . .

. Q . . .
. . . Q .
Q . . . .
. . Q . .
. . . . Q

. . . . Q
. . Q . .
Q . . . .
. . . Q .
. Q . . .

. Q . . .
. . . . Q 
. . Q . .
Q . . . .
. . . Q .

. . . . Q
. Q . . .
. . . Q .
Q . . . .
. . Q . .

. . . Q .
. Q . . .
. . . . Q
. . Q . .
Q . . . .

. . Q . .
. . . . Q
. Q . . .
. . . Q .
Q . . . .
 */