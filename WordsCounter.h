#ifndef WORDSCOUNTER_WORDSCOUNTER_H
#define WORDSCOUNTER_WORDSCOUNTER_H

#include <unordered_map>

/**
 * @class Class for counting words
 */
class WordsCounter {
public:
  /**
   * Absorb a new word into consideration
   * @param new_word - a word to consider
   */
  void consider(std::string &&new_word);

protected:
  std::unordered_map<std::string, int> count_by_word_;
};

#endif // WORDSCOUNTER_WORDSCOUNTER_H
