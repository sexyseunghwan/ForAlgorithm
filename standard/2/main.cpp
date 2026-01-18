#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> left_rotate(vector<int> a, int d) 
{
    int vec_size = a.size();
    vector<int> res(vec_size, 0);
    
    int new_d = d % vec_size;

    for (int i = 0; i < vec_size; i++) {
        int new_idx = i - new_d;
        if (new_idx < 0)
            new_idx += vec_size;
        res[new_idx] = a[i];
    }

    return res;
}   


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);    

    vector<int> vec = {1,3,5,7,9};
    vector<int> res = left_rotate(vec, 1);

    

    return 0;
}