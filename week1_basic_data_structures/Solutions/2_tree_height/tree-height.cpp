#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif
using namespace std;

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};
vector<int> heights_calculated_prev(100000,-1);
int Height(Node treeNode)
{
	if(heights_calculated_prev[treeNode.key]!=-1)
		return heights_calculated_prev[treeNode.key];
	if(treeNode.children.empty())
		return 1;
	int n=treeNode.children.size();
	int max=0;
	for(int i=0;i<n;i++)
	{
		int temp=Height(*(treeNode.children[i]));
		if(temp>max)
			max=temp;
	}

	heights_calculated_prev[treeNode.key]=1 + max;
	return heights_calculated_prev[treeNode.key];
}

int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;

  std::vector<Node> nodes;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);
    nodes[child_index].key = child_index;
  }

  // Replace this code with a faster implementation
	int parentIndex=0;
    for (int i = 0; i < n; i++) {
		if(nodes[i].parent==NULL)
		{
		  parentIndex=i;
		  break;
		}
	}
	cout<<Height(nodes[parentIndex])<<endl;
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