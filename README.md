# Image_Processing_Gate

This project was created to be applied on a simulation of an Autonomous Underwater Vehicle (AUV) created for the submission for the Robosub 2021 competition by the Team DTU-AUV.

This project consists of a specific task out of the various tasks performed by the AUV

Task: When yaw is applied to the bot after releasing it in the water when the gate comes in the field of view of the camera, only the structure and color are visible of the gate, so the algorithm of this code involves the detection of the orange colour of the gate using colour thresholding, then the concept of contour detection is used to measure the perimeter of the sides of the gates so that the relative difference between the lengths of the gates due to different angles of view can be calculated and the bot can align itself rotationally as well as translationally.

The video link of the simulation : https://youtu.be/9H-Ao4aECxI
