//Use MPI_Bcast() and MPI_Reduce() routines to implement the program of part I.

#include <mpi.h>
#include <stdio.h>

#define N 1000

int main(int argc, char **argv){
MPI_Init(&argc, &argv);
int rank, size;
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);

int chunkSize=100;
int a2[1000];
int partialSum=0;
int globalSum=0;
int buffer[1];
int holder=0;

if(rank==0){
for(int i=0; i<N;i++){
a2[i]=i+1;}
}
MPI_Bcast(a2, N, MPI_INT,0, MPI_COMM_WORLD);

for(int y=rank*(N/size); y<(rank*(N/size)+(N/size)); y++){
partialSum+=a2[y];
}

MPI_Reduce(&partialSum,&globalSum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

if(rank==0){
printf("the sum is %d\n", globalSum);
}
MPI_Finalize();
}
