// ofApp.h
#pragma once
#include "ofMain.h"
#include "ofxMaxim.h"
struct ofApp : ofBaseApp {
	maxiOsc osc;
	float freq = 220.0f;
	void setup() {
		ofSoundStreamSettings s;
		s.numInputChannels = 0;
		s.numOutputChannels = 2;
		s.sampleRate = 48000;
		s.bufferSize = 512;
		s.setOutListener(this);
		ofSoundStreamSetup(s);
	}
	void audioOut(ofSoundBuffer & out) {
		for (size_t i = 0; i < out.getNumFrames(); ++i) {
			float v = osc.sinewave(freq) * 0.2f;
			out[i * 2 + 0] = v;
			out[i * 2 + 1] = v;
		}
	}
	void draw() { ofDrawBitmapStringHighlight("ofxMaxim: 220 Hz test tone",
		20, 30); }
};
