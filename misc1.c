#include <linux/fs.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/module.h>

static int misc_open(struct inode *inode, struct file *file)
{
	pr_info("open.\n");
	
	return 0;
}

static int misc_release(struct inode *inode, struct file *file)
{
	pr_info("release.\n");
	
	return 0;
}

static ssize_t misc_read(struct file *file, char __user *user_buffer, size_t size, loff_t *offset)
{
	pr_info("read.\n");
	
	return 0;
}

static ssize_t misc_write(struct file *file, const char __user *user_buffer, size_t size, loff_t * offset)
{
	pr_info("write.\n");
	
	return 0;
}

const struct file_operations misc_fops = {
	.owner = THIS_MODULE,
	.open = misc_open,
	.release = misc_release,
	.read = misc_read,
	.write = misc_write,
	.llseek = no_llseek,
};

struct miscdevice misc_device = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "misc_example",
	.fops = &misc_fops,
};

static int __init misc_init(void)
{
	int error;

	pr_info("init.\n");

	error = misc_register(&misc_device);
	if (error) {
		pr_err("misc register failed.\n");
		return error;
	}
 
	return 0;
}

static void __exit misc_exit(void)
{
	pr_info("exit.\n");

	misc_deregister(&misc_device);
}
 
module_init(misc_init)
module_exit(misc_exit)
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Remi Debord>");
MODULE_DESCRIPTION("misc driver exmaple");
MODULE_VERSION("1.0");
