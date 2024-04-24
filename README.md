# Binary Search Tree

This program in C allows you to read multiple words from multiple text files or standard input, create a binary search tree, perform specified operations, and output those words in the specified traversal order.

## Usage

### Input

If one or more arguments are given in addition to options on the command line, they will be sequentially read as input files. If there are no file arguments, it will read from standard input. The input assumes that multiple words are separated by any number of spaces or line breaks.

### Options

There are four options available:

- **p**: Specifies the traversal order when displaying the binary search tree.
  - If 0 is specified, it outputs in pre-order traversal.
  - If 1 is specified (default), it outputs in in-order traversal.
  - If 2 is specified, it outputs in post-order traversal.

- **s**: Perform replacements on strings. Takes arguments in the form of "-s /match/replace/". If a node in the generated binary search tree contains a substring "match", it replaces that substring with the string "replace". Additionally, if replace is an empty string, it removes the substring "match".

- **u**: Output only one instance when there are multiple occurrences of the same string in the binary search tree.

- **r**: Delete specific string nodes. Takes arguments in the form of "-r /removematch/delall/". Deletes nodes from the binary search tree that match the given string removematch. If delall is true (0), it deletes all nodes that match the deletion criteria; if false (non-zero), it only deletes the closest node to the root node.

## Example Usage
```
% cd PJT
% make

# Example usage: read from standard input, perform in-order traversal
% ./pjt

# Read from file1.txt and file2.txt, perform post-order traversal, and replace "foo" with "bar"
% ./pjt -p 2 -s /foo/bar/ file1.txt file2.txt

# Read from standard input, perform in-order traversal, output only unique strings
% ./pjt -u

# Read from file.txt, perform pre-order traversal, and delete nodes matches "xyz"
% ./pjt -p 0 -r /xyz/1/ file.txt
```
