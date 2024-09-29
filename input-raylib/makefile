SRC := $(wildcard *.cpp)

INCLUDES := -I"C:/dev/include"
LIBS := -L"C:/dev/lib"
LINK := -lraylib -lopengl32 -lgdi32 -lwinmm
OUTPUT := ./builds/main.exe

all:
	$(MAKE) build
	$(MAKE) run

build:
	g++ $(SRC) $(INCLUDES) $(LIBS) $(LINK) -o $(OUTPUT)

run:
	$(OUTPUT)
	