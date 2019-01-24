#include "analizer_words_in_text.h"

unsigned analizer_words_in_text::MAX_WIDTH = 1;

analizer_words_in_text::analizer_words_in_text()
{
    do
    {
        cout << "Do you want to enter text into the console or specify the path?" << endl;
        cout << "Answer(path/console): ";
        string answer;
        cin >> answer;
        if (answer == "console")
        {
            cout << "Enter the text(for end press #): \n\n";
            string input;
            getline(cin, input, '#');
            cout << endl;
            prepare_the_text(input, console);
            break;
        }
        if (answer == "path")
        {
            cout << "Enter the path of input: ";
            getline(cin, path_input, '\r');
            prepare_the_text(path_input, path);
            break;
        }

    }while(true);

    do
    {
        cout << "Do you want to sort (by_popularity or alphabetically): ";
        string answer2;
        getline(cin, answer2, '\r');
        if (answer2 == "by_popularity")
        {
            cout << "\n\n\n\n";
            make_collection();
            make_sort_collection_by_pop();
            printTextInfo(by_popularity);
            break;
        } else if (answer2 == "alphabetically")
        {
            cout << "\n\n\n\n";
            make_collection();
            printTextInfo(alphabetically);
        }
    }while (true);
    path_output = "C:\\Users\\Ivan\\Documents\\Popular_words_v2_1\\save.txt";

}





analizer_words_in_text::analizer_words_in_text(string input, mod M, mod2 M2)
{
    prepare_the_text(input, M);
    make_collection();
    printTextInfo(M2);
    path_output = "C:\\Users\\Ivan\\Documents\\Popular_words_v2_1\\save.txt";

}

bool analizer_words_in_text::is_capital_letter(char s)
{
    int S = static_cast<int>(s);
    if (S > 64 and S < 91) return true;
    return false;

}

bool analizer_words_in_text::is_letter(char s)
{
    int S = static_cast<int>(s);
    S = static_cast<int>(s);
    if ((S > 64 and S < 91)
            or (S > 96 and S < 123)) return true;
    return false;
}

bool analizer_words_in_text::is_word(string wd0)
{
    for (char s : wd0)
        if (!is_letter(s) and s != '-') return false;
    return true;
}

bool analizer_words_in_text::is_roman_numerals(string num)
{
    num = small_word_maker(num);
    for (char s : num)
      if (!(s == 'i' or
            s == 'v' or
            s == 'x' or
            s == 'l' or
            s == 'c')) return false;
    return true;
}


void analizer_words_in_text::prepare_the_text(string path, mod M)
{
    buffer = "";
    char last_symbol = ' ';

   if (!M) {
        ifstream fin;

        fin.open(path);
        if (!(fin.is_open())) throw;
        char s;

        while (fin.get(s))
        {

            if (is_letter(s))
                buffer += s;
            else if ((s == '-') and is_letter(last_symbol))
                buffer += '-';
            else if ( (last_symbol != ' '))
                buffer += " ";
            last_symbol = s;
        }
        fin.close();
       // buffer += " ";
       // cout << buffer << "." << endl;
    }
   else
   {
       for (auto s : path)
       {
           if (is_letter(s))
               buffer += s;
           else if ((s == '-') and is_letter(last_symbol))
               buffer += '-';
           else if ((s == ' ' or s == '\r' or s == '\t')
                    and (last_symbol != ' '))
               buffer += ' ';
           last_symbol = s;
       }
   }
}

void analizer_words_in_text::make_collection()
{
    count_all_words = 0;
    string temp = "";
    for (unsigned i = 0; i < buffer.size(); i++)
    {

        if (buffer[i] != ' ')                           //We construct the word.
        {
            temp += buffer[i];
//            cout << "temp: "<< temp << endl;
        }
        else                                            //When the space, we are looking for a word in the collection.
        {
//            cout << "add word " << temp;
//            cout << endl;
            string temp4search = small_word_maker(temp);
            //cout << temp << endl;
            auto it = list_of_words.find(temp4search);
            if (it == list_of_words.end())              //If the search pointer points to the end of the tree,
            {if (is_word(temp) and !is_roman_numerals(temp)) addWord(temp); }                         //add the word to the collection.
            else
            {
                it->second.applying++;
                if (it->second.isName)
                it->second.isName = is_capital_letter(temp[0]);
            }
            count_all_words++;
            temp = "";
        }
    }
}

