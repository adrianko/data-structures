CC		= gcc

BINDIR 	= bin
SRCDIR  = src
OBJDIR  = obj

APP     = $(BINDIR)/linked_list

SRCS    := $(shell find $(SRCDIR) -name '*.c')
SRCDIRS := $(shell find . -name '*.c' -exec dirname {} \; | uniq)
OBJS    := $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

CFLAGS  = -Wall
LDFLAGS =


all: $(APP)
	
run: 
	$(APP) 

$(APP) : buildrepo $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) -rf $(OBJDIR)
	$(RM) -rf $(BINDIR)

distclean: clean
	$(RM) $(APP)

buildrepo:
	@$(call make-repo)

define make-repo
	for dir in $(SRCDIRS); \
	do \
		mkdir -p $(OBJDIR)/$$dir; \
	done

	mkdir -p $(BINDIR)
endef