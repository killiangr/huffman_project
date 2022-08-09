# huffman_project
The goal of this project is to implement a compression algorithm. This means that we are trying to reduce the space taken up by information, without losing data. We will work here on text files. Huffman's coding relies on translating a character into a shortcode, depending on how often it occurs. The more often a character appears in the text to be encoded, the shorter its translation will be. You may know that a character is encoded on a byte. This means that for each character in a text we need 8 bits in memory. A text of 100 characters will therefore take 800 bits in memory. How then do we reduce this figure?