ALVO = banco

CC = g++

CPPFLAGS = -Wall

ARQ_FONTE = main.cpp Cliente.cpp ContaBancaria.cpp

OBJ = $(ARQ_FONTE:.cpp=.o)

all: $(ALVO)

$(ALVO): $(OBJ)
	$(CC) $(CPPFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(ALVO)
