#include<iostream>
using namespace std;

#define max_size 50
template <typename T>
class Queue {

private:
	
	int 
		front,
		noOfElement,
		rear,
		capacity;
	
		T *data;
	
	void regrow();
	void arrayShifting();
public:
	Queue();
	~Queue();
	Queue(int capacity);
	bool isFull();
	bool isEmpty();
	void enQueue(T value);
	void deQueue();
	T getfront();
	void display();
	int getCurrentSize();
	int getCapacity();
};



template <typename T>
Queue<T>::Queue() {
	capacity = max_size;
	front = 0;
	rear = -1;
	noOfElement = 0;
	data = new T[capacity];
}

template <typename T>
Queue<T>::Queue(int capacity) {
	this->capacity = capacity;
	front = 0;
	rear = -1;
	noOfElement = 0;
	data = new T[capacity];
}


template <typename T>
Queue<T>::~Queue() {
	delete[] data;
}

template <typename T>
bool Queue<T>::isFull()
{
	return (noOfElement == capacity);
}


template <typename T>
bool Queue<T>::isEmpty()
{
	return (noOfElement == 0);
}

template <typename T>
void Queue<T>::enQueue(T value) {
	if (rear == capacity - 1 && front == 0)
	{
		regrow();
	}
	else
	{
		if (front != 0)
		{
			//array shifting
			arrayShifting();
			}

	}
	rear++;
	data[rear] = value;
	noOfElement++;
	cout << "Insertion success!!!"<<endl;
}


template <typename T>
void Queue<T>::deQueue() {
	if (isEmpty())
		cout << "Queue is Empty!!! Deletion is not possible!!!"<<endl;
	else {
		cout << "Dequeue element  " << data[front] << endl;
		front++;
		noOfElement--;
		if (front == rear)
			front = rear = 0;
	}
}

template <typename T>
T Queue<T>::getfront()
{
	if (isEmpty())
	{
		cout << "Queue is Empty!!!" << endl;
		return -1;
	}
	return data[front];
}



template <typename T>
int Queue<T>::getCurrentSize() { return noOfElement; }

template <typename T>
int Queue<T>::getCapacity() { return capacity; }

template <typename T>
void Queue<T>::display() {
	if (isEmpty())
		cout << "Queue is Empty!!!" << endl;
	else {
		cout << "Queue elements are::" <<endl;
		if (front == 0)
		{
			for (int i = 0; i < noOfElement; i++)
				cout << data[i] << " -> ";
		}
		else
		{
			for (int i = front; i <= noOfElement; i++)
				cout << data[i] << " -> ";
		}
		cout << endl;
	}
}

template <typename T>
void Queue<T>::regrow() {
	T*temp_ptr = new T[capacity];
	int j = 0;
	for (int i = front; i < noOfElement; i++)
	{
		temp_ptr[j] = data[i];
		j++;
	}
	delete[] data;

	//arr = temp_ptr;
	//temp_ptr = nullptr;

	data = new T[capacity + 10];
	for (int i = 0; i < noOfElement; i++)
	{
		data[i] = temp_ptr[i];
	}
	delete[] temp_ptr;
	capacity += 10;
}

template <typename T>
void Queue<T>::arrayShifting() {
	rear = rear - front;
	int j = 0;
	for (int i = front; i <= noOfElement; i++)
	{
		data[j] = data[i];
		j++;
	}
	front = 0;
}