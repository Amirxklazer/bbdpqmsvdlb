# AOS 11 Makefile
include $(DEVKITPRO)/libnx/switch_rules

# The name of your output file
TARGET		:=	aos11
BUILD		:=	build
SOURCES		:=	.
INCLUDES	:=	include
DATA		:=	data
ARCH	:=	-march=armv8-a -mtune=cortex-a57 -mtp=soft -fPIE

# Compilation flags
CFLAGS	:=	-g -Wall -O2 -ffunction-sections \
			$(ARCH) $(DEFINES)
CXXFLAGS	:=	$(CFLAGS) -fno-rtti -fno-exceptions

# Linker flags
LDFLAGS	=	-specs=$(DEVKITPRO)/libnx/switch.specs $(ARCH) -Wl,--as-needed

LIBS	:=	-lnx

# Standard build targets
.PHONY: all clean

all: $(OUTPUT).pfs0 $(OUTPUT).nro

clean:
	@echo clean ...
	@rm -fr $(BUILD) $(TARGET).pfs0 $(TARGET).nro $(TARGET).nacp

# The magic build rules
include $(DEVKITPRO)/libnx/switch_rules
