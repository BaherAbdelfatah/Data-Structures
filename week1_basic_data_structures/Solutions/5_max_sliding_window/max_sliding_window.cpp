#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;

class StackWithMax {
    vector<int> stack;
	vector<int> max_index;
  public:

    void push(int value) {
		if(stack.empty())
		{
			max_index.push_back(0);
		}
		else if(value>=stack[max_index.back()])
		{
			max_index.push_back(stack.size());
		}
        stack.push_back(value);
    }

    void pop() {
        assert(stack.size());
		if(stack.size()-1==max_index.back())
		{
			max_index.pop_back();
		}
        stack.pop_back();
    }

    int Max() const {
        if(stack.size()==0)
			return -1;
		return stack[max_index.back()];
    }

	bool empty() {
		return stack.empty()==true;
	}

	int top() {
		return stack.back();
    }

	int size() const {
        return(stack.size());
    }
};

struct Queue { 
    StackWithMax s1, s2;  
  
    // Enqueue an item to the queue 
    void enQueue(int x) 
    { 
        // Push item into the first stack 
        s1.push(x); 
    } 
  
    // Dequeue an item from the queue 
     int deQueue() 
    { 
        // if both stacks are empty 
        if (s1.empty() && s2.empty()) { 
            cout << "Q is empty"; 
            exit(0); 
        } 
  
        // if s2 is empty, move 
        // elements from s1 
        if (s2.empty()) { 
            while (!s1.empty()) { 
                s2.push(s1.top()); 
                s1.pop(); 
            } 
        } 
  
        // return the top item from s2 
        int x = s2.top(); 
        s2.pop(); 
        return x; 
    } 

	int Max() const {
		return max(s1.Max(),s2.Max());
    }
	int Size() const {
		return s1.size();
    }
};
void max_sliding_window_naive(vector<int> const & A, int w) {
	Queue windows;
	for(int i=0;i<A.size();i++)
	{
		if(i<w-1)
			windows.enQueue(A[i]);
		else
		{		
			windows.enQueue(A[i]);
			cout<<windows.Max()<<" ";			
			windows.deQueue();
		}
	}
	return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}