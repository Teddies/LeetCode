class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int S1 = (C - A) * (D - B), S2 = (G - E) * (H - F);
        if (E >= C || F >= D || G <= A || H <= B) return S1 + S2;
        return S1 + S2 - (min(G, C) - max(A, E)) * (min(H, D) - max(B, F));
    }
};