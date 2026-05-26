# lem-ipc

`lem-ipc` is a small C project demonstrating System V IPC through a simple
multi-process arena simulation.

IPC stands for Inter-process communication.

Each process started with `./lemipc <team>` represents one player. Players from
the same team share information through a message queue, all players are stored
in a shared memory grid, and a semaphore protects concurrent access to that
shared state.

## Project purpose

The goal of the project is to practice inter-process communication with:

- shared memory, used as the common game board;
- semaphores, used to synchronize reads and writes to the board;
- message queues, used by players to broadcast enemy positions to teammates.

The game board is a `12 x 15` grid. Each running process randomly joins an empty
cell, then repeatedly:

1. locks the semaphore;
2. prints the shared board;
3. checks whether it is still alive;
4. finds or receives an enemy position;
5. moves toward that enemy;
6. sends the enemy position to its team;
7. unlocks the semaphore.

The program exits when no players remain.

## Requirements

- A Unix-like system with System V IPC support.
- `gcc`
- `make`

The project also builds the bundled `libft` dependency.

## Compile

```sh
make
```

This creates the executable:

```sh
./lemipc
```

Useful maintenance commands:

```sh
make clean    # remove object files
make fclean   # remove object files, executable, and libft build outputs
make re       # rebuild from scratch
```

## Run

Start one process per player:

```sh
./lemipc <team>
```

`<team>` must be a single character. Processes using the same character belong
to the same team.

Example with two teams:

```sh
./lemipc A
./lemipc A
./lemipc B
./lemipc B
```

Run each command in a separate terminal to watch the board evolve from each
player's point of view.

You can use any single character as a team name:

```sh
./lemipc 1
./lemipc 2
./lemipc x
./lemipc y
```

## Reset IPC resources

The special team character `%` clears the active game state:

```sh
./lemipc %
```

Use this if you want to stop the current arena and remove the IPC resources
created by the program.

## Output

The board is printed once per turn. Empty cells are displayed as `_`; occupied
cells display the team character of the player in that cell. The current
process's own position is highlighted in red.

Example board:

```text
_ _ _ _ _ _ _ _ _ _ _ _ _ _ _
_ A _ _ _ _ _ _ _ _ _ _ _ _ _
_ _ _ _ B _ _ _ _ _ _ _ _ _ _
_ _ _ _ _ _ _ _ _ _ _ _ _ _ _
...
il y a 4 en jeu. [1;1]
```

The final line shows the number of active players and the current player's
coordinates.

## Definitions

* **Semaphores :**
Provides a synchronizing mechanism for processes that are accessing the same
resources. No data is passed with a semaphore ; it simply coordinates access
to shared ressources.

* **Shared Memory :**
Proccesses can exchange values in the shared memory One process will create a portion of memory wich other process can access.

* **Message Queue :**
It is an structured amd ordered list of memory segments where proccesses store
or retrieve data.

## IPC functions used

### Keys

`ftok` creates the IPC key from the current directory and a project identifier.

### Shared memory

- `shmget` gets or creates the shared memory segment.
- `shmat` attaches the shared memory segment to the process.
- `shmctl` removes the segment when the game is cleaned up.

### Semaphores

- `semget` gets or creates the semaphore set.
- `semop` locks and unlocks the semaphore.
- `semctl` initializes or removes the semaphore.

### Message queues

- `msgget` gets or creates the message queue.
- `msgsnd` sends an enemy position to the team.
- `msgrcv` receives an enemy position for the team.
- `msgctl` removes the message queue when the game is cleaned up.
