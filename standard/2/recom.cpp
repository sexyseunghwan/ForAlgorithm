#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// vector<int> left_rotate(vector<int> a, int d) 
// {
//     int n = a.size();
//     if (n == 0) return;

//     d %= n;

//     //reverse(a.begin(), a.begin() + d);


// }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);  

    vector<int> vec = {1,3,5,7,9};
    //vector<int> res = left_rotate(vec, 1);

    reverse(vec.begin(), vec.begin() + 3);
    reverse(vec.begin() + 3, vec.end());
    reverse(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }

    return 0;
}