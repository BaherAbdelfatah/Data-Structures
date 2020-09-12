#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using namespace std;

class TreeOrders {
public:
	int n;
	vector <int> key;
	vector <int> left;
	vector <int> right;
	int left_size,right_size;

  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

  void in_order(int node) {
	if(key.size()-1<node)
		return;
	
	in_order(left[node]);
	cout<<key[node]<<" ";
	in_order(right[node]);
  }

  void pre_order(int node) {
	if(key.size()-1<node)
		return;

	cout<<key[node]<<" ";
	pre_order(left[node]);	
	pre_order(right[node]);
  }

  void post_order(int node) {
	if(key.size()-1<node)
		return;

	post_order(left[node]);
	post_order(right[node]);
	cout<<key[node]<<" ";
  }
};

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  t.left_size=0,t.right_size=0;
for(int i=0;i<t.left.size();i++)
{
	if(t.left[i]!=-1)
		t.left_size++;
	else
		break;
}
for(int i=0;i<t.right.size();i++)
{
	if(t.right[i]!=-1)
		t.right_size++;
	else
		break;
}
  t.in_order(0);
  cout<<endl;
  t.pre_order(0);
  cout<<endl;
  t.post_order(0);
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}