// ccipher.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "ccipher.hpp"

// Private functions which can only get accessed indirectly

// XOR with string
/*
 * (PRIVATE)
 * ValidateStringXOR():
 * This is a private function which validates the input params 
 * for the function which use a string key
 * 
 * @params std::string target ~ The target string passed through
 * @params std::string key ~ The key passed through
 * @throws exception: Only thrown if one of the requirements 
 * isn't met
 */
void ValidateStringXOR(std::string target, std::string key)
{
	// Check if target is empty
	if (target.empty())
	{
		throw std::exception("ccipher.cpp::ValidateStringXOR(std::string target, std::string key) target shouldn't be empty");
	}

	// Check if key is empty
	if (key.empty())
	{
		throw std::exception("ccipher.cpp::ValidateStringXOR(std::string target, std::string key) key shouldn't be empty");
	}

	// Key length must be greater than or equal to 8 and less than or equal to 255
	if (key.length() < 8 || key.length() > 255)
	{
		throw std::exception("ccipher.cpp::ValidateStringXOR(std::string target, std::string key) key must have a length between 8 to 255 inclusive");
	}
}


/*
 * (PRIVATE)
 * XORWithStringKey():
 * This is a private function which XOR's a given string
 * using the provided string key
 * 
 * @param std::string target ~ The target string to XOR
 * @param std::string key ~ The key to XOR with
 * @return The XOR'd value
 */
std::string XORWithStringKey(std::string target, std::string key)
{
	std::vector<char> original(target.begin(), target.end());
	std::vector<char> altered(original.size());

	// Loop through key and XOR each letter in key with each 
	// letter in original and add that value to altered
	for (int k = 0; k < key.length(); k++)
	{
		for (int i = 0; i < original.size(); i++)
		{
			altered[i] = original[i] ^ key[k];
		}
	}
	
	// return XOR'd value as string
	return std::string(altered.begin(), altered.end());
}

// XOR with ints
/* (PRIVATE)
 * ValidateIntXOR():
 * This is a private function which validates the input params
 * for the functions which use int keys
 * 
 * @param std::string target ~ The target string passed through
 * @param std::vector<int> keys ~ The keys passed through
 * @throws exception ~ Only thrown if one of the requirements 
 * isn't met
 */
void ValidateIntXOR(std::string target, std::vector<int> keys)
{
	// Check if target is empty
	if (target.empty())
	{
		throw std::exception("ccipher.cpp::ValidateIntXOR(std::string target, std::vector<int> keys) target shouldn't be empty");
	}

	// Make sure length of keys is less than or equal to 256
	if (keys.size() > 256)
	{
		throw std::exception("ccipher.cpp::ValidateIntXOR(std::string target, std::vector<int> keys) keys must only contain less than or equal to 256 keys");
	}

	for (int k = 0; k < keys.size(); k++)
	{
		if (keys[k] > 255 || keys[k] < 1)
		{
			throw std::exception("ccipher.cpp::ValidateIntXOR(std::string target, std::vector<int> keys) a key must be within the range 1 to 255");
		}
	}
}

/*
 * (PRIVATE)
 * XORWithIntKeys():
 * This is a private function which XOR's a given string
 * using the provided int keys
 * 
 * @param std::string target ~ The target string to XOR
 * @param std::vector<int> keys ~ The keys to XOR with
 * @return The XOR'd value
 */
std::string XORWithIntKeys(std::string target, std::vector<int> keys)
{
	std::vector<char> original(target.begin(), target.end());
	std::vector<char> altered(original.size());

	// Loop through keys and XOR each key with every letter 
	// in original and add that value to altered
	for (int k = 0; k < keys.size(); k++)
	{
		for (int i = 0; i < original.size(); i++)
		{
			altered[i] = original[i] ^ keys[k];
		}
	}

	// Return XOR'd value as string
	return std::string(altered.begin(), altered.end());
}

// Public functions

// XOR with string
/*
 * EncryptWithStringKey():
 * This function encrypts a string using the provided string key
 *
 * @param std::string target ~ The target string to encrypt
 * @param std::string key ~ The key to encrypt using
 * @returns The encrypted value
 */
std::string EncryptWithStringKey(std::string target, std::string key)
{
	ValidateStringXOR(target, key);
	return XORWithStringKey(target, key);
}

/*
 * DecryptWithStringKey():
 * This function decrypts a string using the provided string key
 *
 * @param std::string target ~ The target string to decrypt
 * @param std::string key ~ The key to decrypt using
 * @returns The decrypted value
 */
std::string DecryptWithStringKey(std::string target, std::string key)
{
	ValidateStringXOR(target, key);
	return XORWithStringKey(target, key);
}

// XOR with ints
/*
 * Encrypt():
 * This function encrypts a string using the provided int keys
 *
 * @param std::string target ~ The target string to encrypt
 * @param std::vector<int> keys ~ The keys to encrypt using
 * @returns The encrypted value
 */
std::string EncryptWithIntKeys(std::string target, std::vector<int> keys)
{
	ValidateIntXOR(target, keys);
	return XORWithIntKeys(target, keys);
}

/*
 * Decrypt():
 * This function decrypts a string using the provided int keys
 *
 * @param std::string target ~ The target string to decrypt
 * @param std::vector<int> keys ~ The keys to decrypt using
 * @returns The decrypted value
 */
std::string DecryptWithIntKeys(std::string target, std::vector<int> keys)
{
	ValidateIntXOR(target, keys);
	return XORWithIntKeys(target, keys);
}