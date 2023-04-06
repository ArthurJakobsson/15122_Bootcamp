15-122 Principles of Imperative Computation
Debugging in C Pilot Bootcamp
Spring 2023

==========================================================

Compiling example 1 (correct) // TA FACING! EXCLUDE IN HANDOUT
   % gcc -Wall -Wextra -Werror -Wshadow -std=c99 -pedantic ex1-correct.c -o ex1-correct
   % ./ex1-correct

Compiling example 1 (buggy)
   % gcc -Wall -Wextra -Werror -Wshadow -std=c99 -pedantic ex1-bad.c -o ex1-bad
   % ./ex1-bad


Compiling example 2 (correct) // TA FACING! EXCLUDE IN HANDOUT
   % gcc -DDEBUG -fsanitize=undefined -g -Wall -Wextra -Werror -Wshadow -std=c99 -pedantic ex2-correct.c -o ex2-correct
   % ./ex2-correct

Compiling example 2 (buggy)
   % gcc -DDEBUG -fsanitize=undefined -g -Wall -Wextra -Werror -Wshadow -std=c99 -pedantic ex2-bad.c -o ex2-bad
   % ./ex2-bad


Compiling example 3 (correct) // TA FACING! EXCLUDE IN HANDOUT
   % gcc -DDEBUG -fsanitize=undefined -g -Wall -Wextra -Werror -Wshadow -std=c99 -pedantic ex3-correct.c -o ex3-correct
   % ./ex3-correct

Compiling example 3 (buggy)
   % gcc -DDEBUG -fsanitize=undefined -g -Wall -Wextra -Werror -Wshadow -std=c99 -pedantic ex3-bad.c -o ex3-bad
   % ./ex3-bad


 Compiling example 4 (correct) // TA FACING! EXCLUDE IN HANDOUT
   % gcc -g -Wall -Wextra -Werror -Wshadow -std=c99 -pedantic ex4-correct.c -o ex4-correct
   % ./ex4-correct

Compiling example 4 (buggy)
   % gcc -g -Wall -Wextra -Werror -Wshadow -std=c99 -pedantic ex4-bad.c -o ex4-bad
   % ./ex4-bad


 Compiling example 5 (correct) // TA FACING! EXCLUDE IN HANDOUT
   % gcc -DDEBUG -fsanitize=undefined -g -Wall -Wextra -Werror -Wshadow -std=c99 -pedantic ex5-correct.c -o ex5-correct
   % ./ex5-correct

Compiling example 5 (buggy)
   % gcc -DDEBUG -fsanitize=undefined -g -Wall -Wextra -Werror -Wshadow -std=c99 -pedantic ex5-bad.c -o ex5-bad
   % ./ex5-bad


 Compiling example 6 (correct) // TA FACING! EXCLUDE IN HANDOUT
   % gcc -DDEBUG -fsanitize=undefined -g -Wall -Wextra -Werror -Wshadow -std=c99 -pedantic ex6-correct.c -o ex6-correct
   % ./ex6-correct

Compiling example 6 (buggy)
   % gcc -DDEBUG -fsanitize=undefined -g -Wall -Wextra -Werror -Wshadow -std=c99 -pedantic ex6-bad.c -o ex6-bad
   % ./ex6-bad