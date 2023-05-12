#ifndef WORDSCOUNTER_WORDSCOUNTERSORTABLE_H
#define WORDSCOUNTER_WORDSCOUNTERSORTABLE_H

#include <map>
#include <set>

#include "WordsCounter.h"

/**
 * Template class that can sort red words and their counts
 * @tparam WordsSorterT - sorting type for words
 * @tparam CountsSorterT - sorting type for counts
 */
template <typename WordsSorterT, typename CountsSorterT>
class WordsCounterSortableBy : public WordsCounter {
public:
  /**
   * Method to get sorted counts and words
   * @return sorted container of counts and words
   */
  std::map<int, std::set<std::string, WordsSorterT>, CountsSorterT>
  getSorted() {
    std::map<int, std::set<std::string, WordsSorterT>, CountsSorterT>
        sorted_words_by_sorted_count;
    for (auto count_and_word_iter = count_by_word_.cbegin();
         count_and_word_iter != count_by_word_.cend(); ++count_and_word_iter) {
      sorted_words_by_sorted_count[count_and_word_iter->second].emplace(
          count_and_word_iter->first);
    }
    return sorted_words_by_sorted_count;
  }
};

#endif // WORDSCOUNTER_WORDSCOUNTERSORTABLE_H
