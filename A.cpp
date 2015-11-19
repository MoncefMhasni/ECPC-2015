#include<bits/stdc++.h>
using namespace std;
#define pb push_back
float fact[]={1.0, 1.0, 2.0, 6.0, 24.0, 120.0, 720.0, 5040.0, 40320.0, 362880.0};
int countdiff(int n){
    vector<int> dig;
    while(n){
        dig.pb(n%10);
        n/=10;
    }
    int len =dig.size();
    reverse(dig.begin(),dig.end());
    int ans=0;
    for(int i=0;i<dig.size();i++)
        for(int j=i+1;j<len;j++)
            if((dig[j]>dig[i])){
                ans+=(int)fact[len-i-1];
            }
    return ans;
}
int main()
{

    int tc;
    double y,z;
    cin>>tc;
    while(tc--){
       int n; cin>>n;
        int x = countdiff(n);
        double N = fact[(int)(log10(n))+1];
        double z= (x==0 ? 0 : pow((N+1)/N,x-1)/N);
       printf("%.9f\n",z);

    }
}
