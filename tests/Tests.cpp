#ifdef DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest/doctest.h"

#include "../Format.h"
#include "../WordsCounterFlashableSortedBy.h"
#include "../WordsFileReader.h"

TEST_CASE("Format::to_lower") {
  std::string str = " 124 fasdAFSFfsa";
  const std::string expected = " 124 fasdafsffsa";

  Format::to_lower(str);
  CHECK_EQ(str, expected);
}

TEST_CASE("Format::count_space_word") {
  CHECK_EQ(Format::count_space_word("word", -1), "-1 word");
}

TEST_CASE("WordsStreamReaderImpl") {
  const std::string to_read = "* / abc/DEF   \\  gHi . *";
  std::istringstream ss(to_read);
  const auto is_separator = [](const char ch) { return !std::isalpha(ch); };

  CHECK_EQ(WordsStreamReaderImpl::nextWord(ss, is_separator), "abc");
  CHECK_EQ(WordsStreamReaderImpl::nextWord(ss, is_separator), "DEF");
  CHECK_EQ(WordsStreamReaderImpl::nextWord(ss, is_separator), "gHi");
  for (size_t i = 0; i < 5; ++i) {
    CHECK_EQ(WordsStreamReaderImpl::nextWord(ss, is_separator), "");
  }
}

TEST_CASE("WordsCounterFlashableSortedBy<std::greater<>>") {
  WordsCounterFlashableSortedBy<std::less<>, std::greater<>> words_counter;
  const std::set<std::string> words = {"abc", "cde", "AbC"};
  for (const auto &word : words) {
    words_counter.consider(word);
  }
  const std::string expected = "2 abc\n1 cde\n";
  std::stringstream sstream;

  words_counter.flushTo(sstream, Format::count_space_word);
  CHECK_EQ(sstream.str(), expected);
}

#endif
