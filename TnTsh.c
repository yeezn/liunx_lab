#include "TnTsh.h"
#include "header.h"
#include<signal.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

void init_sh(){
  sig_quit();
  sig_int();
  
  printf("----.*★★*.----/n ===*★MERRY★*===/n===★X-MAS★===/n-----★.★-----/n※ ※ ╋ ※ ※/n※ ※ /▦＼ ※ ※/n※ ※ |     | ~♬/n______|∩ |n__&&___/nMerryChristmas!/n/n。*˚+。*˚+。");
}

int getargs(char *cmd, char **argv){
  int narg = 0;

  while (*cmd){
    if(*cmd == ' ' || *cmd == '\t' || *cmd == '&') {
      *cmd++ = '\0';

      if (*cmd == '&') 
	IS_BACKGROUND = 1;

    }
    else{
      argv[narg++] = cmd++;
      while(*cmd != '\0' && *cmd != ' ' && *cmd != '\t'){
	cmd++;

      }
    }
    
    if(strcmp("exit", argv[0]) == 0){
      printf("\n\nTnT Shell is Die TnT,,,\n");
      exit(1);
    }
    
    if(strcmp("cd", argv[0]) == 0){
      change_directory(narg, argv);
    }

  }
  argv[narg] = NULL;
  return narg;
}


void run(){
  while(1){
    getcwd(pwd,BUF_SIZE);
    printf("%s$ ", pwd);
    gets(buf);
    narg = getargs(buf, argv);

    pid = fork();

    if (pid == 0){
      redirect_in(argv);
      redirect_out(argv);
      redirect_append(argv);
      /* pipe_tnt(argv); */
      if(strcmp(argv[0],"cd"))
	if(!IS_BACKGROUND){
	  if(execvp(argv[0], argv) == -1)
	    printf("%s: command not found\n",argv[0]);
	}else{
	  printf("process fall in background.\n");
	  execvp(argv[0], argv);
	}
      exit(1);
    }
    else if(pid > 0){
      if(!IS_BACKGROUND)
	pid = wait(&status);
    }
    else
      perror("fork failed");
  }
}

void main(){
  init_sh();
  run();
}
