//auto 循环方法
//unordered_map
//除法与有向图
//用hash表表示有向图
class Solution {
public:
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		unordered_map<string, unordered_map<string, double>> Gedge;
		int n = equations.size();
		for (int i = 0; i < n; i++) {
			Gedge[equations[i].first][equations[i].second] = values[i];
			Gedge[equations[i].second][equations[i].first] = 1.0 / values[i];
		}
		for (auto it : Gedge) {
			Gedge[it.first][it.first] = 1;
		}//初始化图
		for (auto it1 : Gedge) { //中间节点
			for (auto it2 : Gedge) { //源点
				for (auto it3 : Gedge) { //汇点
					if(Gedge.count(it2.first)&&Gedge.count(it1.first)&&Gedge[it2.first].count(it1.first)&& Gedge[it1.first].count(it3.first))
					Gedge[it2.first][it3.first] = Gedge[it2.first][it1.first] * Gedge[it1.first][it3.first];
				}
			}
		}
		n = queries.size();
		vector<double> res;
		for (int i = 0; i < n; i++) {
			double x;
			if (Gedge.count(queries[i].first) == 0) {
				x = -1.0;
			}
			else if (Gedge[queries[i].first].count(queries[i].second) == 0) {
				x = -1.0;
			}
			else
				x = Gedge[queries[i].first][queries[i].second];
			res.push_back(x);
		}
		return res;
	}
};