#include <iostream>
#include "wordstatistics.h"
#include <string>

using namespace std;

int main()
{
    string wd = "Pop";
    string wd1 = "highway";
    string wd2 = "aplication";
    string wd3 = "Ivan";

//    {
//        word A(wd);
//        word B9(wd1,2);
//        A.printWord();
//        B.printWord();
//    }

    cout << "\n\n\n";
    wordStatistics C(wd);
    wordStatistics D(wd3,99998);
    C.printWord();
    D.printWord();
    //cout << "Hello World!" << endl;
    return 0;
}
