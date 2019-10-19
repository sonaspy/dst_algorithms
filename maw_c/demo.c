// author - newguo@sonaspy.cn
// coding - utf_8

#include <stdio.h>

#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)

struct student
{
    char gender;
    int id;
    int age;
    char name[20];
    struct node
    {
        int i;
    } n;
};

int main()
{

    union {
        int i[2];
        int k;
        int c;
    } t, *s = &t;
    char str[] = {'F', 'O', 'R', 'T', 'R', 'A', 'N', 0};

    s->i[0] = 10;
    s->i[1] = 20;
    s->k = 30;
    printf("%d\n", s->k);
    printf("%d\n", s->i[0]);
    printf("%d\n", s->c);
    char ccc = 127 + 1;
    printf("%d", ccc);
}