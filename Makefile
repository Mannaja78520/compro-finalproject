### Windows
all: compile link

compile:
	g++ -Isrc/include -c main.cpp -DSFML_STATIC

 link:
	g++ main.o -o main -Lsrc/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopeng132 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

# ### Linux
# all: compile link

# compile:
# 	g++ -c main.cpp -DSFML_STATIC

# link:
# 	g++ main.o -o main -Lsrc/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopeng132 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

clean:
	# rm -f main *.o
