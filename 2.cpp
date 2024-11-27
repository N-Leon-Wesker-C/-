#include <iostream>
using namespace std;

// 单链表节点定义
struct Node {
	int data;
	Node* next;
	Node(int value) : data(value), next(nullptr) {}
};

// 单链表类定义
class LinkedList {
private:
	Node* head;
	
public:
	LinkedList() : head(nullptr) {}
	
	// 插入元素到链表
	void insert(int value) {
		Node* newNode = new Node(value);
		if (!head) {
			head = newNode;
		} else {
			Node* temp = head;
			while (temp->next) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	
	// 打印链表
	void print() {
		Node* temp = head;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	
	// 合并两个有序链表
	static Node* merge(Node* list1, Node* list2) {
		Node dummy(0); // 虚拟头节点
		Node* current = &dummy;
		while (list1 && list2) {
			if (list1->data < list2->data) {
				current->next = list1;
				list1 = list1->next;
			} else {
				current->next = list2;
				list2 = list2->next;
			}
			current = current->next;
		}
		if (list1) current->next = list1;
		if (list2) current->next = list2;
		return dummy.next;
	}
	
	// 获取链表头节点
	Node* getHead() {
		return head;
	}
};

int main() {
	LinkedList list1, list2;
	list1.insert(1);
	list1.insert(3);
	list1.insert(5);
	
	list2.insert(2);
	list2.insert(4);
	list2.insert(6);
	
	cout << "List 1: ";
	list1.print();
	cout << "List 2: ";
	list2.print();
	
	Node* mergedHead = LinkedList::merge(list1.getHead(), list2.getHead());
	cout << "Merged List: ";
	while (mergedHead) {
		cout << mergedHead->data << " ";
		mergedHead = mergedHead->next;
	}
	cout << endl;
	
	return 0;
}

