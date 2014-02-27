#include <stdio.h>
 
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>
 
void alloc_mem(void)
{
        char *ptr;
        ptr = kmalloc(1024, GFP_KERNEL);
        ptr = vmalloc(512);
        ptr = kmalloc(2048, GFP_KERNEL);
 }
 
int kmemleak_test_init(void)
{
        printk("Kmemleak Test Init");
        alloc_mem();
        return 0;
}
 
static void kmemleak_test_exit(void)
{
        printk("Kmemleak test de-init");
}
 
module_init(kmemleak_test_init);
module_exit(kmemleak_test_exit);
 
MODULE_LICENSE("Proprietary");
MODULE_AUTHOR("Babu");

}
