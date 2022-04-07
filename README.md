Yaseen Shaikh
Operating Systems 2022
Producer-Consumer Problem


# Overview
This project simulates the producer-consumer problem in 2 different ways, using a static array of size 2 as the shared memory buffer. 

The first method is in 1 file, main.cpp. It continues to produce and consume randomly generated values until the user terminates the program.

The second implementation uses 3 files. The header file is structure.hpp, in which the include directives are kept, as well as the definition of buffer, our structure, which stores 3 semaphores, a counter integer, and a static array of size 2. The producer file is producer.cpp, which creates a shared memory instance of buffer and fills the buffer. The consumer file is consumer.cpp which uses and empties the buffer. In this example emptying is represented as setting the values to 0.  

# Dependencies
This code utilizes pthreads and was creating in a Linux environment, so you may need to use a Linux environment to execute the code.
In addition, g++ was used in the production of this code and is therefore required. 

Beyond that, the code should be pretty much plug-and-play. 

# Compilation
To compile (with 1 file, main.cpp), type the following command: 
g++ -pthread -lrt -o main main.cpp
and then:
./main

To compile with both files (producer.cpp and consumer.cpp), type the following commands:

g++ producer.cpp -pthread -lrt -o producer
g++ consumer.cpp -pthread -lrt -o consumer

./producer & ./consumer



