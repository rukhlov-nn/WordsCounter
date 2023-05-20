cmake_minimum_required(VERSION 3.21)
project(WordsCounter)

set(CMAKE_CXX_STANDARD 17)

set(BUILD_ONLY_TESTS OFF)
if (BUILD_ONLY_TESTS)
    # in order for this to work it is necessary to have link to doctest dir
    # in project folder ( should be like WordsCounter/doctest)
    # Doctest is from https://github.com/doctest/doctest.git
    message("Cmake is configured to build tests only!")
    add_compile_definitions(DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
    include_directories(doctest)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0") # for debug
else ()
    message("Cmake is configured for regular build!")
    add_compile_definitions(DOCTEST_CONFIG_DISABLE) # just in case
endif ()

add_executable(WordsCounter
        WordsCounter.h WordsCounter.cpp
        WordsFileReader.h WordsFileReader.cpp
        Format.h Format.cpp
        main.cpp

        tests/Tests.cpp
        WordsCounterSortable.h WordsCounterSortedFlushable.h WordsStreamReaderImpl.h)
