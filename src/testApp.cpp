#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	
	LocalAddressGrabber :: availableList();
	output = LocalAddressGrabber :: getIpAddress("en1");
	
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofDrawBitmapString(ofToString(output) , 20, 20);
}

