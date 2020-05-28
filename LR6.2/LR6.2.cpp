#include "FindClass.h"
#include <ctime>
#include <iostream>
#include "LR6.2.h"
using namespace std;
int main()
{
    srand(time(NULL));
    vector < int > a = { 2019,3,2,1,2,3,4 };
    vector < int > b = { 2014,3,2,1,2,3,4 };
    vector < int > c = { 2018,3,2,9,2,3,4 };
    vector < int > d = { 2018,3,2,8,2,3,4 };
    vector < int > e = { 2018,3,2,7,2,3,4 };
    vector < int > j = { 2028,3,2,7,2,3,4 };
    vector<dateTime> x;
    x.push_back(dateTime(a));
    x.push_back(dateTime(b));
    x.push_back(dateTime(c));
    x.push_back(dateTime(d));
    x.push_back(dateTime(e));
    x.push_back(dateTime(j));

  
    //x[0] = x[3];
    FindClass<dateTime> test(x);
    for (int i = 0; i < 6; i++) {
        cout<<test[i].getDate() <<' '<<test[i].getTime()<<endl;
    }
    cout << test.findByValue(dateTime({1,2,3,4,5,6,7,8,9}));
    return 0;
}