#ifndef WORDSCOUNTER_WORDSCOUNTERSORTABLE_H
#define WORDSCOUNTER_WORDSCOUNTERSORTABLE_H

#include <map>
#include <set>

#include "WordsCounter.h"

/**
 * Class that can sort red words and their counts
 */
class WordsCounterSortable : public WordsCounter {
public:
  /**
   * Method to get sorted counts and words
   * @return sorted container of counts and words
   */
  template <typename WordsSorterT, typename CountsSorterT>
  std::vector<std::pair<std::string_view, int>>
  getSorted(WordsSorterT words_sorter, CountsSorterT counts_sorter) {
    std::vector<std::pair<std::string_view, int>> sorted_words_and_counts{
        count_by_word_.cbegin(), count_by_word_.cend()};
    std::sort(sorted_words_and_counts.begin(), sorted_words_and_counts.end(),
              [&](auto a, auto b) {
                if (a.second != b.second) {
                  return counts_sorter(a.second, b.second);
                }
                return words_sorter(a.first, b.first);
              });

    return sorted_words_and_counts;
  }
};

#endif // WORDSCOUNTER_WORDSCOUNTERSORTABLE_H
