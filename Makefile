CC       := gcc
TARGET   := hybris_gbm.so
SRC      := main.c

PKG_DEPS := libdrm gbm libgralloc android-headers

CFLAGS   := $(shell pkg-config --cflags $(PKG_DEPS))
CFLAGS   += -fPIC -Wall -Wextra -O3 -shared
LDLIBS   := $(shell pkg-config --libs $(PKG_DEPS))

RM       := rm -f
INSTALL  := install

PREFIX   ?= /usr
LIBDIR   ?= $(PREFIX)/lib/aarch64-linux-gnu/gbm

.PHONY: all clean install uninstall

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

install: $(TARGET)
	$(INSTALL) -d $(DESTDIR)$(LIBDIR)
	$(INSTALL) -m 0755 $(TARGET) $(DESTDIR)$(LIBDIR)/$(TARGET)

uninstall:
	$(RM) $(DESTDIR)$(LIBDIR)/$(TARGET)

clean:
	$(RM) $(TARGET)
