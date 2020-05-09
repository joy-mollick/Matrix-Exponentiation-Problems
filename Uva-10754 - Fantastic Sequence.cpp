
/// Time-0.120s
/// Classical One 

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod;


/// we initialize a structure because we can easily return this from a function after multiplication
 struct matrix {
  ll m[22][22];/// k can be maximum 21
  int row, column;
};

/// it will d*d*d complexity ,where d is matrix size
matrix mul(matrix a, matrix b) {

  matrix M;/// initialize one
  /// it is pretty easy ,when mul ( a x b ) where a and b is matrix

  M.row = a.row; /// initialize new matrix's row
  M.column = b.column; /// initialize new matrix's column
  for (int i = 0; i < M.row; i++) {
    for (int j = 0; j < M.column; j++) {
            M.m[i][j]=0ll;
      for (int k = 0; k < a.column;  k++) {
        M.m[i][j]=((M.m[i][j]%mod)+((a.m[i][k]%mod) * (b.m[k][j]%mod)));
        M.m[i][j]%=mod;
      }
    }
  }
  return M; /// after multiplication of matrices a and b

}


/// Function to compute a raise to power (b+1).
matrix power(matrix a, int b)
{
   matrix ans=a;/// Initialize with a ,that's why it returns a^(b+1) ,as ans is initialized with already a

    while(b>=1) /// calculating a^b
    {
        if(b&1) ans=mul(ans,a);/// it is nothing but ans*a
        b=b>>1;
        a=mul(a,a);/// it is nothing but a*a
    }
    return (ans);/// return result
}

/*

| a  b  1 |   |(f(n-1))|   | f(n)   |
| 1  0  0 | x |(f(n-2))| = | f(n-1) |
| 0  0  1 |   |  c     |   |    c   |
*/

/// Driver code
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,A,b,tc,m,k;
    matrix a;
    cin>>tc;
       ///
   while(tc--)
   {
        cin>>k>>m>>n;
        mod=m;
        ll c[k+1]; /// this array holds the value of the multiplication constant.
        ll arr[k]; /// this array holds the value of the recurrence array element.
        for(int i=0;i<k+1;i++) { cin>>c[i];c[i]=(c[i]%m)+m; c[i]%=m;}/// negative may comes ,be careful by adding mod to this and take mod value of total
        for(int i=0;i<k;i++)   {cin>>arr[i];arr[i]=(arr[i]%m)+m;arr[i]%=m;}
        if(n < k) { /// if n is below than k there is no effect of c constant ,so answer is arr[n].
            cout<< arr[n]<<endl;
            if(tc) cout<<endl;
            continue;
        }
        a.row = a.column = k+1;///  row and column will be (k+1) and (k+1)

        for(int i=0;i<k+1;i++) for(int j=0;j<k+1;j++) a.m[i][j]=0ll;/// fill with zeros

        for(int i=0;i<k;i++) a.m[0][i]=c[i];/// first row with constant c array

        a.m[0][k]=1;/// it will be for multiplication with another matrix (c->k+1) .

        for(int i=1;i<k;i++) a.m[i][i-1]=1ll;/// place diagonally 1 in matrix without last row
        a.m[k][k]=1;/// Last row-> it will keep extra constant c->k+1 as maintainer of all rules of matrix

       matrix mat=power(a,(n-k)); /// it returns a^(n-k+1) , here , here first k-1 elements of arr elements from 1 index in other array with the and another one is c->k+1 ,so n-(k-1)=n-k+1 should be power
       ll res=0ll;
       for(int i=0;i<k;i++) {res=(res+(arr[k-1-i]*mat.m[0][i])%mod)%mod;}
       res=(res+(c[k]*mat.m[0][k])%mod)%mod;/// adding c->(k+1) constant
       cout<<res<<endl;
       if(tc) cout<<endl;
   }
   return 0;
}
