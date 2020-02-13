#include <stdio.h>
#define 100
static inline void asm_counter_enable(unsigned long val)
{
	asm volatile("mcr p15, 0, %0, c9, c12, 1": : "r"(val));
}

static inline void asm_select_counter(unsigned long val)
{
	asm volatile("mcr p15, 0, %0, c9, c12, 5": : "r"(val));
}

static inline void asm_event_select(unsigned long val)
{
	asm volatile("mcr p15, 0, %0, c9, c13, 1": : "r"(val));
}

static inline unsigned long asm_read_counter(void)
{
	unsigned long val;
	asm volatile("mrc p15, 0, %0, c9, c13, 2": "=r"(val):);
	return val;
}

static inline void asm_enable_counters(void)
{
	asm volatile("mcr p15, 0, %0, c9, c12, 0": :"r"(1));
}
static inline void asm_disable_counters(void)
{
	asm volatile("mcr p15, 0, %0, c9, c12, 0": :"r"(0));
}
static inline void asm_reset_counters(void)
{
	unsigned long val;
	asm volatile("mrc p15, 0, %0, c9, c12, 0": "=r"(val):);
	val=val|0x2;
	asm volatile("mcr p15, 0, %0, c9, c12, 0": :"r"(val));
}

int main()
{
	int event=0x7,counter=1,a[SIZE],i=0;
	unsigned long count;
	asm_enable_counters();
	asm_select_counter(counter);
	asm_event_select(event);
	asm_reset_counters();
	asm_counter_enable(0xF);
	for(;i<SIZE;i++)
	{
		a[i]=i;
	}
	asm_disable_counters();
	count=asm_read_counter();
	printf("count: %ld\n",count);
	return 0;
}
