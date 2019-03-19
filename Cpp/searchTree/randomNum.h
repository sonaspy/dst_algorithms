#include<cstdlib>
#include<ctime>

int RAND(int x)
{
    srand((int)time(0));
    return rand() % (x+1);
}
