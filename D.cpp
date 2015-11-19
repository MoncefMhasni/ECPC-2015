#include<bits/stdc++.h>
#define pii pair<int,int>
#define vpii vector<pii>
#define mp make_pair
#define pb push_back
#define s second
#define f first
#define ll long long
using namespace std;
vector<int> nodes;
const int N = 100005 ;
vector<pii> g[N];

ll d[N];
void init(int n){
    nodes.clear();
    for(int i=0;i<n+3;i++)
        g[i].clear();
    d[1]=0;
}
void go (int s){
    if(g[s].empty()){
        nodes.pb(s);
        return ;
    }
    int mindelay=INT_MAX;
    for(int i=0;i<g[s].size();i++){
        mindelay=min(mindelay,g[s][i].s);
    }
    for(int i=0;i<g[s].size();i++){
        int u=g[s][i].f;
        d[u]=d[s]+(ll)mindelay+(ll)(g[s][i].s-mindelay)*2;
        go(u);
    }

}
bool f(int i,int j){
    return d[i]<d[j];
}
void answer(ll x,int n){
    int M = nodes.size()-1,m=0;int i;
    if(x>=d[nodes[M]]){
        cout<<M+1<<endl;
        return;
    }
    if(x<d[nodes[m]]){
        cout<<"0"<<endl;
        return;
    }
    while(m!=M){
         i = (m+M)/2;
        if(d[nodes[i+1]]<=x)
        m=i+1;
        else
        M=i;
    }
    if(d[nodes[m]]<=x)m++;
    cout<<m<<endl;
}

int main()
{
  //  freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int tc;scanf("%d",&tc);
    while(tc--){
        int n;
        scanf("%d",&n);
        init(n);
        for(int i=0;i<n-1;i++)
        {
            int p,d;
            scanf("%d%d",&p,&d);
            g[p].pb(mp(i+2,d));
        }
        d[1]=0;
        go(1);
        sort(nodes.begin(),nodes.end(),f);
        int Q;scanf("%d",&Q);
        while(Q--){
            ll t;scanf("%I64d",&t);
             answer(t,n);
        }

    }
    return 0;
}
