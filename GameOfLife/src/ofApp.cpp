#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(10);
	grid.setup();
}

//--------------------------------------------------------------
void ofApp::update(){

	grid.nextStep();
}

//--------------------------------------------------------------
void ofApp::draw(){

	grid.draw();
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
