COMPILER := g++
INCLUDE_DIR := -I"c:/dev/include"
LIB_DIR := -L"c:/dev/lib"
LIBS := -lraylib -lopengl32 -lgdi32 -lwinmm

SRC_FILES := ./main.cpp
OUTPUT := ./main.exe

build:
	$(COMPILER) $(SRC_FILES) $(INCLUDE_DIR) $(LIB_DIR) $(LIBS) -o $(OUTPUT)

run:
	$(OUTPUT)