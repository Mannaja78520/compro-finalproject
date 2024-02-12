<<<<<<< HEAD
# ### Windows
# all: compile link

# compile:
# 	g++ -Isrc/include -c main.cpp

#  link:
# 	g++ main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

### Linux
all: compile link

compile:
	g++ -c main.cpp

link:
	g++ main.o -o main -lsfml-graphics -lsfml-window -lsfml-system
=======
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
>>>>>>> 961998ac88a31ee74b9bf2357a2e01d90746d70c

clean:
	# rm -f main *.o
