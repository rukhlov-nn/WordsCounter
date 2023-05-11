#include <filesystem>
#include <iostream>
#include <list>

#include "WordsFileReader.h"

WordsFileReader::WordsFileReader(
    const std::string &input_file,
    const std::function<bool(char)> &is_separator) noexcept(false)
    : file_(input_file), is_separator_(is_separator) {
  if (!std::filesystem::exists(input_file)) {
    std::cout << "Input file:" << input_file << " does not exist!" << std::endl;
    throw std::exception();
  } else if (!file_.good()) {
    std::cout << "Unable to open input file:" << input_file << '!' << std::endl;
    throw std::exception();
  }
}

std::unique_ptr<WordsFileReader>
WordsFileReader::create(const std::string &input_file,
                        const std::function<bool(char)> &is_separator) {
  std::unique_ptr<WordsFileReader> words_file_reader;
  try {
    words_file_reader =
        std::make_unique<WordsFileReader>(input_file, is_separator);
  } catch (...) {
    std::cout << "File reading is unavailable!" << std::endl;
  }
  return words_file_reader;
}

std::optional<std::string> WordsFileReader::nextWord() {
  return WordsStreamReaderImpl::nextWord(file_, is_separator_);
}
