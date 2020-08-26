#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
	if(data_.size()==2)
	{
		if(data_[0]>data_[1])
		{
			swap(data_[0],data_[1]);
			swaps_.push_back(make_pair(0, 1));
		}
		return;
	}
    for (int j = data_.size()/2; j >=0; --j)
      {
		  unsigned int size=data_.size();
		  unsigned int max_index;
		  int i=j;
		  while((2*i+1)<size)
		  {
			  max_index=i;
			  unsigned long long l=2*i+1;
			  if ((l<size)&&(data_[l] < data_[max_index])) {
				max_index=l;
			  }
			  unsigned long long r=2*i+2;
			  if ((r<size)&&(data_[r] < data_[max_index])) {
				  max_index=r;
			  }
			  if(i!=max_index)
			  {
					swap(data_[i],data_[max_index]);
					swaps_.push_back(make_pair(i, max_index));
					i=max_index;
			  }
			  else
				  break;
		  }
		  
      }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}