libnn_SRCS:=neuron.cpp neural_network.cpp
libnn_OBJS:=$(subst .cpp,.o,$(libnn_SRCS))

LIB:=libnn.so

TARGET:=example
TARGET_SRCS:=$(addsuffix .cpp,$(TARGET))

CPPFLAGS:=-Wall -Wextra -Weffc++ -std=c++17
ifeq ($(DEBUG),1)
CPPFLAGS+=-g
endif

LIB_CPPFLAGS:=$(CPPFLAGS) -fPIC
LIB_LDFLAGS:=-shared

ifneq ($(V),1)
Q:=@
else
Q:=
endif


default: $(TARGET)

$(TARGET): $(TARGET_SRCS) $(LIB)
	@echo "LD $@"
	$(Q)g++ -o $@ $(TARGET_SRCS) -L. -lnn $(CPPFLAGS) -Wl,-rpath -Wl,.

%.o: %.cpp
	@echo "CPP $<"
	$(Q)g++ -c -o $@ $< $(LIB_CPPFLAGS)

libnn.so: $(libnn_OBJS)
	@echo "LD $@"
	$(Q)g++ -o $@ $(libnn_OBJS) $(LIB_LDFLAGS)

clean:
	@echo "CLEAN"
	$(Q)rm -f $(LIB) $(TARGET) *.o