void analizer_words_in_text::make_sort_collection_by_pop()
{
    for (auto it : list_of_words)
    {
        pair<unsigned, string> pai;
        pai.first = it.second.applying;
        string Word = it.first;
        if (it.second.isName) Word[0] -= 32;
        pai.second = Word;
        sort_list.insert(pai);
    }
}

void analizer_words_in_text::addWord(string WD)
{

    string wd = small_word_maker(WD);
    info inf;
    inf.applying = 1;
    inf.isName = is_capital_letter(WD[0]);
    list_of_words.insert(make_pair(wd,inf));
     if (WD.size() > MAX_WIDTH) MAX_WIDTH = WD.size();
    // cout <<endl;
}

void analizer_words_in_text::printWord(const pair<string, info> &word)
{
    double procent = static_cast<double>(word.second.applying) / count_all_words * 100;
    cout << setiosflags(ios::right) << setiosflags(ios::fixed) << setiosflags(ios::showpoint)
         << setprecision(3) << setw(7) << procent << "% ";

    if(word.second.isName)
    {
        string temp = word.first;
        temp[0] -= 32;
        cout << setiosflags(ios::orientation) << setw(static_cast<int>(MAX_WIDTH))
             << temp << " - " << word.second.applying;
    }
    else
        cout << setiosflags(ios::orientation) << setw(static_cast<int>(MAX_WIDTH))
             << word.first << " - " << word.second.applying;
    cout << endl;
}

void analizer_words_in_text::printPopWord(const pair<unsigned, string> &word)
{
    double procent = static_cast<double>(word.first) / count_all_words * 100;
    cout << setiosflags(ios::right) << setiosflags(ios::fixed) << setiosflags(ios::showpoint)
         << setprecision(3) << setw(7) << procent << "% ";


        cout << setiosflags(ios::orientation) << setw(static_cast<int>(MAX_WIDTH))
             << word.second << " - " << word.first;
        cout << endl;

}

void analizer_words_in_text::printTextInfo(mod2 method)
{

    cout << "Number of words: " << count_all_words << endl;
    cout << "Number of diferent words: " << list_of_words.size() <<endl;
    if (method == alphabetically)
    {
        for (auto it : list_of_words)
            printWord(it);
    } else
    {
        make_sort_collection_by_pop();
        for (auto it : sort_list)
            printPopWord(it);
    }
    cout << "Number of words: " << count_all_words << endl;
    cout << "Number of diferent words: " << list_of_words.size() <<endl;
}


string analizer_words_in_text::small_word_maker(string &WD)
{
    string wd = WD;
    for (unsigned i = 0; i < WD.size(); i++)
        if (is_capital_letter(wd[i]))
            wd[i] += 32;

    return wd;
}

analizer_words_in_text::~analizer_words_in_text()
{
    do
    {
        cout <<"Do you want to save list of word? (yes / no / auto)" << endl;
        cout << "Answer: ";
        string answerSave;
        cin >> answerSave;
        if (answerSave == "no") break;
        if (answerSave == "yes" or answerSave == "auto")
        {
            if (answerSave == "yes") cout << "Enter path of save: ";
            fstream fout;

           if (answerSave == "yes") cin >> path_output;
           fout.open(path_output);
            if (!fout.is_open())
            {
                cout << "Error of open file!" << endl;
                continue;
            }
            for (auto word : sort_list)
            {
                double procent = static_cast<double>(word.first) / count_all_words * 100;
                fout << setiosflags(ios::right) << setiosflags(ios::fixed) << setiosflags(ios::showpoint)
                     << setprecision(3) << setw(7) << procent << "% ";


                    fout << setiosflags(ios::orientation) << setw(static_cast<int>(MAX_WIDTH))
                         << word.second << " - " << word.first;
                    fout << endl;
            }
            fout.close();
            cout << "File has been saved by path:" << endl;
            cout << path_output << endl;
            break;

        }
        break;
    } while (true);


}
