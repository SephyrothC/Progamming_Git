#include <iostream>
#include <map>
#include <random>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

// A function to search for duplicated words in a string
void string_search() {

  // create a map to store the words and their counts
  map<string, int> word_count;

  // create a string to store the input
  string word;
  // create a string to store the previous word
  string last_word;

  // create variables to store the most duplicated word and its count
  string most_duplicated_word;
  int most_duplicated_count = 0;
  // create a variable to store the current repetition count
  int iterator_count = 1;

  // read words from standard input until an empty line (ctrl+Z)
  while (cin >> word) {
    // if the current word is equal to the previous word, increment the
    // repetition count
    if (word == last_word) {
      iterator_count += 1;
    }
    // else if the previous word is not empty and has a higher repetition count
    // than its previous value in the map, update the map
    else if (!last_word.empty() && word_count[last_word] < iterator_count) {
      word_count[last_word] = iterator_count;
      // check if the previous word has a higher count than the current most
      // duplicated word
      if (word_count[last_word] > most_duplicated_count) {
        // update the most duplicated word and its count
        most_duplicated_word = last_word;
        most_duplicated_count = word_count[last_word];
      }

      // reset the repetition count to 1
      iterator_count = 1;
    }
    // else just reset the repetition count to 1
    else {
      iterator_count = 1;
    }
    // update the previous word with the current word
    last_word = word;

    // clear the current word for the next iteration
    word.clear();
  }

  // print the result
  if (most_duplicated_count == 0) {
    cout << "No word was repeated.\n";
  } else {
    cout << "The most duplicated word is " << most_duplicated_word
         << ", which occurred " << most_duplicated_count << " times.\n";
  }
}

vector<unsigned int> pass_or_fail(int size, int score_to_pass) {

  // Generate a random engine with a seed (current time)
  default_random_engine random_engine(time(nullptr));
  // Generate a uniform distribution from 0 to 100
  uniform_int_distribution<unsigned int> score_range(0, 100);

  vector<unsigned int> vec;

  bool *pass = (bool *)calloc(size, sizeof(bool));

  for (int i = 0; i < size; i++) {
    unsigned int score = score_range(random_engine);
    cout << "the score of student #" << i << " is " << score << endl;
    vec.push_back(score);

    if (score >= score_to_pass)
      pass[i] = true;
    else
      pass[i] = false;
  }

  for (int i = 0; i < size; i++) {
    cout << "Student #" << i << ":";
    if (pass[i] == true)
      cout << "passed" << endl;
    else
      cout << "failed" << endl;
  }

  return vec;
}

int main(int argc, const char **argv) {

  // string_search();

  pass_or_fail(30, 60);

  return 0;
}