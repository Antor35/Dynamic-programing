#include<bits/stdc++.h>
using namespace std;
vector<long long>g[150005];
long long vis[150005];

int main(){
    long long n,e,a,b;
    cin >> n >> e;
    for(long long i=1; i<=e; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        vis[a]=0;vis[b]=0;
    }
    // memset(vis,0,sizeof(vis));
     for(long long i=1; i<=n; i++){
        if(vis[i]==0){
            long long node=0,edges=0;
            queue<long long>q;
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                long long u=q.front();
                node++;
                q.pop();
                for(long long i = 0; i<g[u].size(); i++){
                    long long v=g[u][i];edges++;
                    if(vis[v]==0){
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }
            edges /=2;
            long long is=(node*(node-1))/2;
            if(edges!=is){
                cout << "NO" << endl;
                return 0;

            }
        }
     }
    cout << "YES" << endl;
return 0;
}
