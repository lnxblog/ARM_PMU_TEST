#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/platform_device.h>

static inline void asm_user_enable()
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

}

static struct platform_driver pmu_user_enable = {
	.driver = {
		.name   = "pmu enable",
		.owner  = THIS_MODULE,
	}
};

module_init(initfunction);
module_exit(exitfunction);

