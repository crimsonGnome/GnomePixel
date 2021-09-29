#include "draw.h"

#include <stdlib.h> 
#include <string>
#include <vector>

#include "cpputils/graphics/image.h" 
using graphics::Image, graphics::Color, std::string, std::vector; 

void rectangleMirror(Image& image, int midpoint, int startHeight, int bottomHeight, int width, Color& colorRight, Color& colorLeft) {
  //right
  int tempHeight = bottomHeight - startHeight;
  image.DrawRectangle(midpoint, startHeight , width, tempHeight, colorRight);
      
  //left
  int leftSideStart = midpoint - width;
  image.DrawRectangle(leftSideStart, startHeight , width, tempHeight, colorLeft);

} 

void triangleMirror(Image& image, vector<int>& right, vector<int>& left, Color& colorRight, Color& colorLeft) {
  //right
  image.DrawPolygon(left, colorLeft);
  image.DrawPolygon(right, colorRight);
} 


void makePlayer(int height, int width, string fileName) {
    // Vertical breakPoints o
    // VB of where different shapes will fit
    // This wouldnt work for non divisble ints of base25 might skip a line or leave a blank row
    
    const int bottomOfHatPointHeight = height * 22 / 50;
    const int topFace = height * 19/50;
    const int topOfBody = height *3 / 5;
    const int cheakbone = topOfBody - height * 1/50;
    const int cheakboneHigher = cheakbone - height * 1/50;
    const int topBeard = bottomOfHatPointHeight + height * 3 / 50; //same as hegiht / 2
    const int midChunckBeard = topBeard + height * 4 / 25; 
    const int beardPoint = height * 39 / 50;
    const int bottomCoat = beardPoint + height * 4 / 50; 
    const int shoeBuffer = bottomCoat + height * 1 / 50;
    const int shoeHeel = shoeBuffer + height * 3 / 50;
    const int tipOfShoe =  height * 46/50;
    const int leftHandHeight = height *38/50;
    const int maxheight = height - 1;
    // fractions add up to 96% which leaves shoeBuffer to bottom 4% of image
    //Since the image will be mirrored. the 0 will be treated as the mid point.
    // All Wiedths should be used for boxes
    const int midpoint = width/2;
    const int hatOuterWidth = width * 3/25;
    const int faceWidth = width * 1/10;
    const int faceBackroundWidth = width * 6/50;
    const int beardWidth = width * 7/50;
    const int bodyBackgroundWidth = width * 4/25;
    const int pantTaperWidth = width * 2/25;
    const int shoeTopWidth = width * 5/50;
    const int maxImageWidthRight = midpoint + width * 10/50;
    const int maxImageWidthLeft = midpoint - width * 10/50;
    //Postitions are meant for single lines vs widths are for boxes
    const int eyePosition = width *1/50;
    const int armlength = height * 3/25;
    const int handlength = height *4/50; //also eye
    
    
    
    // constants 
    const int onePixelHeight = height * 1/50;
    const int onePixelWidth = width * 1/50;
    const int twoPixelHeight = height * 2/50;
    const int twoPixelWidth = width * 2/50;
    const int threePixelWidth = width * 3/50;
    const int threePixelHeight = width * 3/50;
    
    //Variables that are placeHolders
    
    int leftSideStart;
    int tempHeight;
    int tempWidth;
    int secondPointForLine;
    int shoeTemp;
    int additionalShoePoint;
    
  //Vectors for Triangle Parts
  
  //Vectors for the hat
  
  //right Hat 
  tempWidth = midpoint + hatOuterWidth - onePixelWidth;
  leftSideStart = midpoint + onePixelWidth;
  shoeTemp = midpoint + twoPixelWidth;
  vector<int> rightHatVector {midpoint, 0, midpoint, bottomOfHatPointHeight,tempWidth, bottomOfHatPointHeight, shoeTemp,twoPixelHeight,leftSideStart, onePixelHeight};
  //left Hat 
  
  tempWidth = midpoint - hatOuterWidth;
  leftSideStart = midpoint - onePixelWidth;
  vector<int> leftHatVector {leftSideStart, 0, midpoint, bottomOfHatPointHeight,tempWidth, bottomOfHatPointHeight};
   
  // Vectors for beard
  tempWidth = midpoint + beardWidth - onePixelWidth;
  vector<int> rightBeardVector {midpoint, midChunckBeard, midpoint, beardPoint, tempWidth,midChunckBeard};
  tempWidth = midpoint - beardWidth;
  vector<int> leftBeardVector {midpoint, midChunckBeard, midpoint, beardPoint, tempWidth,midChunckBeard};
  
  //Vectors for face
  //Rigth face
  tempWidth = midpoint + pantTaperWidth;
  leftSideStart = tempWidth - onePixelWidth;
  secondPointForLine = midpoint + onePixelWidth;
  vector<int> rightFaceVector {midpoint,topFace,midpoint, topOfBody, secondPointForLine, topOfBody, leftSideStart,cheakbone,tempWidth,cheakboneHigher, leftSideStart,bottomOfHatPointHeight,secondPointForLine,topFace};

  // left Face
  tempWidth = midpoint - pantTaperWidth - onePixelWidth;

  leftSideStart = tempWidth + onePixelWidth;
  secondPointForLine = midpoint - twoPixelWidth;
  vector<int> leftFaceVector {midpoint,topFace,midpoint,topOfBody,secondPointForLine,  topOfBody,leftSideStart,cheakbone,tempWidth,cheakboneHigher, leftSideStart ,bottomOfHatPointHeight, secondPointForLine,topFace};
  
  //Vector for Shoes
  //right Shoe
  //line for heel to bottom
  tempWidth = midpoint + hatOuterWidth;
  // Adds one more stop in vector
  additionalShoePoint = tempWidth - onePixelWidth; 
  // width tip of shoe 
  secondPointForLine = midpoint + bodyBackgroundWidth;
  
  tempHeight = maxheight - onePixelHeight;
  shoeTemp = shoeTopWidth + midpoint;
  vector<int> rightBootVector {midpoint,shoeBuffer,midpoint, shoeHeel,additionalShoePoint, maxheight,   tempWidth ,maxheight,secondPointForLine ,tempHeight, secondPointForLine, tipOfShoe, shoeTemp ,shoeBuffer};
  //left Shoe
  //line for heel to bottom
  tempWidth = midpoint - hatOuterWidth;
  // adds one more poin to shoe
  additionalShoePoint = tempWidth + onePixelWidth; 
  // width tip of shoe 
  secondPointForLine = midpoint - bodyBackgroundWidth;  
  shoeTemp = midpoint - shoeTopWidth;
  vector<int> leftBootVector {midpoint,shoeBuffer,midpoint, shoeHeel,additionalShoePoint, maxheight, tempWidth ,maxheight,secondPointForLine ,tempHeight, secondPointForLine, tipOfShoe, shoeTemp ,shoeBuffer};
  
  //Second thing I did was make the Image
    Color rightHat(190,73,74);
    Color rightBeard(198,99,98);
    Color rightSkin(254,254,254);
    Color rightBoot(133,64,64);
    Color rightHatTrim(182,47,45);
    Color rightBody(161,66,68);
    //Character left
    Color leftHat(139,22,23);
    Color leftBeard(148,47,44);
    Color leftSkin(200,200,200);
    Color leftBoot(85,15,17);
    Color lefthatTrim(139,22,23);
    Color leftBody(107,11,14);
    Color evilEyebrows(0,0,0);
    // Universal 
    Color eyeColor(176,133,133);
    
  Image image(width,height);
 
  // 1st Draw is the Body
  //rectangleMirror( Image& image, int midpoint, int startHeight,bottomHeight, int width, Color& colorRight, Color& colorLeft)
  
  // Draw Body Background
  
 rectangleMirror(image,midpoint,topOfBody,bottomCoat,bodyBackgroundWidth, rightBody, leftBody);
  // Draw line next to arms 
  //Right arm
  //arm start
  tempHeight = topOfBody + twoPixelHeight;
  //arm end 
  secondPointForLine = tempHeight + armlength;
  leftSideStart = midpoint + bodyBackgroundWidth;
 
  image.DrawLine(leftSideStart, tempHeight, leftSideStart, secondPointForLine, rightBody);
  // Left Arm
  leftSideStart = midpoint - bodyBackgroundWidth - onePixelWidth;
  image.DrawLine(leftSideStart, tempHeight, leftSideStart,secondPointForLine, leftBody);
  
  
  //Very Similar Code - may make into function later
  // Draw tapered bottom body 
  tempWidth = bodyBackgroundWidth - onePixelWidth;
  leftSideStart = bottomCoat;
  tempHeight =  leftSideStart + onePixelHeight; //box is 1/50th of h or 1px
   rectangleMirror(image,midpoint,leftSideStart,tempHeight,tempWidth, rightBody, leftBody);
 // Tapper one more down again 
 leftSideStart = leftSideStart + onePixelHeight;
 rectangleMirror(image,midpoint,leftSideStart,tempHeight,shoeTopWidth, rightBody, leftBody);
 
 
  // Next draw Beard and beard hair 
  // Drawing Face Frame
  rectangleMirror(image,midpoint,bottomOfHatPointHeight, topBeard, faceBackroundWidth, rightBeard, leftBeard);
  // drawing Top of Breard or the main chunck of the beard
  rectangleMirror(image,midpoint,topBeard, midChunckBeard, beardWidth, rightBeard, leftBeard);

  // angled Beard or beard Point 
  //Vector Points
  //hat 
  triangleMirror(image,rightHatVector,leftHatVector,rightBody,leftBody);
  //tiny hat ball
  tempHeight = 0;
  tempWidth = midpoint - threePixelWidth; 
  image.DrawRectangle(tempWidth, tempHeight,twoPixelHeight, twoPixelWidth, leftBody);
  //Beard
  triangleMirror(image,rightBeardVector,leftBeardVector,rightBeard,leftBeard);
  
  //Draw Hands
  // Draw Right
  tempWidth = midpoint + faceWidth - onePixelWidth;
  tempHeight = leftHandHeight - onePixelHeight;
  image.DrawRectangle(tempWidth, tempHeight , threePixelWidth, handlength, rightSkin);
  
  // Left Hand
  tempWidth = midpoint - beardWidth;
  image.DrawRectangle(tempWidth, leftHandHeight,threePixelWidth, handlength, leftSkin);
  //Face 
  triangleMirror(image,rightFaceVector,leftFaceVector,rightSkin,leftSkin);
  //Eyes
  //right Eye
  leftSideStart = midpoint + eyePosition;
  tempHeight = bottomOfHatPointHeight + twoPixelHeight;
  image.DrawLine(leftSideStart,bottomOfHatPointHeight,leftSideStart,tempHeight,eyeColor);
  //Left eye
  leftSideStart = midpoint - eyePosition - onePixelWidth;
  image.DrawLine(leftSideStart,bottomOfHatPointHeight,leftSideStart,tempHeight,eyeColor);
  //Shoes 
  triangleMirror(image,rightBootVector,leftBootVector,rightBoot,leftBoot);
  
  //Pixelization to make it look cooler 
  for(int x = 0; x < width; x++){
    if(maxImageWidthLeft < x && x < maxImageWidthRight){
      for(int y = 0; y < width; y++){
        int red = image.GetRed(x,y);
        if(red == 255){
          continue;
        } else if (red == 254 || red == 200) {
          red =  red - rand() % 10 +1;
          Color tempColor(red,red,red);
          image.SetColor(x,y,tempColor);
        } else {
        int random = rand() % 8 + 1;
          if(random % 4 == 0) {
            int green = image.GetGreen(x,y);
            int blue = image.GetBlue(x,y);
            red =  red + rand() % 20 +1;
            blue = blue + rand() % 10 +1;
            green = green + rand() % 10 +1;
            
            Color tempColor(red,green,blue);
            image.SetColor(x,y,tempColor);
          } else {
            continue;
          }
        
        } 
      }
    } else {
    continue;
   }
  }
  image.SaveImageBmp(fileName);
    
    
}

 
