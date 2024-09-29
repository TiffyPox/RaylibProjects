SRC := $(wildcard *.cpp)

INCLUDES := -I"C:/dev/include"
LIBS := -L"C:/dev/lib"
LINK := -lraylib -lopengl32 -lgdi32 -lwinmm
OUTPUT := ./builds/main.exe

all:
	$(MAKE) build
	$(MAKE) copy
	$(MAKE) run

build:
	if not exist builds mkdir builds
	g++ $(SRC) $(INCLUDES) $(LIBS) $(LINK) -o $(OUTPUT)

copy:
	if not exist resources mkdir resources
	if not exist builds\resources mkdir builds\resources
	xcopy /E /I /Y resources builds\resources

run:
	$(OUTPUT)
	