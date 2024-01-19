// tar -cv lalal | gzip - | gpg
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

 int main(int argc, char * argv[]) {
 // Phase 1 
 	//system ("tar ls | gzip | gpg");   // Get the accurate commmand line
    char *inputFile = argv[1];

    printf("the file / foldr is : %s\n",inputFile);

    //if myzip need to zip file
    if(strcmp(inputFile, "myzip") == 0){
        printf("\nmyzip\n\n");
        //creating pipeline
        int pipefdone[2];
        int pipefdtwo[2];
        if(pipe(pipefdone) == -1){
            perror("pipe");
            exit(1);
        }
        if(pipe(pipefdtwo) == -1){
            perror("pipe");
            exit(1);
        }

        //first child process
        if(!fork()){
            close(1); // closing STDOUT fd[1] = NULL
            dup2(pipefdone[1], 1); // fd[1] = pipefdone[0];
            close(pipefdone[1]); // dont need this
            //comand line
            //execlp("usr/bin/tar", "tar", "czf", "-",inputFile, NULL);
            execlp("tar", "tar", "czf", "-", inputFile,NULL);
            perror("execlp tar");
            fprintf(stderr, "errno: %d\n", errno);
            exit(EXIT_FAILURE);
        }
        
        if (!fork()) {
            close (pipefdone[1]); // close stdin // in child fd[0]=NULL
            close (pipefdtwo[0]) ; // close stdout // in CHILD fd[1]= NULL
            dup2(pipefdone[0], 0);   // in child fd[0]=pipefdone[1];
            dup2(pipefdtwo[1], 1);   // in child fd[1]=pipetwo[0];
            close(pipefdone[0]);
            close(pipefdtwo[1]);
            // TODO need to create commandline
            execlp ("gzip", "gzip", NULL);
            perror("execpl gzip");
            exit(EXIT_FAILURE);
 	    }
       
        if(!fork()){
            close(pipefdone[0]); // close STDIN - fd[0] = NULL
            close(pipefdone[1]);
            close(pipefdtwo[1]);
            dup2(pipefdtwo[0], 0); // fd[0] = pipefdtwo[1];
            close(pipefdtwo[0]);
            // TODO need to create commandline
            execlp("gpg", "gpg", "--encrypt","--recipient","joshua gordon <jodogo9897@gmail.com>","--output","myunzip.gpg",  NULL);
            perror("execpl gpg");
            exit(EXIT_FAILURE);
        }
        close(pipefdone[0]);
        close(pipefdone[1]);
        close(pipefdtwo[0]);
        close(pipefdtwo[1]);

        wait(NULL);
        wait(NULL);
        wait(NULL);

        printf ("compression completeted terminating\n");
        return 0;
    }else if(strcmp(inputFile, "myunzip.gpg") == 0){
        printf("\nmyunzip.gpg\n\n");
        int pipefdone[2];
        int pipefdtwo[2];

        if(pipe(pipefdone) == -1){
            perror("pipe");
            exit(1);
        }
        if(pipe(pipefdtwo) == -1){
            perror("pipe");
            exit(1);
        }

        if(!fork()){
            close(pipefdone[0]); // close unused read end of pipefdone
            dup2(pipefdone[1], 1);
            close(pipefdone[1]); //close original pipe end

            execlp("gpg", "gpg", "--decrypt", "--output","-", inputFile, NULL);
            perror("execlp gpg");
            exit(EXIT_FAILURE);
        }

        if(!fork()){
            close(pipefdone[1]);
            close(pipefdtwo[0]);
            dup2(pipefdone[0],0);
            dup2(pipefdone[1], 1);
            close(pipefdone[0]);
            close(pipefdtwo[1]);

                execlp("gunzip", "gunzip", NULL);
            perror("execlp gunzip");
            exit(EXIT_FAILURE);
        }

        if(!fork()){
            close(pipefdone[0]); // close STDIN - fd[0] = NULL
            close(pipefdone[1]); //added
            close(pipefdtwo[1]);
            dup2(pipefdtwo[0], 0);
            close(pipefdtwo[0]);
            execlp("tar", "tar", "xvf", "-", NULL);
            perror("execlp tar");
            //printf(stderr, "errno: %d\n", errno);
            exit(EXIT_FAILURE);
        }
        close(pipefdone[0]);
        close(pipefdone[1]);
        close(pipefdtwo[0]);
        close(pipefdtwo[1]);

        wait(NULL);
        wait(NULL);
        wait(NULL);

        printf("finished unzip terminiating");

        return 0;
    }else{
        printf("No folder named myzip or myunzip given in argv");
        exit(-1);
    }
 
 	// fdarry THIS ARRARY DOES NOT EXIST
 	// fd[0] = STDIN
 	// fd[1] = STDOUT
 	// fd[2] = STDERR
 	// fd[3] = pipefdone[0]; 
 	// fd[4] = pipefdone[1]; 
 	// fd[5] = pipefdtwo[0]; 
 	// fd[6] = pipefdtwo[1];

 }