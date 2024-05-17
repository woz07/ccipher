# ccipher
A simple yet powerful C++ static library for ciphering data.

## Note
- The reason why each key within keys must be between 1 - 255 when passing through a vector of int keys is because
  anything past 255 will just reset back to the start, so 256 would be 0, 257 would be 1... etc, and the reason why
  0 alone as a key is prohibited is because it will not be able to XOR and will just have the `altered` value the same as
  the `original` value. Although it's not much of an issue, it's just best to keep it out to prevent issues from arising.

## Issue:
- An issue is thrown upon executing either one of the encrypt methods, something about "unable to write at 0x000000"
