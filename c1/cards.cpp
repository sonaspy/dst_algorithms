// author - sonaspy@zju.edu.cn
// coding - utf_8

#include <bits/stdc++.h>

using namespace std;

enum class suit : short { SPADE, HEART, DIAMOND, CLUB };

class pips {
   public:
    pips(int val) : v(val) { assert(v > 0 && v < 14); }
    friend ostream &operator<<(ostream &out, const pips &p);
    int get_pips() { return v; }

   private:
    int v;
};

class card {
   public:
    card() : s(suit::SPADE), v(1) {}
    card(suit s, pips v) : s(s), v(v) {}
    friend ostream &operator<<(ostream &out, const card &c);

    suit get_suit() { return s; }
    pips get_pips() { return v; }

   private:
    suit s;
    pips v;
};

ostream &operator<<(ostream &out, const pips &p) {
    cout << p.v;
    return out;
}

ostream &operator<<(ostream &out, const suit &s) {
    cout << s;
    return out;
}

ostream &operator<<(ostream &out, const card &c) {
    cout << c.v << c.s;
    return out;
}

void init_deck(vector<card> &d) {
    for (int i = 1; i < 14; ++i) {
        d[i - 1] = card(suit::SPADE, i);
        d[i + 12] = card(suit::HEART, i);
        d[i + 25] = card(suit::DIAMOND, i);
        d[i + 38] = card(suit::CLUB, i);
    }
}

void print(vector<card> &deck) {
    for (auto c : deck) cout << c;
    cout << endl;
}

bool is_flush(vector<card> &hand) {
    suit s = hand[0].get_suit();
    for (auto p = hand.begin() + 1; p != hand.end(); ++p)
        if (s != p->get_suit()) return false;
    return true;
}

bool is_straight(vector<card> &hand) {
    int pips_v[5], i = 0;
    for (auto &c : hand) pips_v[i++] = c.get_pips().get_pips();
    sort(pips_v, pips_v + 5);
    if (*pips_v != 1)
        return (pips_v[0] == pips_v[1] - 1 && pips_v[0] == pips_v[2] - 2 &&
                pips_v[0] == pips_v[3] - 3 && pips_v[0] == pips_v[4] - 4);
    else
        return (pips_v[0] == pips_v[1] - 1 && pips_v[0] == pips_v[2] - 2 &&
                pips_v[0] == pips_v[3] - 3 && pips_v[0] == pips_v[4] - 4) ||
               (pips_v[0] == 1 && pips_v[1] == 10 && pips_v[2] == 11 &&
                pips_v[3] == 12 && pips_v[4] == 13);
}

int main(int argc, char const *argv[]) {
    /* code */
    vector<card> deck(52);
    srand(time(0));
    init_deck(deck);
    int how_many = 1000000;
    int flush_count = 0;
    int str_count = 0;
    int strflush_count = 0;
    bool isflush, isstr;
    for (int loop = 0; loop < how_many; ++loop) {
        isflush = isstr = false;
        random_shuffle(deck.begin(), deck.end());
        vector<card> hand(5);
        int i = 0;
        for (auto p = deck.begin(); i < 5; ++p) hand[i++] = *p;
        if (is_flush(hand)) {
            isflush = true;
            flush_count++;
        }
        if (is_straight(hand)) {
            isstr = true;
            str_count++;
        }
        if (isstr && isflush) strflush_count++;
    }

    cout << "Flushes " << flush_count << " out of " << how_many << endl;
    cout << "Straights " << str_count << " out of " << how_many << endl;
    cout << "Straights Flushes " << strflush_count << " out of " << how_many
         << endl;

    return 0;
}
