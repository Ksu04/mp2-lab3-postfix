#pragma once
#pragma once
#include<iostream>
#include<exception>
#include<map>
#include<vector>
#include"Stack.h"
using namespace std;

class Postfix {
	string infix;
	string postfix;
	vector<char> lexems;
	map<char, int> priority;
	map<char, double> operands;
	void Parse();
	void ToPostfix();
public:
	Postfix(string infx);
	const map<char, double> values = { {'0',0}, {'1',1}, {'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9} };
	string GetInfix() const { return infix; }
	string GetPostfix() const { return postfix; }
	vector<char> GetOperands() const;
	vector<char> GetLexems() const { return lexems; }
	double Calculate();
};