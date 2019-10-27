#ifndef PREDEFINED_H
#define PREDEFINED_H

#include <string.h>

namespace bpt {

/* predefined B+ info */
#define BP_ORDER 4

/* key/value type */
typedef int value_type;
struct key_type {
    char _key[16];

    key_type(const char *str = "") {
        bzero(_key, sizeof(_key));
        strcpy(_key, str);
    }

    operator bool() const { return strcmp(_key, ""); }
};

inline int __key_compare(const key_type &l, const key_type &r) {
    return strcmp(l._key, r._key);
}

#define OPERATOR_KEYCMP(type)                                                  \
    bool operator<(const key_type &l, const type &r) {                      \
        return __key_compare(l, r.key) < 0;                                           \
    }                                                                          \
    bool operator<(const type &l, const key_type &r) {                      \
        return __key_compare(l.key, r) < 0;                                           \
    }                                                                          \
    bool operator==(const key_type &l, const type &r) {                     \
        return __key_compare(l, r.key) == 0;                                          \
    }                                                                          \
    bool operator==(const type &l, const key_type &r) {                     \
        return __key_compare(l.key, r) == 0;                                          \
    }

} // namespace bpt

#endif /* end of PREDEFINED_H */
