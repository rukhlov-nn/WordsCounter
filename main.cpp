#ifndef DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <filesystem>
#include <iostream>

#include "Format.h"
#include "WordsCounterSortedFlushable.h"
#include "WordsFileReader.h"

int main(int argc, char *argv[]) {
  // check and prepare args
  constexpr static int expected_parameters_count = 3;
  if (argc != expected_parameters_count) {
    std::cout << "Wrong parameters count:" << argc << '!' << std::endl;
    std::cout << argv[0] << ": usage: " << argv[0]
              << " [input file] [output file]" << std::endl;
    exit(1);
  }
  const std::string &input_file = argv[1];
  const std::string &output_file = argv[2];

  // prepare to read the input file
  auto words_file_reader = WordsFileReader::create(
      input_file, [](char ch) { return !std::isalpha(ch); });
  if (!words_file_reader) {
    exit(1);
  }

  // read input file while counting words
  WordsCounterSortedFlushable words_counter;
  while (true) {
    auto next_word = words_file_reader->nextWord();
    if (!next_word) {
      break;
    }
    Format::to_lower(*next_word);
    words_counter.consider(std::move(*next_word));
  }

  // save results of counting
  std::filesystem::remove(output_file);
  std::ofstream output_file_stream(output_file);
  const auto words_sorter = std::less<>{};
  const auto counts_sorter = std::greater<>{};
  words_counter.flushTo(output_file_stream, words_sorter, counts_sorter,
                        Format::count_space_word);

  return 0;
}

#endif
