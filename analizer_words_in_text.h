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
enum mod  {path, console};
enum mod2 {alphabetically,
           by_popularity};
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

    map<string, info> list_of_words;        //binari trees
    multimap<unsigned, string> sort_list;

    ull count_all_words;                    //Info about all words
    static unsigned MAX_WIDTH;

    bool is_capital_letter(char);
    bool is_letter(char);
    bool is_word(string);
    bool is_roman_numerals(string);


    void prepare_the_text(string, mod = path);
    void make_collection();
    void make_sort_collection_by_pop();
    void addWord(string);
    void printWord(const pair<string, info> &);
    void printPopWord(const pair<unsigned, string> &);
    void printTextInfo(mod2 = alphabetically);


    string small_word_maker(string&);


public:
    analizer_words_in_text(string, mod = path, mod2 = by_popularity);
    analizer_words_in_text();
    ~analizer_words_in_text();
};

#endif // ANALIZER_WORS_IN_TEXT_H
