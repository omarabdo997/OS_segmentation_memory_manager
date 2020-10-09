# Memory Management Simulator

A desktop app that simulates some memory allocation and memory de-allocation techniques using segmentation.

### How to use the simulator

#### Input
The user should input the following:
* Total memory size
* The starting address and size of the holes in the memory
* Data of the processes
* Inputs for each process
* Number of segments
* Name and size of each segment
* The method of allocation (first fit or best fit)

#### What the simulator should do
* Allocate segments using either First-Fit or Best-Fit allocation methodology.
* If one segment or more of a process can not fit in any hole, The simulator generates a message to state that this process does not fit.
* Deallocate a process (The user chooses a process to deallocate, The simulator deallocates all segments of this process and considers their spaces as holes to be
used later and adds them to any neighbouring holes.)

#### Output
The output is a graphical representing of memory layout after each allocation or deallocation. The simulator also shows the contents of the segment table for each process.


