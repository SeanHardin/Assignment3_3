/*
 * LinkedStack.h
 *
 *  Created on: Oct 30, 2017
 *      Author: Sean
 *      template class for link based stack, includes definitions because templates
 */

#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_
#include <iostream>
using namespace std;

	//***PART I********************************************

template <class T>
struct Node{//not same type as top, guess the assignment is impossible~
    T data;
    Node<T>* next;//changed capitalization to make it actually work
};

template <class T>
class LinkedStack{
      Node<T> *top;
   public:
      LinkedStack();
      bool isEmpty();
      int getCount();
      Node<T> getTop();
      Node<T> pop();
      void push(const T& datum);
      void destroy();
      template <typename U>
      friend ostream& operator<<(ostream& os, LinkedStack<U>& a);
      ~LinkedStack();
};

template <typename T>//constructor
LinkedStack<T>::LinkedStack(){
	top = NULL;
}

template <typename T>//constructor
bool LinkedStack<T>::isEmpty(){
	return top == NULL;
}

template <typename T>//returns number of entries in stack
int LinkedStack<T>::getCount(){
	int count = 0;
	Node<T> *ptemp = top;
	while (!isEmpty()){
		ptemp = ptemp->next;
		count++;//count after leaving node
	}
	return count;
}

template <typename T>//return top node
Node<T> LinkedStack<T>::getTop(){
	return top;
}

template <typename T>//destroy and return top node
Node<T> LinkedStack<T>::pop(){
	Node<T> *pdel = top;//to delete
	Node<T> temp = *top;//to return
	if (!isEmpty()){
		top = top->next;
		delete pdel;//actually delete nodes when lost
	}
	return temp;
}

template <typename T>//add onto the stack
void LinkedStack<T>::push(const T& datum){
	Node<T> *pnewNode = new Node<T>();
	pnewNode->data = datum;
	pnewNode->next = top;
	top = pnewNode;
}

template <typename T>//empty list
void LinkedStack<T>::destroy(){
	while (!isEmpty()){//top != NULL){
		pop();
	}
}

template <typename T>//destructor
LinkedStack<T>::~LinkedStack(){
	this->destroy();
}

template <typename T>//convert stack into stream
ostream& operator<<(ostream& os, LinkedStack<T>& a){
	Node<T> *tempTop=a.top;
	while (tempTop!=NULL){
		os << tempTop->data <<'\n';
		tempTop = tempTop->next;
	}
	return os;
}

#endif /* LINKEDSTACK_H_ */
