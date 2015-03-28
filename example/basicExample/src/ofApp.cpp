#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    save = 0;
    if (conf.loadFile("config.json"))
    {
        ofLogNotice("ofApp::setup") << conf.dump();
    }
    else
    {
        ofLogError("ofApp::setup") << "enable to load the config file";
    }

}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);

    ofSetHexColor(0x00FF00);

    std::stringstream display;
    display << conf.dump();
    display << "save" + ofToString(save) + " time(s)";
    ofDrawBitmapString(display.str(), 10, 50 );
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    switch (key)
    {
    //save test
    case 's':
        conf.saveFile("newSave.json");
        save++;
        break;
    //add element test
    case 'a':
        conf.addConfElement("newElement", true);
        conf.saveFile("newSaveModified.json");
        save++;
        // add array
        break;

    case 't':
        {
        int tab[] = {1,5,9,59,182,1896};
        bool ret = true;
        ret = conf.addConfElementArray("myArray",tab);
        if (!ret)
        ofLogNotice("keyPressed") << "error";
        conf.saveFile("newSaveModifiedArray.json");
        save++;
        }
        break;

    default:
        break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
