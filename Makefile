clang stack_fuzzer.c -o stack_fuzzer
clang -fsanitize=address -g -o stack stack.c

