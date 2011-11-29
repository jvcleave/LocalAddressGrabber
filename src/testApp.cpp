#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	
	LocalAddressGrabber localAddressGrabber;
	output = localAddressGrabber.getIpAddress();
	
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofDrawBitmapString("YOUR IP ADDRESS FOR en0 is " + output , 20, 20);
}

