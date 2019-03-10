#!/bin/bash
cd ./data
ffmpeg.exe -f image2 -framerate 1 -i %d.png  out.gif