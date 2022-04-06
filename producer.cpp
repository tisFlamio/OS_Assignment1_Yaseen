//producer.cpp
//Yaseen Shaikh
//Produces data and fills a shared memory buffer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>
#include <iostream>
#include "structure.hpp"


int main(){
    //need to create shared memory of type buffer
    //shm_open

    //generate random number
    srand(time(nullptr));
    int X = rand() % 100;

    //store in buffer

    cout << "Produced: " << X << endl;
    //increment full semaphore

}