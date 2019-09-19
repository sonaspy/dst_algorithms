// author - sonaspy@outlook.com
// coding - utf_8

#include "../src/dsa.h"

using namespace std;
using namespace dsa;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int n, range;
    string valtype, instruction, prin;

    while (cin >> instruction && instruction[0] != 'q')
    {
        if (instruction[0] == 'b' || instruction[0] == 'r')
        {
            cin >> n >> valtype;
            rbtree<char> rbxc;
            rbtree<int> rbxi;
            if (valtype[0] == 'c')
            {
                vector<char> a(n);
                generate(a.begin(), a.end(), [&]() { return rand() % 93 + 33; });
                rbxc.build(a);
                cout << "need print out to terminal ? \n";
                cin >> prin;
                if (prin[0] == 'y')
                    rbxc.printhorizon();
            }
            else
            {
                cin >> range;
                vector<int> a(n);
                generate(a.begin(), a.end(), [&]() { return rand() % range; });
                rbxi.build(a);
                cout << "need print out to terminal ? \n";
                cin >> prin;
                if (prin[0] == 'y')
                    rbxi.printhorizon();
            }
        }
    }

    return 0;
}