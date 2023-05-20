#include <cctype>

#include "Format.h"

void Format::to_lower(std::string &str) {
  for (char &ch : str) {
    ch = static_cast<char>(std::tolower(ch));
  }
}

std::string Format::count_space_word(std::string_view word, int count) {
  return std::to_string(count) + ' ' + std::string(word);
}
