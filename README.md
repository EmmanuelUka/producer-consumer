# Producer–Consumer Problem

## Files included
`producer.cpp` Produces values and adds them to the shared table, printing token and table count

`consumer.cpp`  Consumes tokens from the shared table, printing consumed token and table count. 

`cleanShared.cpp`  Cleans up shared memory and semaphores for future runs. 

## Usage Instructions 
### To Compile
```text
g++ producer.cpp -pthread -lrt -o producer
g++ consumer.cpp -pthread -lrt -o consumer
g++ cleanShared.cpp -pthread -lrt -o cleanShared
```

### To Run 
```text
./cleanShared
./producer & ./consumer &
```

### Example Output
```text
Produced: 0  Count: 0
Produced: 1  Count: 1
Consumed: 1  Count: 1
Consumed: 0  Count: 0
Produced: 2  Count: 0
Consumed: 2  Count: 0
Produced: 3  Count: 0
Consumed: 3  Count: 0
```

### To stop program
```text
pkill producer
pkill consumer
```

### Clean Shared Resources
```text
./cleanShared
```

