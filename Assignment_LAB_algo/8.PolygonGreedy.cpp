#include<iostream>
#include<math.h>
#define ll long long
using namespace std;
class Point
{
    public:
        double x, y;
    public:
        Point(){}
        Point(double x, double y)
        {
            this -> x = x;
            this -> y = y;
        }
        void getPoint()
        {
            cin>>x>>y;
        }
        Point(Point& p)
        {
            x = p.x;
            y = p.y;
        }
        double operator -(Point& p)
        {
            return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
        }
        void display()
        {
            cout<<"("<<x<<", "<<y<<"), ";
        }
};
class Line
{
    public:
        Point x1, y1;
        double a, b, c, d;
    public:
        Line(){}
        Line(Line& L)
        {
            x1 = L.x1;
            y1 = L.y1;
            a = L.a;
            b = L.b;
            c = L.c;
            d = L.d;
        }
        void operator =(Line L)
        {
            x1 = L.x1;
            y1 = L.y1;
            a = L.a;
            b = L.b;
            c = L.c;
            d = L.d;
        }
        Line(Point a1, Point b1)
        {
            x1 = a1;
            y1 = b1;
            if(x1.x == y1.x)
            {
                a = 1;
                b = 0;
                c = -1 * x1.x;
            }
            else
            {
                b = 1;
                a = -1 * ((x1.y - y1.y) / (x1.x - y1.x));
                c = -1 * (a * x1.x + b * x1.y);
            }
            d = x1 - y1;
        }
        Line(double a, double b, double c)
        {
            this ->  a = a;
            this -> b = b;
            this -> c = c;
        }
        void setLine(Point a1, Point b1)
        {
            x1 = a1;
            y1 = b1;
            if(x1.x == y1.x)
            {
                a = 1;
                b = 0;
                c = -1 * x1.x;
            }
            else
            {
                b = 1;
                a = -1 * ((x1.y - y1.y) / (x1.x - y1.x));
                c = -1 * (a * x1.x + b * x1.y);
            }
            d = x1 - y1;
        }
        int notPossible(Line L)
        {
            double a1 = a * L.x1.x + b * L.x1.y + c;
            double b1 = a * L.y1.x + b * L.y1.y + c;
            if(a1 * b1 < 0)
                return 1;
            return 0;
        }
        void display()
        {
            cout<<"[";
            x1.display();
            y1.display();
            cout<<"\b\b]; ";
            cout<<"\n";
        }
};
Point* P;
Line* E;
Line* E2;
void allCombo(ll N)
{
    ll i, j, pos = 0, temp;
    for(i = 0; i < N - 1; i++)
    {
        for(j = i + 2; j < N; j++)
        {
            if(i == 0 && j == N - 1)
                continue;
            (E + pos) -> setLine(*(P + i), *(P + j));
            pos += 1;
        }
    }
    for(i = 0; i < N - 1; i++)
        (E2 + i) -> setLine(*(P + i), *(P + i + 1));
    (E2 + i) -> setLine(*(P + N - 1), *(P + 0));
    pos = (ll)(N * (N - 1) / 2) - N;
    for(i = 0; i < pos - 1; i++)
    {
        temp = i;
        for(j = i + 1; j < pos; j++)
        {
            if((E + j) -> d < (E + temp) -> d)
                temp = j;
        }
        Line t = *(E + temp);
        *(E + temp) = *(E + i);
        *(E + i) = t;
    }
}
Line* E1;
double getDiag(ll N)
{
    double sum = 0;
    ll c = 0, i = 0, test, j;
    while(c < N - 3)
    {
        test = 0;
        for(j = 0; j < c; j++)
        {
            if((E + i) -> notPossible(*(E1 + j)) == 1)
            {
                test = 1;
                break;
            }
        }
        if(test == 0)
        {
            *(E1 + c) = *(E + i);
            c += 1;
            sum += (E + i) -> d;
        }
        i += 1;
    }
    return sum;
}
double edgeSum(ll N)
{
    double sum = 0;
    ll i;
    for(i = 0; i < N - 1; i++)
        sum = sum + (*(P + i) - *(P + i + 1));
    sum = sum + (*(P + N - 1) - *(P + 0));
    return sum;
}
int main()
{
    ll i, j, N;
    cout<<"Enter the number of points : ";
    cin>>N;
    P = new Point[N];
    cout<<"Enter the points : ";
    for(i = 0; i < N; i++)
        (P + i) -> getPoint();
    E = new Line[(ll)(N * (N - 1) / 2) - N];
    E1 = new Line[N - 3];
    E2 = new Line[N];
    allCombo(N);
    cout<<"Minimum perimeter is : "<<2*getDiag(N) + edgeSum(N)<<"\n";
    cout<<"The lines involved in the triangulation are : \n";
    for(i = 0; i < N - 3; i++)
       (E1 + i) -> display();
    for(i = 0; i < N; i++)
        (E2 + i) -> display();
    return 0;
}
/*
(0, 0), (2, 2), (5, 2), (7, 0), (3, -4), (2, -4)
*/
