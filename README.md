# Minitalk

![Minitalk]([https://i.pinimg.com/736x/4e/53/0a/4e530a4fb2a99f45161d9e194058bc15.jpg](https://img.freepik.com/free-vector/two-luminescent-polygonal-wireframe-human-hands-stretching-towards-each-other_1284-30755.jpg))

## Summary
Minitalk is a small data exchange program developed using UNIX signals. It consists of a client and a server that communicate by sending and receiving messages using SIGUSR1 and SIGUSR2 signals.

## Table of Contents
1. [Project Overview](#project-overview)
2. [What Was Done](#what-was-done)
3. [Implementation Details](#implementation-details)
4. [How to Build and Run](#how-to-build-and-run)
5. [Examples](#examples)
6. [License](#license)
7. [Acknowledgments](#acknowledgments)

## Project Overview
The Minitalk project demonstrates the use of UNIX signals for inter-process communication (IPC). The task involved creating two programs: a server and a client. The server waits for incoming messages from clients, while the client sends messages to the server. Communication is handled using SIGUSR1 and SIGUSR2 signals.

## What Was Done

### Server
- Developed a server program that prints its Process ID (PID) upon launch.
- Designed to receive any number of characters from multiple clients sequentially without needing to restart.
- The server reassembles the message from received bits and prints the complete message once all bits are received.
- Ensures that messages are printed only when fully received, preventing incomplete message displays and improving clarity and reliability.
- Acknowledges each received message by sending a signal back to the client.

### Client
- Created a client program that takes two parameters: the server’s PID and the message to be sent.
- Sends each character of the message bit by bit to the server using UNIX signals.
- Waits for an acknowledgment signal from the server for each bit sent to ensure reliable communication.

### Error Handling
- Implemented thorough error handling to prevent the program from quitting unexpectedly due to segmentation faults, memory leaks, or other errors.
- Ensures all allocated memory is properly freed.

## Implementation Details

### Server
- **Files:** `server.c`, `server.h`, `server_global.c`, `server_utils.c`
- **Functionality:** Initializes the server, sets up signal handlers, handles incoming signals, processes message bits, and dynamically resizes buffers as needed.

### Client
- **Files:** `client.c`, `client.h`, `client_global.c`, `client_utils.c`
- **Functionality:** Parses command-line arguments, sets up signal handlers, sends messages to the server character by character, and handles acknowledgment signals.

### Utility Functions
- **Files:** `ft_atopid_t.c`, `ft_memcpy.c`
- **Functionality:** Implements auxiliary functions for converting strings to pid_t and copying memory.

## How to Build and Run

### Building
1. Clone the repository:
   ```sh
   git clone git@github.com:with-pouyax/minitalk.git
   ```
2. Navigate to the project directory:
   ```sh
   cd minitalk
   ```
3. Build the project using the provided Makefile:
   ```sh
   make
   ```

### Running the Server
1. Start the server:
   ```sh
   ./server
   ```
2. The server will print its PID, which will be used by the client for communication.

### Running the Client
1. Start the client with the server PID and the message to send:
   ```sh
   ./client <server_pid> "<message>"
   ```

## Examples

### Start the Server
```sh
./server
```
Output:
```
Server PID: 12345
```

### Send a Message from the Client
```sh
./client 12345 "Hello, World!"
```
Server Output:
```
Hello, World!
```

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments
Special thanks to the 42 School for providing the framework and inspiration for this project.
