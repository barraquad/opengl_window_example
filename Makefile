test:
	clang++ -o test hello.cpp glad.c -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl
clean:
	rm -rf test
