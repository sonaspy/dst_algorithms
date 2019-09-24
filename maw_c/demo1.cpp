// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<stack>
#include<queue>
#include<numeric>
#include<cmath>

#define test() freopen("in","r",stdin)

using namespace std;

bool isPrime(int num){
    if(num == 2)return true;
    if(num % 2 == 0 || num < 2) return false;
    for(int i = 3; i <= sqrt(num); i += 2){
        if(num % i == 0)return false;
    }
    return true;
}


int main(int argc, char const *argv[])
{
    /* code */
    //test();

    return 0;
}