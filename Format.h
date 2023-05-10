#ifndef WORDSCOUNTER_FORMAT_H
#define WORDSCOUNTER_FORMAT_H

#include <functional>
#include <string>

namespace Format {
void to_lower(std::string &str);
std::string count_space_word(const std::string &word, int count);
}; // namespace Format

#endif // WORDSCOUNTER_FORMAT_H
