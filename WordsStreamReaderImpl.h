#ifndef WORDSCOUNTER_WORDSSTREAMREADERIMPL_H
#define WORDSCOUNTER_WORDSSTREAMREADERIMPL_H

#include <functional>
#include <ios>
#include <list>
#include <string>

/**
 * Class with implementation if reading words from a stream
 */
class WordsStreamReaderImpl {
public:
  /**
   * Method to get next word from stream
   * @tparam StreamT - type of a stream to get word from
   * @param stream - of a stream to get word from
   * @param is_separator - method to check whether provided char could be considered a separator
   * @return next word string
   */
  template <typename StreamT>
  static std::string nextWord(StreamT &stream,
                              const std::function<bool(char)> &is_separator) {
    stream >> std::noskipws;

    std::string result;
    std::list<char> chars_for_result;

    char ch;

    while (stream >> ch) {
      if (!is_separator(ch)) {
        stream.unget();
        break;
      }
    }

    while (stream >> ch) {
      if (!is_separator(ch)) {
        chars_for_result.emplace_back(ch);
        continue;
      }

      break;
    }

    while (stream >> ch) {
      if (!is_separator(ch)) {
        stream.unget();
        break;
      }
    }

    result.reserve(chars_for_result.size());
    for (const char ch : chars_for_result) {
      result.push_back(ch);
    }

    return result;
  }
};

#endif // WORDSCOUNTER_WORDSSTREAMREADERIMPL_H
