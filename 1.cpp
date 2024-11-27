#include <iostream>
using namespace std;

// 定义顺序表类
class SeqList {
private:
	int *arr;        // 存储数据的数组
	int size;        // 当前元素个数
	int capacity;    // 数组容量
	
public:
	SeqList(int cap) {
		capacity = cap;
		size = 0;
		arr = new int[capacity];
	}
	
	// 插入元素
	void insert(int index, int value) {
		if (index < 0 || index > size) {
			cout << "Index out of bounds!" << endl;
			return;
		}
		if (size == capacity) {
			cout << "List is full!" << endl;
			return;
		}
		for (int i = size; i > index; --i) {
			arr[i] = arr[i - 1];
		}
		arr[index] = value;
		size++;
	}
	
	// 删除元素
	void remove(int index) {
		if (index < 0 || index >= size) {
			cout << "Index out of bounds!" << endl;
			return;
		}
		for (int i = index; i < size - 1; ++i) {
			arr[i] = arr[i + 1];
		}
		size--;
	}
	
	// 定位查找
	int locate(int value) {
		for (int i = 0; i < size; ++i) {
			if (arr[i] == value) {
				return i;  // 返回元素位置
			}
		}
		return -1; // 未找到
	}
	
	// 查找并删除指定元素
	void findAndRemove(int value) {
		int index = locate(value);
		if (index != -1) {
			remove(index);
			cout << "Element " << value << " removed." << endl;
		} else {
			cout << "Element not found!" << endl;
		}
	}
	
	// 打印顺序表
	void print() {
		for (int i = 0; i < size; ++i) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	
	~SeqList() {
		delete[] arr;
	}
};

int main() {
	SeqList list(10);
	list.insert(0, 10);
	list.insert(1, 20);
	list.insert(2, 30);
	list.insert(1, 15);
	cout << "List after insertions: ";
	list.print();
	
	list.remove(2);
	cout << "List after removing element at index 2: ";
	list.print();
	
	list.findAndRemove(15);
	cout << "List after removing element 15: ";
	list.print();
	
	return 0;
}

