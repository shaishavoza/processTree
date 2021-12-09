# processTree
Process Tree using fork and exec system calls

Installation:
Compile the project using command: 'make'
Run the project by passing command line arguments for depth of the tree(L) and number of children(N) using command: './processTree L N'

Usage:
The project can be used to learn fork and exec system calls. Child processes are differentiated from parent process using the fork return value and exec is used for each child to recursively create children of their own based on the input provided via the command line for depth and number of children.
For eg: For a input of L=2 and N=2 a parent process 'A' will create 2 child processes 'B' and 'C' which in turn will create two more processes each respectively.
