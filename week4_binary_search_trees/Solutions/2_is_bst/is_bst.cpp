#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  long long key;
  long long left;
  long long right;

  Node() : key(0), left(-1), right(-1) {}
  Node(long long key_, long long left_, long long right_) : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTree(const vector<Node>& tree,long long node) {
  // Implement correct algorithm here
	if(tree.size()==0)
		return true;
	if(tree[node].left==-1&&tree[node].right==-1)
		return true;
	else if(tree[node].left==-1)
	{
		if(tree[node].key>tree[tree[node].right].key)
			return false;
		if(tree[tree[node].right].left!=-1&&tree[tree[tree[node].right].left].key<tree[node].key)
			return false;
		return IsBinarySearchTree(tree,tree[node].right);
	}
	else if(tree[node].right==-1)
	{
		if(tree[node].key<tree[tree[node].left].key)
			return false;
		if(tree[tree[node].left].right!=-1&&tree[tree[tree[node].left].right].key>tree[node].key)
			return false;
		return IsBinarySearchTree(tree,tree[node].left);
	}
	else 
	{
		if(tree[node].key>tree[tree[node].left].key&&tree[node].key<tree[tree[node].right].key)
		{
			if(tree[tree[node].right].left!=-1&&tree[tree[tree[node].right].left].key<tree[node].key)
				return false;
			if(tree[tree[node].left].right!=-1&&tree[tree[tree[node].left].right].key>tree[node].key)
				return false;
			return IsBinarySearchTree(tree,tree[node].left)&&IsBinarySearchTree(tree,tree[node].right);
		}
		else
			return false;
	}
	return true;
}

int main() {
  long long nodes;
  cin >> nodes;
  vector<Node> tree;
  for (long long i = 0; i < nodes; ++i) {
    long long key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree,0)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}