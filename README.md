# Operating_Systems_2022
# Producer_Consumer Problem
# Utilizes Semaphoresand Pthreads

# Overview
This code uses 2 files to simulate the producer-consumer problem, using a static array of size 2 as the shared memory buffer. producer.cpp is the producer file which fills the buffer, and consumer.cpp is the consumer file, using and emptying the buffer. 

# Dependencies
This code utilizes pthreads and was creating in a Linux environment, so you may need to use a Linux environment to execute the code.
In addition, g++ was used in the production of this code and is therefore required. 

Beyond that, the code should be pretty much plug-and-play. 

# Compilation
To compile (with 1 file, main.cpp), type the following command: 
g++ -o main.exe main.cpp
and then:
./main

To compile with both files (producer.cpp and consumer.cpp), type the following command:


