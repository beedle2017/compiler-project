g++ -std=c++17 dfa/analyser.cpp -o dfa/analyser
g++ -std=c++17 Parsing/bottom-up.cpp -o Parsing/bottom-up
g++ -std=c++17 symboltab/symtab.cpp -o symboltab/symtab
cd dfa/
./analyser.exe
cd ../Parsing
./bottom-up.exe
cd ../symboltab
./symtab.exe
cd ../
