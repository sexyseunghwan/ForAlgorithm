#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string trim(const string& str) {

    if (str.empty()) return str;
    
    int start = 0;
    int end = str.length() - 1;

    while (start <= end && str[start] == ' ') {
        start++;
    }

    while(end >= start && str[end] == ' ') {
        end--;
    }

    return str.substr(start, end + 1 - start);

}

int find_voca_cnt(string str)
{
    string trim_str = trim(str);   
    
    if (trim_str.empty()) 
        return 0;
    else
        return count(trim_str.begin(), trim_str.end(), ' ') + 1;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string str;

    getline(cin, str);

    int res = find_voca_cnt(str);
    
    cout << res << endl;

    return 0;
}