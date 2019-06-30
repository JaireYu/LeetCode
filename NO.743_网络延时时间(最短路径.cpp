//如何new delete二维数组
//如何定义∞：int_MAX
//为什么D用D[n]申请会出错
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        K = K-1;
        int **graph = initgraph(times, N);
        int *D = initD(graph, K, N);
        vector<int> fin(N);
        fin[K] = 1;
        for(int i = 1; i!=N; i++){
            int minval = INT_MAX;
            int tempv = K;
            for(int j = 0; j!=N; j++){
                if(fin[j] == 0){
                    if(D[j] < minval){
                        tempv = j;
                        minval = D[j];
                    }
                }  
            }
            if(tempv == K)
                return -1;
            else
                fin[tempv] = 1;
            for(int i = 0; i!=N; i++){
                if(fin[i] == 0){
                    if(graph[tempv][i] != INT_MAX)
                        D[i] = min(D[i], D[tempv] + graph[tempv][i]);
                }
            }
        }
        int maxval = 0;
        for(int i = 0; i != N; i++){
            maxval = max(maxval, D[i]);
        }
        for(int i = 0; i < N; i ++)
             delete [] graph[i];
        delete []graph;
        delete []D;
        if(maxval == INT_MAX)
            return -1;
        else
            return maxval;
    }
    int **initgraph(const vector<vector<int>>& times, const int &N){
        int ** a;
        a = new int *[N];
        for(int i = 0; i < N; i ++)
            a[i] = new int[N];
        int n = times.size();
        for(int i = 0; i != N; i++){
            for(int j = 0; j!=N; j ++){
                a[i][j] = INT_MAX;
            }
        }
        for(int i = 0; i != n; i++){
            a[times[i][0] - 1][times[i][1] - 1] = times[i][2];
        }
        return a;
    }
    int *initD(int** graph, const int& k, const int& N){
        int *D = new int[N];
        for(int i = 0; i!= N; i++){
            D[i] = graph[k][i];
        }
        D[k] = 0;
        return D;
    }
};