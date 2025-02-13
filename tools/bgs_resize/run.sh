#!/bin/sh

rm  ../../graphics/video/temp_emi/*.png
rm  ../../graphics/video/temp_emi_imgs/*.png
rm  ../../graphics/video/temp_emi_imgs/positive/*
rm  ../../graphics/video/temp_emi_imgs/saturated/*
rm  ../../graphics/video/temp_emi_imgs/converted/*

#python3.12 ./fast_video_conv.py


#python3.12 ./quantize_gbc.py
python ./resize.py
