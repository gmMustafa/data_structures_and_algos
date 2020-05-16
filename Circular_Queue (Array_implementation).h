#include<iostream>
using namespace std;

#define max_size 50
template<typename T>
class Circular_Queue {
	int rear, front;
	int size;
	T *arr;
public:
	Circular_Queue();
	Circular_Queue(int size);
	void enQueue(T value);
	T deQueue();
	void displayQueue();
};

template<typename T>
Circular_Queue<T>::Circular_Queue() {
	front = rear = -1;
	size = max_size;
	arr = new T[size];
}


template<typename T>
Circular_Queue<T>::Circular_Queue(int s)
{
	front = rear = -1;
	size = s;
	arr = new T[s];
}

template<typename T>
void Circular_Queue<T>::enQueue(T value)
{
	if ((front == 0 && rear == size - 1) ||
		(rear == front - 1))
	{
		cout<<"Queue is Full"<<endl;
		return;
	}

	else if (front == -1) 
		/* Insert First Element */
	{
		front = rear = 0;
		arr[rear] = value;
	}

	else if (rear == size - 1 && front != 0)
	{
		rear = 0;
		arr[rear] = value;
	}

	else
	{
		rear++;
		arr[rear] = value;
	}
}

// Function to delete element from Circular Queue
template<typename T>
T Circular_Queue<T>::deQueue()
{
	if (front == -1)
	{
		cout<<"Queue is Empty"<<endl;
		return -1;
	}

	int data = arr[front];
	arr[front] = -1;
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (front == size - 1)
		front = 0;
	else
		front++;

	return data;
}

// Function displaying the elements
// of Circular Queue


template<typename T>
void Circular_Queue<T>::displayQueue()
{
	if (front == -1)
	{
		cout<<"Queue is Empty"<<endl;
		return;
	}
	cout<<"Elements in Circular Queue are:" << endl;
	if (rear >= front)
	{
		for (int i = front; i <= rear; i++)
			cout<< arr[i]<<" -> ";
		cout << endl;
	}
	else
	{
		for (int i = front; i < size; i++)
			cout<< arr[i]<<" -> ";

		for (int i = 0; i <= rear; i++)
			cout << arr[i] << " -> ";
	}
}