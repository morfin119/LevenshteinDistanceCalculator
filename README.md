# LevenshteinDistanceCalculator
This C++ program calculates the Levenshtein distance between two input strings. The Levenshtein distance, also known as the edit distance, measures the minimum number of single-character edits (insertions, deletions, or substitutions) required to transform one string into another.

### Usage

To run the program, provide exactly two strings as command-line arguments:

```
./LevenshteinDistance <string1> <string2>
```

### Example

Here's an example of how to use the program:

```
./LevenshteinDistance kitten sitten
```

Output:

```
1
```

### Note

The Levenshtein distance is calculated using dynamic programming to find the shortest edit distance between the two strings. The function `levenshteinDistance` efficiently computes the result and returns it as an integer.
