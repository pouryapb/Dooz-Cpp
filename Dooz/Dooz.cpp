// Dooz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int player1_wins = 0, player2_wins = 0;
char **place;
string player1, player2;
void getter(int turn);
bool win_detector();
void game();
int start();
void singleplayer();
void multiplayer();
void winners();
void the_ai();

int main()
{
	//jadvale dooz
	place = new char *[13];
	for (int i = 0; i < 13; i++) {
		place[i] = new char[19];
	}
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 13; j++) {
			place[j][i] = ' ';
		}
	}
	for (int i = 0; i < 19; i++) {
		place[0][i] = '$';
		place[4][i] = '$';
		place[8][i] = '$';
		place[12][i] = '$';
	}
	for (int i = 0; i < 13; i++) {
		place[i][0] = '$';
		place[i][6] = '$';
		place[i][12] = '$';
		place[i][18] = '$';
	}
	place[2][3] = '1';
	place[2][9] = '2';
	place[2][15] = '3';
	place[6][3] = '4';
	place[6][9] = '5';
	place[6][15] = '6';
	place[10][3] = '7';
	place[10][9] = '8';
	place[10][15] = '9';

	start();
    return 0;
}
//tabe E baraye tashkhise payane bazi
bool win_detector() {
	if (place[2][3] == 'X' && place[2][9] == 'X' && place[2][15] == 'X') {
		player1_wins++;
		return true;
	}
	else if (place[6][3] == 'X' && place[6][9] == 'X' && place[6][15] == 'X') {
		player1_wins++;
		return true;
	}
	else if (place[10][3] == 'X' && place[10][9] == 'X' && place[10][15] == 'X') {
		player1_wins++;
		return true;
	}
	else if (place[2][3] == 'X' && place[6][3] == 'X' && place[10][3] == 'X') {
		player1_wins++;
		return true;
	}
	else if (place[2][9] == 'X' && place[6][9] == 'X' && place[10][9] == 'X') {
		player1_wins++;
		return true;
	}
	else if (place[2][15] == 'X' && place[6][15] == 'X' && place[10][15] == 'X') {
		player1_wins++;
		return true;
	}
	else if (place[2][3] == 'X' && place[6][9] == 'X' && place[10][15] == 'X') {
		player1_wins++;
		return true;
	}
	else if (place[2][15] == 'X' && place[6][9] == 'X' && place[10][3] == 'X') {
		player1_wins++;
		return true;
	}
	//player2
	else if (place[2][3] == 'O' && place[2][9] == 'O' && place[2][15] == 'O') {
		player2_wins++;
		return true;
	}
	else if (place[6][3] == 'O' && place[6][9] == 'O' && place[6][15] == 'O') {
		player2_wins++;
		return true;
	}
	else if (place[10][3] == 'O' && place[10][9] == 'O' && place[10][15] == 'O') {
		player2_wins++;
		return true;
	}
	else if (place[2][3] == 'O' && place[6][3] == 'O' && place[10][3] == 'O') {
		player2_wins++;
		return true;
	}
	else if (place[2][9] == 'O' && place[6][9] == 'O' && place[10][9] == 'O') {
		player2_wins++;
		return true;
	}
	else if (place[2][15] == 'O' && place[6][15] == 'O' && place[10][15] == 'O') {
		player2_wins++;
		return true;
	}
	else if (place[2][3] == 'O' && place[6][9] == 'O' && place[10][15] == 'O') {
		player2_wins++;
		return true;
	}
	else if (place[2][15] == 'O' && place[6][9] == 'O' && place[10][3] == 'O') {
		player2_wins++;
		return true;
	}
	else {
		return false;
	}
}
//voroodi gir
void getter(int turn) {
	int a;
	label:
	cin >> a;
	while (a < 1 || a > 9) {
		cout << "wrong number, please insert a number between 1-9\n";
		cin >> a;
	}
	switch (a)
	{
	case 1:
		if (place[2][3] != '1') {
			cout << "place token! pick another:\n";
			goto label;
		}
		else if (turn == 0) {
			place[2][3] = 'X';
		}
		else {
			place[2][3] = 'O';
		}
		break;
	case 2:
		if (place[2][9] != '2') {
			cout << "place token! pick another:\n";
			goto label;
		}
		else if (turn == 0) {
			place[2][9] = 'X';
		}
		else {
			place[2][9] = 'O';
		}
		break;
	case 3:
		if (place[2][15] != '3') {
			cout << "place token! pick another:\n";
			goto label;
		}
		else if (turn == 0) {
			place[2][15] = 'X';
		}
		else {
			place[2][15] = 'O';
		}
		break;
	case 4:
		if (place[6][3] != '4') {
			cout << "place token! pick another:\n";
			goto label;
		}
		else if (turn == 0) {
			place[6][3] = 'X';
		}
		else {
			place[6][3] = 'O';
		}
		break;
	case 5:
		if (place[6][9] != '5') {
			cout << "place token! pick another:\n";
			goto label;
		}
		else if (turn == 0) {
			place[6][9] = 'X';
		}
		else {
			place[6][9] = 'O';
		}
		break;
	case 6:
		if (place[6][15] != '6') {
			cout << "place token! pick another:\n";
			goto label;
		}
		else if (turn == 0) {
			place[6][15] = 'X';
		}
		else {
			place[6][15] = 'O';
		}
		break;
	case 7:
		if (place[10][3] != '7') {
			cout << "place token! pick another:\n";
			goto label;
		}
		else if (turn == 0) {
			place[10][3] = 'X';
		}
		else {
			place[10][3] = 'O';
		}
		break;
	case 8:
		if (place[10][9] != '8') {
			cout << "place token! pick another:\n";
			goto label;
		}
		else if (turn == 0) {
			place[10][9] = 'X';
		}
		else {
			place[10][9] = 'O';
		}
		break;
	case 9:
		if (place[10][15] != '9') {
			cout << "place token! pick another:\n";
			goto label;
		}
		else if (turn == 0) {
			place[10][15] = 'X';
		}
		else {
			place[10][15] = 'O';
		}
		break;
	}
}
//game
void game() {
	system("cls");
	cout << "1.single player\n2.multiplayer\n";
	int a;
	cin >> a;
	while (a < 1 || a>2) {
		cout << "wrong number, please insert a number between 1-3:\n";
		cin >> a;
	}
	switch (a)
	{
	case 1: singleplayer();
		break;
	case 2:multiplayer();
		break;
	}
}
//start 
int start() {
	system("cls");
	cout << "welcome to the tic tac toe game!\n\n1.start game\n2.winner\n3.exit\n\nplease insert the number:\n";
	int a;
	cin >> a;
	while (a < 1 || a>3) {
		cout << "wrong number, please insert a number between 1-3:\n";
		cin >> a;
	}
	switch (a)
	{
	case 1: game();
		break;
	case 2: winners();
		break;
	case 3: return 0;
		break;
	}
}
//multiplayer
void multiplayer() {
	player1_wins = 0;
	player2_wins = 0;
	system("cls");
	cout << "Player1: ";
	cin >> player1;
	system("cls");
	cout << "Player2: ";
	cin >> player2;
	system("cls");
	int round = 1;
	srand(time(0));
	int turn = rand() % 2;
	int nowin = turn;
	while (round <= 5) {
		//Round: X
		cout << "Round: " << round << endl << endl;
		//player1--wins			player2--wins
		cout << player1 << "--" << player1_wins << "\t\t\t" << player2 << "--" << player2_wins << endl << endl;
		for (int i = 0; i < 13; i++) {
			cout << "     ";
			for (int j = 0; j < 19; j++) {
				cout << place[i][j];
			}
			cout << endl;
		}
		cout << endl;
		if (turn == 0) {
			cout << player1 << "'s turn\n";
		}
		else {
			cout << player2 << "'s turn\n";
		}
		getter(turn);
		turn = (turn + 1) % 2;
		if (win_detector()) {
			round++;
			place[2][3] = '1';
			place[2][9] = '2';
			place[2][15] = '3';
			place[6][3] = '4';
			place[6][9] = '5';
			place[6][15] = '6';
			place[10][3] = '7';
			place[10][9] = '8';
			place[10][15] = '9';
		}
		else if (place[2][3] != '1' && place[2][9] != '2' && place[2][15] != '3' && place[6][3] != '4' && place[6][9] != '5' && place[6][15] != '6' && place[10][3] != '7' && place[10][9] != '8' && place[10][15] != '9') {
			round++;
			place[2][3] = '1';
			place[2][9] = '2';
			place[2][15] = '3';
			place[6][3] = '4';
			place[6][9] = '5';
			place[6][15] = '6';
			place[10][3] = '7';
			place[10][9] = '8';
			place[10][15] = '9';
		}
		system("cls");
	}
	if (player1_wins > player2_wins) {
		fstream file;
		file.open("wins.txt", ios::app);
		file << player1 << " ------------------------------ " << player1_wins << "\n";
		file.close();
	}
	else if (player1_wins < player2_wins) {
		fstream file;
		file.open("wins.txt", ios::app);
		file << player2 << " ------------------------------ " << player2_wins << "\n";
		file.close();
	}
	else if (player1_wins == player2_wins && player1_wins != 0) {
		fstream file;
		file.open("wins.txt", ios::app);
		file << player1 << " ------------------------------ " << player1_wins << "\n";
		file << player2 << " ------------------------------ " << player2_wins << "\n";
		file.close();
	}
	else if (player1_wins == 0 && nowin == 1) {
		fstream file;
		file.open("wins.txt", ios::app);
		file << player1 << " ------------------------------ " << player1_wins << "\n";
		file.close();
	}
	else if (player2_wins == 0 && nowin == 0) {
		fstream file;
		file.open("wins.txt", ios::app);
		file << player2 << " ------------------------------ " << player2_wins << "\n";
		file.close();
	}
	winners();
}

