#include<iostream>
#include<stack>

char* remove_spaces(char *s)
{
    char *p = s, *q = s;
    while(true)
        {
            while(isspace(*q))
                q++;
            if(*q == '\0')
                {
                    *p = '\0';
                    return s;
                }
            *p++ = *q++;
        }
}

void append_(char* & rpn, float opnd)
{
    int n = strlen(rpn);
    char buf[64];
    if(opnd != (float)(int)opnd)
        sprintf(buf, "%.2f",opnd);
    else
        sprintf(buf, "%d", (int)opnd);
    rpn = (char*)realloc(rpn, sizeof(char*)*(n+strlen(buf)+1));
    strcat(rpn, buf);
}

void append(char* & rpn, char optr)
{
    int n = strlen(rpn);
    rpn = (char *)realloc(rpn, sizeof(char *) * (n + 3));
    sprintf(rpn+n, "%c",optr);
}

void readNumber(char* &p, stack<float> stk)
{
    stk.push((float)(*p - '0'));
    float var;
    while (isdigit(*(++p)))
        {
            var = stk.top()*10 +(*p) - '0';
            stk.pop();
            stk.push(var);
        }
    if(*p != '.') return;
    float fraction = 1;
    while (isdigit(*(++p)))
        {
            var = stk.top() + ((*p) -'0')*(fraction /= 10) ;
            stk.pop();
            stk.push(var);
        }
}



