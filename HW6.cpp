// HW6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int extraction_method(int key);
bool quadratic_probing_without_repacement(int key,int*hash_table,int M, int i);

int main()
{
	int input=0;
	while (input < 1 || input>450000000)
	{
		cout << "enter a number between 1 and 450 million" << endl;
		cin >> input;
		if (input < 1 || input>450000000)
			cout << "invalid input" << endl;
	}


	ifstream in;
	int SSnum[65000];
	int SShash[65000] = { 0 };
	in.open("everybodys_socials.txt");
	if (!in.is_open())
	{
		cout << "file not found" << endl;
		return 0;
	}
	char num[9];
	int j = 0;
	while (in.good())//stores SS nums in array
	{
		in.getline(num,10,',');

		SSnum[j] = atoi(num);
		j++;
	}

	for (j = 0; j < 65000; j++)//hashing nums to table
	{
		int address = extraction_method(SSnum[j]);
		if (SShash[address] == 0)
			SShash[address] = SSnum[j];
		else
			quadratic_probing_without_repacement(SSnum[j], SShash, 65000, input);
	}
	ofstream out;
	out.open("hashed_socials.txt");
	string output;
	for (int i=0; i < 65000; i++)
	{
		out << SShash[i];
		if (i != 64999)
			out << ',';
	}
	system("pause");
	return 0;
}

int extraction_method(int key)
{
	int digit3 = (key / 1000000) % 10;
	int digit5 = (key / 1000) % 10;
	int digit7 = (key / 100) % 10;
	int digit8 = (key / 10) % 10;
	return (digit3 * 1000) + (digit5 * 100) + (digit7 * 10) + digit8;
}

bool quadratic_probing_without_repacement(int key, int*hash_table, int M, int i)//MAY NEED TO CHANGE
{
	int address = (extraction_method(key) + i*i)%M;
	int j;
	for (j = 0; j < 65000; j++ )
	{
		if (hash_table[address] == 0)
		{
			hash_table[address] = key;
			return true;
		}
		else
		{
			address++;
			address=address%M;
		}
	}
	if (j >= 65000)//all addresses were checked
		return false;
	
}