#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxOsc.h"
#include "fft.h"
#include "ofxSimpleFloatingGui.h"
#include "ofRtAudioSoundStream.h"

#define LW 50
#define UH 120
#define WW 400
#define HW 250
#define INTW 80
#define TH -10
#define WAPP 2 * LW + 2 * WW + INTW
#define HAPP UH + 2 * HW + LW + INTW

class ofApp : public ofBaseApp{

    public:

        void setup();
        void update();
        void draw();

        ofRectangle getBitmapStringBoundingBox(string text);

        void exit();
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

        void audioIn(ofSoundBuffer & input);

        vector <float> left;
        vector <float> right;
        vector <float> volHistory;
        vector <float> derVolHistory;
        vector <float> freq_amp;
        vector <float> magnitude;
        vector <float> phase;
        vector <float> power;
        vector <float> binsAmp;

        // frequency analysis
        FFT fftoperator;

        int 	bufferCounter;
        int 	drawCounter;

        float curVol, curVolPrev, divVol, maxDivVol;
        int   numHist;
        float smoothedVol;
        float scaledVol;

        // onset detection
        bool above, abovePrev, onSet;

         // UI variables
            // panel and sliders
        SliderA     maxFreq;
        SliderA     volume;
        SliderB     volThresh;
        SliderB     volScale;
        SliderA     numBin;
        int         numBinInt;
        int         numBinPrev;
        SliderB     smoothBin;
        TextField   oscAdress;
            // colors
        ofColor backgroundColor;
        ofColor outlineColor;
        ofColor contentColor;
            // font
        ofTrueTypeFont overPassMono10;
        ofTrueTypeFont overPassMono12;
        ofTrueTypeFont overPassMono14;

        // Sound stream variable
        ofSoundStream soundStream;
		ofRtAudioSoundStream s;
		int bufferSize;
        int samplingFreq;
        float samplePerFreq;

        // OSC variables
        ofxOscSender oscSender;
        int             oscAdressAsInt, oscAdressAsIntPrev;
};
