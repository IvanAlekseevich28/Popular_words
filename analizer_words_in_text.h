#ifndef ANALIZER_WORS_IN_TEXT_H
#define ANALIZER_WORS_IN_TEXT_H

#define orientation left

#include <map>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>


using namespace std;

typedef unsigned long long ull;
enum mod {path, console};

class analizer_words_in_text
{

    struct info
    {
        unsigned applying;
        bool isName;
    };

    string path_input;                      //paths input/output
    string path_output;

    string buffer;                          //for small books

    map<string, info> list_of_words;        //binari tree

    ull count_all_words;                    //Info about all words
    static unsigned MAX_WIDTH;

    bool is_capital_letter(char);
    bool is_letter(char);
    bool is_word(string);

    void prepare_the_text(string, mod = path);
    void make_collection();
    void addWord(string);
    void printWord(const pair<string, info> &);

    string small_word_maker(string&);


public:
    analizer_words_in_text(string, mod = path);
    analizer_words_in_text();
};

#endif // ANALIZER_WORS_IN_TEXT_H
