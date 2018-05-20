class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int left2_x = rec2[0];
        int left2_y = rec2[1];
        int right1_x = rec1[2];
        int right1_y = rec1[3];
        
        int left1_x = rec1[0];
        int left1_y = rec1[1];
        int right2_x = rec2[2];
        int right2_y = rec2[3];
        
        if (left2_x >= right1_x || left2_y >= right1_y || right2_x <= left1_x || right2_y <= left1_y) return false;
        else return true;
     }
};