#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
	static string contacts[10000000];
	for(int i=0;i<10000000;i++)
	{
		contacts[i]="not found";
	}
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
				contacts[queries[i].number]=queries[i].name;
        } else if (queries[i].type == "del") {
         if(contacts[queries[i].number]!="not found")
			 contacts[queries[i].number]="not found";
        } else {
            result.push_back(contacts[queries[i].number]);
        }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}