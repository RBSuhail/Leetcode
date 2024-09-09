class Solution {
public:
    // Parent mapping and weight mapping for union-find structure
    unordered_map<string, string> parent;
    unordered_map<string, double> weight;

    // Function to evaluate division results for given division equations
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int equationCount = equations.size();
      
        // Initialize the parents and weights for the disjoint set
        for (const auto& equation : equations) {
            parent[equation[0]] = equation[0];
            parent[equation[1]] = equation[1];
            weight[equation[0]] = 1.0;
            weight[equation[1]] = 1.0;
        }

        // Perform Union operation
        for (int i = 0; i < equationCount; ++i) {
            const auto& equation = equations[i];
            const string& varA = equation[0];
            const string& varB = equation[1];
            string parentA = find(varA);
            string parentB = find(varB);

            // If they already have the same parent, they are already connected
            if (parentA == parentB) continue;
          
            // Union the two sets and adjust the weights
            parent[parentA] = parentB;
            weight[parentA] = weight[varB] * values[i] / weight[varA];
        }

        int queryCount = queries.size();
        vector<double> answers(queryCount);
      
        // Process queries
        for (int i = 0; i < queryCount; ++i) {
            const string& varC = queries[i][0];
            const string& varD = queries[i][1];

            // Check whether the variables are present in the union-find structure and connected
            if (parent.find(varC) == parent.end() || parent.find(varD) == parent.end() || find(varC) != find(varD)) {
                answers[i] = -1.0;  // Variables are disconnected or not present
            } else {
                answers[i] = weight[varC] / weight[varD];  // Compute the ratio
            }
        }

        return answers;
    }

    // Helper function to perform Find operation in the union-find data structure
    string find(string x) {
        if (parent[x] != x) {
            string originParent = parent[x];
            parent[x] = find(parent[x]); // Path compression
            weight[x] *= weight[originParent]; // Adjust weights during path compression
        }
        return parent[x];
    }
};
