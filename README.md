# ARM PMU test
Experimenting with the ARM Performance Monitoring Unit

Demonstration of capturing STR instruction count in PMU counters

1. ***pmu_kernelspace.c*** should be compiled with kernel sources to generate a loadable kernel module
2. ***pmu_userspace.c*** is a userspace program and can be compiled and executed once the previous kernel modules is loaded

