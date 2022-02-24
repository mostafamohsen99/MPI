on this file there are 2 source codes:
1-maclurin(cos)
2-mpi

1-Maclurin(cos)[sequential code]

   this is program is used to calculate the maclurin series of cos(X) ,the user must enter the value of x
   and the upper limit until this code ,and the result will be printed sequentially
2- m_p_i [m_p_i parallel code]
   this is program is used to calculate the maclurin series of cos(X) ,the user must enter the value of x
   and the upper limit until this code ,and the result will be printed parallel 
 
to increase the number of parallel processes you must build m_p_i code then go to the plac of m_p_i.exe and
then run that command
                    mpiexec -n <no of processes> m_p_i.exe
and choose the number of processes to put on <no of processes>