#include <iostream>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/mman.h>

using namespace std;

int main() {
    shm_unlink("/shared_table");
    sem_unlink("/sem_tbl_mutex");
    sem_unlink("/sem_tbl_space");
    sem_unlink("/sem_tbl_items");

    cout << "Shared Memories and Semaphores are cleared up" << endl;
    return 0;
}
