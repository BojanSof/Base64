# Base64 Encoder and Decoder
## How to use
Simply, copy base64.hpp and base64.cpp in your project's directory and include base64.hpp.
To encode a std::string in base64 use Base64Encode(std::string str).
To decode a base64 encoded std::string use Base64Decode(std::string str).
## Simple Program
```cpp
#include <iostream>
#include "base64.hpp"

int main()
{
    std::string str;
    std::cout << "Enter string to encode to base64: ";
    std::cin >> str;
    std::string b64 = Base64Encode(str);
    std::cout << "Base64: " << b64 << std::endl;
    std::cout<<"Now decoding: "<<Base64Decode(b64)<<std::endl;
    return 0;
}
```

