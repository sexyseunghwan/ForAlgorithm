#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> matchingStrings(vector<string> stringList, vector<string> queries)
{
    vector<int> res;

    for (string query : queries) {
        int equal_cnt = 0;
        
        for (string str : stringList) {
            if (query == str) {
                equal_cnt++;
            } 
        }
        
        res.push_back(equal_cnt);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N,M;
    
    cin >> N;

    vector<string> stringList(N);

    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        
        stringList[i] = input;
    }

    cin >> M;

    vector<string> queries(M);

    for (int i = 0; i < M; i++) {
        string input;
        cin >> input;

        queries[i] = input;
    }

    vector<int> result_list = matchingStrings(stringList, queries);

    for (int res : result_list) {
        cout << res << "\n";
    }

    return 0;
}