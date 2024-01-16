constexpr int STK_MAX = 1000;
class Stack
{
	int _top;
	char buf[STK_MAX];
public:
	Stack();

	void push(char c){
		buf = buf[c];
		}

	char pop(){
		return _top;
		}

	char top(){
		return _top;
		}
	bool isEmpty(){
		if not (buf[STK_MAX]){
			return true;
			}
		}
	bool isFull(){
		if (buf[STK_MAX]){
			return true;
			}
		}
};


void push_all(Stack & stk, string line);
void pop_all(Stack & stk);

