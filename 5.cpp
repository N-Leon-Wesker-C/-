#include <iostream>
#include <vector>
using namespace std;

// 稀疏矩阵三元组结构定义
struct Triple {
	int row;
	int col;
	int value;
};

// 稀疏矩阵快速转置
vector<Triple> fastTranspose(const vector<Triple>& matrix, int m, int n) {
	vector<Triple> result;
	vector<int> count(n, 0);  // 用来记录每列的非零元素个数
	vector<int> position(n, 0);  // 用来记录每列非零元素的起始位置
	
	// 计算每列的非零元素数量
	for (const auto& item : matrix) {
		count[item.col]++;
	}
	
	// 计算每列非零元素的起始位置
	position[0] = 0;
	for (int i = 1; i < n; ++i) {
		position[i] = position[i - 1] + count[i - 1];
	}
	
	// 按照转置后的顺序填充结果
	for (const auto& item : matrix) {
		int row = item.col;
		int col = item.row;
		int value = item.value;
		result.push_back({row, col, value});
		count[row]--;
		position[row]++;
	}
	
	return result;
}

void printMatrix(const vector<Triple>& matrix, int m, int n) {
	for (const auto& item : matrix) {
		cout << "Row: " << item.row << " Column: " << item.col << " Value: " << item.value << endl;
	}
}

int main() {
	// 稀疏矩阵：3行4列，包含非零元素
	vector<Triple> matrix = {{0, 0, 1}, {0, 2, 3}, {1, 1, 4}, {2, 0, 5}};
	int m = 3, n = 4;
	
	cout << "Original Sparse Matrix (in triplet form):" << endl;
	printMatrix(matrix, m, n);
	
	// 快速转置
	vector<Triple> transposed = fastTranspose(matrix, m, n);
	cout << "\nTransposed Sparse Matrix (in triplet form):" << endl;
	printMatrix(transposed, n, m);
	
	return 0;
}

