CC := g++ -g -w -std=c++11 
ROOT := ../../
INC := $(ROOT)include/
SRC := $(ROOT)src/
BIN := $(ROOT)bin/
WOR := WithoutRead/
THIS := $(SRC)$(WOR)
THIS_H := $(INC)$(WOR)


FILES := $(wildcard $(SRC)*.cpp) $(wildcard $(THIS)*.cpp)
OBJECTS := $(FILES:$(SRC)%.cpp=$(BIN)$(WOR)%.o)

TARGET := $(ROOT)jitd_noread

INCLUDES := -I $(INC) -I $(SRC) -I $(THIS) -I $(THIS_H)

all: $(BIN) $(BIN)$(WOR) $(BIN)$(WOR)$(WOR) $(TARGET)

$(BIN):
	@mkdir $@

$(BIN)$(WOR):
	@mkdir $@

$(BIN)$(WOR)$(WOR):
	@mkdir $@

print:
	@echo $(FILES)
	@echo $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@

$(BIN)$(WOR)$(WOR)main.o: $(SRC)$(WOR)main.cpp
	$(CC) -c $(INCLUDES) $^ -o $@

$(BIN)$(WOR)%.o: $(SRC)%.cpp $(INC)%.h
	$(CC) -c $(INCLUDES) $< -o $@

%.h:

clean:
	rm -rf $(BIN) $(TARGET)