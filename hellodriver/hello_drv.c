#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

#define HELLO_MAJOR_NUM 290
#define HELLO_NAME "hello"

static char array[2000] = {0.};

static int hello_open(struct inode *node, struct file *pfile)
{
	printk("hello_open enter\n");
	return 0;
}

static ssize_t hello_read(struct file *pfile, char __user *pBuff, size_t size, loff_t *filepos)
{
	printk("hello_read enter\n");
	copy_to_user(pBuff,array,size);
	return size;
}

static ssize_t hello_write(struct file *pfile, const char __user *pBuff, size_t size, loff_t *filepos)
{
	printk("hello_write enter\n");
	copy_from_user (array, pBuff ,size);
	return size;
}

static long hello_ioctl (struct file *pfile, unsigned int cmd, unsigned long arg)
{
	int cnt = 0;
	int i = 0;
	
	if(_IOC_TYPE (cmd) != 0x55)
	{
		printk("wrong magic num\n");
		return -1;
	}
	switch (_IOC_NR(cmd))
	{
		case 97:
		copy_from_user(&cnt,arg,_IOC_SIZE(cmd));
		for(i; i<cnt; i++)
		{
			printk("%d ",array[i]);
			}
		printk("\n");
		break;
		
		default: break;
	}
	
}
static int hello_release(struct inode *node, struct file *pfile)
{
	printk("hello_release enter\n");
	return 0;
}

static const struct file_operations hello_fops = {
	.owner = THIS_MODULE,
	.open = hello_open,
	.read = hello_read,
	.write = hello_write,
	.release = hello_release,
	.unlocked_ioctl = hello_ioctl,
};


int flagRegisterSuccess = 0;

int __init init_hello(void)
{
	int ret;
	printk("hello world\n");
	ret = register_chrdev(HELLO_MAJOR_NUM, HELLO_NAME, &hello_fops);
	if(ret < 0)
	{
		printk("failed\n");
		return ret;
	}
	flagRegisterSuccess =1;
	return 0;
}

void __exit exit_hello(void)
{
	if(flagRegisterSuccess)
	{
		flagRegisterSuccess = 0;
		unregister_chrdev(HELLO_MAJOR_NUM,HELLO_NAME);
	}
	printk("good bye\n");
}

module_init(init_hello);
module_exit(exit_hello);

MODULE_LICENSE("GPL");
