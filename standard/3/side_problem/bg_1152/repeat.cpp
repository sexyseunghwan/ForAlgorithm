#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string trim(const string& str) {

    if (str.empty()) 
        return str;

    int start_idx = 0;
    int end_idx = str.length() - 1;
    
    while(str[start_idx] == ' ' && start_idx <= end_idx) {
        start_idx++;
    }

    while(str[end_idx] == ' ' && end_idx >= start_idx) {
        end_idx--;
    }

    return str.substr(start_idx, end_idx - start_idx + 1);
}

int find_voca_cnt(const string& str) {
    string trim_str = trim(str);
    return trim_str.empty() == true ? 0 : (count(trim_str.begin(), trim_str.end(), ' ') + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string input;
    getline(cin, input);

    int res = find_voca_cnt(input);
    cout << res << endl;
}