# MOES Lab 01
Laboratory 1 of the Modeling and Optimization of Embedded Systems course of the master degree in Embedded System (Electronic Engineering) of Politecnico di Torino, academic year 2020/2021.<br/>
Tested with SystemC v2.3.3.

## Exercise 1 - HelloWorld
A SystemC module is a C++ class, it encapsulates a hardware or software description.
SystemC defines that any module has to be derived from the existing class `sc_module`, and supplies a macro `SC_MODULE` to simplify the declaration process.

Inside the folder Exercise_1, there are two versions of HelloWorld realized by plain C++ and SystemC respectively, which simply print “Hello World !” on the console.
Read the comments on the source codes and compare the two versions. Finally compile the source code and run the obtained executable.
### Tip 1
To compile the code, open a terminal and change to the directory where the source file located.
- For C++ version, type `g++ HelloWorld.cpp main.cpp o run.x` in the terminal to compile the source code.
- For SystemC version, type `make` in the terminal to compile the source code.
### Tip 2
After compilation, an executable file named *run.x* is created. To run the simulation, just type `./run.x` in the terminal.
If you want to delete all created files (including the executable itself),
- for C++ version, type `rm run.x` in the terminal.
- for SystemC version, ty pe `make clean` in the terminal.

## Exercise 2 - Modules
All programs need a starting point.
In C/C++, the starting point is called `main()`.
In SystemC, the starting point is called `sc_main()`, and this is where elaboration and simulation start.
By convention, SystemC programmers simply name the file containing `sc_main()`, as *main.cpp* to indicate to the C/C++ programmer that this is the place where everything begins.
The actual `main()` routine is located in the SystemC library itself and is not exposed to the user.

Inside the folder *Exercise_2*, an example `BasicModule` lists the fundamental and minimum elements to compose a SystemC module.
Read and compile the source code, and run the obtained executable.
Write a module from scratch using what you know, to display an output that could count down from 3 to 1.
Note that these simple examples do not use the `wait()` function call only because they involve just one `SC_THREAD`.
**When there is more than one, the `wait()` function must be called to allow other SC_THREADs or SC_METHODs to run.**
Simulation time may or may not advance (depending on whether you wait for an event that occurs in another delta cycle at the same simulation time, or wait for time).

### Tip 1
Within `sc_main()`, code executes in three distinct major stages: elaboration, simulation, and post processing.
- Elaboration, performed by executing the **constructors** of the various SC_MODULEs in the design, invokes code to register simulation processes and performs the connections between design module instances.
- `sc_start()` invokes the simulation stage where process code representing the behavior of the model executes.
This call lasts as long as the simulator is running, and returns to `sc_main` after simulation is complete.
Simulation completes when **the first** of three events occurs:
  1. Either there are no more events to be simulated in the queue, i.e. the design has reached quiescence.
  2. Or the `sc_stop()` method is called by one of the processes.
  3. Or the **simulation** time (optionally) specified as an argument to `sc_start()` has elapsed.
- Finally, post processing stage begins after returning from `sc_start()`.
During this stage (not used in the labs) waveform files are closed, errors detected by monitors are checked and reported, and so on.

### Tip 2
- To compile the code, open a terminal and change to the directory where the source file located.
Then type `make` in the terminal.
- After compilation, an executable file named *run.x* is created. To run the simulation, just type `./run.x` in the terminal.
- If you want to delete all created files (including the executable itself), type `make clean` in the terminal.

## Exercise 3 - sc_time

## Exercise 4 - sc_event

## Exercise 5 - TicToc



