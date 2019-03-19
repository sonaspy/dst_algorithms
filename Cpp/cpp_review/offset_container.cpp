#include <stdio.h>
#include <string.h>


#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({          \
    const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
    (type *)( (char *)__mptr - offsetof(type,member) ); })

struct student
{
    char gender;
    int id;
    int age;
    char name[20];
};

int  main()
{
    struct student stu;
    struct student *pstu;
    stu.gender = '1';
    stu.id = 9527;
    stu.age = 24;
    strcpy(stu.name, "zhouxingxing");
    pstu = container_of(&stu.id, struct student, id);
    printf("gender= %c\n", pstu->gender);
    printf("age= %d\n", pstu->age);
    printf("name= %s\n", pstu->name);
}

