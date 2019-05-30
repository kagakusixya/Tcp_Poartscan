
#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
    int sd;
    struct sockaddr_in addr;
    for(int i=0;i<65536;i++){
    sd = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(i);

    if(connect(sd, (struct sockaddr *)&addr, sizeof(struct sockaddr_in))==-1){
        printf("port:%d %s\n",i,strerror(errno));
    }else{
      printf("port:%d OK\n",i);
    }
    close(sd);
  }
    return 0;
}
