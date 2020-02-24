#include <iostream>
#include "ofApp.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


//--------------------------------------------------------------
void ofApp::setup(){
	// window setup
	ofBackground(128, 128, 128);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

	// seed the random generator
	srand(time(NULL));

	// set initial position:
	_curPosX = WIDTH / 2;
	_curPosY = HEIGTH / 2;

	// zero out the board
	for (int x = 0; x < WIDTH; x++)
		for (int y = 0; y < HEIGTH; y++)
			_heatMap[x][y] = 0;

	// record initial position
	_heatMap[_curPosX][_curPosY]++;

	for (int i = 0; i < MAX_STEPS; i++) {
		// randomly get a direction
		_nextDir = static_cast<Directions>(rand() % 4);

		// move in that direction
		switch (_nextDir) {
		case NORTH:
			if (_curPosY > 0) // we make sure we are not at the board limit
				_curPosY--; // move up
			break;
		case EAST:
			if (_curPosX < (WIDTH - 1)) // we make sure we are not at the board limit
				_curPosX++; // move right
			break;
		case SOUTH:
			if (_curPosY < (HEIGTH - 1)) // we make sure we are not at the board limit
				_curPosY++; // move down
			break;
		default: //case WEST:
			if (_curPosX > 0) // we make sure we are not at the board limit
				_curPosX--; // move left
			break;
		}

		// record step position
		_heatMap[_curPosX][_curPosY]++;
	}

	// find tile the most stepped in at this point
	_maxSteps = 0;
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGTH; y++) {
			if (_maxSteps < _heatMap[x][y])
				_maxSteps = _heatMap[x][y];
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	// drawing constants
	const int minStep = 0;
	const int noColor = 0;
	const int fullColor = 255;
	
	// box dimensions: Example shows boxes of 40px wide but that won't fit in the window
	float width = 1.5 * WIDTH; // 30px wide
	float heigth = 1.5 * HEIGTH; // 30px high

	// draw an empty black box behind the heatmap
	ofSetColor(ofColor::black);
	ofDrawRectangle(0, 0, width * WIDTH, heigth * HEIGTH);

	// draw the heatmap
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGTH; y++) {
			// give the highest coloration to the most stepped in box
			_alpha = ofMap(_heatMap[x][y], minStep, _maxSteps, noColor, fullColor);
			
			// determine color gradient
			ofSetColor(fullColor, noColor, noColor, _alpha); // red plus transparency
			
			// pixel draw every box
			ofDrawRectangle(x * width, y * heigth, width, heigth);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
