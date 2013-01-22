#include "main.h"

#include "net.h"
#include "graphics.h"

pthread_mutex_t networkPacketsMutex;

int main(int argc, char *argv[])
{
    std::vector<packet> *packets = new std::vector<packet>();
    pthread_t networkThread;

    pthread_mutex_init(&networkPacketsMutex, NULL);
    
    pthread_create(&networkThread, NULL, initNet, (void *)packets);
    //initNet((void *)packets);

    initGL(packets, argc, argv);

    pthread_join(networkThread, NULL);
    pthread_mutex_destroy(&networkPacketsMutex);
}
