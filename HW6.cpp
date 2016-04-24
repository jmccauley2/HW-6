// HW6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;



int main()
{
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
	while (in.good())
	{
		in.getline(num,10,',');

		SSnum[j] = atoi(num);
		j++;
	}

	system("pause");
	return 0;
}