#define PI 3.141592653589793238462
class Solution {
public:
    double r, xc, yc;
    Solution(double radius, double xc, double yc) {
        r = radius;
        this->xc = xc; this->yc = yc;
    }
    double uniform(){
        return (double)rand()/RAND_MAX;
    }
    vector<double> randPoint() {
        double theta = 2*PI*uniform();
        double R = r*sqrt(uniform());
        vector<double>ans = {
            xc+R*cos(theta),
            yc+R*sin(theta)
        };
        return ans;
    }
};

/**be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
