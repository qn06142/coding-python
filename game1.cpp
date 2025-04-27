#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
// A large constant for infinity.
const ll INF = 1LL << 60;
 
// Maximum size. (For testing you might use a smaller value.)
const int MAXN = 2050;
 
// Global arrays (1-indexed)
int n, m;
ll a[MAXN], b[MAXN];
ll sa[MAXN], sb[MAXN]; // suffix sums: sa[i] = a[i] + a[i+1] + ... + a[n], and similarly sb.
ll dp[MAXN][MAXN];    // dp[i][j] for 1 <= i <= n+1, 1 <= j <= m+1.
 
// Helper functions for the affine parts.
// For i in [1,n], define U(i) = sa[i+1] + i.
ll U(int i) {
    return sa[i+1] + i;
}
// For j in [1,m], define V(j) = sb[j+1] + j.
ll V(int j) {
    return sb[j+1] + j;
}
 
// For a given cell (i,j) (with 1<=i<=n, 1<=j<=m), define the base value:
// F(i,j) = dp[i+1][j+1] + U(i)*V(j)
ll computeF(int i, int j) {
    return dp[i+1][j+1] + U(i) * V(j);
}
 
// ----- 2D Segment Tree Structure -----
// We build a 2D segment tree on grid indices [1,n] x [1,m].
// Each leaf corresponds to one point (i,j) and stores the current F(i,j).
// The query will return the minimum over the rectangle, after applying the
// affine adjustment: for query parameters A and B, at a leaf (i,j) we want
// F(i,j) - B * U(i) - A * V(j).
 
struct Node2D {
    int r1, r2, c1, c2;
    bool isLeaf;
    int r, c; // valid if isLeaf==true
    ll val;   // if leaf, holds F(r,c); for internal nodes this field is not used.
    vector<Node2D*> children;
};
 
// Build a 2D segment tree for rectangle [r1, r2] x [c1, c2].
Node2D* buildTree(int r1, int r2, int c1, int c2) {
    Node2D* node = new Node2D();
    node->r1 = r1; node->r2 = r2;
    node->c1 = c1; node->c2 = c2;
    if(r1 == r2 && c1 == c2) {
        node->isLeaf = true;
        node->r = r1; node->c = c1;
        node->val = INF; // initially, set to INF.
        return node;
    }
    node->isLeaf = false;
    int rm = (r1 + r2) / 2;
    int cm = (c1 + c2) / 2;
    // Partition the rectangle into up to four children.
    if(r1 <= rm && c1 <= cm)
        node->children.push_back(buildTree(r1, rm, c1, cm));
    if(r1 <= rm && cm+1 <= c2)
        node->children.push_back(buildTree(r1, rm, cm+1, c2));
    if(rm+1 <= r2 && c1 <= cm)
        node->children.push_back(buildTree(rm+1, r2, c1, cm));
    if(rm+1 <= r2 && cm+1 <= c2)
        node->children.push_back(buildTree(rm+1, r2, cm+1, c2));
    return node;
}
 
// Update the tree at point (r,c) with new value newVal.
void updateTree(Node2D* node, int r, int c, ll newVal) {
    if(r < node->r1 || r > node->r2 || c < node->c1 || c > node->c2)
        return;
    if(node->isLeaf) {
        node->val = newVal;
        return;
    }
    for(auto child : node->children) {
        if(r >= child->r1 && r <= child->r2 && c >= child->c1 && c <= child->c2) {
            updateTree(child, r, c, newVal);
            break;
        }
    }
}
 
// Query the tree over rectangle [qr1, qr2] x [qc1, qc2] with parameters A and B.
// For a leaf corresponding to (i,j), we return: F(i,j) - B * U(i) - A * V(j).
ll queryTree(Node2D* node, int qr1, int qr2, int qc1, int qc2, ll A, ll B) {
    // No overlap.
    if(node->r2 < qr1 || node->r1 > qr2 || node->c2 < qc1 || node->c1 > qc2)
        return INF;
    // If this node is completely inside the query rectangle:
    if(qr1 <= node->r1 && node->r2 <= qr2 && qc1 <= node->c1 && node->c2 <= qc2) {
        if(node->isLeaf) {
            int i = node->r, j = node->c;
            return node->val - B * U(i) - A * V(j);
        }
        ll best = INF;
        for(auto child : node->children)
            best = min(best, queryTree(child, qr1, qr2, qc1, qc2, A, B));
        return best;
    }
    // Otherwise, partial overlap: descend into children.
    if(node->isLeaf) {
        int i = node->r, j = node->c;
        if(i >= qr1 && i <= qr2 && j >= qc1 && j <= qc2)
            return node->val - B * U(i) - A * V(j);
        return INF;
    }
    ll best = INF;
    for(auto child : node->children)
        best = min(best, queryTree(child, qr1, qr2, qc1, qc2, A, B));
    return best;
}
 
// ----- Main DP with 2D Segment Tree -----
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int j = 1; j <= m; j++){
        cin >> b[j];
    }
    
    // Precompute suffix sums.
    sa[n+1] = 0;
    for (int i = n; i >= 1; i--){
        sa[i] = sa[i+1] + a[i];
    }
    sb[m+1] = 0;
    for (int j = m; j >= 1; j--){
        sb[j] = sb[j+1] + b[j];
    }
    
    // Set base cases: dp[i][m+1] = dp[n+1][j] = 0.
    for (int i = 1; i <= n+1; i++){
        dp[i][m+1] = 0;
    }
    for (int j = 1; j <= m+1; j++){
        dp[n+1][j] = 0;
    }
    // Initialize dp for other indices to INF.
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] = INF;
        }
    }
    
    // Build an empty 2D segment tree over indices [1,n] x [1,m].
    Node2D* segTree = buildTree(1, n, 1, m);
    // Initially, every point holds INF.
    
    // Process dp in reverse order.
    // We compute dp[i][j] = A*B + Q, where:
    //   A = sa[i] + i - 1,   B = sb[j] + j - 1,
    // and Q = min_{(k,l) in [i,n]x[j,m]} { F(k,l) - B*U(k) - A*V(l) }.
    // Then we update the segtree at (i,j) with F(i,j) = dp[i+1][j+1] + U(i)*V(j).
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            ll A = sa[i] + i - 1;
            ll B = sb[j] + j - 1;
            ll queryRes = queryTree(segTree, i, n, j, m, A, B);
            if(queryRes == INF) queryRes = 0; // if no candidate exists, treat as 0.
            dp[i][j] = A * B + queryRes;
            
            ll newF = computeF(i, j);
            updateTree(segTree, i, j, newF);
        }
    }
    
    cout << dp[1][1] << "\n";
    return 0;
}
