#include "figure_in_space.h"
using namespace std;
int main()
{
    half_piramide h;
    cout << "half piramide" << endl;
    cout <<"V:"<< h.volume()<<endl<<"Full square:"<<h.full_square()<<endl;
    piramide pir(2.5, { 1, 2, 1.5, 3, 3, 3 });
    cout << "piramide" << endl;
    cout << "V:" << pir.volume() << endl << "Full square:" << pir.full_square()<<endl;
    prisma pr(2.5, { 1, 2, 1.5, 3 });
    cout << "prisma" << endl;
    cout << "V:" << pr.volume() << endl << "Full square:" << pr.full_square()<<endl;
}
