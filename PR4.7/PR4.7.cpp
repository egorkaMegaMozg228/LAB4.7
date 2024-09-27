#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double xp, xk, x, dx, eps, a = 0, R = 0, S = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "----------------------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << setw(5) << " |"
        << setw(7) << "lg((1+x)/(1-x))" << "|"
        << setw(9) << "2*S" << setw(8) << " |"
        << setw(7) << "n" << setw(7) << " |"
        << endl;
    cout << "----------------------------------------------------------" << endl;

    x = xp;
    while (x <= xk) {
        if (abs(x) < 1 - eps) {
            n = 0;
            a = x;
            S = a;
            do {
                n++;
                R = (2. * n * pow(x, 2) - pow(x, 2)) / (2 * n + 1);
                a *= R;
                S += a;
            } while (abs(a) >= eps);

            cout << "|" << setw(7) << setprecision(2) << x << setw(3) << " |"
                << setw(11) << setprecision(5) << log((1 + x) / (1 - x)) << setw(5) << " |"
                << setw(10) << setprecision(5) << 2 * S << setw(7) << " |"
                << setw(7) << n << setw(7) << " |"
                << endl;
        }
        else {
            cout << "|" << setw(7) << setprecision(2) << x << setw(3) << " |"
                << setw(14) << "Out of range" << " |" <<
                setw(15) << "Out of range" << " |"
                << "Out of range" << " |"
                << endl;
        }
        x += dx;
    }
    cout << "----------------------------------------------------------" << endl;
    return 0;
}
