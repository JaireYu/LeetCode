class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int vexnum = graph.size();
        vector<int> visit(vexnum);
        if(DFS(visit,graph,0,1) == false)
                 return false;
        return true;
    }
    bool DFS(vector<int>& visit, const vector<vector<int>>& graph, const int& v, const int& c){
        visit[v] = c;
        int n = graph[v].size();
        for(int i = 0; i != n; i ++){
            if(visit[graph[v][i]] == c)
                return false;
            else if(visit[graph[v][i]] == 0 && DFS(visit, graph, graph[v][i], -c) == false)
                return false;
        }
        return true;
    }
};