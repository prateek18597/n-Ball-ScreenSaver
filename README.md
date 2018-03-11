# n-Ball ScreenSaver

This is a n Ball 3D ScreenSaver where n is number between 1 and 99.

### System Requirement 

Linux Based Operating System.
G++ complier
OpenGL GLUT library
pthread Library

### Instructions

1. Extract the 2016CSJ0002_2016CSJ0049.tar.gz file.
2. Change Directory to 2016CSJ0002_2016CSJ0049.
3. Open terminal in this folder.
4. To run the default version of the program execute "make",this version contains 10 balls.
5. To run the advanced version of the program, execute "make execute num_thread=<num of balls>".
6. To get the design document, execute "make doc".This will generate the Design Document in doc folder.

### To see Change Document and Design Document

1. Extract the 2016CSJ0002_2016CSJ0049.tar.gz file.
2. Change Directory to 2016CSJ0002_2016CSJ0049/doc.
3. Open terminal in this folder.
4. To generate pdf of change document of the program execute "make".


### Features

To be accessed during run-time.

1. EarthQuake Mode:
	Press F1.
	It will rotate the camera in vertical direction.Pressing F1 again will change screensaver to normal mode. 

2. Tornado Mode:
	Press F2.
	It will rotate the camera in horizontal.Pressing F2 again will change it to normal mode.When both F1 and F2 are pressed one after other Earthquake+Tornado effect will be seen.

3. Ball Selection:
	To Select All Balls- Press Del
	To Select Single Ball (26 balls can be selected)- Press any character key "a-z".Then Increment/Decrement radius of ball(using up-down key) to check which ball is selected.
	For selecting single ball when no. of balls are more than 26 balls:
		Press F3 to decrement the selected ball number.
		Press F4 to increment the selected ball number.
	Here also increment/decrement radius after pressing F3 or F4 to detect which ball is selected.	
4. Play/Pause Ball Movement:
	Press Space Bar to Pause/Play Movement of Balls.

5. Play/Pause Camera Movement:
	Press Enter to Pause/Play Movement of Camera.

6. Size Increment/Decrement:
	Once selection of ball is done. Arrow Up will Increase the size of ball while Arrow Down will Decrease the size.

7. Speed Increment/Decrement:
	Once selection of ball is done. Arrow Right will Increase the speed of ball while Arrow Left will Decrease the speed.
	(Maximum allowed Speed is 0.8 and Minimum allowed Speed is 0.01)

8. View Selection:
	Left Mouse Click will Resets the Camera to start state.
	Rigth Mouse CLick will show the scene which was behind the camera.
9. Exit
	Press Esc.

### About The Program
	
	Balls are generated at random position in the box with random radius and random velocity.
	Balls have 5 predefined colors based on their id.
	





