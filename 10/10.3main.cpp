#include <iostream>
#include <vector>

using namespace std;

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

string make_plural(size_t count, const string &word, const string &ending)
{
    return (count==1) ? word : word + ending;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b){return a.size() < b.size();});
    for_each(words.begin(), words.end(), [](const string &s){cout << s << " ";});
    cout << endl;
    
    auto wc = find_if(words.begin(), words.end(), [sz](const string &a){return a.size() >= sz;});
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(), [](const string &s){cout << s << " ";});
    cout << endl;
}

int main(int argc, char** argv)
{
    vector<string> words{"weng", "zhi", "han"};
    vector<string>::size_type sz = 4;
    biggies(words, sz);
    return 1;
}
