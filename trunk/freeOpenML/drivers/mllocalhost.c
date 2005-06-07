/***********************************************************************
* copyright (c) 2004 MALET Jean-luc aka cityhunter
* This program is free software; you can redistribute it and/or modify
* it under the terms of the artistic license as published at 
* http://cityhunter.is-a-geek.org/TESTAMENT
* you must have received a copy of the licence along with this package
************************************************************************/


#include <OpenML/OpenML.h>
#include <popt.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SERVER_PATH "/var/run/OpenML_SERV_ctrl.socket"

/***                OPTIONS                      ***/
struct my_opt 
{
	int verbose
};
struct my_opt opt;

const struct poptOption popt_options[] = {
			{ "help",		'?', POPT_ARG_NONE, NULL, 0 , _("Show this help message"), NULL},
			{ "verbose",'v', POPT_ARG_INT, &(opt.verbose), 0, _("verbosity level"), NULL},
			POPT_TABLEEND
	};


/***                SOCKETS                       ***/

struct connection {
		int socket;
		struct sockaddr_un addr;
}

void *
handle_connection (void* arg)
{
	struct connection *connected =(struct connection *) arg;
	//now do the real stuff
}
				

int 
main(int arch, char* argv)
{
	int rc; 
	struct connection listen;
	struct connection newConnection;
	struct connection *connected;
	poptContext popt_context;
	pthread_t new_connection_handler;
	
	popt_context = poptGetContext("OpenML_Localhost", argc, (const char **)argv,
	                              popt_options, 0);
	rc = poptGetNextOpt(poptcon);
	if (rc != -1 || NULL != poptPeekArg(popt_context))
		{
			poptPrintHelp(popt_context, stderr, 0);
			return 1;
		}
	poptFreeContext(popt_context);
	
	//now open the socket and listen to it
	listen.socket = socket(PF_UNIX, SOCK_STREAM, 0);
	if (listen.socket == -1)
		{
			perror("creating socket");
			return 1;
		}
	listen.addr.family = AF_UNIX;
	listen.addr.path = SERVER_PATH;
	if (bind(listen.socket, &(listen.addr), sizeof(listen.addr)))
		{
			perror("binding socket");
			return 1;
		}
	if (listen(listen.socket, 20))
		{
			perror("listening socket");
			return 1;
		}
	while (running)
		{
			newConnection.socket=accept(listen.socket, 
					                        &(newConnection.addr), 
																	sizeof(newConnection.addr));
			if (newConnection.socket < 0)
				{
					perror("accepting connection");
					continue;
				}
			connected = malloc(sizeof(struct connection));
			if (connected == NULL)
				{
					perror("handling new connection")
					return 1
				}
			*connected=newConnection;
			
			if ( pthread_create(&new_connection_handler,
										 NULL,
										 handle_connection,
										 (void*) connected);
				 )
				{
					perror("can't create connection handler");
					return 1
				}
			pthread_detach(new_connection_handler);
			
		}
}
