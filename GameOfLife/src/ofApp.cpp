#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(236);
	cam.setFov(90);
	cam.setPosition(500, 500, 900);
	
	grid.setup();

	string guiName = "settings";
	gui.setup(guiName);
	gui.add(gui_options.setup("OPTIONS", ""));
	gui.add(gui_fpsSlider.setup("FrameratePerSecond", 10, 1, 60));
	gui.add(gui_probabilitySlider.setup("Probability", 0.5, 0.01, 0.99));
	gui.add(gui_color.setup("COLOR", ""));
	gui.add(gui_useOneColor.setup("Use One Color", false));
	gui.add(color.set(ofColor::white));

	isPaused = false;
	ofSetFrameRate(gui_fpsSlider);

}

//--------------------------------------------------------------
void ofApp::update(){

	if (!isPaused) {

		grid.nextStep(color.get());
	}

	if (grid.probability != gui_probabilitySlider) {
		grid.probability = gui_probabilitySlider;
		grid.setup();
	}
	
	grid.isOneColor = gui_useOneColor;
	ofSetFrameRate(gui_fpsSlider);

}

//--------------------------------------------------------------
void ofApp::draw(){

	gui.draw();

	cam.begin();

	grid.draw();

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == 'p') {
		if (!isPaused) {
			isPaused = true;
		}
		else {
			isPaused = false;
		}
	}

	if (key == 'r') {
		if (grid.arr.size() != NULL) {
			grid.setup();
		}
	}

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

//void ofApp::init_c(int _c) {
//
//	for (int i = 0; i < 100; ++i) {
//		for (int j = 0; j < 100; ++j) {
//
//			arr[_c][i][j] = std::round(ofRandom(1));
//		}
//	}
//}
//
//void ofApp::draw_c(int _c) {
//
//	ofSetColor(ofColor::ghostWhite);
//	ofFill();
//
//	for (int i = 0; i < 100; ++i) {
//		for (int j = 0; j < 100; ++j) {
//
//			if (arr[_c][i][j] == 1) {
//
//				ofDrawRectangle(glm::vec2(i * 10.24, j * 10.24), ofGetWidth() / 100, ofGetHeight() / 100);
//			}
//
//			else {
//
//			}
//		}
//	}
//
//}
//
//int ofApp::suma(int _c, int i, int j) {
//
//	int ip, im, jp, jm;
//
//	if (i < 100 - 1)
//		ip = i + 1;
//	else
//		ip = 0;
//
//	if (i > 0)
//		im = i;
//	else
//		im = 100 - 1;
//
//	if (j < 100 - 1)
//		jp = j + 1;
//	else
//		jp = 0;
//
//	if (j > 0)
//		jm = j - 1;
//	else
//		jm = 100 - 1;
//
//	return arr[_c][ip][j] + arr[_c][im][j] + arr[_c][i][jp] + arr[_c][i][jm] +
//		arr[_c][ip][jp] + arr[_c][im][jm] + arr[_c][im][jp] + arr[_c][ip][im];
//}
//
//void ofApp::gameoflife(int _c) {
//
//	for (int i = 0; i < 100; ++i) {
//		for (int j = 0; j < 100; ++j) {
//
//			int s = suma(_c, i, j);
//
//			if (arr[_c][i][j] && (s == 2 || s == 3))
//				arr[_c][i][j] = 1;
//
//			else
//				if (!arr[_c][i][j] && s == 3)
//					arr[_c][i][j] = 1;
//
//				else
//					arr[_c][i][j] = 0;
//
//		}
//	}
//
//}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
