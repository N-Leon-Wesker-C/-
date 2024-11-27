#include <iostream>
using namespace std;

class DynamicStack {
private:
	int *arr;
	int top;
	int capacity;
	
	// 扩展栈的容量
	void resize() {
		capacity *= 2;
		int* newArr = new int[capacity];
		for (int i = 0; i <= top; ++i) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
	}
	
public:
	DynamicStack(int cap = 10) : capacity(cap), top(-1) {
		arr = new int[capacity];
	}
	
	// 进栈
	void push(int value) {
		if (top == capacity - 1) {
			resize();
		}
		arr[++top] = value;
	}
	
	// 出栈
	int pop() {
		if (top == -1) {
			cout << "Stack is empty!" << endl;
			return -1;
		}
		return arr[top--];
	}
	
	// 查看栈顶元素
	int peek() {
		if (top == -1) {
			cout << "Stack is empty!" << endl;
			return -1;
		}
		return arr[top];
	}
	
	~DynamicStack() {
		delete[] arr;
	}
};

// 链队列节点定义
struct Node {
	int data;
	Node* next;
	Node(int value) : data(value), next(nullptr) {}
};

// 链队列类定义
class LinkedQueue {
private:
	Node* front;
	Node* rear;
	
public:
	LinkedQueue() : front(nullptr), rear(nullptr) {}
	
	// 入队
	void enqueue(int value) {
		Node* newNode = new Node(value);
		if (rear) {
			rear->next = newNode;
		} else {
			front = newNode;
		}
		rear = newNode;
	}
	
	// 出队
	int dequeue() {
		if (!front) {
			cout << "Queue is empty!" << endl;
			return -1;
		}
		int value = front->data;
		Node* temp = front;
		front = front->next;
		if (!front) {
			rear = nullptr;
		}
		delete temp;
		return value;
	}
	
	// 查看队头元素
	int peek() {
		if (!front) {
			cout << "Queue is empty!" << endl;
			return -1;
		}
		return front->data;
	}
	
	~LinkedQueue() {
		while (front) {
			Node* temp = front;
			front = front->next;
			delete temp;
		}
	}
};


int main() {
	LinkedQueue queue;
	
	queue.enqueue(10);
	queue.enqueue(20);
	queue.enqueue(30);
	cout << "Front of queue: " << queue.peek() << endl;
	
	cout << "Dequeue from queue: " << queue.dequeue() << endl;
	cout << "Front of queue after dequeue: " << queue.peek() << endl;
	
	DynamicStack stack;
	
	stack.push(10);
	stack.push(20);
	stack.push(30);
	cout << "Top of stack: " << stack.peek() << endl;
	
	cout << "Pop from stack: " << stack.pop() << endl;
	cout << "Top of stack after pop: " << stack.peek() << endl;
	
	return 0;
}

