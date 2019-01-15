#include <iostream>
#include "word.h"
#include <string>

using namespace std;

int main()
{
    string wd = "Popular";
    string wd1 = "highway";

    word A(wd);

    A.printWord();
    word B(wd1,2);
    B.printWord();
    cout << "Hello World!" << endl;
    return 0;
}
