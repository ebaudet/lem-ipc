

# Make a program who uses IPC. #

```
	IPC - Inter-process communication
```

* **Semaphores :**
Provides a synchronizing mechanism for processes that are accessing the same
resources. No data is passed with a semaphore ; it simply coordinates access
to shared ressources.

* **Shared Memory :**
Proccesses can exchange values in the shared memory One process will create a portion of memory wich other process can access.

* **Message Queue :**
It is an structured amd ordered list of memory segments where proccesses store
or retrieve data.




# List of functions #

`key_t ftok(char *pathname, int proj_id);`
create IPC identifier from path name


## Shared Memory ##
`int	shmget(key_t key, size_t size, int shmflg);`
will get or create a segment of shared memory

`void *shmat(int shmid, const void *shmaddr, int shmflg);`
will map the segment of shared memory

`int	shmctl(int shmid, int cmd, struct shmid_ds *buf);`
will apply the `cmd` instruction, like remove the memory.


## Semaphores ##
`int semget (key_t key, int nsems, int semflg);`
will get or create a sepahore linked to the `key`

`int semop(int semid, struct sembuf *sops, unsigned nsops);`
atomic array of operations on a semaphore set.

`int semctl (int semid, int semno, int cmd, ...);`
control operations on a semaphore set. Like remove semaphore or set a value.


## Message Queue ##
`int msgget(key_t key, int msgflg);`
will get or create a message queue.

`int msgctl(int msqid, int cmd, struct msqid_ds *buf);`
will apply the `cmd` instruction, like remove the message queue.

`int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);`
will send a message on the Message Queue

`ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);`
will receive a message on the Message Queue
