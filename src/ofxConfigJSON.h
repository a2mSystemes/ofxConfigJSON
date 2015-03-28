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
#ifndef OFXCONFIGJSON_H
#define OFXCONFIGJSON_H

#include "ofxJSON.h"

using namespace std;

class ofxConfigJSON
{
    public:

        ofxConfigJSON();
        virtual ~ofxConfigJSON();

        void setup(){};
        void setup(string file);



        bool loadFile(string file);
        bool saveFile();
        bool saveFile(string file);

        bool addConfElement(string key, int value);
        bool addConfElement(string key, float value);
        bool addConfElement(string key, bool value);
        bool addConfElement(string key, string value);

        bool addConfElementArray(string key, int values[]);

//        bool addConfElement(string key, int value);
//        bool addConfElement(string key, float value);
//        bool addConfElement(string key, bool value);
//        bool addConfElement(string key, string value);

        string dump();

    protected:
    private:
        bool fileSaved;
        ofxJSONElement _conf;
};

#endif // OFXCONFIGJSON_H
