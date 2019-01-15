#ifndef WORD_H
#define WORD_H
#define orientation left

#include <string>
#include <ctype.h>
#include <iostream>
#include <iomanip>


using namespace std;

class word
{
private:
    string wd;
    string Wd;
    string WD;
    unsigned applying;
    bool isName;
    static unsigned MAX_WIDTH;
protected:
    char lowerHigherConverter(char);
    char higherLowerConverter(char);
    const static char arrHIGH[27];
    const static char arrLOW[27];
public:
    word(string &, unsigned applying = 0);

    unsigned getApplying() {return applying;}
    void printFullWord();
    bool addApplying(string);
    void printWord();


    bool operator > (word &);
    bool operator < (word &);
    bool operator == (word &);
    bool operator == (string);
    bool operator != (word &);
    bool operator != (string);
    word operator ++ ()    {return word (this->wd, ++applying);}
    word operator ++ (int) {return word (this->wd, applying++);}

    static bool isWord(string);


};

#endif // WORD_H
