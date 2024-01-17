#include <iostream>
#include <string>
using namespace std;

constexpr int N_CHARS = 26;
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int alphabet_count[N_CHARS] = {0};
string s;

int char_to_index(char chr) {
    chr = toupper(chr);
    return chr - 'A';
}

char index_to_char(int i) { 
    return static_cast<char>('A' + i);
}

void count(string str, int counts[]) {
    for (char c : str) {
        int index = char_to_index(c);
        if (index >= 0 && index < N_CHARS) {
            counts[index] += index + 65;
        }
    }
}

void print_counts(int counts[], int len) {
    for (int i = 0; i < len; ++i){
        cout << alphabet[i] << " " << counts[i] << endl;
    }
}

int main() {
    cin >> s;
    count(s, alphabet_count);
    print_counts(alphabet_count, N_CHARS);
    return 0;
}
