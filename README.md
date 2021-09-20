# README allen-bradley-ctrlX

The sample app __allen-bradley__ creates provider nodes corresponding to data on an Allen-Bradely PLC. This data is readable/writable to the PLC.

## Introduction

Create an AB.json file at the root of the activeConfiguration folder on the ctrlX. 

The json has a few elements that can be configured including the IP address of the Allen-Bradely control and Rate which is the milli-seconds between samples. The tag array is required and is where the tag name and type can be set. 

    {"IP":"192.168.0.70",
    "Rate":250,
    "tag":
        [
            {"name":"tag1Name","type":"tag1Type"},
            {"name":"tag2Name","type":"tag2Type"},
            {"name":"tag3Name","type":"tag3Type"}
        ]
    }

Tag types include:

    bool8,
    int8,
    uint8,
    int16,
    uint16,
    int32,
    uint32,
    int64,
    uint64,
    float,
    double,
    string
___

## License

MIT License

Copyright (c) 2020, Bosch Rexroth AG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
