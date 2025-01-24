#include "StringUtils.h"

// [ RUN      ] StringUtilsTest.SliceTest
// [       OK ] StringUtilsTest.SliceTest (0 ms)
// [ RUN      ] StringUtilsTest.Capitalize
// [       OK ] StringUtilsTest.Capitalize (0 ms)
// [ RUN      ] StringUtilsTest.Upper
// [       OK ] StringUtilsTest.Upper (0 ms)
// [ RUN      ] StringUtilsTest.Lower
// [       OK ] StringUtilsTest.Lower (0 ms)
// [ RUN      ] StringUtilsTest.LStrip
// [       OK ] StringUtilsTest.LStrip (0 ms)
// [ RUN      ] StringUtilsTest.RStrip
// [       OK ] StringUtilsTest.RStrip (0 ms)
// [ RUN      ] StringUtilsTest.Strip
// [       OK ] StringUtilsTest.Strip (0 ms)
// [ RUN      ] StringUtilsTest.Center
// [       OK ] StringUtilsTest.Center (0 ms)
// [ RUN      ] StringUtilsTest.LJust
// [       OK ] StringUtilsTest.LJust (0 ms)
// [ RUN      ] StringUtilsTest.RJust
// [       OK ] StringUtilsTest.RJust (0 ms)
// [ RUN      ] StringUtilsTest.Replace
// [       OK ] StringUtilsTest.Replace (0 ms)
// [ RUN      ] StringUtilsTest.Split
// [       OK ] StringUtilsTest.Split (0 ms)
// [ RUN      ] StringUtilsTest.Join
// [       OK ] StringUtilsTest.Join (0 ms)
// [ RUN      ] StringUtilsTest.ExpandTabs
// [       OK ] StringUtilsTest.ExpandTabs (0 ms)
// [ RUN      ] StringUtilsTest.EditDistance
// [       OK ] StringUtilsTest.EditDistance (0 ms)

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    // Replace code here
    return "";
}

std::string Capitalize(const std::string &str) noexcept{
    if (str.empty()) return str;
    std::string output = str;
    for (char& lowercase_char: output){
        lowercase_char = std::tolower(lowercase_char);
    }
    output[0] = std::toupper(output[0]);

    return output;
}

std::string Upper(const std::string &str) noexcept{
    std::string output = str;
    for (size_t i = 0; i < output.size(); i++){
        output[i] = std::toupper(static_cast<unsigned char>(output[i]));
    }
    return output;
}

std::string Lower(const std::string &str) noexcept{
    std::string output = str;
    for (size_t i = 0; i < output.size(); i++){
        output[i] = std::tolower(static_cast<unsigned char>(output[i]));
    }
    return output;
}

std::string LStrip(const std::string &str) noexcept{
    size_t start = 0;

    while (start < str.length() && std::isspace(static_cast<unsigned char>(str[start]))){
        start ++;
    }

    if (start == str.length()){
        return "";
    } else {
        return str.substr(start);
    }

}

std::string RStrip(const std::string &str) noexcept{
    size_t start = 0;
    size_t end = str.length();

    while (end > 0 && std::isspace(static_cast<unsigned char>(str[end - 1]))){
        end --;
    }

    if (start == str.length()){
        return "";
    } else {
        return str.substr(0, end);
    }
}

std::string Strip(const std::string &str) noexcept{
    return LStrip(RStrip(str));

}

std::string Center(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    if (str.length() >= width){
        return str;
    }

    int adding_size = width - str.length();
    std::string adding_char = "";
    for (int i = 0; i < adding_size; i++){
        adding_char += fill;
    }

    return str + adding_char;
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
        if (str.length() >= width){
        return str;
    }

    int adding_size = width - str.length();
    std::string adding_char = "";
    for (int i = 0; i < adding_size; i++){
        adding_char += fill;
    }

    return adding_char + str;
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    // Replace code here
    return "";
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    // Replace code here
    return {};
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    // Replace code here
    return "";
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    // Replace code here
    return "";
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

};