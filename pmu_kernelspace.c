#include <linux/module.h>

static inline void asm_user_enable(void *a)
{
	asm volatile("mcr p15, 0, %0, c9, c14, 0": : "r"(1));
}

int __init initfunction(void)
{
	asm_user_enable();	
	return 0;
}
int __exit exitfunction(void)
{
	printk(KERN_ALERT "pmu user enable exit");
	return 0;
}

module_init(initfunction);
module_exit(exitfunction);

