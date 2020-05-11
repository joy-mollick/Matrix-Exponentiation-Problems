/*

Time-590ms

Test Case is so strict.
Try to reduce the use of mod ,it will reduce time complexity.

Think about binomial co-efficient 
F(n) = 1^k + 2^k +.....+ n^k.

F(n) = F(n-1) + (n)^k .

Now , You have to make expression of (n)^k in term of recurrence multiplicative constant to build our matrix of matExpo.
(n)^k can be expanded into (k 0)*(n-1)^k + (k 1) *(n-1)^(k-1) + ........ + (k k) *(n-1)^0 .

where ,(k 0) ......(k k) are constant .So previously we had to compute it till k constraint by nCr relation .

and for base case F(1) is obviously 1 and 1^k .....1^0 all are one (1) .

Now make sketch of matrix .

*/

#include<bits/stdc++.h>

typedef unsigned long long ll;

const ll mod = (1LL << 32);

///2^32


ll nCr[55][55];

void compute_nCr()
{
    nCr[0][0]=nCr[1][1]=1ll;
    for(int i=1;i<55;i++)
    {
        nCr[i][0]=1ll;///nC0=1 ,base case
        for(int j=1;j<55;j++)
            nCr[i][j]=(nCr[i-1][j]+nCr[i-1][j-1])%mod;/// nCr=(n-1)Cr + (n-1)C(r-1) . relation
    }
}

/// we initialize a structure because we can easily return this from a function after multiplication
 struct matrix {
  ll m[55][55];
  int row, column;
};

/// it will d*d*d complexity ,where d is matrix size
matrix mul(matrix &a, matrix &b) {

  matrix M;/// initialize one
  /// it is pretty easy ,when mul ( a x b ) where a and b is matrix

  M.row = a.row; /// initialize new matrix's row
  M.column = b.column; /// initialize new matrix's column
  for (int i = 0; i < M.row; i++) {
    for (int j = 0; j < M.column; j++) {
            M.m[i][j]=0ll;
      for (int k = 0; k < a.column;  k++) {
        M.m[i][j]=(M.m[i][j])+((a.m[i][k]) * (b.m[k][j]));
        M.m[i][j]%=mod;
      }
    }
  }
  return M; /// after multiplication of matrices a and b

}


/// Function to compute a raise to power (b+1).
matrix power(matrix a, ll b)
{
   matrix ans=a;

    while(b>=1ll) /// calculating a^b
    {
        if(b&1ll) ans=mul(ans,a);/// it is nothing but ans*a
        b >>= 1ll;/// it is more faster than b=b>>1ll;
        a=mul(a,a);/// it is nothing but a*a
    }
    return (ans);/// return result
}


/// Driver code
int main()
{
    ///ios_base::sync_with_stdio(false);
    ///cin.tie(NULL);
    ///cout.tie(NULL);
    matrix a;
    ll n;
    int k;
    compute_nCr();/// previously computed
    int tc;
    scanf("%d",&tc);
    int caso=1;
    ll ans;
   while(tc--)
   {
       scanf("%llu%d",&n,&k);
       printf("Case %d: ", caso++);
       ans = 0ll;
       if(k==1)
       {
           ans=( (n % mod) * ( (n + 1ll) % mod) / 2ll) % mod;
           printf("%llu\n", ans);
           continue;
       }
       a.row=a.column=k+2ll;/// k+1 -> constant  from(  (k 0) ....... (k k) ) of binomial constant and one extra constant ,total k+2
       for(int i=0;i<k+2;i++) for(int j=0;j<k+2;j++) a.m[i][j]=0ll;/// initially fill_up with zeros
       a.m[0][0]=1ll;
       for(int i=1;i<=k+1;i++)/// filling only first and second  row which has full match without the first one
        {
            a.m[0][i]=nCr[k][i-1];
            a.m[1][i]=nCr[k][i-1];
        }
        for(int i=2;i<=k+1;i++) /// filling other rows
        {
            for(int j=i;j<=k+1;j++)
                a.m[i][j]=nCr[k-i+1][j-i];
        }
        matrix mat=power(a,n-2ll);/// it returns a^(n-1)
        for(int i=0;i<k+2;i++) {ans=(ans+mat.m[0][i])%mod;}/// because all f(1) and 1^0...1^k will be one (1)
        printf("%llu\n", ans);
   }
   return 0;
}
