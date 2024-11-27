#include <iostream>
#include <string>
using namespace std;

// BF 算法实现
int BF(string text, string pattern) {
	int n = text.length();
	int m = pattern.length();
	
	// 如果模式串长大于文本串，直接返回-1
	if (m > n) return -1;
	
	// 按照暴力算法匹配
	for (int i = 0; i <= n - m; ++i) {
		int j = 0;
		while (j < m && text[i + j] == pattern[j]) {
			++j;
		}
		if (j == m) {
			return i; // 找到匹配的位置，返回索引
		}
	}
	return -1; // 未找到匹配
}

int main() {
	string text = "ababcabcacbab";
	string pattern = "abcac";
	
	int result = BF(text, pattern);
	
	if (result != -1) {
		cout << "Pattern found at index: " << result << endl;
	} else {
		cout << "Pattern not found!" << endl;
	}
	
	return 0;
}

