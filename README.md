# CPlusPlus-SimpleBaseball
A simple command-line baseball game created with C++.

A Linux executable is included. But other OSes will probably have to build from source or use the Dockerfile.

Make sure to run the Dockerfile in interactive mode or you will get an infinite loop.

# Docker Build Instructions
from within a folder containing the program files run the command: `docker build .`

Docker will then give you a container ID at the end of the command output to run the container

# Docker Run Instructions
now run `docker run -i --name yourcontainernamehere containeridhere`

The program should start after this.
