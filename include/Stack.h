#pragma once
#include<iostream>
#include<exception>
#include<map>
#include<vector>
using namespace std;
template <class T>
class Stack {
	T* begin; // pMem
	T* end; // end
	int size; // memSize (максимально допустимое)
public:

	Stack(int _n=100) {
		if (_n < 0) throw invalid_argument("Stack size should be positive value");
		size = _n;
		begin = new T[size]{};
		end = begin;
	}
	Stack(const Stack& s) : size(s.size) {
		begin = new T[size]{};
		for (int i = 0; i < size; i++) {
			begin[i] = s.begin[i];
		}
		end = begin + (s.end - s.begin);
	}
	~Stack() { delete[] begin; }

	void Push(T el) {
		if (end - begin == size) {
			size *= 2;
			T* tmp = new T[size]{};
			std::copy(begin, begin + size, tmp);
			end = tmp + (end - begin);
			delete[] begin;
			begin = tmp;
		}
		*end = el;
		end++;
	}
	T Top() {
		if (IsEmpty()) {
			throw out_of_range("Stack is empty");
		}
		return *end;
	}
	T Pop() {
		if (IsEmpty()) throw "Stack is empty"; 
		return *(--end);
		 
	}
	bool IsEmpty() { return end == begin; }
	int Size() { return end - begin; }
	bool operator==(const Stack& s) {
		if ((end - begin) != (s.end - s.begin)) return false;
		
		for (int i = 0; i < end - begin; i++) {
			if (begin[i] != s.begin[i]) return false;
		}
		return true;
	}
	friend ostream& operator<<(ostream& ostr, const Stack<T>& s) {
		for (int i = s.end - s.begin - 1; i >= 0; i--) {
			cout << s.begin[i];
		}
		return ostr;
	}

};
