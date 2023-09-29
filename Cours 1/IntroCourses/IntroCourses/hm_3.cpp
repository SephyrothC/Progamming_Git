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

// A function that generates random scores for a given number of students and
// displays their pass/fail status
void pass_or_fail(int size, int score_to_pass) {

  // Generate a random engine with a seed (current time)
  default_random_engine random_engine(time(nullptr));
  // Generate a uniform distribution from 0 to 100
  uniform_int_distribution<unsigned int> score_range(0, 100);

  // Create a dynamic array of bools to store the pass/fail status of each
  // student as booleans
  bool *pass = (bool *)calloc(size, sizeof(bool));

  // Loop through the students and generate their scores
  for (int i = 0; i < size; i++) {
    // Generate a random score using the random engine and the distribution
    unsigned int score = score_range(random_engine);
    // Check if the score is greater than or equal to the score to pass
    if (score >= score_to_pass)
      // Set the corresponding element in the bool array to true (pass)
      pass[i] = true;
    else
      // Set the corresponding element in the bool array to false (fail)
      pass[i] = false;
  }

  // Loop through the students and display their pass/fail status
  for (int i = 0; i < size; i++) {
    // Print the student number
    cout << "Student #" << i << ":";
    // Get the corresponding element from the bool array
    if (pass[i] == true)
      // Print "passed" if true
      cout << "passed" << endl;
    else
      // Print "failed" if false
      cout << "failed" << endl;
  }
}

int main(int argc, const char **argv) {

  cout << "Q26 :" << endl;
  string_search();

  cout << "Q31 :" << endl;
  pass_or_fail(30, 60);

  return 0;
}