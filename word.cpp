#include "word.h"

const char word::arrHIGH[27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
const char word::arrLOW[27] =  {"abcdefghijklmnopqrstuvwxyz"};

unsigned word::MAX_WIDTH = 1;

word::word(string &wd0, unsigned applying)
{
    if (!isWord(wd0)) throw;
        this->wd = wd0;
    for (unsigned i = 0; i < wd0.size(); i++)
        wd[i] = higherLowerConverter(wd0[i]);

    this->Wd = wd0;
    Wd[0] = lowerHigherConverter(Wd[0]);
    for (unsigned i = 1; i < wd0.size(); i++)
        Wd[i] = higherLowerConverter(wd[i]);

    this->WD = wd0;
    for (unsigned i = 0; i < wd0.size(); i++)
        this->WD[i] = lowerHigherConverter(wd0[i]);

    isName = true;
    this->applying = applying;
    this->applying++;

    if (wd0.size() > MAX_WIDTH) MAX_WIDTH = wd0.size();
}

char word::higherLowerConverter(char sym)
{
    if (static_cast<int>(sym) > 96 and static_cast<int>(sym) < 123) return sym;
    if (static_cast<int>(sym) > 64 and static_cast<int>(sym) < 91)
    return static_cast<char>(static_cast<int>(sym) + 32);
    return false;
}

char word::lowerHigherConverter(char sym)
{
    if (static_cast<int>(sym) > 64 and static_cast<int>(sym) < 91) return sym;
    if (static_cast<int>(sym) > 96 and static_cast<int>(sym) < 123)
    return static_cast<char>(static_cast<int>(sym) - 32);
    return false;
}

void word::printFullWord()
{
    cout << wd << " - " << Wd << " - " << WD << "\t" << "applying: " << applying << endl;
}

bool word::addApplying(string wd0)
{
    if (*this == wd0)
    {
        if (islower(wd[0])) isName = 0;
        ++applying;
        return true;
    } else return false;
}

void word::printWord()
{
    if (isName) cout  << setiosflags(ios::orientation) << setw(static_cast<int>(MAX_WIDTH)) << Wd;
    else cout << setiosflags(ios::orientation) << setw(static_cast<int>(MAX_WIDTH)) << wd;
    cout << " - " << applying << endl;
}

bool word::operator<(word &other)
{
    if (this->wd < other.wd) return true;
    return false;
}

bool word::operator>(word &other)
{
    if (this->wd > other.wd) return true;
    return false;
}

bool word::operator==(word &other)
{
    if (this->wd == other.wd) return true;
    return false;
}

bool word::operator!=(word &other)
{
    if (this->wd != other.wd) return true;
    return false;
}

bool word::operator==(string wd0)
{
    word test(wd0);
    if (test == *this) return true;
    return false;
}

bool word::operator!=(string wd0)
{
    word test(wd0);
    if (test != *this) return true;
    return false;
}


bool word::isWord(string testee)
{
    bool flag = true;
    for (unsigned i = 0; i < testee.size(); i++)
    {
        if (testee[i] == '\0') continue;
        if (!((static_cast<int>(testee[i]) > 64 and static_cast<int>(testee[i]) < 91)
              or (static_cast<int>(testee[i]) > 96 and static_cast<int>(testee[i]) < 123)))
                flag = false;
    }

    return flag;
}
