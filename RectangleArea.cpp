//矩形叠加总面积
// 我们给出了一个（轴对齐的）矩形列表 rectangles 。 对于 rectangle[i] = [x1, y1, x2, y2]，
// 其中（x1，y1）是矩形 i 左下角的坐标，（x2，y2）是该矩形右上角的坐标。
// 找出平面中所有矩形叠加覆盖后的总面积。 由于答案可能太大，请返回它对 10 ^ 9 + 7 取模的结果。
#include <vector>
#include <algorithm>
using namespace std;

// //线性扫描法
// class verticalEdge //竖边
// {
// public:
//     verticalEdge(){};
//     verticalEdge(int x, int l_y, int h_y, int flag) :
//                  _x(x), _less_y(l_y),
//                   _greater_y(h_y),  _flag(flag){};
//     int _x;
//     int _less_y;
//     int _greater_y;
//     bool _flag; //标记是入边还是出边,1是如边，0是出边
// };

// int rectangleArea(vector<vector<int>>& rectangles) 
// {   

//     vector<verticalEdge> segment_tree;
//     //收集所有的竖边
//     for(auto r : rectangles)
//     {
//         segment_tree.push_back(verticalEdge(r[0],r[1],r[3],true));
//         segment_tree.push_back(verticalEdge(r[2],r[1],r[3],false));
//     };
//     //按x坐标排序
//     sort(segment_tree.begin(), segment_tree.end(), 
//     [&](const verticalEdge& e1, const verticalEdge& e2)
//     {
//         return e1._x > e2._x ? true : false;
//     });

 

//     //求差集
//     auto cal_diff_set = [](const vector<verticalEdge>& vv_cur, const verticalEdge& next) 
//                         ->vector<verticalEdge>
//     {
//         //在vv_cur总坐标中依次减去next并集合
//         vector<verticalEdge> ret;
//         for(auto vv_i : vv_cur)
//         {
//             //next全包含cur则为空
//             if(vv_i._greater_y <= next._greater_y && vv_i._less_y >= next._less_y)
//             {
//             }
//             //cur全包含next则分段
//             else if(vv_i._greater_y >= next._greater_y && vv_i._less_y <= next._less_y)
//             {
//                 ret.push_back(verticalEdge(vv_i._x,next._greater_y,vv_i._greater_y,true));
//                 ret.push_back(verticalEdge(vv_i._x,vv_i._less_y,next._less_y,true));
//             }
//             //next上交叉于cur
//             else if(vv_i._greater_y <= next._greater_y && vv_i._greater_y >= next._less_y
//                     && vv_i._less_y <= next._less_y)
//             {
//                 ret.push_back(verticalEdge(vv_i._x,next._less_y,vv_i._less_y,true));
//             }
//             //cur上交叉nNext
//             else if(vv_i._greater_y >= next._greater_y && vv_i._greater_y >= next._less_y
//                     && vv_i._less_y >= next._less_y)
//             {
//                 ret.push_back(verticalEdge(vv_i._x,next._greater_y,vv_i._greater_y,true));
//             };

//         };
//         return ret;
//     };

//     //求并集
//     auto cal_union_set = [&](const vector<verticalEdge>& vv_cur, const verticalEdge& next) 
//                         ->vector<verticalEdge>
//     {
//         vector<verticalEdge> ret;
//         //检测next
//         //看能拉通到哪一级别
//         if(next._greater_y > vv_cur[0]._greater_y)
//         {
//             int i = 0;
//             for(; i< vv_cur.size(); i++)
//             {
//                 if(next._less_y < vv_cur[i]._less_y)
//                 {
//                     break;
//                 }
//             };
//             ret.push_back(verticalEdge(vv_cur[0]._x, min(next._less_y, cur_vv[i])))
//         }

//     };


