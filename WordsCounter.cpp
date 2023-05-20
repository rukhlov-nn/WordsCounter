#include <iostream>

#include "Format.h"
#include "WordsCounter.h"

void WordsCounter::consider(std::string &&new_word) {
  if (new_word.empty()) {
    std::cout << "Empty words could not be taken into consideration!"
              << std::endl;
    return;
  }

  ++count_by_word_[std::move(new_word)];
}
