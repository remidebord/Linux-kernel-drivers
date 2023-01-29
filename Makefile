ifeq ($(DEBUG), y)
	DEBFLAGS = -Wall -O -g -DDEBUG
else
	DEBFLAGS = -Wall -O
endif

obj-m := misc1.o

misc1.objs := misc1.o

SRC := $(shell pwd)
ccflags-y += $(DEBFLAGS)

EXTRA_CFLAGS=-I$(PWD)/include

ifndef KERNEL_SRC
KERNEL_SRC=$(SDKTARGETSYSROOT)/usr/src/kernel/
endif

all:
	$(MAKE) -C $(KERNEL_SRC) M=$(SRC) modules

clean:
	$(MAKE) -C $(KERNEL_SRC) M=$(SRC) clean

