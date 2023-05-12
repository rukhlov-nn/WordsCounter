#ifndef WORDSCOUNTER_WORDSCOUNTERFLASHABLESORTEDBY_H
#define WORDSCOUNTER_WORDSCOUNTERFLASHABLESORTEDBY_H

#include <functional>

#include "WordsCounterSortable.h"

/**
 * Template class that can flush sorted words and counts
 * @tparam WordsSorterT - sorting type for words
 * @tparam CountsSorterT - sorting type for counts
 */
template <typename WordsSorterT, typename CountsSorterT>
class WordsCounterFlashableSortedBy
    : public WordsCounterSortableBy<WordsSorterT, CountsSorterT> {
  using SortableBase = WordsCounterSortableBy<WordsSorterT, CountsSorterT>;

public:
  /**
   * Method to flush sorted words and counts into a stream
   * @tparam StreamT - output stream type
   * @param stream - output stream
   * @param formatted_line - formatting function for single output line
   */
  template <typename StreamT>
  void flushTo(StreamT &stream,
               const std::function<std::string(const std::string &, int)>
                   &formatted_line) {
    const auto sorted_words_by_sorted_count = SortableBase::getSorted();
    for (const auto &[count, words] : sorted_words_by_sorted_count) {
      for (const auto &word : words) {
        stream << formatted_line(word, count) << '\n';
      }
    }
  }
};

#endif // WORDSCOUNTER_WORDSCOUNTERFLASHABLESORTEDBY_H
