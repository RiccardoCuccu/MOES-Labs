# MOES Lab 03
Laboratory 3 of the Modeling and Optimization of Embedded Systems course of the master degree in Embedded System (Electronic Engineering) of Politecnico di Torino, academic year 2020/2021.<br/>
Tested with SystemC v2.3.3.

In case of problems try to source the .bashrc file with the command `. ~/.bashrc`.

If this error occurs:
```
./run.x: error while loading shared libraries: libsystemc-2.3.3.so: cannot open shared object file: No such file or directory
```
Enter the command:
```
export LD_LIBRARY_PATH=/usr/local/systemc-2.3.3/lib-linux64:$LD_LIBRARY_PATH
```

If you want to remove the SystemC startup text enter the command:
```
export SYSTEMC_DISABLE_COPYRIGHT_MESSAGE=1
```

## Exercise 1 - Simulation cycle and advanced knowledge of sc_signal<T>


## Exercise 2 - Traffic light controller


## Exercise 3 - Traffic light controller and monitors

