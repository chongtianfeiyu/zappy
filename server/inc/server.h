#ifndef SERVER_H_INCLUDED
# define SERVER_H_INCLUDED

# include <signal.h>
# include <string.h>

# include "tab.h"
# include "network.h"
# include "select.h"
# include "game.h"

typedef struct	s_server
{
  int		quit;
  t_net		**listener;
  t_list	*watch;
  t_game	game;
}		t_server;

typedef struct	s_client
{
  t_net		*sock;
  char		type_cli;
  char		*teamname;
  // pour toutes les infos relatives à un client
}		t_client;

int	listen_on_port(t_server *serv, char *port, int socktype);
void	close_server_binds(t_server *serv);
void	serv_verbose(t_server *serv);
void	server_setup_select(t_server *serv);
void	handle_newconnection(t_selfd *fd, t_server *serv);
void	quit_server(t_server *serv);
void	log_connection(t_net *sock, char *message);

/*
** exec_cmd.c
*/

void	handle_exec_cmd(t_selfd *fd, char *cmd);

/*
** parse_command_line.c
*/

int	parse_command_line(t_server *server, int ac, char *av[]);

#endif /* !SERVER_H_INCLUDED */
