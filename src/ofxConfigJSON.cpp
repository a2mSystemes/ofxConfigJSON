// *******************************************************************************
//
// Copyright (c) 2015 Ange-Marie MAURIN A2M Systèmes <http://a2msystemes.fr>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// *******************************************************************************
#include "ofxConfigJSON.h"
#include "ofMain.h"

ofxConfigJSON::ofxConfigJSON()
{

}

ofxConfigJSON::~ofxConfigJSON()
{

}

void ofxConfigJSON::setup(string file)
{
    loadFile(file);
}

bool ofxConfigJSON::loadFile(string file)
{
    return _conf.open(file);
}

bool ofxConfigJSON::saveFile()
{
    return saveFile("tmp.json");
}

bool ofxConfigJSON::saveFile(string file)
{
    return _conf.save(file, true);
}

bool ofxConfigJSON::addConfElement(string key, int value)
{

}

bool ofxConfigJSON::addConfElement(string key, float value)
{
        _conf[key] = value;
    if (_conf[key] == value)
        return true;
    return false;
}

bool ofxConfigJSON::addConfElement(string key, bool value)
{
    _conf[key] = value;
    if (_conf[key] == value)
        return true;
    return false;
}

bool ofxConfigJSON::addConfElement(string key, string value)
{
    _conf[key] = value;
    if (_conf[key] == value)
        return true;
    return false;
}

bool ofxConfigJSON::addConfElementArray(string key, int* values)
{
    if (values == NULL) return false;
    Json::Value vec(Json::arrayValue);
    int length = sizeof(int) / sizeof(int);
    ofLogWarning("ofxConfigJSON::addConfElementArray") << "ok. data length : " + ofToString(length);

    for(int i = 0; i <= length; i++){
        vec.append(Json::Value(values[i]));
    }
    _conf[key] = vec;
    return true;
}

string ofxConfigJSON::dump()
{
    return _conf.getRawString();
}
