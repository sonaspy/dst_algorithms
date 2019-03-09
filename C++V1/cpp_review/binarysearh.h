// author - newguo@sonaspy.cn
// coding - utf_8


#ifndef binarySearch_
#define binarySearch_

template <class T>
int binarySearch(T list[], int n, const T & x)
{
    int left = 0;
    int right = n - 1;
    int mid;
    while(left <= right)
        {
            mid = (left + right) /2;
            if(x > list[mid])
                left = mid + 1;
            if(x < list[mid])
                right = mid - 1;
            else
                return mid;
        }
    return -1;
}

#endif
