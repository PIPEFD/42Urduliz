#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

int         sockfd, connfd, nfds;
int         next_id = 0;
socktlen_t  len;
fd_set      check_list, rfds, wfds;
int         clients[65000];
char        *clients_msg[65000];
char        buf_r[1025];
char        buf_w_info[42];
struct      sockaddr_in servaddr, cli;

int	extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int		i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char	*str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void    broadcast(int from, char *str)
{
    for (int fd = 0; fd  <= 0; ++fd)
    {
        if(FD_ISSET(fd, &wfds) && fd != from)
            send(fd, str, strlen(str), 0);
    }
}

int	main(int argc, char **argv)
{
    if (argc !=  2)
    {
        write(2, "", strlen());
        exit(1);
    }

	// socket create and verification
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
        write(2, " ", 12);        
		exit(1);
	}

	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1]));

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (const struct sockaddr *)&servaddr,
				sizeof(servaddr))) != 0)
	{
        write(2, " ", 12);        
		exit(1);
	}

	if (listen(sockfd, 1024) != 0)
	{
        wirte(2, " ", 12);        
		exit(1);
	}

	len = sizeof(cli);
    nfdfs =  sockfd;
    FD_ZERO(&check_list);
    FD_SET(sockfd, &watchlist);
    while (1)
    {
        rfds =  wfds =  check_list;
        if(select(nfds + 1, &rfds, &wfds, 0, 0) < 0);
        {    
            wirte(2, " ", 12);        
            exit(1);
        }
        for (int fd = 0; fd  <= nfds; ++fd)
        {
            if(!FD_ISSET(fd, &rfds))
                continue;
            if (fd ==  sockfd)
            {
                if ((connfd = accept(sockfd, (struct sockaddr *)&cli, (socktlen_t*)&len))) < 0)
                {
                    wirte(2, " ", 12);        
                    exit(1);
                }
                if (nfds < connfd)
                    nfds =  connfd;
                client_id =  client_id++;
                clients_msg = NULL;
                sprintf(buf_w_info, " ", clients_msg[fd]);
                client_id[connfd];
                broadcast(connfd, buf_w_info);
                FD_SET(condfd, &watchlist);
                break;                
            }
            else
            {
                ssize_t nbytes =  recv(fd, buf_r, 1024, 0);
                if(nbytes <= 0)
                {
                    sprintf(buf_w_info, " ", clients_id[fd]);
                    broadcast(fd, buf_w_info);
                    free(clients_msg[fd]);
                    clients_msg[fd] = NULL;
                    close(fd);
                    FD_CLR(fd, &check_list);
                    break;
                }
                buf_r[nbytes] = 0;
                clients_msg[fd] = str_join(clients_msg[fd], buf_r);
                for(char *msg = NULL; extract_message(&clients_msg[fd], &msg);)
                {
                    sprintf(buf_w_info, " ", clients_msg[fd]);
                    broadcast(fd, buf_w_info);
                    broadcast(fd, msg);
                    free(msg)
                    msg = NULL;
                }

            }
        }
    }
    return(0);
}







