#ifndef WORDSTATISTICS_H
#define WORDSTATISTICS_H
#include "word.h"

class wordStatistics : public word
{
private:
    float procent_of_using;
    static unsigned number_all_words;
    unsigned number_of_vowels;
    void make_procent();
protected:


public:
    wordStatistics(string wd0, unsigned appluing = 0);
    void print_word();
    float getProcent_of_using() {return this->procent_of_using;}
    static unsigned counter_of_vowels(string);
    static bool isVowel(char);
    void printWord();
    ~wordStatistics();
};

#endif // WORDSTATISTICS_H
