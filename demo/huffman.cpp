// author - sonaspy@outlook.com
// coding - utf_8

#include "../src/dsa.h"
using namespace dsa;
#include <fstream>
vector<vector<char>> __display_buffer;
void __print(binode<char> *opnv, int root_x, int root_y, int interval)
{
    if (!opnv)
        return;
    int left_child = root_y - interval, right_child = root_y + interval;
    __display_buffer[root_x][root_y] = opnv->val;
    if (opnv->lc)
        __display_buffer[root_x + 1][root_y - (interval + 1) / 2] = '/';
    if (opnv->rc)
        __display_buffer[root_x + 1][root_y + (interval + 1) / 2] = '\\';
    __print(opnv->lc, root_x + 2, left_child, (interval >> 1));
    __print(opnv->rc, root_x + 2, right_child, (interval >> 1));
}
void printhfm(binode<char> *_root, ofstream &of)
{
    of << "🌲  HUFFMAN TREE  🌲\n";
    __display_buffer = vector<vector<char>>(40, vector<char>(MAXCOL, ' '));
    __print(_root, 0, pow(2, _root->height) - 1, pow(2, _root->height - 1));
    int n = _root->height * 2 + 1, i, j, breadth = pow(2, _root->height + 1) + 1;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < breadth; ++j)
            of << __display_buffer[i][j];
        of << endl;
    }
    of << "🌲  HUFFMAN TREE  🌲\n";
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string infname("in.txt"), smode, outfname("hfm_result.txt"), cipher("hfm_raw_code.txt");
    FREQ_table mp;
    PFCvec pfvec;
    int mode = 0;
    if (argc > 3 || argc < 2)
    {
        cout << " Usage: huffman -<mode>(option, default is 0, else is 1) <inputfilename> \n";
        exit(0);
    }
    else if (argc == 3)
    {
        smode = argv[1];
        if (smode != "0" || smode != "1")
            mode = 2;
        else
            mode = smode[1] - '0';
        infname = argv[2];
    }
    else
        infname = argv[1];

    ifstream fin(infname);
    ofstream fout(outfname);
    ofstream fout2(cipher);
    char c;
    if (fin.fail() || fin.bad() || fout.fail() || fout.bad() || fout2.bad() || fout2.fail())
    {
        cout << "File Stream is Failed !\n";
        exit(0);
    }
    while (fin >> c)
        mp[c]++;
    fin.close();
    if (mp.size() == 1)
    {
        cout << "Too few character !\n";
        exit(0);
    }
    huffman hfm(mp);
    hfm.generate(pfvec, mode);
    cout << "The Total optimal WPL is -> " << hfm.wpl() << endl;
    fout << "The Total optimal WPL is -> " << hfm.wpl() << endl;
    sort(pfvec.begin(), pfvec.end());

    for (auto &kv : pfvec)
    {
        cout << kv.node->val << endl
             << "freq is -> " << kv.node->freq << endl
             << "code is -> \" " << kv.pattern << " \"" << endl;
        fout << kv.node->val << endl
             << "freq is -> " << kv.node->freq << endl
             << "code is -> \" " << kv.pattern << " \"" << endl;
    }
    printhfm(hfm.root(), fout);
    fout.close();
    fin.open(infname);
    while (fin >> c)
    {
        fout2 << hfm.pfmp[c] << " ";
    }
    fout2.close();
    fin.close();
    return 0;
}