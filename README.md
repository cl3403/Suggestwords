# Suggestwords
The program goes through the input file and print the words whose edit distance from the given string is at most the given threshold. An edit can be a substitution, a deletion, or an insertion.
You may compile according to the directions below.

---suggestwords---

To compile: make suggestwords

To run: ./suggestwords <a file name> <a string> <integer edit-distance threshold> 

Description:

The suggestwords program takes three command-line arguments: <a file name> where the file will be a list of words with one word on each line, <a string>, and an <integer edit-distance threshold>. The program goes through the file and print the words whose edit distance from the given string is at most the given threshold.
