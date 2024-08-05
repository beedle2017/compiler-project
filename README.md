### Problem Statement

Consider a simple C-like language with

* Data types: int, float, char
* Declaration statements: Identifiers are declared in statements as basic data types and may also be assigned constant values
* Conditional constructs: **if, then, else**. Relational operators can be used in the constructs such as >, <, ==, !=
For example:
```
if (a < 10) then
{
    a = a * a;
}
else
    a = a / 2;
```
* Nested statements are supported. There may be **if** statement without **else**
* Assignment is performed using input/output constructs
```
cin >> x - Read into variable x
cout << x - Write variable x to output
```
* Arithmetic operators +, -, *, % are supported
* Only function is main(), there is no other function.

For this language construct the CFG and lexical analyser. Maintain a symbol table with appropriate data structures. Write a bottom up parser (modules include item-set construction, computation of FOLLOW, parsing table construction and parsing)

### Input

Write the language code in the file `input_code.txt`

### Output

Compile using `compile_unix.sh` for UNIX, and `compile.bat` for Windows.
Generated files:
* `symboltab/output.txt` - Generated tokens after scanning by lexical analyser
* `symboltab/symbol_table.txt` - Symbol table at different points in the code
* `parsing/output.txt` - First and follow sets, item set for bottom up parser and stack at different points in parsing
* `parsing/graph.pdf` - Parse tree of the input code