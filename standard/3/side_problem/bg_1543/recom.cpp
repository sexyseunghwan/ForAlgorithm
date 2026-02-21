#include <iostream>
#include <string>

using namespace std;


int find_voca_cnt(string target_str, string query) {

    size_t res = 0;
    size_t pos = 0;

    while(true) {
        pos = target_str.find(query, pos);
        if (pos == string::npos) break;
        res++;
        pos += query.length();
    }

    return res;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string target_str;
    string query;
    
    getline(cin, target_str);
    getline(cin, query);

    int res = find_voca_cnt(target_str, query);

    cout << res << endl;
    
    return 0;
}