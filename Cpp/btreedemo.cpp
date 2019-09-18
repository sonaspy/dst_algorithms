// author - sonaspy@outlook.com
// coding - utf_8

#define SIZE 1000
#include "dsa.h"
#define test() freopen("in", "r", stdin)

using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int b[SIZE];
    generate(b, b + SIZE, [&]() { return rand() % 10000; });
    iota(b, b + SIZE, 0);
    vector<int> a(b, b + SIZE);
    btree<int> bt(4);
    bt.build(a);
    clock_t startTime, endTime;
    //bt.printTree();
    startTime = clock();
    cout << bt.size() << endl;
    cout << bt.root()->key.size() << endl;
    cout << bt.root()->child.size() << endl;
    string s;
    int key1, key2, c;
    char cc;
    while (cin >> s && s != "q")
    {
        stringstream ss(s);
        ss >> key1 >> cc >> key2;
        c = 0;
        cout << key1 << " " << key2 << endl;
        for (int i = key1; i <= key2; i++)
        {
            if (bt.erase(i))
                c++;
        }
        cout << c << endl;
    }

    endTime = clock();
    cout << "The run time is: " << (double)(endTime - startTime) / 1000 << "ms" << endl;
    return 0;
}