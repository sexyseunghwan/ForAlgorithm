#include <iostream>
#include <unordered_map>


using namespace std;

struct Node {
    char left;
    char right;
};

unordered_map<char, Node> tree;

void pre_order(char cur) {
    if (cur == '.') return;

    cout << cur << " ";
    pre_order(tree[cur].left);
    pre_order(tree[cur].right);
}

void in_order(char cur) {
    if (cur == '.') return;

    in_order(tree[cur].left);
    cout << cur << " ";
    in_order(tree[cur].right);
}

void post_order(char cur) {
    if (cur == '.') return;

    post_order(tree[cur].left);
    post_order(tree[cur].right);
    cout << cur << " ";
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        char parent, left, right;
        cin >> parent >> left >> right;
        tree[parent] = {left, right};
    }

    cout << "preOrder: "; pre_order('A'); cout << endl;
    cout << "inOrder: "; in_order('A'); cout << endl;
    cout << "postOrder: "; post_order('A'); cout << endl;

    return 0;
}