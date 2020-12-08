#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

#include "hello1.h"

MODULE_AUTHOR("Danil Solovjov <mr.danechek0@gmail.com>");
MODULE_DESCRIPTION("Hello1 module");
MODULE_LICENSE("Dual BSD/GPL");

int print_hello(uint t) {
  if (t == 0) {
    pr_warn("The parameter is equaled to zero");
  } 
  else if (t >=5 && t <= 10) {
    pr_warn("The parameter is between 5 and 10");
  } 
  else if(t > 10) {
    pr_err(KERN_ERR "The parameter is greater than 10");
    return -EINVAL;
  }
  
  int i = 0;
  for (; i < t; i++) {
    pr_info(KERN_INFO "Hello world!\n");	  
  }
  return 0;	
}

EXPORT_SYMBOL(print_hello);

static int __init hello1_init(void)
{
  pr_info("Initialization of Hello1 module!");
  return 0;
}

static void __exit hello1_exit(void)
{
	/* Do nothing here right now */
}

module_init(hello1_init);
module_exit(hello1_exit);
