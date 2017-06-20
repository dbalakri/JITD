CC := g++ -w -std=c++11 
ROOT := ../../
INC := $(ROOT)include/
SRC := $(ROOT)src/
BIN := $(ROOT)bin/
WR := WithRead/
THIS := $(SRC)$(WR)
THIS_H := $(INC)$(WR)


FILES := $(wildcard $(SRC)*.cpp) $(wildcard $(THIS)*.cpp)
#OBJECTS :=$(addprefix $(BIN)$(WR), $(addsuffix .o, $(basename $(notdir $(FILES)))))
OBJECTS := $(FILES:$(SRC)%.cpp=$(BIN)$(WR)%.o)

TARGET := $(ROOT)jitd_read

INCLUDES := -I $(INC) -I $(SRC) -I $(THIS) -I $(THIS_H)

all: $(BIN) $(BIN)$(WR) $(BIN)$(WR)$(WR) $(TARGET)

$(BIN):
	@mkdir $@

$(BIN)$(WR):
	@mkdir $@

$(BIN)$(WR)$(WR):
	@mkdir $@

print:
	@echo $(FILES)
	@echo $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@

$(BIN)$(WR)$(WR)main.o: $(SRC)$(WR)main.cpp
	$(CC) -c $(INCLUDES) $^ -o $@

$(BIN)$(WR)%.o: $(SRC)%.cpp $(INC)%.h
	$(CC) -c $(INCLUDES) $< -o $@

%.h:

clean:
	rm -rf $(BIN) $(TARGET)