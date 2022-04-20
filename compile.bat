g++ -std=c++17 -fsanitize=address -Wl,-stack_size,0x10000000 dfa/analyser.cpp -o dfa/analyser
g++ -std=c++17 -fsanitize=address -Wl,-stack_size,0x10000000 Parsing/bottom-up.cpp -o Parsing/bottom-up
g++ -std=c++17 -fsanitize=address -Wl,-stack_size,0x10000000 symboltab/symtab.cpp -o symboltab/symtab
cd dfa/
./analyser
cd ../Parsing
./bottom-up
cd ../symboltab
./symtab
cd ../
