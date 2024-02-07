### Windows
all: compile link

compile:
	g++ -Isrc/include -c main.cpp

link:
	g++ main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

# ### Linux
# all: compile link

# compile:
# 	g++ -c main.cpp

# link:
# 	g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

