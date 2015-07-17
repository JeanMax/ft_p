# Ft_P #

TCP/IP Client/Server

### TODO: ###

* error handling (is_digit)
* server loose stdin reading after a client disconnection
* could be good to have two separates headers files...
* ^C on client should intercept current command... good luck bro -.-
* if a line from client is interpreted as a command but isn't : free error party mix
* c_read_stdin go zombie 
* server won't read client after an execv (e.g. ls)
* "lszboub" triggers ls