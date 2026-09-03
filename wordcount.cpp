// ECE 3574 Exercise: Word Count - starter code 

#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    std::ifstream file("mobydick.txt");

    if (!file) {

        std::cerr << "Could not open mobydick.txt" << std::endl;

        return EXIT_FAILURE;

    }
    std::unordered_map<std::string, int> counts;
    std::string word;

    // Convert each word to lowercase
    while (file >> word) {

        std::transform(word.begin(), word.end(), word.begin(),

                       [](unsigned char c) { return std::tolower(c); });

        counts[word]++;

    }

    // Copy words and counts into a vector for sorting
    std::vector<std::pair<std::string, int>> words(counts.begin(), counts.end());

    // Sort from most frequent to least frequent
    std::sort(words.begin(), words.end(),

              [](const std::pair<std::string, int>& a,

                 const std::pair<std::string, int>& b) {

                  return a.second > b.second;

              });

    // Print the 10 most frequent words
    for (int i = 0; i < 10 && i < static_cast<int>(words.size()); i++) {

        std::cout << i + 1 << ". " << words[i].first

                  << ": " << words[i].second << " times" << std::endl;

    }

    return EXIT_SUCCESS;
}
