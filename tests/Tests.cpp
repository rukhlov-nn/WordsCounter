#ifdef DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest/doctest.h"

#include "../Format.h"
#include "../WordsCounterFlashableSortedBy.h"
#include "../WordsStreamReaderImpl.h"

TEST_CASE("Business logic") {
  const std::vector<std::pair<std::string, std::string>> in_out = {
      {"", ""},
      {"           ", ""},
      {"a", "1 a\n"},
      {" a ", "1 a\n"},
      {"A a", "2 a\n"},
      {" b a C zz", "1 a\n1 b\n1 c\n1 zz\n"},
      {" b zZ a B Zz d C zz", "3 zz\n2 b\n1 a\n1 c\n1 d\n"},
      {"* / abc/DEF   \\  gHi . __ \n BcD!@#$%^&*()_+=-?/\'\";:№?|<>[]{}ghi ",
       "2 ghi\n1 abc\n1 bcd\n1 def\n"}};

  for (const auto &[in, out] : in_out) {
    std::istringstream ss_read(in);

    const auto is_separator = [](const char ch) { return !std::isalpha(ch); };

    WordsCounterFlashableSortedBy<std::less<>, std::greater<>> words_counter;
    while (true) {
      auto next_word = WordsStreamReaderImpl::nextWord(ss_read, is_separator);
      if (next_word.empty()) {
        break;
      }
      Format::to_lower(next_word);
      words_counter.consider(next_word);
    }

    std::ostringstream ss_write;
    words_counter.flushTo(ss_write, Format::count_space_word);

    CHECK_EQ(ss_write.str(), out);
  }
}

#endif
