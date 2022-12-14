# Image_Processing_Gate

This project was created to be applied on a simulation of an Autonomous Underwater Vehicle (AUV) created for the submission for the Robosub 2021 competition by the Team DTU-AUV.

This project consists of a specific task out of the various tasks performed by the AUV

Task: When yaw is applied to the bot after releasing it in the water when the gate comes in the field of view of the camera, only the structure and color are visible of the gate, so the algorithm of this code involves the detection of the orange colour of the gate using colour thresholding, then the concept of contour detection is used to measure the perimeter of the sides of the gates so that the relative difference between the lengths of the gates due to different angles of view can be calculated and the bot can align itself rotationally as well as translationally.

The video link of the simulation : https://youtu.be/9H-Ao4aECxI

Original Image : 
![Gate](https://user-images.githubusercontent.com/76791881/207584622-7fc334ff-d50b-480c-838a-bbcbf135a24e.png)

Mask Image : 
![mask_gate](https://user-images.githubusercontent.com/76791881/207585158-14c350ac-4738-4c80-b240-d0132c7a60d5.png)

Image with Contours:
![contours_gate](https://user-images.githubusercontent.com/76791881/207585262-011e899f-305f-4c4a-90dc-f571e2918b90.png)

Created by: Ishpreet Singh Luthra
