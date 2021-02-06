/* Convert this program to C++
*   change to C++ io
*   change to one line comments
*   change defines of constants to const
*   change array to vector<>
*   inline any short function
#include <stdio.h>
#define N 40
void sum(int* p, int n, int d[])
{
    int i;
    *p = 0;
    for (i = 0; i < n; ++i)
        *p = *p + d[i];
}
int main()
{
    int i;
    int accum = 0;
    int data[N];
    for (i = 0; i < N; ++i)
        data[i] = i;
    sum(&accum, N, data);
    printf("sum is %d\n", accum);
    return 0;
}
*/

#include <iostream>
#include <vector>
using namespace std;

inline void sum(int& p, int n, vector<int> d) {
    p = 0;
    for (int i = 0; i < n; i++)
        p += d[i];
}

int main(void) {
    const int N = 40;
    int accum = 0;
    int data[N];
    vector<int> v;
    
    for (int i = 0; i < N; ++i)
         v.push_back(i);

    sum(accum, N, v);

    cout << "sum is " << accum;
    return 0;
}

