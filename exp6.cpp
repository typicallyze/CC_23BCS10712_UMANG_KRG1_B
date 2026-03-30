#include<bits/stdc++.h>
using namespace std;

vector<int> bfstopoSort(int V, vector<int> adj[]){
    vector<int> indegree(V, 0);
    queue<int> q;
    vector<int> ans;
    for(int i = 0; i < V; i++){
        for(auto a : adj[i]){
            indegree[a]++;
        }
    }
    for(int i = 0; i < V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int qNode = q.front();
        q.pop();
        ans.push_back(qNode);
        for(auto a : adj[qNode]){
            indegree[a]--;
            if(indegree[a] == 0){
                q.push(a);
            }
        }
    }
    return ans;
}

int main(){
    vector<int> adj[26];
    set<pair<int,int>> edges;
    int N;
    cin >> N;
    vector<string> words(N);
    for(int i = 0; i < N; i++) cin >> words[i];

    for(int i = 0; i < N-1; i++){
        int len = min(words[i].size(), words[i+1].size());
        bool found = false;
        for(int j = 0; j < len; j++){
            if(words[i][j] != words[i+1][j]){
                int u = words[i][j] - 'a';
                int v = words[i+1][j] - 'a';
                if(!edges.count({u, v})){
                    adj[u].push_back(v);
                    edges.insert({u, v});
                }
                found = true;
                break;
            }
        }
        if(!found && words[i].size() > words[i+1].size()){
            cout << "Impossible";
            return 0;
        }
    }

    int V = 26;
    vector<int> ans = bfstopoSort(V, adj);
    if((int)ans.size() != V){
        cout << "Impossible";
        return 0;
    }
    for(auto it : ans) cout << char(it + 'a');
    return 0;
}
