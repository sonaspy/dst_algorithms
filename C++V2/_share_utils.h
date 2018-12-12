

template <class T>
struct CheckOrder
{
    T pred;
    int &u;
    CheckOrder(int &unsorted, T &first) : pred(first), u(unsorted) {}
    virtual void operator()(T &e)
    {
        if (pred > e)
            u++;
        pred = e;
    }
};

template <class T>
void checkOrder(List<T> &L)
{
    int unsorted = 0;
    L.traverse(CheckOrder<T>(unsorted, L.first()->data));
    if (0 < unsorted)
        printf("Unsorted with %d adjacent disordered pair(s)\n", unsorted);
    else
        printf("Sorted\n");
    printf("DISORDERED = %d\n", L.disordered());
}

template <class T>
void checkOrder(Vector<T> &V)
{
    int unsorted = 0;
    V.traverse(CheckOrder<T>(unsorted, V[0]));
    if (0 < unsorted)
        printf("Unsorted with %d adjacent disordered pair(s)\n", unsorted);
    else
        printf("Sorted\n");
}

template <class T>
static bool lt(T *a, T *b) { return lt(*a, *b); }
template <class T>
static bool lt(T &a, T &b) { return a < b; }
template <class T>
static bool eq(T *a, T *b) { return eq(*a, *b); }
template <class T>
static bool eq(T &a, T &b) { return a == b; }

template <class T>
struct Crc
{
    T &c;
    Crc(T &crc) : c(crc) {}
    virtual void operator()(T &e) { c += e; }
};

template <class T>
void crc(List<T> &L)
{
    T crc = 0;
    L.traverse(Crc<T>(crc));
    printf("CRC =");
    print(crc);
    printf("\n");
}

template <class T>
void crc(Vector<T> &V)
{
    T crc = 0;
    V.traverse(Crc<T>(crc));
    printf("CRC =");
    print(crc);
    printf("\n");
}

template <class T>
struct Decrease
{
    virtual void operator()(T &e) { e--; }
};

template <class T>
void decrease(List<T> &L)
{
    L.traverse(Decrease<T>());
}

template <class T>
void decrease(Vector<T> &V)
{
    V.traverse(Decrease<T>());
}

template <class T>
struct Double
{
    virtual void operator()(T &e) { e *= 2; }
};

template <class T>
void double(Vector<T> &V)
{
    V.traverse(Double<T>());
}

template <class T>
struct Hailstone
{
    virtual void operator()(T &e)
    {
        int step = 0;
        while (1 != e)
        {
            (e % 2) ? e = 3 *e + 1 : e /= 2;
            step++;
        }
        e = step;
    }
};

template <class T>
struct Half
{
    virtual void operator()(T &e) { e /= 2; }
};

template <class T>
void half(List<T> &L)
{
    L.traverse(Half<T>());
}

template <class T>
struct Increase
{
    virtual void operator()(T &e) { e++; }
};

/*DSA*/

template <class T>
void increase(List<T> &L)
{
    L.traverse(Increase<T>());
}

template <class T>
void increase(Vector<T> &V)
{
    V.traverse(Increase<T>());
}

static int dice(int range)
{
    return rand() % range;
}
static int dice(int lo, int hi) { return lo + rand() % (hi - lo); }
static float dice(float range) { return rand() % (1000 * (int)range) / (float)1000.; }
static double dice(double range) { return rand() % (1000 * (int)range) / (double)1000.; }
static char dice(char range) { return (char)(32 + rand() % 96); }

template <class T>
struct Cleaner
{
    static void clean(T x)
    {
#ifdef _DEBUG
        static int n = 0;
        if (7 > strlen(typeid(T).name()))
        {
            printf("\t<%s>[%d]=", typeid(T).name(), ++n);
            print(x);
            printf(" purged\n");
        }
#endif
    }
};

template <class T>
struct Cleaner<T>
{
    static void clean(T *x)
    {
        if (x)
        {
            delete x;
        }
#ifdef _DEBUG
        static int n = 0;
        printf("\t<%s>[%d] released\n", typeid(T *).name(), ++n);
#endif
    }
};

template <class T>
void release(T x) { Cleaner<T>::clean(x); }

#define _CRT_SECURE_NO_WARNINGS
#if defined(DSA_DEBUG)
#define DSA(x) \
    {          \
        x      \
    }
#else
#define DSA(x)
#endif