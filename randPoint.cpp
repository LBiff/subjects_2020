#include <vector>
#include <random>
#include <cmath>
#include <cstdlib>
using namespace std;

class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        center_x = x_center;
        center_y = y_center;
    }



    vector<double> randPoint() {
        double angle = ((double)rand() / RAND_MAX) * 2 * M_PI; //是弧度
        double new_r = ((double)rand() / RAND_MAX) * r;

        double x = new_r * cos(angle);
        double y = new_r * sin(angle);
        return {x + center_x, y + center_y};
    };
private:
    mt19937 rng{random_device{}()}; //随机数生成器
    uniform_real_distribution<double> uni{0, 1}; //随机数分布引擎
    double r;
    double center_x;
    double center_y;
};