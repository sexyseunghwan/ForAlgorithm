#include <iostream>
#include <string>

using namespace std;


int find_voca_by_query(const string& str, const string& query) {

    size_t res = 0;
    size_t pos = 0;
    size_t query_len = query.length();

    while(1) {
        pos = str.find(query, pos);
        if (pos == string::npos) 
            break;
        pos += query_len;
        res++;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    string input;
    string query;

    getline(cin, input);
    getline(cin, query);

    int res = find_voca_by_query(input, query);
    
    cout << res << endl;
    
    return 0;
}