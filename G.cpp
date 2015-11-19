#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define ppi pair<ll,pii>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define N 100003
int s,p,mx;
vector<ppi>a[N];
void init(int n){
for(int i=0;i<n+1;i++)
    a[i].clear();
}
ll dijkstra(int MW) {
    vector<ll> cost( N, INT_MAX );
    vector<ll> mw( N, INT_MAX );
    cost[ s ] = 0;
    mw[ s ] = 0;
    set< pair<ll,ll> > index;
    index.insert( {0,s} );

    while (!index.empty()) {
        int cur = index.begin()->second;
        if (cur == p) return cost[cur];
        index.erase( index.begin() );
        for (auto edge : a[cur]){
                ll tar = edge.f ,c=edge.s.f,w=edge.s.s;
                if (cost[tar] > cost[cur] + c     && max(mw[cur],w)<=MW ) {
                mw[tar]=min(mw[tar],max(mw[cur],w));
                index.erase( { cost[tar], tar } );
                cost[tar] = cost[cur] + c;
                index.insert( { cost[tar], tar } );
                }

            }
    }
    return cost[p];
}

int main()
    {
	int v1,v2,w,n,c,m,wmax=0,wmin=1<<30,T;cin>>T;
	while(T--){
    scanf("%d%d%d",&n,&m,&mx);
    init(n);
	for(int i=0;i<m;i++)
	{
	    scanf("%d%d%d%d",&v1,&v2,&c,&w);
	    wmax=max(wmax,w);
	    wmin=min(wmin,w);
		a[v1-1].pb(mp(v2-1,mp(c,w)));
		a[v2-1].pb(mp(v1-1,mp(c,w)));
	}
	s=0;p=n-1;
	wmax+=10;
	wmin-=10;
	int i,wans;
	while(wmin!=wmax){
         i = (wmin+wmax)/2;
        ll x =	dijkstra(i);
        if(x>=mx)
        wmin=i+1;
        else
        wmax=i;
    }

    printf("%d\n",(dijkstra(wmin) >=mx ? -1 : wmin));

	}
}
