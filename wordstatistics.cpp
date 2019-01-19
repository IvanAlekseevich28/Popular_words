#include "wordstatistics.h"

unsigned wordStatistics::number_all_words = 0;

wordStatistics::wordStatistics(string wd0, unsigned appluing) : word(wd0, appluing)
{
    number_of_vowels = counter_of_vowels(wd0);
    number_all_words += 1 + appluing;
}

void wordStatistics::make_procent()
{
    this->procent_of_using = static_cast<float>(word::getApplying()) / number_all_words * 100;
}

unsigned wordStatistics::counter_of_vowels(string wd0)
{
    unsigned count = 0;
    for (unsigned i = 0; i < wd0.size(); i++)
    {
        if (isVowel(wd0[i])) count++;
    }
    return count;
}
bool wordStatistics::isVowel(char t)
{
    const char VowelsArray[13] = {"eyuioaEYUIOA"};
    for (unsigned i = 0; i < 12; i++)
        if (t == VowelsArray[i]) return true;
    return false;
}

void wordStatistics::printWord()
{
    make_procent();
    cout << setiosflags(ios::right) << setiosflags(ios::fixed) << setiosflags(ios::showpoint)
         << setprecision(3) << setw(7) << procent_of_using << "% ";
    word::printWord();

}

wordStatistics::~wordStatistics()
{
    //cout << "destructor" << endl;
    number_all_words = 0;
}
