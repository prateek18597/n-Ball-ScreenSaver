all:
	#make clean;
	g++ -std=c++11 -pthread Main.cpp Start.cpp Physics.cpp Threads.cpp Controls.cpp Graphics.cpp -lGL -lGLU -lglut -o ScreenSaver;	
	@./ScreenSaver 10	
	#make -s execute;
execute:
	#echo "Enter Number of Balls (Should be less than 100) :"; 	
	g++ -std=c++11 -pthread Main.cpp Start.cpp Physics.cpp Threads.cpp Controls.cpp Graphics.cpp -lGL -lGLU -lglut -o ScreenSaver;
	@./ScreenSaver $(num_thread)
clean:
	@rm -r ScreenSaver;

