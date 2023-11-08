class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> degree(n,0); //degree = [0, 0, ..., 0] (size n)
        vector<vector<int>> neighbours(n);
        for (vector<int>& edge : edges) {
            degree[edge[0]] += 1;
            degree[edge[1]] += 1;
            neighbours[edge[0]].push_back(edge[1]);
            neighbours[edge[1]].push_back(edge[0]);
        }
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1 || degree[i] == 0) {
                leaves.push_back(i);
                degree[i] = 0;
            }
        }
        int count = leaves.size();
        while (count < n) {
            vector<int> new_leaves;
            for (int leaf : leaves) {
                for  (int neighbour : neighbours[leaf]){
                    degree[neighbour] -= 1;
                    if (degree[neighbour] == 1) {
                        new_leaves.push_back(neighbour);
                    }
                degree[leaf] = 0;
                }
            }
            count += new_leaves.size();
            leaves.resize(new_leaves.size());
            for (int i = 0; i < new_leaves.size(); i++) {
                leaves[i] = new_leaves[i];
            }
        }
        return leaves;
    }
};
