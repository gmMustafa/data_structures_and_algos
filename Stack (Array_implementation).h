#include<iostream>
using namespace std;

#define max_Size 50

template<typename T>
class Stack {

private:
	T *data;
	int curr_size;
	int capacity;
public:
	Stack();
	~Stack();
	void push(T element);
	void pop();
	T getTop();
	bool isEmpty();

	int getSize();
	int getCapacity();
};


template<typename T>
Stack<T>::Stack(){
	data = new T[max_Size];
	capacity = max_Size;
}

template<typename T>
Stack<T>::~Stack(){
	delete[] data;
}

template<typename T>
void Stack<T>::push(T element){
	data[curr_size] = element;
	curr_size++;
}

template<typename T>
void Stack<T>::pop(){
	if (isEmpty())
	{
		cout << "EMPTY STACK" << endl;
		return;
	}
	curr_size--;
}

template<typename T>
T Stack<T>::getTop(){
	if (isEmpty())
	{
		cout << "EMPTY STACK" << endl;
		return -1;
	}
	return data[curr_size - 1];
}

template<typename T>
bool Stack<T>::isEmpty(){
	if (curr_size == 0) { return true; }
	return false;
}

template<typename T>
int Stack<T>::getSize(){
	return curr_size;
}

template<typename T>
int Stack<T>::getCapacity(){
	return capacity;
}