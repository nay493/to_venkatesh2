#include<stdio.h>
#include <pthread.h>

FILE *stream, *stream2;
int g = 0;

int main() {

#ifdef __linux__ 
    printf("liinux code goes here\n");
    fops_win();
    thread_fun();
#elif _WIN32
    printf(" windows code goes here\n");
    fops_win();
#else
    printf("NO code !!!\n");
#endif


return 0;
}


fops_win() {
     int numclosed;

     if( (stream  = fopen( "crt_fopen.c", "rw" )) == NULL )
     printf( "The file 'crt_fopen.c' was not opened\n" );
     else
     printf( "The file 'crt_fopen.c' was opened\n" );

   // Open for write
   if( (stream2 = fopen( "data2", "w+" )) == NULL ) // C4996
      printf( "The file 'data2' was not opened\n" );
   else
      printf( "The file 'data2' was opened\n" );

   // Close stream if it is not NULL
   if( stream)
   {
      if ( fclose( stream ) )
      {
         printf( "The file 'crt_fopen.c' was not closed\n" );
      }
   }

   // All other files are closed:
   // numclosed = _fcloseall( );
   printf( "Number of files closed by _fcloseall: %u\n", numclosed );
}

// The function to be executed by all threads 
void *myThreadFun(void *vargp) 
{ 
    // Store the value argument passed to this thread 
    int *myid = (int *)vargp; 
  
    // Let us create a static variable to observe its changes 
    static int s = 0; 
  
    // Change static and global variables 
    ++s; ++g; 
  
    // Print the argument, static and global variables 
    printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g); 
} 

thread_fun() {
    int i; 
    pthread_t tid; 
  
    // Let us create three threads 
    for (i = 0; i < 3; i++) 
        pthread_create(&tid, NULL, myThreadFun, (void *)&tid); 
  
    pthread_exit(NULL); 

}
