#include "base64.hpp"

std::string Base64Encode(const std::string& input){
    std::string encoded = "";
    std::string ASCIIbinary = "";
    for(size_t i = 0; i < input.length(); i++){
        ASCIIbinary += std::bitset<8>(int(input[i])).to_string();
    }
    while(ASCIIbinary.length() % 6 != 0){
        ASCIIbinary += "0";
    }
    size_t pos = 0;
    while(pos < ASCIIbinary.length()){
        std::string sub = ASCIIbinary.substr(pos, 6);
        encoded += base64table[int(std::bitset<6>(sub).to_ulong())];
        pos += 6;
    }
    while(encoded.length() % 4 != 0)
        encoded += "=";
    return encoded;
}

const int base64index(char c){
    switch(c){
        case 'A' : return 0; break;
        case 'B' : return 1; break;
        case 'C' : return 2; break;
        case 'D' : return 3; break;
        case 'E' : return 4; break;
        case 'F' : return 5; break;
        case 'G' : return 6; break;
        case 'H' : return 7; break;
        case 'I' : return 8; break;
        case 'J' : return 9; break;
        case 'K' : return 10; break;
        case 'L' : return 11; break;
        case 'M' : return 12; break;
        case 'N' : return 13; break;
        case 'O' : return 14; break;
        case 'P' : return 15; break;
        case 'Q' : return 16; break;
        case 'R' : return 17; break;
        case 'S' : return 18; break;
        case 'T' : return 19; break;
        case 'U' : return 20; break;
        case 'V' : return 21; break;
        case 'W' : return 22; break;
        case 'X' : return 23; break;
        case 'Y' : return 24; break;
        case 'Z' : return 25; break;
        case 'a' : return 26; break;
        case 'b' : return 27; break;
        case 'c' : return 28; break;
        case 'd' : return 29; break;
        case 'e' : return 30; break;
        case 'f' : return 31; break;
        case 'g' : return 32; break;
        case 'h' : return 33; break;
        case 'i' : return 34; break;
        case 'j' : return 35; break;
        case 'k' : return 36; break;
        case 'l' : return 37; break;
        case 'm' : return 38; break;
        case 'n' : return 39; break;
        case 'o' : return 40; break;
        case 'p' : return 41; break;
        case 'q' : return 42; break;
        case 'r' : return 43; break;
        case 's' : return 44; break;
        case 't' : return 45; break;
        case 'u' : return 46; break;
        case 'v' : return 47; break;
        case 'w' : return 48; break;
        case 'x' : return 49; break;
        case 'y' : return 50; break;
        case 'z' : return 51; break;
        case '0' : return 52; break;
        case '1' : return 53; break;
        case '2' : return 54; break;
        case '3' : return 55; break;
        case '4' : return 56; break;
        case '5' : return 57; break;
        case '6' : return 58; break;
        case '7' : return 59; break;
        case '8' : return 60; break;
        case '9' : return 61; break;
        case '+' : return 62; break;
        case '/' : return 63; break;
    }
    return -1; //default
}

std::string Base64Decode(const std::string& encodedInput){
    std::string decoded = "";
    std::string ASCIIbinary = "";
    int extrazeros = 0;
    if(encodedInput[encodedInput.length() - 1] == '=' && encodedInput[encodedInput.length() - 2] != '=' )
        extrazeros = 1;
    else if(encodedInput[encodedInput.length() - 2] == '=' )
        extrazeros = 2;

    for(size_t i = 0; i < encodedInput.length() - extrazeros; i++){
        ASCIIbinary += std::bitset<6>(base64index(encodedInput[i])).to_string();
    }
    size_t pos = 0;
    while(pos < ASCIIbinary.length() - 2*extrazeros){
        std::string sub = ASCIIbinary.substr(pos, 8);
        decoded += int(std::bitset<8>(sub).to_ulong());
        pos += 8;
    }
    return decoded;
}
