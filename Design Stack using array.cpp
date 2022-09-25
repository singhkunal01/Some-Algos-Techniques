/*---------------------------------Design stack ---------------------------------*/

#include<bits/stdc++.h>
using namespace std;


void push(int value , int &top, vector<int> &stack) {
	if (top == stack.size() - 1)
		cout << " Stack is Full " << endl;
	else {
		top++;
		stack[top] = value;
	}

}

void pop(int &top, vector<int> &stack) {
	if (top == -1)
		cout << "Stack is Empty." << endl;
	else {
		int del = stack[top--];
		cout << "Popped Element: " << del << endl;
	}
}


void display(int &top, vector<int> &stack) {
	if (top == -1) cout << "Please Exit, stack is Empty." << endl;
	else {
		for (int i = top; i >= 0; i--) cout << stack[i] << " ";
		cout << endl;
	}
}

void expandSize(int newSize, vector<int> &stack) {
	stack.resize(newSize);
}

int main() {
	int sizeOfStack, choice, top = -1;
	cout << "Enter the size of stack : ";
	cin >> sizeOfStack;
	vector<int> stack(sizeOfStack);//it will always remain dynamic
//making switch cases for the multiple choices
	cout << "1.Push the value." << endl <<
	     "2.Pop the value." << endl <<
	     "3.Display the Stack." << endl <<
	     "4.Expand the size of Stack." << endl <<
	     "5.Exit." << endl ;
	do {
		cout << "Input your Choice: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "Enter the value : ";
			int val;
			cin >> val;
			push(val, top, stack);
			break;
		}
		case 2: {
			pop(top, stack);
			break;
		}
		case 3: {
			display(top, stack);
			break;
		}
		case 4: {
			int newSize;
			cout << "Enter the New size :";
			cin >> newSize;
			expandSize(newSize,stack);
			break;
		}
		case 5: {
			cout << "Exiting..." << endl;
			break;
		}
		default: {
			cout << "Invalid Entry (-_-)" << endl;
			break;
		}
		}
	} while (choice != 5);
	return 0;

}
