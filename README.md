# Ft_P #

TCP/IP Client/Server


### TODO: ###

* leaks tests
* mac os tests -> well, client reading of stdin is bjorked on mac... enjoy
* norme :
```
Norme: src/send_recv.c
Error (line 60): function send_file has 26 lines

Norme: src/client/c_read.c
Error (line 41): function c_read_server has 28 lines
Error (line 73): function c_read_stdin has 29 lines

Norme: src/server/permission.c
Error (line 19): function check_path has 26 lines

Norme: src/server/s_cd.c
Error (line 19): function go_to has 27 lines

Norme: src/server/s_exec.c
Error (line 66): function exec_cmd has 38 lines
```