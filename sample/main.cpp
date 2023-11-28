#include"Stack.h"
#include"Postfix.h"
int main() {
	Stack<int> a;
	cout << "Stack: " << a << endl;
	a.Push(3);
	a.Push(5);
	cout << "Stack: "<< a << endl;
	a.Size();
	cout <<"Size of stack: "<< a.Size() << endl;
	//cout << "Top: " << a.Top() << endl;

	Stack<int> s(7);
	s.Push(2);
	s.Push(4);
	cout <<"After pushing: "<< s << endl;;
	s.Pop();
	cout <<"After popping: "<< s << endl;
	cout << "__________________________" << endl;
	string ex;
	cout << "enter expression: ";
	cin >> ex;
	Postfix expr(ex);
	cout <<"Infix form: " << expr.GetInfix() << endl;
	cout <<"Postfix form: "<< expr.GetPostfix() << endl;
	vector<char> operands = expr.GetOperands();
	for (size_t i = 0; i < operands.size(); i++) {
		cout << operands[i] << " ";
	}
	cout << endl;
	cout << "Caclulate: "<< expr.Calculate() << endl;
	
	setlocale(LC_ALL, "Russian");

	return 0;
}
// �������� �����. ���� ���, ���, ���, ==, 




/*

����
1) ����������� ������(���� ������, ����� sup)
#define MAX_SIZE  10
T arr[MAX_SIZE];
int n =0;
void push(t el)
{
	arr[n] = el;
	n++;
}

T end() { return arr[n-1]; }

void pop(){ n--; }

2) ������������ ������ (����� ������, ���������� sup)
T* end;
T* begin; // ������ ������� (�����)
int size;
n~end-begin // ���-�� ���������

3) ������ (�����������)
T data...	->...->	...	...
*next ...	  ...->	...	...

*/