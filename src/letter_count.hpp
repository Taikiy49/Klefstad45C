#include <iostream>
using namespace std;
#include <cctype>

constexpr int N_CHARS = 26;

int char_to_index(char ch){
	if (islower(ch)) {
		ch = toupper(ch);
	}
	return ch - 'A';
}

char index_to_char(int i){
	return 'A' + i;
}

void count(string s, int counts[]){
	for (char ch : s) {
		if (isalpha(ch)){
			int index = char_to_index(ch);
			counts[index]++;
			}
	}
}

void print_counts(int counts[], int len){
	for (int i = 0; i < len; ++i){
		cout << index_to_char(i) << ' ' << counts[i] << endl;
	}
}
