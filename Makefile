#
# Kernel Makefile.
#

#
# Target
#
#ARCH            := mips
#PLATFORM        := atheros
ARCH		 := x86_32
PLATFORM	 := generic

TARGET          := apefish-$(ARCH)-$(PLATFORM)

IMAGE           := $(TARGET).elf
MAP		:= $(TARGET).map

#
# Toolchain
#

# TODO: fix this
ifeq ($(ARCH), mips)
	CC_DIR          := /usr/local/xtools/mips-unknown-elf/bin
	CC     	        := $(CC_DIR)/mips-elf-gcc
	LD              := $(CC_DIR)/mips-elf-ld
	OBJCOPY         := $(CC_DIR)/mips-elf-objcopy
	OBJDUMP         := $(CC_DIR)/mips-elf-objdump
else
	CC_DIR          := /usr/local/xtools/i386-unknown-elf/bin
	CC     	        := $(CC_DIR)/i386-elf-gcc
	LD              := $(CC_DIR)/i386-elf-ld
	OBJCOPY         := $(CC_DIR)/i386-elf-objcopy
	OBJDUMP         := $(CC_DIR)/i386-elf-objdump
endif

#
# Build paths and settings
#
ARCH_DIR     = arch/$(ARCH)
PLATFORM_DIR = arch/$(ARCH)/$(PLATFORM)

include $(PLATFORM_DIR)/boot/Makefile.inc
-include $(PLATFORM_DIR)/Makefile.inc

include arch/generic/Makefile.inc
include kernel/Makefile.inc
include lib/Makefile.inc

CC_OPTS         := -Wall -Wformat -nostdinc -nostdlib -ffreestanding \
                   -Iinclude \
		   -I$(ARCH_DIR)/include \
		   -I$(PLATFORM_DIR)/include \
                   -Iarch/generic/include

LD_SCRIPT       := $(PLATFORM_DIR)/boot/boot.ld
LD_OPTS         := -static -T $(LD_SCRIPT) -o $(IMAGE) -Map $(MAP)

OBJS            := $(addsuffix .o,$(basename $(SRCS)))


.PHONY: all
all: $(IMAGE)

.PHONY: install
install: $(IMAGE)
	@cp $< /tftpboot/

.PHONY: clean
clean:
	@$(RM) $(OBJS)
	@$(RM) $(IMAGE) $(MAP)

$(IMAGE): $(OBJS)
	$(LD) $(LD_OPTS) $(OBJS)

%.o: %.c
	$(CC) $(CC_OPTS) -c -o $@ $<
%.o: %.S
	$(CC) $(CC_OPTS) -c -o $@ $<
