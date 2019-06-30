
typedef struct{
    int indegree = 0;
    vector<int> out;
}graph;
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		int count = 0;
		vector<int> order;
		graph *G = init(numCourses,prerequisites);
		stack<int> temp;
		for (int i = 0; i != numCourses; i++) {
			if (G[i].indegree == 0) {
				temp.push(i);
			}
		}
		while (!temp.empty()) {
			int vex = temp.top();
			order.push_back(vex);
			count++;
			temp.pop();
			int n = G[vex].out.size();
			for (int i = 0; i != n; i++) {
				int node = G[vex].out[i];
				G[node].indegree--;
				if (G[node].indegree == 0) {
					temp.push(node);
				}
			}
		}
		if (count < numCourses) {
			return false;
		}
		else
			return true;
	}
	graph* init(int &numCourses, vector<pair<int, int>>& prerequisites) {
		graph* G = new graph[numCourses];
		int n = prerequisites.size();
		for (int i = 0; i != n; i++) {
			G[prerequisites[i].second].out.push_back(prerequisites[i].first);
			G[prerequisites[i].first].indegree++;
		}
		return G;
	}
};