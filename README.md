# Simple HTTP Server in C

This project is a **basic HTTP server** written in C using socket programming.  
It listens on **port 8080**, accepts a single client connection, parses a simple `GET` request, and serves the requested file using `sendfile()`.  
⚠️ This is **only for learning purposes** — not intended for production use.

## Build
Compile with GCC:
```bash
gcc main.c -o server
