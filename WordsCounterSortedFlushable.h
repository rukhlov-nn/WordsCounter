#ifndef WORDSCOUNTER_WORDSCOUNTERSORTEDFLUSHABLE_H
#define WORDSCOUNTER_WORDSCOUNTERSORTEDFLUSHABLE_H

#include <functional>

#include "WordsCounterSortable.h"

/**
 * Template class that can flush sorted words and counts
 * @tparam WordsSorterT - sorting type for words
 * @tparam CountsSorterT - sorting type for counts
 */
//template <typename WordsSorterT, typename CountsSorterT>
class WordsCounterSortedFlushable : public WordsCounterSortable {
public:
  /**
   * Method to flush sorted words and counts into a stream
   * @tparam StreamT - output stream type
   * @param stream - output stream
   * @param get_formatted_line - formatting function for single output line
   */
  template <typename StreamT, typename WordsSotrerT, typename CountsSorterT>
  void flushTo(
      StreamT &stream, WordsSotrerT words_sorter, CountsSorterT counts_sorter,
      const std::function<std::string(std::string_view, int)> &get_formatted_line) {
    const auto sorted_words_by_sorted_count =
        WordsCounterSortable::getSorted(words_sorter, counts_sorter);
    for (const auto &[word, count] : sorted_words_by_sorted_count) {
      stream << get_formatted_line(word, count) << '\n';
    }
  }
};

#endif // WORDSCOUNTER_WORDSCOUNTERSORTEDFLUSHABLE_H
