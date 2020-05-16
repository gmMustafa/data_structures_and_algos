#include<iostream>
using namespace std;

template<typename T>
class Circular_Queue {

	struct Node
	{
		int data;
		struct Node* next;
	};
	 Node *front, *rear;
public:
	Circular_Queue();
	void enQueue(T value);
	T deQueue();
	void displayQueue();
};

template<typename T>
Circular_Queue<T>::Circular_Queue() {
	rear = front = nullptr;
}


template<typename T>
void Circular_Queue<T>::enQueue(T value)
{
	Node *temp = new Node();
	temp->data = value;
	if (front == NULL)
		front= temp;
	else
		rear->next = temp;

	rear = temp;
	rear->next = front;
}

template<typename T>
T Circular_Queue<T>::deQueue()
{
	if (front == NULL)
	{
		printf("Queue is empty");
		return NULL;
	}

	// If this is the last node to be deleted
	T value; // Value to be dequeued
	if (front == rear)
	{
		value = front->data;
		free(front);
		front = NULL;
		rear = NULL;
	}
	else  // There are more than one nodes
	{
		Node *temp = front;
		value = temp->data;
		front = front->next;
		rear->next = front;
		free(temp);
	}
	return value;
}

template<typename T>
void Circular_Queue<T>::displayQueue()
{
	Node *temp = front;
	cout << "Elements in Circular Queue are: " << endl;
	while (temp->next != front)
	{
		cout << temp->data<<" -> ";
		temp = temp->next;
	}
	cout << temp->data << endl;
}