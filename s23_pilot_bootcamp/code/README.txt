15-122 Principles of Imperative Computation
Debugging in C Pilot Bootcamp
Spring 2023

==========================================================

Compiling example 1
   % gcc -Wall -Wextra -Werror -Wshadow -std=c99 -pedantic ex1.c -o ex1
   % ./ex1

Compiling example 2
   % gcc -DDEBUG -fsanitize=undefined -g -Wall -Wextra -Werror -Wshadow -std=c99 -pedantic lib/ex2-helper.o ex2.c -o ex2
   % ./ex2

Compiling example 3
   % gcc -DDEBUG -fsanitize=undefined -g -Wall -Wextra -Werror -Wshadow -std=c99 -pedantic lib/ex3-helper.o ex3.c -o ex3
   % ./ex3

Compiling example 4
   % gcc -g -Wall -Wextra -Werror -Wshadow -std=c99 -pedantic lib/ex4-helper.o ex4.c -o ex4
   % valgrind ./ex4

Compiling example 5
   % gcc -DDEBUG -fsanitize=undefined -g -Wall -Wextra -Werror -Wshadow -std=c99 -pedantic lib/ex5-helper.o ex5.c -o ex5
   % ./ex5

Compiling example 6
   % gcc -DDEBUG -fsanitize=undefined -g -Wall -Wextra -Werror -Wshadow -std=c99 -pedantic lib/ex6-helper.o ex6.c -o ex6
   % ./ex6

Compiling print-struct
   % gcc -g -Wall -Wextra -Werror -Wshadow -std=c99 -pedantic print-struct.c -o print-struct
   % ./print-struct
