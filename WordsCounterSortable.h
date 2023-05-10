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
   * Method to sort counts and words
   */
  void sort() {
    for (auto count_and_word_iter = count_by_word_.cbegin();
         count_and_word_iter != count_by_word_.cend();
         /**/) {
      sorted_words_by_sorted_count_[count_and_word_iter->second].emplace(
          count_and_word_iter->first);

      // not to double up the memory consumption
      count_and_word_iter = count_by_word_.erase(count_and_word_iter);
    }
  }

protected:
  std::map<int, std::set<std::string, WordsSorterT>, CountsSorterT>
      sorted_words_by_sorted_count_;
};

#endif // WORDSCOUNTER_WORDSCOUNTERSORTABLE_H
