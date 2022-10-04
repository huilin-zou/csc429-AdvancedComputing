//Use MPI_Send () and MPI _Recv() to find the partial sum

#include <mpi.h>
#include <stdio.h>
#define N 1000
int main(int argc, char **argv) {
 MPI_Init(&argc, &argv);
 int rank, size;
 MPI_Comm_rank(MPI_COMM_WORLD, &rank);
 MPI_Comm_size(MPI_COMM_WORLD, &size);
 int tag = 0;
 int chunk = N / size;
 if (rank == 0) { 
int a[N];
 
int partial_sum = 0;
 
int final_sum = 0;
for (int i = 0; i < N; i++) {
 
a[i] = i + 1;
 
}
 
for (int i = 0; i < chunk; i++) {
 
partial_sum += a[i];
 
}
 final_sum = partial_sum;
 printf("Partial sum from processor %d of total 10 processors is: %d\n",
 
rank, partial_sum);
 
for (int i = 1; i < size; i++) {
 
MPI_Send(&a[i* chunk], chunk, MPI_INT, i, tag, MPI_COMM_WORLD);
 
}
 
for (int i = 1; i < 10; i++) {
 
MPI_Recv(&partial_sum, 1, MPI_INT, i, tag, MPI_COMM_WORLD,
 
MPI_STATUS_IGNORE);
 
final_sum += partial_sum;
 
}
 printf("The final sum is: %d\n", final_sum);
 } else {
 
int b[100];
 MPI_Recv(b, chunk, MPI_INT, 0, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
 
int partial_sum = 0;
 
for (int i = 0; i < chunk; i++) {
 
partial_sum += b[i];
 
}
 printf("Partial sum from processor %d of total 10 processors is: %d\n",
 
rank, partial_sum);
 MPI_Send(&partial_sum, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
 }
 MPI_Finalize();
 return 0;
}