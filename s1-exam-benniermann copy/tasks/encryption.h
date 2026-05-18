#pragma once

#include <stdio.h>

/**
 * @brief Encrypt a message using a given offset, writing the result to an output file.
 * 
 * The message will only contain lowercase letters (a-z) and spaces.
 * Spaces are written to the output unmodified.
 * The encrypted message should be written in the format:
 * <length>;<encrypted message>
 * 
 * The given offset is a number which should be used to shift each *letter*
 * of the message *within the alphabet*.
 * 
 * Example:
 * 'a' offset by   1 = 'b'
 * 'z' offset by  -1 = 'y'
 * 'a' offset by  26 = 'a'
 * 'a' offset by  -1 = 'z' ( -1 + 26 =  25 -> 'a' + 25 = 'z')
 * 'a' offset by  42 = 'q' ( 42 % 26 =  16 -> 'a' + 16 = 'q')
 * 'a' offset by -90 = 'o' (-90 % 26 = -12 -> -12 + 26 = 14 -> 'a' + 14 = 'o')
 * 'z' offset by   1 = 'a' (Hint: Viewing a-z as 0-25, one can do (25 + 1) % 26 = 0 -> 'a')
 * 
 * So the message "hello world" and an offset of 4
 * will produce the following output in the given file:
 * 11;lipps asvph
 * 
 * Hint: The above examples ensure no overflow can happen with the modulo operator.
 * Focus on implementing a functioning version first and worry about overflow afterwards.
 * 
 * @param message message to encrypt (contains only a-z and spaces)
 * @param offset number of positions to offset each letter within the alphabet
 * @param output file to write the encrypted message to
 */
void encrypt(const char* message, char offset, FILE* output);

/**
 * @brief Decrypt a message from a file with a given offset.
 * 
 * The input file contains a single message in the format:
 * <length>;<encrypted message>
 * 
 * This function should read the length first to allocate enough memory
 * for the decrypted message to return.
 * 
 * The returned string should always be null-terminated.
 * 
 * The decryption works similar to the encryption. The only difference
 * is that the offset moves the letter into the opposite direction.
 * 'b' with offset 1 is 'a'
 * 'a' with offset 1 is 'z'
 * etc.
 * 
 * @param offset offset to use for the decryption (same offset used to encrypt the original message)
 * @param input file containing a single encrypted message
 * @return dynamically allocated null-terminated string containing the decrypted message, or NULL if there was an error
 */
char* decrypt(char offset, FILE* input);