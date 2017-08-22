#ifndef BASE64_HPP
#define BASE64_HPP

#include <bitset>
#include <string>
#include <vector>

const std::string base64table("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");
const int base64index(char c);

std::string Base64Encode(const std::string& input);
std::string Base64Decode(const std::string& encodedInput);

#endif // BASE64_HPP
