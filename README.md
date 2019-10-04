# KVPstorage
Simple key-value pair storage in C

Compiling:

Run make to create the binary
For a static binary you can run make static=true

Executing:

KVPstorage will, by default, store KVP's in .settings.
It is possible to provide a filepath as parameter and KVPstorage will use that file instead.
This file has to be empty or have a valid KVP storage format (see KVPstorage format).

KVPstorage format:
KEYSIZE (64) and VALUESIZE (512) are defined in the header file.
If KVP's are stored in a file with a different size the program won't work.
Keys cannot contain blank spaces but values can. Values can also be empty.

Commands:

SET		<KEY> [VALUE]

- SET command requires a key and optionally a value.

GET		<KEY>

- GET command requires a key. Any other input after the first key is ignored.

DELETE	<KEY>

- DELETE command requires a key. Any other input after the first key is ignored.

GETALL

- GETALL does not take any arguments and shows all currently stored KVP's.

exit

- exit does not take any arguments and will exit the program.