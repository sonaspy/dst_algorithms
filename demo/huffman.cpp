// author - sonaspy@outlook.com
// coding - utf_8

#include "../cpp/huffman.h"
using namespace dsa;
#include <fstream>
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    FREQ_table mp;
    ifstream fin("./in.txt");
    char c;
    if (fin.bad())
    {
        cout << "Open File Failed !\n";
        exit(0);
    }
    while (fin >> c)
        mp[c]++;
    fin.close();
    for (auto kv : mp)
    {
        cout << kv.first << " -> " << kv.second << endl;
    }

    return 0;
}