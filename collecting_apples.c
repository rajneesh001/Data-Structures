#include <stdio.h>
#include <stdlib.h>
#define OUT 0
#define MAX 1000
 
long long int T, N, i;
long long int P, total, revtotal[MAX+1], milk[MAX], apple[MAX];
long long int ans[MAX+1][MAX+1], zz;
 
long long int max(long long int a,long long int b)
{
    return (a > b)?a:b;
}
 
long long int min(long long int a,long long int b)
{
    return (a < b)?a:b;
}
 
long long int Checkbounds(long long int i, long long int zz)
{
    if(i == N || i < 0) return OUT;
    if( zz >= (N-i)) return revtotal[i];
    if( zz <= 0) return OUT;
    return ans[i][zz];
}
 
int main()
{
    scanf("%lld",&T);
    
    while(T--)
    {
       scanf("%lld%lld",&N,&P);
       
       revtotal[N]=total=0;
       
       for(i=0;i<N;i++)
         scanf("%lld",&milk[i]);
         
       for(i=0;i<N;i++)
         { 
             scanf("%lld",&apple[i]); 
             total=total+apple[i];
         }
         
      for(i=N-1;i>=0;i--)
       revtotal[i]=revtotal[i+1]+apple[i];
         
       if(P >= N)
       {
           
           printf("%lld\n",total);
       }
       else
       {
           for(i=N-1;i>=0;i--)
           {
               for(zz=0;zz<=N;zz++)
               {
                   if(zz >= (N-i))
                     ans[i][zz] = revtotal[i]; // enough energy to take all apples
                    else
                    {
                        ans[i][zz] = max(
                            apple[i]+Checkbounds(i+1,zz-1), // take apple
                             Checkbounds(i+1,milk[i]+zz-1) // drink milk
                            );
                    }
               }
           }
           
            printf("%lld\n", Checkbounds(0,min(N,P)) );
       }
       
      
        
    }
    
    return 0;
}