#include<bits/stdc++.h>
#define pb push_back
#define N 105
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--){
       int m,q;
        cin>>q>>m;
        string right="ABCD?";
        vector<int> ans(q,4);
        vector<string> WA(q,"0123");
        int pos[N][5]={{0}};
        while(m--){
            for(int i=0;i<q;i++){
                char C,A;
                cin>>C>>A;
                if(A=='T')
                    ans[i]=(C-'A');
                else {
                    char s=(C-'A'+'0');
                    int f=WA[i].find(s);
                    if(f!=string::npos)
                    WA[i].erase(f,1);
                }
            }
        }
        for(int i=0;i<q;i++){
            if(ans[i]!=4||WA[i].length()!=1)continue;
            ans[i]=WA[i][0]-'0';

        }
        cout<<right[ans[0]];
        for(int i=1;i<q;i++)
            cout<<" "<<right[ans[i]];
        cout<<endl;
    }
    return 0;
}
