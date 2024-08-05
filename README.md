# Minitalk

## Summary
Minitalk is a small data exchange program developed using UNIX signals. It consists of a client and a server that communicate by sending and receiving messages using SIGUSR1 and SIGUSR2 signals.

## Table of Contents
1. [Project Overview](#project-overview)
2. [Implementation Details](#implementation-details)
3. [How to Build and Run](#how-to-build-and-run)
4. [Examples](#examples)
5. [License](#license)
6. [Acknowledgments](#acknowledgments)

## Project Overview
The Minitalk project demonstrates the use of UNIX signals for inter-process communication (IPC). The task involved creating two programs: a server and a client. The server waits for incoming messages from clients, while the client sends messages to the server. Communication is handled using SIGUSR1 and SIGUSR2 signals.

## Implementation Details

### Server
- **File:** `server.c`
- **Header:** `server.h`
- **Global Variables:** Used in `server_global.c`
- **Utility Functions:** Implemented in `server_utils.c`

The server program starts by printing its PID upon launch. It is designed to receive any number of characters from multiple clients sequentially without needing to restart. The server reassembles the message from these bits and prints the complete message once all bits are received. This approach ensures that messages are printed only when fully received, preventing incomplete message displays and improving the clarity and reliability of the communication.

#### Key Functions:
- `main(void)`: Initializes the server and sets up signal handlers.
    ```c
    int main(void) {
        struct sigaction sa;
        setup_signal_handling(&sa);
        printf("Server PID: %d\n", getpid());
        while (1) {
            pause();
        }
        return 0;
    }
    ```
- `handle_signal(int sig, siginfo_t *siginfo, void *context)`: Handles incoming signals and processes message bits.
    ```c
    void handle_signal(int sig, siginfo_t *siginfo, void *context) {
        // Signal handling logic
    }
    ```
- `resize_buffer(int *char_index, int *buffer_size)`: Dynamically resizes the buffer to accommodate incoming messages.
    ```c
    void resize_buffer(int *char_index, int *buffer_size) {
        // Buffer resizing logic
    }
    ```
- `process_complete_char(int *char_index, unsigned char *current_char, int *bit_index, int *buffer_size)`: Processes a complete character received from the client.
    ```c
    void process_complete_char(int *char_index, unsigned char *current_char, int *bit_index, int *buffer_size) {
        // Character processing logic
    }
    ```
- `init_signal_handling(int *bit_index, int *char_index, int *buffer_size, unsigned char *current_char)`: Initializes variables for signal handling.
    ```c
    void init_signal_handling(int *bit_index, int *char_index, int *buffer_size, unsigned char *current_char) {
        // Signal handling initialization logic
    }
    ```

### Client
- **File:** `client.c`
- **Header:** `client.h`
- **Global Variables:** Used in `client_global.c`
- **Utility Functions:** Implemented in `client_utils.c`

The client program takes two parameters: the server’s PID and the message to be sent. It sends each character of the message bit by bit to the server using UNIX signals. The client waits for an acknowledgment signal from the server for each bit sent to ensure reliable communication.

#### Key Functions:
- `main(int argc, char **argv)`: Parses command-line arguments, sets up signal handlers, and sends the message to the server.
    ```c
    int main(int argc, char **argv) {
        if (argc != 3) {
            printf("Usage: %s <server_pid> <message>\n", argv[0]);
            return EXIT_FAILURE;
        }
        pid_t server_pid = (pid_t)atoi(argv[1]);
        if (server_pid <= 0) {
            printf("Invalid server PID\n");
            return EXIT_FAILURE;
        }
        setup_signal_handlers();
        send_message(server_pid, argv[2]);
        return EXIT_SUCCESS;
    }
    ```
- `send_message(pid_t server_pid, char *message)`: Sends the message to the server character by character.
    ```c
    void send_message(pid_t server_pid, char *message) {
        // Message sending logic
    }
    ```
- `send_char(pid_t server_pid, unsigned char c)`: Sends each bit of the character to the server.
    ```c
    void send_char(pid_t server_pid, unsigned char c) {
        // Character sending logic
    }
    ```
- `send_bit(pid_t server_pid, int bit)`: Sends individual bits to the server.
    ```c
    void send_bit(pid_t server_pid, int bit) {
        // Bit sending logic
    }
    ```
- `setup_signal_handlers(void)`: Sets up signal handlers for acknowledgment signals from the server.
    ```c
    void setup_signal_handlers(void) {
        // Signal handler setup logic
    }
    ```

### Utility Functions
- **File:** `ft_atoi.c`: Implements `ft_atoi` for converting string to integer.
    ```c
    int ft_atoi(const char *str) {
        // Atoi logic
    }
    ```
- **File:** `ft_memcpy.c`: Implements `ft_memcpy` for memory copying operations.
    ```c
    void *ft_memcpy(void *dest, const void *src, size_t n) {
        // Memcpy logic
    }
    ```

## How to Build and Run

### Building
1. Clone the repository:
   ```sh
   git clone <repository_url>
