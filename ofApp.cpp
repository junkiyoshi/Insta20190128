#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(3);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	ofColor color;
	for (int v = 0; v < 360; v += 10) {

		vector<glm::vec3> vertices_1;
		vector<glm::vec3> vertices_2;
		int u_start = v * 3 + ofGetFrameNum() * 2;

		color.setHsb(ofMap(v, 0, 360, 0, 255), 255, 230);
		ofSetColor(color);

		ofFill();
		ofDrawSphere(this->make_point(250, 50, (u_start) * DEG_TO_RAD, v * DEG_TO_RAD), 10);
		ofDrawSphere(this->make_point(250, 50, (u_start + 180) * DEG_TO_RAD, v * DEG_TO_RAD), 10);

		for (int u = u_start + 20; u <= u_start + 150; u += 10) {

			vertices_1.push_back(this->make_point(250, 50, u * DEG_TO_RAD, v * DEG_TO_RAD));
			vertices_2.push_back(this->make_point(250, 50, (u + 180) * DEG_TO_RAD, v * DEG_TO_RAD));
		}

		ofNoFill();

		ofBeginShape();
		ofVertices(vertices_1);
		ofEndShape();

		ofBeginShape();
		ofVertices(vertices_2);
		ofEndShape();
	}

	this->cam.end();
}

//--------------------------------------------------------------
glm::vec3 ofApp::make_point(float R, float r, float u, float v) {

	// 数学デッサン教室 描いて楽しむ数学たち　P.31

	float x = (R + r * cos(u)) * cos(v);
	float y = (R + r * cos(u)) * sin(v);
	float z = r * sin(u);

	return glm::vec3(x, y, z);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}