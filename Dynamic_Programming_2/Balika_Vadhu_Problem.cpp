/*Anandi and Jagya were getting married again when they have achieved proper age. Dadi Sa invited Alok Nath to do the kanyadaan and give blessings. Alok Nath has 2 blessings. Each bessing is in the form of a string consisting of lowercase charaters(a-z) only. But he can give only one blessing of K length because some priest told him to do so. Thus he decides to generate a blessing using the other two blessings. While doing this he wants to ensure that happiness brought into their life by his blessing is maximum.
The generated blessing is a common subsequence of length K of the two blessings he has. Happiness of the blessing he generates is calculated by the sum of ASCII values of characters in the blessing and he wants the happiness to be maximum. If he is not able to generate a common subsequence of length K then the happiness is 0 (zero). Alok Nath comes to you and asks you to find the maximum happiness that can be generated by the two blessings he has.
Input Specification
First line consists of number of test cases t. Each test case consists of two strings b1 (blessing 1),b2 (blessing 2) and an integer K, each of them in separate lines.
Output Specification
Output consists of t lines each containing an integer denoting the maximum happiness value that can be generated by the two blessings.
Constraint
1 <= t <= 50

1 <= length(b1) , length(b2) <= 100 

1 <= K <= 100
Sample Input
2
asdf
asdf
3
anandi
jagya
3
Sample Output
317
0*/

#include <bits/stdc++.h>
using namespace std;
int LCS(string s1, string s2, int m,int n,int k,int*** dp){
    if(k<=0) 
        return 0;
    if(m==0||n==0) {
        if(k>0) 
            return INT_MIN;
        return 0;
    }
    if(dp[m][n][k]!=-1) 
        return dp[m][n][k];
    int ans;
    if(s1[0]==s2[0]){
        int b1 = s1[0]+LCS(s1.substr(1),s2.substr(1),m-1,n-1,k-1,dp);
        int b2 = LCS(s1.substr(1),s2.substr(1),m-1,n-1,k,dp);
        ans = max(b1,b2);
    }
    else{
        int b3 = LCS(s1.substr(1),s2,m-1,n,k,dp);
        int b4 = LCS(s1,s2.substr(1),m,n-1,k,dp);
        ans = max(b3,b4);
    }
    dp[m][n][k] = ans;
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int k;
        cin>>k;
        int m,n;
        m=s1.length();
        n=s2.length();
        int*** dp = new int**[m+1];
        for(int i=0;i<=m;i++){
            dp[i] = new int*[n+1];
            for(int j=0;j<=n;j++){
                dp[i][j] = new int[k+1];
                for(int p=0;p<=k;p++) 
                    dp[i][j][p] = -1;
            }
        }
        int ans = LCS(s1,s2,m,n,k,dp);
        if(ans<0) 
            cout<<0<<endl;
        else cout<<ans<<endl;
    }
    return 0;