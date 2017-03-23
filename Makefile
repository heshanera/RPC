.c.o:
	gcc -c -Wall -DRPC_SVC_FG $<

all: prog client server

prog: prog.o
	gcc -o prog prog.o

client: client.o prog_clnt.o prog_xdr.o
	gcc -o client client.o prog_clnt.o prog_xdr.o -lnsl


server: server.o prog_svc.o prog_xdr.o
	gcc -o server server.o prog_svc.o prog_xdr.o -lrpcsvc -lnsl

prog.h: prog.x
	rpcgen -C prog.x

clean: 
	rm *.o prog.h prog_svc.* prog_clnt.* prog_xdr.*

client.c: prog.h
server.c: prog.h
