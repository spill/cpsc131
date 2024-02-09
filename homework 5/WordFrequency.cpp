///////////////////////// TO-DO (1) //////////////////////////////
  /// Include necessary header files
  /// Hint:  Include what you use, use what you include
  ///
  /// Do not put anything else in this section, i.e. comments, classes, functions, etc.  Only #include directives
#include <string>
#include <unordered_map>
#include <istream>
#include <locale>

#include "WordFrequency.hpp"
/////////////////////// END-TO-DO (1) ////////////////////////////







// unnamed, anonymous namespace providing non-member private working area
namespace
{
  std::string sanitize( const std::string & word )
  {
    constexpr char bad_char[] = " \t\n\b\v_-\"'(){}+/*,=.!?:;";            // leading and trailing characters to be removed
    static std::locale locality;

    auto startIndex = word.find_first_not_of( bad_char );                  // start with the first non-bad character
    if( startIndex == std::string::npos ) startIndex = word.size();        // if the word contains only bad characters ...

    std::size_t count    = 0;                                              // assume the word contains only bad characters ...
    auto        endIndex = word.find_last_not_of( bad_char );              // end with the first non-bad character

    if( endIndex != std::string::npos ) count = endIndex - startIndex + 1; // number of characters to use in results

    auto result = word.substr( startIndex, count );                        // strip the leading and trailing bad characters
    for( auto & c : result ) c = std::tolower( c, locality );              // convert to lower case

    return result;
  }
}  // unnamed, anonymous namespace







// Implement WordFrequency::WordFrequency( std::istream ) - See requirements
///////////////////////// TO-DO (2) //////////////////////////////
WordFrequency::WordFrequency(std::istream& is) { 
    std::string word;
    while (is >> word) { // loop reads the words from the input stream individually
        auto sanitizedWord = sanitize(word);
        if (!sanitizedWord.empty()) { // for each input stream stream a sanitize(word) is called
            ++words[sanitizedWord]; // increments the count for the sanitized word
        }
    }
}
/////////////////////// END-TO-DO (2) ////////////////////////////







// Implement WordFrequency::numberOfWords() const - See requirements
///////////////////////// TO-DO (3) //////////////////////////////
size_t WordFrequency::numberOfWords() const { // numberOfWords implementation
    return words.size(); // returns the elements of the words in unordered map
}
/////////////////////// END-TO-DO (3) ////////////////////////////







// Implement WordFrequency::wordCount( const std::string & ) const - See requirements
///////////////////////// TO-DO (4) //////////////////////////////
size_t WordFrequency::wordCount(const std::string &word) const { // defines the method of wordCount
    auto sanitizedWord = sanitize(word); // calls the sanitize function
    auto it = words.find(sanitizedWord); // attempts to find the sanitized version of the word in the words unordered map
    if (it != words.end()) { // iterator it is not equal to words.end
        return it->second;
    }
    return 0;
}
/////////////////////// END-TO-DO (4) ////////////////////////////







// Implement WordFrequency::mostFrequentWord() const - See requirements
///////////////////////// TO-DO (5) //////////////////////////////
std::string WordFrequency::mostFrequentWord() const { // method named mostFrequentWord
    if (words.empty()) return "";

    auto mostFrequent = words.begin();// checks if the words map is empty
    for (auto it = words.begin(); it != words.end(); ++it) {
        if (it->second > mostFrequent->second) { // checks is the current word is greater than the frequency of the word
            mostFrequent = it;
        }
    }
    return mostFrequent->first; // after completing iteration returns th word pointed to the mostFrequent iterator
}
/////////////////////// END-TO-DO (5) ////////////////////////////







// Implement WordFrequency::maxBucketSize() const - See requirements
///////////////////////// TO-DO (6) //////////////////////////////
  /// Hint: see the unordered_map's bucket interface at https://en.cppreference.com/w/cpp/container/unordered_map
  size_t WordFrequency::maxBucketSize() const { // initializes  maxBucketSize
    size_t maxSize = 0;
    for (size_t i = 0; i < words.bucket_count(); ++i) {
        maxSize = std::max(maxSize, words.bucket_size(i));
    }
    return maxSize;
}
/////////////////////// END-TO-DO (6) ////////////////////////////
