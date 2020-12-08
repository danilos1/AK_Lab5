#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include "hello1.h"

extern int print_hello(uint);

MODULE_AUTHOR("Danil Solovjov <mr.danechek0@gmail.com>");
MODULE_DESCRIPTION("The module is intended for showing 'Hello, world' message according to parameter 't', which defines how many times the message will be displayed");
MODULE_LICENSE("Dual BSD/GPL");

static uint t = 1;

module_param(t,uint,S_IRUGO);
MODULE_PARM_DESC(t, "A parameter, which defines how many times the message will be displayed");

static int __init hello2_init(void)
{
  return print_hello(t);
}


static void __exit hello2_exit(void)
{
	/* Do nothing here right now */
}

module_init(hello2_init);
module_exit(hello2_exit);
