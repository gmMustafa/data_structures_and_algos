#include<iostream>
using namespace std;

template <typename T>
class Queue {
	private:
		struct Node
		{
			T data;
			struct Node *next;
		};
		Node *front, *rear;

	public:
		Queue();
		void enqueue(T);
		T dequeue();
		void display();
};

template <typename T>
Queue<T>::Queue() {
	front = rear = NULL;
}


template <typename T>
void Queue<T>::enqueue(T value)
{
	struct Node *newNode;
	newNode = new Node();
	newNode->data = value;
	newNode->next = NULL;
	if (front == NULL)
		front = rear = newNode;
	else {
		rear->next = newNode;
		rear = newNode;
	}
	cout << "Insertion completed" << endl;
}


template <typename T>
T Queue<T>::dequeue()
{
	if (front == NULL)
		cout<<"Queue is Empty"<<endl;
			return NULL;
	else {
		T value;
		Node *temp = front;
		value = temp->data;
		front = front->next;
		cout << "Deleted element: " << temp->data <<endl;
		free(temp);
	}
	return value;
}


template <typename T>
void Queue<T>::display()
{
	if (front == NULL)
		cout<<"Queue is Empty"<<endl;
	else {
		struct Node *temp = front;
		while (temp->next != NULL) {
			cout<<"-->"<< temp->data;
			temp = temp->next;
		}
		cout << "-->" << temp->data << endl;
		
	}
}
