#include <iostream>
#define N 55

using namespace std;

int a, b, c;
long long d[N*3][N*3][N*3];

long long get(int x, int y, int z)
{
    int xx, yy, zz;
    xx = x+N;
    yy = y+N;
    zz = z+N;
    if (d[xx][yy][zz]!=0)
        return d[xx][yy][zz];

    if (x <= 0 || y <= 0 || z <= 0)
        return d[xx][yy][zz] = 1;
    if (x > 20 || y > 20 || z > 20)
        return d[xx][yy][zz] = get(20, 20, 20);
    if (x < y && y < z)
        return d[xx][yy][zz] = get(x, y, z - 1) + get(x, y - 1, z - 1) - get(x, y - 1, z);
    return d[xx][yy][zz] = get(x - 1, y, z) + get(x - 1, y - 1, z) + get(x - 1, y, z - 1) - get(x - 1, y - 1, z - 1);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (1)
    {
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
            break;

        printf("w(%d, %d, %d) = %lld\n", a, b, c, get(a, b, c));
    }

    return 0;
}