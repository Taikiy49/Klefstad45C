#include <iostream>
using namespace std;

constexpr int N_CHARS = 26;
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char alphabet_array[N_CHARS];
int int_index;
int value;
string input;

void char_to_index(){
  for (int i = 0; i < N_CHARS; ++i){
    alphabet_array[i] = alphabet[i];
  }
}

int find_index(char c){
  for (int i = 0; i < N_CHARS; ++i){
    if (c == alphabet_array[i]){
      int_index = i;
	  }
	}
  return int_index;
  }

int main(){
  char_to_index();
  cin >> input;
  for (char c : input){
    value = find_index(c);
   	  cout << value << endl;
  return 0;
  }
}

