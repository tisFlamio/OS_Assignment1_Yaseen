//consumer_cpp
//Yaseen Shaikh
//Consumes items of a buffer filled by producer.cpp


#include "structure.hpp"


int main(){
    //need to create shared memory of type buffer
    sleep(1);
    const char* shmPtr = "/sharedMemObject";

    //access buffer
    int fd = shm_open(shmPtr, O_RDWR, S_IRUSR | S_IWUSR);
    if (fd == -1){
        perror("CONSUMER: ");
        std::cout << "CONSUMER: FD == -1" << std::endl;
        exit(0);
    }
    buffer *shmp = (struct buffer*)mmap(NULL, sizeof(*shmp), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(shmp == MAP_FAILED){
        std::cout << "CONSUMER: MAP FAILED" << std::endl;
        exit(0);
    } 

    

    for(int i = 0; i < 6; ++i){ //don't want to loop this too many times

        sem_wait(&shmp->semFull);
        sem_wait(&shmp->S);


        //Take
        shmp->count--;
        int Y = shmp->data[shmp->count];

        //print data
        std::cout << "Consumer: Buffer content is ";
        for(int j = 0; j < 2; ++j){
            std::cout << shmp->data[j] << " ";
        }
        shmp->data[shmp->count] = 0; //RESET (effectively remove from buffer)
        std::cout << '\n';
        std::cout << "Consumed: " << Y << std::endl;
        std::cout << "CONSUMER: Count = " << shmp->count << std::endl;



        

        sem_post(&shmp->semEmpty);
        sem_post(&shmp->S);
    }

    shm_unlink(shmPtr);
    exit(EXIT_SUCCESS);
}