// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <unordered_map>
#define test() freopen("in", "r", stdin)

using namespace std;

typedef struct File *fptr;
struct File
{
    bool isDir;
    string f_name;
    map<string, fptr> subdir;
    vector<fptr> container;
    File(bool i, string name) : isDir(i), f_name(name) {}
};
bool cmp(const fptr a, const fptr b) { return a->isDir == b->isDir ? a->f_name < b->f_name : a->isDir > b->isDir; }

void Insert(fptr &parent, fptr sub)
{
    parent->subdir[sub->f_name] = sub;
    parent->container.push_back(sub);
}

static void ListDir(fptr root, int depth)
{
    if (root == nullptr || root->f_name.empty())
        return;
    for (int i = 0; i < 2 * depth; i++)
        printf(" ");
    cout << root->f_name << endl;
    sort(root->container.begin(), root->container.end(), cmp);
    for (auto &i : root->container)
    {
        ListDir(i, depth + 1);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    int n;
    cin >> n;
    vector<string> ss(n);
    unordered_map<string, int> mp;
    fptr root = new File(true, "root");
    mp["root"] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> ss[i];
        fptr pre = root;
        int j, c1 = 0, c2;
        string s1;
        for (j = 0; j < ss[i].size(); j++)
        {
            if (ss[i][j] == '\\')
            {
                c2 = j;
                s1 = ss[i].substr(c1, c2 - c1);
                c1 = j + 1;
                if (!mp.count(s1))
                {
                    fptr tmp = new File(true, s1);
                    Insert(pre, tmp);
                    mp[s1] = 1;
                    pre = tmp;
                }
                else
                    pre = pre->subdir[s1];
            }
        }
        c2 = ss[i].size();
        s1 = ss[i].substr(c1, c2 - c1);
        Insert(pre, new File(false, s1));
    }
    ListDir(root, 0);
    return 0;
}