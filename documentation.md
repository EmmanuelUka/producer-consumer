
---

# **Documentation.md**

```markdown
# Producer–Consumer Documentation

## 1. Program Description

This project implements the **Producer–Consumer problem** using:

- **POSIX shared memory** (`shm_open`, `mmap`)  
- **POSIX semaphores** (`sem_open`, `sem_wait`, `sem_post`)  
- **C++ threads** (`std::thread`)  

**Functionality:**

- The **producer** generates tokens starting from 0 and adds them to a shared table (buffer) with capacity 2.  
- The **consumer** removes tokens from the table.  
- Synchronization prevents the producer from adding items when full and prevents the consumer from consuming when empty.  
- **Mutual exclusion** ensures only one thread modifies the table at a time.

---

## 2. Key Components

### Shared Memory
- `Table` struct contains:
  - `items[2]` – array of current tokens  
  - `count` – number of items currently on the table  
- Shared memory allows both producer and consumer to access the **same memory**.

### Semaphores
- **mutexSem**: ensures **mutual exclusion** (only one thread modifies the table at a time).  
- **spaceSem**: tracks **available space** for the producer (initially 2).  
- **itemsSem**: tracks **available items** for the consumer (initially 0).  

### Threads
- `std::thread` runs producer and consumer concurrently.  
- Semaphores manage synchronization and prevent race conditions.

---

## 3. Example Results

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