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
};

int main()
{
    int gender_offset, id_offset, age_offset, name_offset;
    gender_offset = offsetof(struct student, gender);
    id_offset = offsetof(struct student, id);
    age_offset = offsetof(struct student, age);
    name_offset = offsetof(struct student, name);
    printf("gender_offset = %d\n", gender_offset);
    printf("id_offset = %d\n", id_offset);
    printf("age_offset = %d\n", age_offset);
    printf("name_offset = %d\n", name_offset);
}