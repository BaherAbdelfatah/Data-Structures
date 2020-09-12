#include <algorithm>
#include <iostream>
#include <vector>
#define MY_INT64_MIN        (-9223372036854775807 - 1)
#define MY_INT64_MAX          9223372036854775807
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
bool isBSTUtil(const vector<Node>& tree, const int &node_idx, long long min, long long max)
{

	/* an empty tree is BST */
	if (node_idx == -1)
		return true;

	/* false if this node violates the min/max constraint */
	if (tree[node_idx].key < min || tree[node_idx].key >= max)
		return false;

	/* otherwise check the subtrees recursively,
	tightening the min or max constraint */
	return
		isBSTUtil(tree, tree[node_idx].left, min, (tree[node_idx].key)) &&  // Allow only distinct values
		isBSTUtil(tree, tree[node_idx].right, (tree[node_idx].key), max);  // Allow only distinct values
}

bool IsBinarySearchTree(const vector<Node>& tree) {
	// Implement correct algorithm here
	/* an empty tree is BST */
	if (tree.size() == 0)
		return  true;
	return isBSTUtil(tree, 0, MY_INT64_MIN, MY_INT64_MAX);
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
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}