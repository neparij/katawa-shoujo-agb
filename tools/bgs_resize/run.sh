#!/bin/sh

rm  ../../graphics/video/temp_emi/*.png
rm  ../../graphics/video/temp_emi_imgs/*.png
rm  ../../graphics/video/temp_emi_imgs/positive/*
rm  ../../graphics/video/temp_emi_imgs/saturated/*
rm  ../../graphics/video/temp_emi_imgs/converted/*

python ./fast_video_conv.py

#python ./resize.py
