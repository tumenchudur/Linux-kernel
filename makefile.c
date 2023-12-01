#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/slab.h>

struct birthday
{
    int day;
    int month;
    int year;
    struct list_head list; // Linked list member
};

static LIST_HEAD(birthday_list);

static int simple_init(void)
{
    struct birthday *person;
    int i;

    printk(KERN_INFO "Loading Module\n");

    for (i = 0; i < 5; i++)
    {
        person = kmalloc(sizeof(*person), GFP_KERNEL);
        person->day = i + 1;
        person->month = 9;
        person->year = 2000 + i;
        INIT_LIST_HEAD(&person->list);

        list_add_tail(&person->list, &birthday_list);
    }

    struct birthday *ptr;
    list_for_each_entry(ptr, &birthday_list, list)
    {
        printk(KERN_INFO "Birthday: %d/%d/%d\n", ptr->day, ptr->month, ptr->year);
    }

    return 0;
}

static void simple_exit(void)
{
    struct birthday *ptr, *next;

    printk(KERN_INFO "Removing Module\n");

    list_for_each_entry_safe(ptr, next, &birthday_list, list)
    {
        list_del(&ptr->list);
        kfree(ptr);
    }
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/slab.h>

struct birthday
{
    int day;
    int month;
    int year;
    struct list_head list; // Linked list member
};

static LIST_HEAD(birthday_list);

static int simple_init(void)
{
    struct birthday *person;
    int i;

    printk(KERN_INFO "Loading Module\n");

    for (i = 0; i < 5; i++)
    {
        person = kmalloc(sizeof(*person), GFP_KERNEL);
        person->day = i + 1;
        person->month = 9;
        person->year = 2000 + i;
        INIT_LIST_HEAD(&person->list);

        list_add_tail(&person->list, &birthday_list);
    }

    struct birthday *ptr;
    list_for_each_entry(ptr, &birthday_list, list)
    {
        printk(KERN_INFO "Birthday: %d/%d/%d\n", ptr->day, ptr->month, ptr->year);
    }

    return 0;
}

static void simple_exit(void)
{
    struct birthday *ptr, *next;

    printk(KERN_INFO "Removing Module\n");

    list_for_each_entry_safe(ptr, next, &birthday_list, list)
    {
        list_del(&ptr->list);
        kfree(ptr);
    }
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");