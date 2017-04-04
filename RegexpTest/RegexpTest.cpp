// RegexpTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	cout << "RegexpTest Start" << endl;
	cout << "Arguments:" << argc << endl;
	vector<string> args(argv, argv + argc);
	for (auto& arg : args)
		cout << arg << endl;
	cout << "RegexpTest End" << endl;
	return 0;
}

