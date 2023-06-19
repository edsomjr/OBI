// OBI 2016 - Nível Sênior - Fase 2: Jardim de Infância (https://olimpiada.ic.unicamp.br/pratique/ps/2016/f2/jardim/)
#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

struct Point {
    int x, y;
};

int dist2(const Point& P, const Point& Q)
{
    return (P.x - Q.x)*(P.x - Q.x) + (P.y - Q.y)*(P.y - Q.y);
}

int D(const Point& P, const Point& Q, const Point& R)
{
    return P.x * Q.y + P.y * R.x + Q.x * R.y - R.x*Q.y - R.y * P.x - Q.x * P.y;
}

bool perp(const Point& A, const Point& B, const Point& C, const Point& D)
{
    auto ux = A.x - B.x, uy = A.y - B.y;
    auto vx = C.x - D.x, vy = C.y - D.y;

    return ux*vx + uy*vy == 0;
}

double angle(const Point& P, const Point& Q, const Point& R)
{
    // Condition 1
    auto ux = Q.x - P.x;
    auto uy = Q.y - P.y;

    if (ux == 0 and uy == 0)
        return 'N';

    auto vx = R.x - P.x;
    auto vy = R.y - P.y;

    if (vx == 0 and vy == 0)
        return 'N';

    auto dot = ux*vx + uy*vy;
    auto ulen = hypot(ux, uy);
    auto vlen = hypot(vx, vy);

    return acos(dot/(ulen * vlen));
}

char solve(const vector<Point>& ps)
{
    // Condition 1
    if (angle(ps[1], ps[2], ps[3]) >= PI/2)
        return 'N';

    // Condition 2
    auto d1 = dist2(ps[1], ps[2]);
    auto d2 = dist2(ps[1], ps[3]);

    if (d1 != d2)
        return 'N';

    // Condition 3
    if (D(ps[2], ps[3], ps[4]) or D(ps[3], ps[4], ps[5]))
        return 'N';

    // Condition 4
    if (ps[2].x + ps[3].x != ps[4].x + ps[5].x or ps[2].y + ps[3].y != ps[4].y + ps[5].y)
        return 'N';

    // Condition 4
    if (dist2(ps[2], ps[3]) <= dist2(ps[4], ps[5]))
        return 'N';

    // Condition 5
    if (not perp(ps[2], ps[3], ps[4], ps[6]) or not perp(ps[2], ps[3], ps[5], ps[7]))
        return 'N';

    // Condition 6
    if (dist2(ps[4], ps[6]) != dist2(ps[5], ps[7]))
        return 'N';

    // Condition 7
    long long a = D(ps[1], ps[2], ps[3]), b = D(ps[6], ps[2], ps[3]);

    if (a*b >= 0)
        return 'N';
 
    return 'S';
}

int main()
{
    vector<Point> ps(8);

    for (int i = 1; i <= 7; ++i)
        cin >> ps[i].x >> ps[i].y;

    cout << solve(ps) << '\n';

    return 0;
}
