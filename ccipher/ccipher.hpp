#ifndef CCIPHER_HPP
#define CCIPHER_HPP

#include <string>
#include <vector>

// Using string key
std::string EncryptWithStringKey(std::string target, std::string key);
std::string DecryptWithStringKey(std::string target, std::string key);

// Using int keys
std::string EncryptWithIntKeys(std::string target, std::vector<int> keys);
std::string DecryptWithIntKeys(std::string target, std::vector<int> keys);

#endif // CCIPHER_HPP