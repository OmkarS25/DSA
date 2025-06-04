// Kth Ancestor of a Tree Node (LeetCode 1483)
#include <vector>
using namespace std;

class TreeAncestor {
public:
    vector<vector<int> > P; // P[i][node] :::: [node] 's [2^i]th parent
    TreeAncestor(int n, vector<int>& parent) {
        // initialize
        P.resize(20, vector<int>(parent.size(), -1));
        
        // 2^0
        for(int i = 0; i < parent.size(); i++)
            P[0][i] = parent[i];
        
        // 2^i
        for(int i = 1; i < 20; i++){
            for(int node = 0; node < parent.size(); node ++){
                int nodep = P[i-1][node];
                if(nodep != -1) P[i][node] = P[i-1][nodep];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i < 20; i++){
            if(k & (1 << i)){
                node = P[i][node];
                if(node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

// Another code with a bit different approach
class TreeAncestor2 {
public:
    vector<vector<int>> up;
    vector<int> depth;
    int LOG;
public:
    TreeAncestor2(int n, vector<int>& parent){
        LOG = 0;
        while((1 << LOG) <= n) LOG++;
        up = vector<vector<int>>(n, vector<int>(LOG, -1));
        depth = vector<int>(n, 0);
        parent[0] = -1; // root has no parent
        for(int v=0; v<n; v++){
            up[v][0] = parent[v];
            if(parent[v] != -1) depth[v] = depth[parent[v]] + 1;
            for(int j=1; j<LOG; j++){
                up[v][j] = up[ up[v][j-1] ][j-1];
            }
        }
    }
    int getKthAncestor(int node, int k) {
        if(k > depth[node]) return -1; // k is larger than the depth of the node
        for(int j=LOG-1; j>=0; j--){
            if(k >= (1 << j)){
                node = up[node][j];
                k -= (1 << j);
            }
        }
        return node;
    }
};