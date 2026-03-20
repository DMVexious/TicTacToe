#include <bits/stdc++.h>
using namespace std;


vector<vector<char>> boardInfo;

bool isAvailable(){
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			if (boardInfo[i][j]==' '){
			   return true;
			}
		}
	}
	return false;
}

void printBoard(){
	for (int i=0;i<3;i++){
		cout<<"-------------"<<endl;
		for (int j=0;j<3;j++){
			cout<<"| ";
			cout<<boardInfo[i][j];
			cout<<' ';
			if (j==2) cout<<"|\n";
		}
		if (i==2) cout<<"-------------"<<endl;
	}
}

bool canMove(string move){
	int nrow;
	char row=move[0];
	if (row=='a')nrow=0; if (row=='b')nrow=1; if (row=='c')nrow=2;
	int col= (move[1]-1)-'0';
	
	if (boardInfo[nrow][col]==' ') return true;
}

string lowerit(string input){
	string output="";
	for (int i=0;i<input.size();i++){
		output+=tolower(input[i]);
	}
	return output;
}

void game(){
	int count=0;
	char player=' ';
	boardInfo.clear();
	boardInfo.resize(3,vector<char>(3,' ')); //reset
	
	while(isAvailable()){
		system("cls");
		printBoard();
		cout<<"It's Player "<<count+1<<"'s turn \n";
		if (count==0)player='X';
		else player='O';
	

		cout<<"Available moves: \n";
		for (int i=0;i<3;i++){
			for (int j=0;j<3;j++){
				if (boardInfo[i][j]==' '){
					if (i==0) cout<<'A'<<j+1;
					if (i==1) cout<<'B'<<j+1;
					if (i==2) cout<<'C'<<j+1;
					cout<<" ";
				}
			}
		}
		
		cout<<"\nWhere would you like to move?\n";
		bool again=true;
		while (again){
			string input;
	        cin>>input;
	        string move=lowerit(input);
			if (canMove(move)){
				int col= (move[1]-1)-'0';
				if (move[0]=='a') boardInfo[0][col]=player;
				if (move[0]=='b') boardInfo[1][col]=player;
				if (move[0]=='c') boardInfo[2][col]=player;
				again=false;
			}
			else cout<<"Not possible. Pick another move.\n";
		}
		//Wincheck
		for (int i=0;i<3;i++){
			bool rowcheck=((((boardInfo[i][0] == boardInfo[i][1]) && (boardInfo[i][1] == boardInfo[i][2]))) && (boardInfo[i][2]!=' '));
			bool colcheck=((((boardInfo[0][i] == boardInfo[1][i]) && (boardInfo[1][i]== boardInfo[2][i]))) && (boardInfo[2][i]!=' '));
			bool diagleft=((((boardInfo[0][0] == boardInfo[1][1]) && (boardInfo[1][1] == boardInfo[2][2]))) && (boardInfo[2][2]!=' '));
			bool diagright=((((boardInfo[0][2] == boardInfo[1][1]) && (boardInfo[1][1]== boardInfo[2][0]))) && (boardInfo[2][0]!=' '));
			//cout<<rowcheck<<colcheck<<diagleft<<diagright;
			if (rowcheck || colcheck || diagleft || diagright){
				if (rowcheck){
					if (boardInfo[i][0]=='X')cout<<"Player 1 has won!";
					else cout<<"Player 2 has won!";
				}
				if (colcheck){
					if (boardInfo[0][1]=='X')cout<<"Player 1 has won!";
					else cout<<"Player 2 has won!";
				}
				if (diagleft){
					if (boardInfo[0][0]=='X')cout<<"Player 1 has won!";
					else cout<<"Player 2 has won!";
				}
				if (diagright){
					if (boardInfo[2][0]=='X')cout<<"Player 1 has won!";
					else cout<<"Player 2 has won!";
				}
				cout<<endl;
				return;
			}
		}
		count++;
		count=count%2;
	}
	
	cout<<"It's a draw! \n";
}



//3x3 TicTacToe
int main() {
	cout<<"Start game?\n";
	cout<<"Yes/No 	";
	string input; cin>>input;
	string ans=lowerit(input);
	if (ans=="yes" or ans=="y"){
		bool play=true;
		string input2;
		while(play){
			game();
			cout<<"Play again? (y/n): ";
			cin>>input2;
			string ans2=lowerit(input2);
			if (ans2=="n" or ans2=="no") play=false;
		}
	}
	else{
		cout<<"Goodbye.";
	}
	
	
	return 0;
}


