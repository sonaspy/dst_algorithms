#ifndef PREDEFINED_H
#define PREDEFINED_H

#include <string.h>

#define __BEGIN_NAMESPACE_BPT namespace bpt {
#define __END_NAMESPACE_BPT }

__BEGIN_NAMESPACE_BPT

/* predefined B+ info */
#define BP_ORDER 20
#define SIZEOFKEY 16

typedef int value_type;
struct key_type {
    char _key[SIZEOFKEY];
    int _key_len;

    key_type(const char *str = "") {
        bzero(_key, sizeof(_key));
        strcpy(_key, str);
        _key_len = strlen(_key);
    }

    operator bool() const { return strcmp(_key, ""); }
};

inline int __key_compare(const key_type &a, const key_type &b) {
    int x = a._key_len - b._key_len;
    return x == 0 ? strcmp(a._key, b._key) : x;
}

#define OPERATOR_KEYCMP(__typename)                                            \
    bool operator<(const key_type &l, const __typename &r) {                   \
        return __key_compare(l, r.key) < 0;                                    \
    }                                                                          \
    bool operator<(const __typename &l, const key_type &r) {                   \
        return __key_compare(l.key, r) < 0;                                    \
    }                                                                          \
    bool operator==(const key_type &l, const __typename &r) {                  \
        return __key_compare(l, r.key) == 0;                                   \
    }                                                                          \
    bool operator==(const __typename &l, const key_type &r) {                  \
        return __key_compare(l.key, r) == 0;                                   \
    }

__END_NAMESPACE_BPT

#endif /* end of PREDEFINED_H */
