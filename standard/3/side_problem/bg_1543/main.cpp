#include <iostream>
#include <string>

using namespace std;

int find_voca_cnt(string target_str, string query) 
{
    int res_cnt = 0;
    int query_size = query.length();
    int target_str_len = target_str.length();

    for (int i = 0; i < target_str_len; i++) {
        if (target_str_len >= i + query_size - 1) {
            string sub_str = target_str.substr(i,query_size);
            if (sub_str == query) {
                res_cnt++;
                i += sub_str.length() - 1;
            }
        }
        
    }

    return res_cnt;
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

    cout << res;
    
    return 0;
}