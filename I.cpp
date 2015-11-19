#include<bits/stdc++.h>
using namespace std;
int ham(int a,int b){
    int ans=0;
    if(a<b)swap(a,b);
    while(b){
        if ((b&1) != (a&1))
            ans++;
        b=b>>1;
        a=a>>1;
    }
    while(a){
        if(a&1)
            ans++;
        a=a>>1;
    }
    return ans;
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--){
       int N;
       cin>>N;
       vector<int> v(N);
       for(int i=0;i<N;i++)
        cin>>v[i];
        int ans = 0;
       for(int i=0;i<N;i++)
       for(int j=0;j<i;j++)
        ans=max(ans,ham(v[i],v[j]));
        cout<<ans<<endl;
    }

}
