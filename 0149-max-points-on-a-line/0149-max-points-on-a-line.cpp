class Solution {
    int gcd(int a, int b) {
        return b==0 ? a : gcd(b, a%b);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), mxp = 1;
        for(int p=0;p<n;p++) {
            map<pair<int,int>, int> slopes;
            int duplicate = 1;
            for(int np=p+1;np<n;np++) {
                if(points[p][0] == points[np][0] && points[p][1] == points[np][1]) {
                    duplicate++;
                } else {
                    int xs = points[p][0] - points[np][0], ys = points[p][1] - points[np][1];
                    int g = gcd(abs(xs), abs(ys));
                    xs = xs/g;
                    ys = ys/g;
                    if(ys < 0) {
                        ys = abs(ys);
                        xs = -xs;
                    }
                    if(ys == 0) {
                        xs = abs(xs);
                    }
                    slopes[make_pair(xs, ys)]++;
                }
            }
            for(const auto& slope : slopes) {
                mxp = max(mxp, slope.second+duplicate);
            }
        }
        return mxp;
    }
};