void winners() {
	string line;
	system("cls");
	fstream file;
	file.open("wins.txt", ios::_Nocreate);
	if (file.is_open()) {
		while (getline(file, line)) {
			cout << line << "\n";
		}
		file.close();
	}
	else {
		cout << "No winner found!\n";
	}
	label1:
	cout << "Enter 0 to go back: ";
	int a;
	cin >> a;
	if (a == 0) {
		start();
	}
	else {
		system("cls");
		goto label1;
	}
}

void singleplayer() {
	player1_wins = 0;
	player2_wins = 0;
	system("cls");
	cout << "Please enter your name: ";
	cin >> player1;
	player2 = "AI";
	system("cls");
	int round = 1;
	srand(time(0));
	int turn = rand() % 2;
	int nowin = turn;
	while (round <= 5) {
		//Round: X
		cout << "Round: " << round << endl << endl;
		//player1--wins			player2--wins
		cout << player1 << "--" << player1_wins << "\t\t\t" << player2 << "--" << player2_wins << endl << endl;
		for (int i = 0; i < 13; i++) {
			cout << "     ";
			for (int j = 0; j < 19; j++) {
				cout << place[i][j];
			}
			cout << endl;
		}
		cout << endl;
		if (turn == 0) {
			cout << "Your turn!\n";
			getter(turn);
		}
		else {
			the_ai();
		}
		turn = (turn + 1) % 2;
		if (win_detector()) {
			round++;
			place[2][3] = '1';
			place[2][9] = '2';
			place[2][15] = '3';
			place[6][3] = '4';
			place[6][9] = '5';
			place[6][15] = '6';
			place[10][3] = '7';
			place[10][9] = '8';
			place[10][15] = '9';
		}
		else if (place[2][3] != '1' && place[2][9] != '2' && place[2][15] != '3' && place[6][3] != '4' && place[6][9] != '5' && place[6][15] != '6' && place[10][3] != '7' && place[10][9] != '8' && place[10][15] != '9') {
			round++;
			place[2][3] = '1';
			place[2][9] = '2';
			place[2][15] = '3';
			place[6][3] = '4';
			place[6][9] = '5';
			place[6][15] = '6';
			place[10][3] = '7';
			place[10][9] = '8';
			place[10][15] = '9';
		}
		system("cls");
	}
	if (player1_wins > player2_wins) {
		fstream file;
		file.open("wins.txt", ios::app);
		file << player1 << " ------------------------------ " << player1_wins << "\n";
		file.close();
	}
	else if (player1_wins == 0 && nowin == 1) {
		fstream file;
		file.open("wins.txt", ios::app);
		file << player1 << " ------------------------------ " << player1_wins << "\n";
		file.close();
	}
	winners();
}
void the_ai() {
	srand(time(0));
	//olaviate avval
	//1
	if (place[2][3] == 'O' && place[2][9] == 'O' && place[2][15] != 'X') {
		place[2][15] = 'O';
	}
	//2
	else if (place[2][9] == 'O' && place[2][15] == 'O' && place[2][3] != 'X') {
		place[2][3] = 'O';
	}
	//3
	else if (place[2][3] == 'O' && place[2][15] == 'O' && place[2][9] != 'X') {
		place[2][9] = 'O';
	}
	//4
	else if (place[6][3] == 'O' && place[6][9] == 'O' && place[6][15] != 'X') {
		place[6][15] = 'O';
	}
	//5
	else if (place[6][9] == 'O' && place[6][15] == 'O' && place[6][3] != 'X') {
		place[6][3] = 'O';
	}
	//6
	else if (place[6][3] == 'O' && place[6][15] == 'O' && place[6][9] != 'X') {
		place[6][9] = 'O';
	}
	//7
	else if (place[10][3] == 'O' && place[10][9] == 'O' && place[10][15] != 'X') {
		place[10][15] = 'O';
	}
	//8
	else if (place[10][9] == 'O' && place[10][15] == 'O' && place[10][3] != 'X') {
		place[10][3] = 'O';
	}
	//9
	else if (place[10][3] == 'O' && place[10][15] == 'O' && place[10][9] != 'X') {
		place[10][9] = 'O';
	}
	//10
	else if (place[2][3] == 'O' && place[6][3] == 'O' && place[10][3] != 'X') {
		place[10][3] = 'O';
	}
	//11
	else if (place[6][3] == 'O' && place[10][3] == 'O' && place[2][3] != 'X') {
		place[2][3] = 'O';
	}
	//12
	else if (place[2][3] == 'O' && place[10][3] == 'O' && place[6][3] != 'X') {
		place[6][3] = 'O';
	}
	//13
	else if (place[2][9] == 'O' && place[6][9] == 'O' && place[10][9] != 'X') {
		place[10][9] = 'O';
	}
	//14
	else if (place[6][9] == 'O' && place[10][9] == 'O' && place[2][9] != 'X') {
		place[2][9] = 'O';
	}
	//15
	else if (place[2][9] == 'O' && place[10][9] == 'O' && place[6][9] != 'X') {
		place[6][9] = 'O';
	}
	//16
	else if (place[2][15] == 'O' && place[6][15] == 'O' && place[10][15] != 'X') {
		place[10][15] = 'O';
	}
	//17
	else if (place[6][15] == 'O' && place[10][15] == 'O' && place[2][15] != 'X') {
		place[2][15] = 'O';
	}
	//18
	else if (place[2][15] == 'O' && place[10][15] == 'O' && place[6][15] != 'X') {
		place[6][15] = 'O';
	}
	//19
	else if (place[2][3] == 'O' && place[6][9] == 'O' && place[10][15] != 'X') {
		place[10][15] = 'O';
	}
	//20
	else if (place[6][9] == 'O' && place[10][15] == 'O' && place[2][3] != 'X') {
		place[2][3] = 'O';
	}
	//21
	else if (place[2][3] == 'O' && place[10][15] == 'O' && place[6][9] != 'X') {
		place[6][9] = 'O';
	}
	//22
	else if (place[10][3] == 'O' && place[6][9] == 'O' && place[2][15] != 'X') {
		place[2][15] = 'O';
	}
	//23
	else if (place[6][9] == 'O' && place[2][15] == 'O' && place[10][3] != 'X') {
		place[10][3] = 'O';
	}
	//24
	else if (place[10][3] == 'O' && place[2][15] == 'O' && place[6][9] != 'X') {
		place[6][9] = 'O';
	}
	//olaviat avval
	//1
	else if (place[2][3] == 'X' && place[2][9] == 'X' && place[2][15] != 'O') {
		place[2][15] = 'O';
	}
	//2
	else if (place[2][9] == 'X' && place[2][15] == 'X' && place[2][3] != 'O') {
		place[2][3] = 'O';
	}
	//3
	else if (place[2][3] == 'X' && place[2][15] == 'X' && place[2][9] != 'O') {
		place[2][9] = 'O';
	}
	//4
	else if (place[6][3] == 'X' && place[6][9] == 'X' && place[6][15] != 'O') {
		place[6][15] = 'O';
	}
	//5
	else if (place[6][9] == 'X' && place[6][15] == 'X' && place[6][3] != 'O') {
		place[6][3] = 'O';
	}
	//6
	else if (place[6][3] == 'X' && place[6][15] == 'X' && place[6][9] != 'O') {
		place[6][9] = 'O';
	}
	//7
	else if (place[10][3] == 'X' && place[10][9] == 'X' && place[10][15] != 'O') {
		place[10][15] = 'O';
	}
	//8
	else if (place[10][9] == 'X' && place[10][15] == 'X' && place[10][3] != 'O') {
		place[10][3] = 'O';
	}
	//9
	else if (place[10][3] == 'X' && place[10][15] == 'X' && place[10][9] != 'O') {
		place[10][9] = 'O';
	}
	//10
	else if (place[2][3] == 'X' && place[6][3] == 'X' && place[10][3] != 'O') {
		place[10][3] = 'O';
	}
	//11
	else if (place[6][3] == 'X' && place[10][3] == 'X' && place[2][3] != 'O') {
		place[2][3] = 'O';
	}
	//12
	else if (place[2][3] == 'X' && place[10][3] == 'X' && place[6][3] != 'O') {
		place[6][3] = 'O';
	}
	//13
	else if (place[2][9] == 'X' && place[6][9] == 'X' && place[10][9] != 'O') {
		place[10][9] = 'O';
	}
	//14
	else if (place[6][9] == 'X' && place[10][9] == 'X' && place[2][9] != 'O') {
		place[2][9] = 'O';
	}
	//15
	else if (place[2][9] == 'X' && place[10][9] == 'X' && place[6][9] != 'O') {
		place[6][9] = 'O';
	}
	//16
	else if (place[2][15] == 'X' && place[6][15] == 'X' && place[10][15] != 'O') {
		place[10][15] = 'O';
	}
	//17
	else if (place[6][15] == 'X' && place[10][15] == 'X' && place[2][15] != 'O') {
		place[2][15] = 'O';
	}
	//18
	else if (place[2][15] == 'X' && place[10][15] == 'X' && place[6][15] != 'O') {
		place[6][15] = 'O';
	}
	//19
	else if (place[2][3] == 'X' && place[6][9] == 'X' && place[10][15] != 'O') {
		place[10][15] = 'O';
	}
	//20
	else if (place[6][9] == 'X' && place[10][15] == 'X' && place[2][3] != 'O') {
		place[2][3] = 'O';
	}
	//21
	else if (place[2][3] == 'X' && place[10][15] == 'X' && place[6][9] != 'O') {
		place[6][9] = 'O';
	}
	//22
	else if (place[10][3] == 'X' && place[6][9] == 'X' && place[2][15] != 'O') {
		place[2][15] = 'O';
	}
	//23
	else if (place[6][9] == 'X' && place[2][15] == 'X' && place[10][3] != 'O') {
		place[10][3] = 'O';
	}
	//24
	else if (place[10][3] == 'X' && place[2][15] == 'X' && place[6][9] != 'O') {
		place[6][9] = 'O';
	}
	else {
		label2:
		int x = rand() % 9;
		switch (x)
		{
		case 0:
			if (place[2][3] == '1') {
				place[2][3] = 'O';
			}
			else {
				goto label2;
			}
			break;
		case 1:
			if (place[2][9] == '2') {
				place[2][9] = 'O';
			}
			else {
				goto label2;
			}
			break;
		case 2:
			if (place[2][15] == '3') {
				place[2][15] = 'O';
			}
			else {
				goto label2;
			}
			break;
		case 3:
			if (place[6][3] == '4') {
				place[6][3] = 'O';
			}
			else {
				goto label2;
			}
			break;
		case 4:
			if (place[6][9] == '5') {
				place[6][9] = 'O';
			}
			else {
				goto label2;
			}
			break;
		case 5:
			if (place[6][15] == '6') {
				place[6][15] = 'O';
			}
			else {
				goto label2;
			}
			break;
		case 6:
			if (place[10][3] == '7') {
				place[10][3] = 'O';
			}
			else {
				goto label2;
			}
			break;
		case 7:
			if (place[10][9] == '8') {
				place[10][9] = 'O';
			}
			else {
				goto label2;
			}
			break;
		case 8:
			if (place[10][15] == '9') {
				place[10][15] = 'O';
			}
			else {
				goto label2;
			}
			break;
		}
	}
}