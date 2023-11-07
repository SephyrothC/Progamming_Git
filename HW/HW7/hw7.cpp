#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to eliminate duplicates in a vector
void elimDups(vector<string> &words) {
  sort(words.begin(), words.end());
  auto end_unique = unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
}

// Function to return plural form of a word
string make_plural(size_t ctr, const string &word, const string &ending) {
  return (ctr > 1) ? word + ending : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
  elimDups(words); // put words in alphabetical order and remove duplicates

  // sort words by size, but maintain alphabetical order for words of the same
  // size
  stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {
    return a.size() < b.size();
  });

  // get an iterator to the first element whose size() is >= sz
  //   auto wc = find_if(words.begin(), words.end(),
  //                     [sz](const string &a) { return a.size() >= sz; });

  auto wc = partition(words.begin(), words.end(),
                      [sz](const string &a) { return a.size() >= sz; });

  // compute the number of elements with size >= sz
  auto count = words.end() - wc;
  cout << count << " " << make_plural(count, "word", "s") << " of length " << sz
       << " or longer" << endl;

  // print words of the given size or longer, each one followed by a space
  for_each(wc, words.end(), [](const string &s) { cout << s << " "; });
  cout << endl;
}

int main(int argc, const char **argv) {
  // Initialiser un vecteur de chaînes de caractères
  vector<string> words = {"le",     "temps",  "est", "un",      "grand",
                          "maître", "dit-on", "le",  "malheur", "est",
                          "qu'il",  "tue",    "ses", "élèves"};

  // Appeler la fonction biggies
  biggies(words, 5);

  return 0;
}