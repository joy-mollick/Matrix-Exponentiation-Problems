/*

You can learn it from many tutorials or articles .Here I can suggest a wonderful article about it
http://zobayer.blogspot.com/2010/11/matrix-exponentiation.html
It is very easy to implement ,if you know about the calculation of a^b in O(logn) time 
*/

#include<bits/stdc++.h>

using namespace std;


/// we initialize a structure because we can easily return this from a function after multiplication . 
/// Otherwise  to return a two dimensional array from function is a fact of pointer ,I would like to avoid to make it simple 

 struct matrix {
  int m[2][2];
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
        int sum_of_row_i=0;
      for (int k = 0; k < a.column;  k++) {
        sum_of_row_i += a.m[i][k] * b.m[k][j];
      }
      M.m[i][j] = sum_of_row_i;
    }
  }
  return M; /// after multiplication of matrices a and b

}

/// Here I included it ,so that You can compare it with our new function of calculating of matrix-power 
/// This function has nothing to do with this matrix power ,it is for calculating a^(b+1) 

int pow(int a,int b)
{
    int ans=a;
    while(b>=1)
    {
        if(b&1) ans=(ans*a);
        b=b>>1;
        a=a*a;
    }
    return ans;
}
/// Function to compute a raise to power (b+1).
matrix power(matrix a, int b)
{
   matrix ans=a;/// Initialize ans with   | 1 1 |
               ///                        | 1 0 | that's why it returns a^(b+1) ,as ans is initialized with already a 

    while(b>=1) /// calculating a^b 
    {
        if(b&1) ans=mul(ans,a);/// it is nothing but ans*a
        b=b>>1;
        a=mul(a,a);/// it is nothing but a*a
    }
    return ans;/// return result
}

/// Driver code
int main()
{
    int n;
   while(cin>>n)
   {
       matrix a;
       a.row = a.column = 2;
       a.m[0][0] = a.m[0][1] = a.m[1][0] = 1;
       a.m[1][1] = 0;
       /// Initialize     with   | 1 1 |
      ///                        | 1 0 |
       if(n==1||n==2) cout<<"1"<<endl;
       else
        {
       matrix mat=power(a,n-3); /// it returns a^(n-2) 
       int res=mat.m[0][0]+mat.m[0][1];
       cout<<res<<endl;/// nth term in fibonacchi 
       }
   }
   return 0;
}
