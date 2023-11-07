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

void biggies(vector<string> &words, vector<string>::size_type sz, int option) {
  elimDups(words); // put words in alphabetical order and remove duplicates

  // sort words by size, but maintain alphabetical order for words of the same
  // size
  stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {
    return a.size() < b.size();
  });

  switch (option) {

  case 1: {
    auto wc = find_if(words.begin(), words.end(),
                      [sz](const string &a) { return a.size() >= sz; });
    // compute the number of elements with size >= sz
    auto count = wc - words.begin();
    cout << count << " " << make_plural(count, "word", "s") << " of length "
         << sz << " or longer" << endl;

    // print words of the given size or longer, each one followed by a space
    for_each(words.begin(), wc, [](const string &s) { cout << s << " "; });
    cout << endl;
    break;
  }

  case 2: {
    auto wc = partition(words.begin(), words.end(),
                        [sz](const string &a) { return a.size() >= sz; });
    // compute the number of elements with size >= sz
    auto count = wc - words.begin();
    cout << count << " " << make_plural(count, "word", "s") << " of length "
         << sz << " or longer" << endl;

    // print words of the given size or longer, each one followed by a space
    for_each(words.begin(), wc, [](const string &s) { cout << s << " "; });
    cout << endl;
    break;
  }

  case 3: {
    auto wc =
        stable_partition(words.begin(), words.end(),
                         [sz](const string &a) { return a.size() >= sz; });
    // compute the number of elements with size >= sz
    auto count = wc - words.begin();
    cout << count << " " << make_plural(count, "word", "s") << " of length "
         << sz << " or longer" << endl;

    // print words of the given size or longer, each one followed by a space
    for_each(words.begin(), wc, [](const string &s) { cout << s << " "; });
    cout << endl;
    break;
  }

  default:
    break;
  }
}

void SixCounter(vector<string> &words) {
  // Use count_if to count the number of words with more than 6 characters
  int count = std::count_if(words.begin(), words.end(),
                            [](const string &word) { return word.size() > 6; });

  std::cout << "Number of words with more than 6 characters: " << count
            << std::endl;
}

int main(int argc, const char **argv) {
  // Initialiser un vecteur de chaînes de caractères
  vector<string> words = {"le",     "temps",  "est", "un",      "grand",
                          "maitre", "dit-on", "le",  "malheur", "est",
                          "qu'il",  "tue",    "ses", "eleves"};

  // Appeler la fonction biggies
  biggies(words, 5, 1);

  SixCounter(words);

  return 0;
}