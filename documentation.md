# Producer–Consumer Documentation

## Program Description

This project implements the **Producer–Consumer problem**

- The **producer** generates values starting from 0 and adds them to a shared table (buffer) with capacity 2.  
- The **consumer** removes values from the table.  
- Synchronization prevents the producer from adding items when full and prevents the consumer from consuming when empty.  
- **Mutual exclusion** ensures only one thread modifies the table at a time.

---

## Example Results

### Terminal Output

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

- Values start at 0 and increment sequentially.
- Count shows current number of items on the table.
- Synchronization prevents overproduction or consumption when the table is empty.


## Description of Key Parts
### Shared Memory
- Stores the shared buffer (items[2]) and a count of current items.
- Both producer and consumer processes map this memory using mmap to share items safely.
- Ensures that both processes are working with the same data in real time, allowing proper communication without copying data between processes.

### Semaphores
- mutexSem: Provides mutual exclusion, ensuring that only one thread accesses the buffer at a time. This prevents race conditions when reading or writing to the shared memory.
- spaceSem: Tracks available slots in the buffer. The producer waits on this semaphore when the buffer is full, preventing overproduction.
- itemsSem: Tracks available items for the consumer. The consumer waits on this semaphore when the buffer is empty, preventing underflow.

### Mutual Exclusion
- Achieved using the mutex semaphore.
- Ensures that critical sections—where the buffer is updated—are accessed by only one thread at a time.
- Protects the count and items array from concurrent modifications that could cause incorrect behavior.

### Producer Process
- Generates values (starting from 0) and adds them to the buffer.
- Waits on spaceSem if the buffer is full.
- Locks mutexSem before modifying the buffer and unlocking afterward.
- Signals itemsSem after producing a value to notify the consumer.

### Consumer Process
- Removes values from the buffer.
- Waits on itemsSem if the buffer is empty.
- Locks mutexSem before modifying the buffer and unlocking afterward.
- Signals spaceSem after consuming a value to notify the producer.

### Cleanup
- A separate program removes the shared memory and semaphores (shm_unlink and sem_unlink) to prevent resource leaks and ensure clean execution for future runs.