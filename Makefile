CC := g++ -w
INC := include/
SRC := src/
BIN := bin/

WOR := WithoutRead/
WR := WithRead/

all: read noread

read:
	@cd $(SRC)$(WR) && $(MAKE)

noread:
	@cd $(SRC)$(WOR) && $(MAKE)

clean:
	@cd $(SRC)$(WR) && $(MAKE) clean 
	@cd $(SRC)$(WOR) && $(MAKE) clean