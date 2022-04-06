//structure.hpp
//Yaseen Shaikh
//defines a structure that contains a buffer and semaphore
#ifndef STRUCTURE_HPP
#define STRUCTURE_HPP


#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

struct buffer{
    int data[2];
    int count = 0;
    //sem_t semEmpty;
    sem_t semFull;
}

#endif