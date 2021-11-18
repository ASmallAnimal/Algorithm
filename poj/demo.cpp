#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double MAX_DIST = 1e100;
const int MAXN = 200010;

struct Point
{
    double x, y;
    bool flag;
};

inline double dist(const Point &a, const Point &b)
{
    if (a.flag != b.flag)
        return sqrt(pow(a.x - b.x,2)  + pow(a.y - b.y,2));
    else
        return MAX_DIST;
}

Point pt[MAXN];
int y_sort[MAXN];

inline bool x_cmp(const Point &a, const Point &b)
{
    return a.x < b.x;
}

inline bool y_cmp(const int &a, const int &b)
{
    return pt[a].y < pt[b].y;
}

double shortest_distance(int left, int right)
{
    if (right - left == 1)
        return dist(pt[left], pt[right]);
    else if (right - left == 2)
        return min(min(dist(pt[left], pt[left + 1]), dist(pt[left], pt[left + 2])),
                   dist(pt[left + 1], pt[left + 2]));
    int mid = (left + right) >> 1;
    double mind = min(shortest_distance(left, mid), shortest_distance(mid + 1, right));
    if (mind == 0)
        return 0;
    int yn = 0;
    for (int i = mid; pt[mid].x - pt[i].x < mind && i >= left; --i)
        y_sort[yn++] = i;
    int y_mid = yn;
    for (int i = mid + 1; pt[i].x - pt[mid].x < mind && i <= right; ++i)
        y_sort[yn++] = i;
    for (int i = 0; i < y_mid; ++i)
        for (int j = y_mid; j < yn; ++j)
            mind = min(mind, dist(pt[y_sort[i]], pt[y_sort[j]]));
    return mind;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%lf%lf", &pt[i].x, &pt[i].y);
            pt[i].flag = false;
        }
        for (int i = n; i < 2 * n; ++i)
        {
            scanf("%lf%lf", &pt[i].x, &pt[i].y);
            pt[i].flag = true;
        }
        sort(pt, pt + 2 * n, x_cmp);
        printf("%.3f\n", shortest_distance(0, 2 * n - 1));
    }
}