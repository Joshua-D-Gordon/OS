// tar -cv lalal | gzip - | gpg


// int main(int argc, char * argv[])
// {
// // Phase 1 
// 	system (“tar x…. | gzip | gpg);   // Get the accurate commmand line
// // Phase 2
// 	int pipefdone[2] = pipe();
// 	int pipefdtwo[2] = pipe();
// 	// fdarry THIS ARRARY DOES NOT EXIST
// 	// fd[0] = STDIN
// 	// fd[1] = STDOUT
// 	// fd[2] = STDERR
// 	// fd[3] = pipefdone[0]; 
// 	// fd[4] = pipefdone[1]; 
// 	// fd[5] = pipefdtwo[0]; 
// 	// fd[6] = pipefdtwo[1];
 
// 	if (!fork()) {
// 		// child 
// 		close (1) ; // close stdout // in CHILD fd[1]= NULL
// 		dup2 (pipefdone[0], 1);   // in child fd[1]=pipefdone[0];
// 		// TODO need to create commandline	 
// 		execvc ("/bin/tar", arglist, environ);
// 	}
// 	if (!fork()) {
// 		// child 
// 		close (0); // close stdin // in child fd[0]=NULL
// 		close (1) ; // close stdout // in CHILD fd[1]= NULL
// 		dup2 (pipefdone[1], 0);   // in child fd[0]=pipefdone[1];
// 		dup2 (pipetfdwo[0], 1);   // in child fd[1]=pipetwo[0];
// 		// TODO need to create commandline	 
// 		execvc ("/bin/gzip", arglist, environ);
// 	}
// 	if (!fork()) {
// 		// child 
// 		close (0); // close stdin // in child fd[0]=NULL
// 		dup2 (pipefdtwo[1], 0);   // in child fd[0]=pipefdtwo[1];
// 		// TODO need to create commandline	 
// 		execvc ("/bin/gpg", arglist, environ);
// 	}
// 	wait()
// 	wait()
// 	wait()
// 	printf ("compression completeted terminating\n");

// }