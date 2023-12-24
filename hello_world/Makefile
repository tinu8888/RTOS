export ARCH=arm
export CROSS_COMPILE=arm-linux-

KDIR := /home/src/workspace/linux-3.3.7
PWD := /home/src/workspace/programs/hello_dd


obj-m := hello_dd.o

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

