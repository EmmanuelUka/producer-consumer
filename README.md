# Producer–Consumer Problem

## Files included
`producer.cpp` Produces values and adds them to the shared table, printing token and table count

`consumer.cpp`  Consumes tokens from the shared table, printing consumed token and table count. 

`cleanShared.cpp`  Cleans up shared memory and semaphores for future runs. 

## Usage Instructions 
### To Compile
g++ producer.cpp -pthread -lrt -o producer

g++ consumer.cpp -pthread -lrt -o consumer

g++ cleanShared.cpp -pthread -lrt -o cleanShared

### To Run 
./cleanShared

./producer & ./consumer &

### To stop program
pkill producer

pkill consumer

### Clean Shared Resources
./cleanShared

