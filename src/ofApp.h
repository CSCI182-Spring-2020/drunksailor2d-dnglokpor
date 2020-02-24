#pragma once

#include "ofMain.h"



class ofApp : public ofBaseApp{
private:
	// program constans
	static const int WIDTH = 20;
	static const int HEIGTH = 20;
	static const int MAX_STEPS = 1000;

	// direction enum
	enum Directions { NORTH, EAST, SOUTH, WEST };

	// values
	int _heatMap[WIDTH][HEIGTH];
	int _curPosX;
	int _curPosY;
	Directions _nextDir;
	int _maxSteps;
	float _alpha;
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
		
};
