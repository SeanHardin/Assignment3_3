//============================================================================
// Name        : Assignment3.cpp
// Author      : Sean Hardin
// Date        : 10/31/17
// Copyright   : Your copyright notice
// Description : Assignment 3 for cs300, includes stack based summation
//============================================================================

#include <iostream>
using namespace std;
#include "LinkedStack.h"

int main() {

	//***PART III********************************************
	bool valid = 0;
	string str1, str2;
	int count1, count2;
	while (!valid){//only takes number inputs
		valid = 1;
		cout << "Enter a very large number: ";
		getline (cin, str1);
		for (int i = 0; i < str1.length(); i++){
			if (str1[i] < '0' || str1[i] > '9')//any char that isn't a number
				valid = 0;//go through loop again
		}
		if (!valid)
			cout << "Non-number characters are not allowed." << '\n';
	}

	valid = 0;
	while (!valid){//only numbers
		valid = 1;
		cout << "Enter another very large number: ";
		getline (cin, str2);
		for (int i = 0; i < str2.length(); i++){
			if (str2[i] < '0' || str2[i] > '9')
				valid = 0;
		}
		if (!valid)
			cout << "Non-number characters are not allowed." << '\n';
	}
	if (str1.length()<str2.length()){//make stack 1 the larger one
		string temp = str1;
		str1 = str2;
		str2 = temp;
	}
	count1 = str1.length();//count # elements in each stack
	count2 = str2.length();
	LinkedStack<char> st1;//create larger stack
	for (int i = 0; i < count1; i++){
		st1.push(str1[i]);
	}
	LinkedStack<char> st2;
	for (int i = 0; i < count2; i++){//create stack 2, smaller
		st2.push(str2[i]);
	}
	LinkedStack<int> st3;//result stack

	int excess = 0;
	while (count2 > 0){//while stack 2 has elements
		int temp = (st1.pop().data - '0' + st2.pop().data - '0' + excess);//adds int value together
		st3.push(temp % 10);//push to result stack
		excess = 0;//reset excess after using
		if (temp > 9)//if there is an excess, change excess
			excess = 1;//because 2 value addition, can only be 1 or 0
		count2--;
		count1--;
	}
	if (excess){
		if (!st1.isEmpty())//more to stack 1
			st1.push(st1.pop().data + 1);
		else//stacks same height, deals with excess
			st3.push(excess);
	}
	while (count1 > 0){//prints remaining digits left in larger stack
		int temp = st1.pop().data - '0';
		st3.push(temp % 10);
		count1--;
		if (temp > 9) {//in case excess digits
			if (!st1.isEmpty())//to not pop empty stack
				st1.push(st1.pop().data + 1);//bump next value by 1
			else {//no more elements, just push excess on top of result stack
				excess = 1;
				st3.push(excess);
			}
		}
	}

	cout << "sum = ";
	while (!st3.isEmpty()){//print the resulting list
		cout << st3.pop().data;
	}

	return 0;
}
