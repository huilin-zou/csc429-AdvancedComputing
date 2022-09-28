//Using MPI program to print out “Hello World from process xxx of total xxx!”

#include <stdio.h>
#include <mpi.h>

int main (int argc, char** argv)
{
int my_rank, my_size;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
MPI_Comm_size(MPI_COMM_WORLD, &my_size);

printf("Hello world from process %d of total %d.\n", my_rank, my_size);

MPI_Finalize();
}
