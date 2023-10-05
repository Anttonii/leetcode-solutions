class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // distinct rectangles
        int arect = abs(ax2-ax1) * abs(ay2 - ay1);
        int brect = abs(bx2-bx1) * abs(by2 - by1);

        // overlapping rectangle
        int orectx = min(ax2,bx2) - max(ax1,bx1);
        int orecty = min(ay2,by2) - max(ay1,by1);
        int orect = orectx * orecty;
        
        if(ax1 > bx2 || ay1 > by2 || bx1 > ax2 || by1 > ay2) orect = 0;
        return arect + brect - orect;
    }
};