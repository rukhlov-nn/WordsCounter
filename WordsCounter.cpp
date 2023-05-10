#include <iostream>

#include "Format.h"
#include "WordsCounter.h"

void WordsCounter::consider(const std::string &new_word) {
  if (new_word.empty()) {
    std::cout << "Empty words could not be taken into consideration!"
              << std::endl;
    return;
  }

  std::string new_word_formatted = new_word;
  Format::to_lower(new_word_formatted);
  ++count_by_word_[std::move(new_word_formatted)];
}
