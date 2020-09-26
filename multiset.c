#include<stdio.h>
#define sd(n) scanf("%d",&n)
#define pf(n) printf("%d\n",n)

int BIT[1000002];
int n;

void update(int index,int val)
{
    
    while(index <=n)
    {
        BIT[index] +=val;
        index += index & (-index);
    }
}

int query(int index)
{
    int cnt = 0;
    while(index>0)
    {
        cnt += BIT[index];
        index -= index & (-index);
    }
    
    return cnt;
}

int find(int val)
{
    int low =1,high =n;
    
    while(low<high)
    {
        int mid = low + (high-low)/2;
        if(query(mid)<val)
            low=mid+1;
        else
            high=mid;
    }
    
 
    return low;
}

int main()
{
    int q,k;
    sd(n);
    sd(q);
    for(int i=0;i<n;i++)
    {
        sd(k);
        update(k,1);
    }
    
    
    for(int i=0;i<q;i++)
    {
        sd( k);
        if(k>0)
            update(k,1);
        else
            update(find(-k),-1);
    }
    
    if(query(n) == 0)
        pf(0); 
    else
        pf(find(1));
    
    return 0;
}