
/*
 * Copyright (c) 2017, GlobalLogic Ukraine LLC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    This product includes software developed by the GlobalLogic.
 * 4. Neither the name of the GlobalLogic nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY GLOBALLOGIC UKRAINE LLC ``AS IS`` AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL GLOBALLOGIC UKRAINE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

MODULE_AUTHOR("Danil Solovjov <mr.danechek0@gmail.com>");
MODULE_DESCRIPTION("The module is intended for showing 'Hello, world' message according to parameter 't', which defines how many times the message will be displayed");
MODULE_LICENSE("Dual BSD/GPL");

static uint t = 1;
module_param(t,uint,S_IRUGO);
MODULE_PARM_DESC(t, "A parameter, which defines how many times the message will be displayed");

static int __init hello(void)
{
  if (t == 0) {
    pr_warning("The parameter is equaled to zero");
  } 
  else if (t >=5 && t <= 10) {
    pr_warning("The parameter is between 5 and 10");
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


static void __exit hello_exit(void)
{
	/* Do nothing here right now */
}

module_init(hello);
module_exit(hello_exit);
