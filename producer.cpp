//producer.cpp
//Yaseen Shaikh
//Produces data and fills a shared memory buffer


#include "structure.hpp"
int main(){

    const char* shmPtr = "/sharedMemObject";

    shm_unlink(shmPtr);
    int fd = shm_open(shmPtr, O_CREAT | O_EXCL | O_RDWR, S_IRUSR | S_IWUSR);

    if (fd == -1){
        std::cout << "PRODUCER: FD == -1" << std::endl;
        exit(0);
    }
      

    if(ftruncate(fd, sizeof(struct buffer)) == -1){
        std::cout << "PRODUCER: ftruncate == -1" << std::endl;
        exit(0);
    }


    //struct buffer *shmp = reinterpret_cast<buffer*>(mmap(NULL, sizeof(*shmp), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0));
    buffer *shmp = (struct buffer*)mmap(NULL, sizeof(*shmp), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);


    if(shmp == MAP_FAILED){
        perror("PRODUCER: ");
        std::cout << "PRODUCER: MAP FAILED" << std::endl;
        exit(0);
    }  

    /* Initialize semaphores as process-shared, with value 0. */

    if (sem_init(&shmp->semFull, 1, 0) == -1){ // no full slots
        std::cout << "PRODUCER: SEMFULL == -1" << std::endl;
        exit(0);
    } 
    if (sem_init(&shmp->semEmpty, 1, 2) == -1){ //2 empty slots
        std::cout << "PRODUCER: SEMEMPTY == -1" << std::endl;
        exit(0);
    } 
    if (sem_init(&shmp->S, 1, 1) == -1){ //Semaphore to lock
        std::cout << "PRODUCER: S == -1" << std::endl;
        exit(0);
    } 
    
        
    srand(time(nullptr)); //random seed


    for(int i = 0; i < 6; ++i){

        sem_wait(&shmp->semEmpty);
        sem_wait(&shmp->S);

        //generate random number
        srand(time(nullptr));
        int X = rand() % 100;


       //store in buffer
        shmp->data[shmp->count] = X;
        std::cout << "Produced: " << shmp->data[shmp->count] << std::endl;
        shmp->count++;
        
        std::cout << "PRODUCER: Count = " << shmp->count << std::endl;

        sem_post(&shmp->S); //Signal
        sem_post(&shmp->semFull); //1 more full

    }

    exit(EXIT_SUCCESS);
}