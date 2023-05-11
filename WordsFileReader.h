#ifndef WORDSCOUNTER_WORDSFILEREADER_H
#define WORDSCOUNTER_WORDSFILEREADER_H

#include <fstream>
#include <memory>

#include "WordsStreamReaderImpl.h"

/**
 * Specialization of stream reader through file namely
 */
class WordsFileReader : WordsStreamReaderImpl {
  template <typename T, typename... Args>
  friend inline typename std::_MakeUniq<T>::__single_object
  std::make_unique(Args &&...);

public:
  /**
   * Fabric method for a reader
   * @param input_file - name of an input file
   * @param is_separator - method to check whether provided char could be
   * considered a separator
   * @return reader object
   */
  static std::unique_ptr<WordsFileReader>
  create(const std::string &input_file,
         const std::function<bool(char)> &is_separator);

  /**
   * Wrapper around the implementation, see parent class
   * @return
   */
  std::string nextWord();

private:
  WordsFileReader(
      const std::string &input_file,
      const std::function<bool(char)> &is_separator) noexcept(false);

  std::ifstream file_;
  const std::function<bool(char)> is_separator_;
};

#endif // WORDSCOUNTER_WORDSFILEREADER_H
