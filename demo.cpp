// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
using namespace std;
unordered_set<char> st;
#define ISOP(c) (st.count(c))
typedef struct TreeNode *tptr;
struct TreeNode
{
    tptr left = NULL, right = NULL;
    char data;
    TreeNode(char c) : data(c) {}
};

void post(tptr root){
    if(!root)return;
    if(root->left) post(root->left);
    if(root->right) post(root->right);
    cout << root->data << " ";
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    string s;
    st.insert('*'), st.insert('+');
    cin >> s;
    stack<tptr> stack_;
    for (auto &i : s)
    {
        tptr tmp = new TreeNode(i);
        if (!ISOP(i))
        {
            stack_.push(tmp);
        }
        else
        {
            tptr t1, t2, t3 = new TreeNode(i);
            t1 = stack_.top(), stack_.pop(), t2 = stack_.top(), stack_.pop();
            t3->left = t2, t3->right = t1;
            stack_.push(t3);
        }
    }
    post(stack_.top());

    return 0;
}