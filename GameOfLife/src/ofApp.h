#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "game.h"

class ofApp : public ofBaseApp{

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

		bool isPaused;
		float temp_probability = 0.5;

		Grid grid;
		ofEasyCam cam;
		
		ofxPanel gui;
		ofxLabel gui_options;
		ofxIntSlider gui_fpsSlider;
		ofxFloatSlider gui_probabilitySlider;

		ofxLabel gui_color;
		ofxToggle gui_useOneColor;
		ofParameter<ofColor> color;
};
