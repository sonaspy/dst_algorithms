// author - sonaspy@outlook.com
// coding - utf_8

#include "../cpp/huffman.h"
using namespace dsa;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    FREQ_table mp;
    FILE *fp = fopen("./in.txt", "a+");
    char c;
    if (!fp)
    {
        cout << "Open File Failed !\n";
        exit(0);
    }
    while (!feof(fp))
    {
        c = fgetc(fp);
        cout << c << endl;
        mp[c]++;
    }
    fclose(fp);

    for (auto kv : mp)
    {
        cout << kv.first << " -> " << kv.second << endl;
    }
    ifstream fin("in.txt");

    return 0;
}