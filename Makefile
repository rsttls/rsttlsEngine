LDFLAGS := -lSDL2 -lSDL2_image -lstdc++ -lSDL2_ttf
INCLUDES := -Isrc

CCFLAGS := $(INCLUDES)

ifeq ($(DEBUG),1)
CCFLAGS += -g
LDFLAGS += -g
BUILDDIR := build/debug
else
CCFLAGS += -O2
LDFLAGS += -O2
BUILDDIR := build/release
endif

SRCDIR := src

SOURCES := $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(SRCDIR)/**/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
DEPFILES := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.d,$(SOURCES))

TARGET := $(BUILDDIR)/main.exe

.PHONY: all run debug clean compile

all: run

run: compile
	./$(TARGET)

compile:
	make build -j16

build: $(TARGET)

debug:
	make compile DEBUG=1

clean:
	rm -rf build

$(TARGET): $(OBJECTS)
	gcc -o $@ $^ $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(BUILDDIR)/%.d | $(BUILDDIR)
	@mkdir -p $(dir $@)
	gcc -MMD -o $@ $< -c $(CCFLAGS)

$(BUILDDIR):
	@mkdir -p $@

$(DEPFILES): ;

-include $(wildcard $(DEPFILES))

# $@ - vystup
# $< - prvni dependency
# $^ - vsechny dependency
