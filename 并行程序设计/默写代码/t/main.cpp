#include <iostream>
#include<pmmintrin.h>
#include<algorithm.h>

using namespace std;

//SSEæÿ’Û≥À∑®
void sse_mul(int n,float a[][MaxN],float b[][MaxN],float c[][MaxN])
{

    __m128 t1,t2,sum;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(b[i][j],b[j][i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=0.0;
            sum=_mm_setzero_ps();
            for(int k=n-4;k>=0;k-=4)
            {
                t1=_mm_loadu_ps(a[i]+k);
                t2=_mm_loadu_ps(b[j]+k);
                t1=_mm_mul_ps(t1,t2);
                sum=_mm_add_ps(sum,t1);
            }
            sum=_mm_hadd_ps(sum,sum);
            sum=_mm_hadd_ps(sum,sum);
            _mm_store_ss(c[i]+j,sum);
            for(int k=(n%4)-1;k>=0;k--)
            {
                c[i][j]+=a[i][k]*b[j][k];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(b[i][j],b[j][i]);
        }
    }
}













































int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
