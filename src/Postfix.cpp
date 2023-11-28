#include"Stack.h"
#include"Postfix.h"
/* 

3+2*(6-4)

*/
Postfix::Postfix(string infx) {
	infix = infx;
	if (infix.empty()) throw invalid_argument("String is empty");
	int count = 0;
	for (int i = 0; i < infix.size(); i++) {
		if (infix[i] == '(') count++;
		if (infix[i] == ')')count--;
	}
	if (count != 0) throw "Incorrect string";
	if (infix.back() == '+' || infix.back() == '-' || infix.back() == '*' || infix.back() == '/')
		throw "Last element of string can't be '+' or '-' or '*' or '/'";
	priority = { {'+',1},{'-',1}, {'*',2}, {'/',2} , {'(',0}};
	ToPostfix();
}
void Postfix::Parse() {
	for (char c : infix) {
		lexems.push_back(c);
	}
}
void Postfix::ToPostfix() {
	Parse();
	Stack<char> st;
	char stItem;
	for (char item : lexems) {
		switch (item) {
		case '(':
			st.Push(item);
			break;
		case ')':
			stItem = st.Pop();
			while (stItem != '(') {
				postfix += stItem;
				stItem = st.Pop();
			}
			break;
		case '+': case '-': case '*': case '/':
			while (!st.IsEmpty()) {
				stItem = st.Pop();
				if (priority[item] <= priority[stItem]) 
					postfix += stItem;
				else {
					st.Push(stItem);
					break;
				}
			}
			st.Push(item);
			break;
		default:
			operands.insert({ item, 0.0 });
			postfix += item;
		}
	}
	while (!st.IsEmpty()) {
		stItem = st.Pop();
		postfix += stItem;
	}
}
double Postfix::Calculate() {
	for (auto& val : values) {
		try {
			operands.at(val.first) = val.second;
		}
		catch (out_of_range &e){}
	}
	Stack<double> st;
	double leftOperand, rightOperand;
	for (char lexem : postfix) {
		switch (lexem) {
		case '+':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(leftOperand + rightOperand);
			break;
		case '-':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(leftOperand - rightOperand);
			break;
		case '*':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(leftOperand * rightOperand);
			break;
		case '/':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(leftOperand / rightOperand);
			break;
		default:
			st.Push(operands[lexem]);
		}
	}
	return st.Pop();
}
vector<char> Postfix::GetOperands() const {
	vector<char> op;
	for (const auto& item : operands) {
		op.push_back(item.first);
	}
	map<char, double> values;
	double val;
	for (const auto& op : operands) {
		const char* s = &op.first;
		val = atof(s);
		values[op.first] = val;
	}
	return op;
}
