#include<iostream>
using namespace std;

template<typename T>
class Stack {

private:
	struct Node
	{
		T data;
		struct Node *next;
	};	Node *top = NULL;

public:
	void push(T);
	void pop();
	void display();
	bool isEmpty();
};


template<typename T>
void Stack<T>::push(T value)
{
	struct Node *newNode;
	newNode = new Node();
	newNode->data = value;
	if (top == NULL)
		newNode->next = NULL;
	else
		newNode->next = top;
	top = newNode;
	cout << "Insertion is Success" << endl;
}


template<typename T>
void Stack<T>::pop()
{
	if (top == NULL)
		cout << "Stack is Empty " << endl;
	else {
		struct Node *temp = top;
		cout << "Deleted element:" << temp->data << endl;
		top = temp->next;
		free(temp);
	}
}


template<typename T>
void Stack<T>::display()
{
	if (top == NULL)
		cout<<"Stack is Empty"<<endl;
	else {
		
		struct Node *temp = top;
		while (temp->next != NULL)
		{
			cout << "--->" << temp->data;
			temp = temp->next;
		}
			cout << "--->" << temp->data << endl;
	}
}

template<typename T>
bool Stack<T>::isEmpty() {
	if (top == NULL)
	{ return true; }
	return false;
}