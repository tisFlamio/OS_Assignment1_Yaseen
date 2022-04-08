//structure.hpp
//Yaseen Shaikh
//defines a structure that contains a buffer and semaphore
#ifndef STRUCTURE_HPP
#define STRUCTURE_HPP

//I might have a couple unncessary directives here
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>

struct buffer{
    int data[2]; //buffer
    int count = 0; //counter
    sem_t semFull; 
    sem_t semEmpty;
    sem_t S; //might not be necessary, as I don't see it making any impact in its current implementation
};

#endif