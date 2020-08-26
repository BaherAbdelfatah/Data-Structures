#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> 
#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pi; 

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
	priority_queue<pi, vector<pi>, greater<pi> > pq; 
	for (long long j = 0; j < num_workers_; ++j) {
		pq.push(make_pair(0,j)); 
	}
    for (int i = 0; i < jobs_.size(); ++i) {
      long long duration = jobs_[i];
	  long long next_worker=pq.top().second;
	  long long start_time=pq.top().first;
	  pq.pop();
      assigned_workers_[i] = next_worker;
      start_times_[i] = start_time;
	  pq.push(make_pair(start_time+duration,next_worker)); 
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}