How it works:
1.Take user input
2.Decide whether it is meta commands(eg- .exit) or dml,ddl commands.
    if input starts with .,it is meta command
3.Check whether given command is known/valid or not.

Storing Strategy:
Store rows in blocks of memory called pages
Each page stores as many rows as it can fit
Rows are serialized into a compact representation with each page
Pages are only allocated as needed
Keep a fixed-size array of pointers to pages