//     vector<verticalEdge> cur_es{segment_tree[0]};  //x始终相等
//     verticalEdge next_e;
//     int total = 0;
//     for(int i = 0; i < segment_tree.size() - 1; i++)
//     {
//         next_e = segment_tree[i + 1];
//         int x_diff = next_e._x - cur_es[0]._x;
//         if(next_e._flag) //入边, 直接cur横向扫描
//         {
//             for(auto cur_e : cur_es)
//             {
//                 total += (cur_e._greater_y - cur_e._less_y) * x_diff;
//             };

//             cur_es = cal_union_set(cur_es,next_e);
//         }
//         else //出边,求并集扫描
//         {   //并集扫描
//             auto union_set = cal_union_set(cur_es, next_e);
//             for(auto cur_e : cur_es)
//             {
//                 total += (cur_e._greater_y - cur_e._less_y) * x_diff;
//             };
//             cur_es = cal_diff_set(cur_es,next_e);
//         };

//         return total;
//     }
// };

//lc线性扫描
//Thinking
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Node 
{
public:
    int _start;
    int _end;
    vector<int> _x;
    Node* _left;
    Node* _right;
    int _count;
    long _total;

    Node(int start, int end, vector<int> x) 
    {
        _start = start;
        _end = end;
        _x = x;
        _left = nullptr;
        _right = nullptr;
        _count = 0;
        _total = 0;
    }

    int getRangeMid() 
    {
        return _start + (_end - _start) / 2;
    }

    Node* getLeft() 
    {
        if (!_left) 
        _left = new Node(_start, getRangeMid(), _x);
        return _left;
    }

    Node* getRight() 
    {
        if (!_right) _right = new Node(getRangeMid(), _end, _x);
        return _right;
    };

    long update(int i, int j, int val) 
    {
        if (i >= j) return 0;
        if (_start == i && _end == j) 
        {
            _count += val;
        } else 
        {
            getLeft()->update(i, min(getRangeMid(), j), val);
            getRight()->update(max(getRangeMid(), i), j, val);
        }
        if (_count > 0) 
        {
            _total = _x[_end] - _x[_start];
        }
        else 
        {
            _total = getLeft()->_total + getRight()->_total;
        };
        return _total;
    }
};

class Solution 
{
public: 
    //从左到右的竖线性扫描
    int rectangleArea(vector<vector<int>> rectangles) 
    {
        int OPEN = 1, CLOSE = -1;
        vector<vector<int>> events(rectangles.size() * 2); //取一个矩形的两条纵边
        unordered_set<int> Xvals; //x的不重复值
        int t = 0;
        for (auto rec: rectangles) 
        {
            events[t++] = vector<int>{rec[1], OPEN, rec[0], rec[2]}; 
            events[t++] = vector<int>{rec[3], CLOSE, rec[0], rec[2]};
            Xvals.insert(rec[0]);
            Xvals.insert(rec[2]);
        };

        //按y的升序排列
        sort(events.begin(),events.end(),[](const vector<int>& a, const vector<int>& b)
        {
            return a[0] < b[0] ? true : false;
        });

        vector<int> X;
        for(auto iter = Xvals.begin(); iter != Xvals.end(); iter++)
        {
            X.push_back(*iter);
        }
        //x的升序排列
        sort(X.begin(), X.end(), less<int>());
        unordered_map<int, int> Xi; //<x_val,idx>
        for (int i = 0; i < X.size; ++i)
        {
            Xi.insert(X[i], i);
        };

        Node active(0, X.size() - 1, X);
        long ans = 0;
        long cur_x_sum = 0;
        int cur_y = events[0][0];

        for (auto event: events) 
        {
            int y = event[0], typ = event[1], x1 = event[2], x2 = event[3];
            ans += cur_x_sum * (y - cur_y);
            cur_x_sum = active.update(Xi[x1], Xi[x2], typ);
            cur_y = y;
        };
        const int over_count = 1e7;
        ans %= over_count;
        return ans;
    }
};
