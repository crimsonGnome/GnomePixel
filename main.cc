// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu

#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>

#include "cpputils/graphics/image.h"

using graphics::Image, graphics::Color, std::cin, std::cout, std::string,
    std::vector;

void rectangleMirror(Image& image, int midpoint, int startHeight,
                     int bottomHeight, int width, Color& colorRight,
                     Color& colorLeft) {
  // this Function makes a reactangle on both sides of the midpoint
  // right
  int tempHeight = bottomHeight - startHeight;
  image.DrawRectangle(midpoint, startHeight, width, tempHeight, colorRight);

  // left
  int leftSideStart = midpoint - width;
  image.DrawRectangle(leftSideStart, startHeight, width, tempHeight, colorLeft);
}

void triangleMirror(Image& image, vector<int>& right, vector<int>& left,
                    Color& colorRight, Color& colorLeft) {
  image.DrawPolygon(left, colorLeft);
  image.DrawPolygon(right, colorRight);
}

void makePlayer(int height, int width, string fileName, bool isEvil) {
  // ------------ Start of Variable Declaration --------------------
  // Vertical breakPoints
  // This wouldnt work for non divisble ints of base 50
  // Designed to scale to whatever hieght that is given;

  // VB of where different shapes will fit
  const int bottomOfHatPointHeight = height * 22 / 50;
  const int topFace = height * 19 / 50;
  const int topOfBody = height * 3 / 5;
  const int cheakbone = topOfBody - height * 1 / 50;
  const int cheakboneHigher = cheakbone - height * 1 / 50;
  const int topBeard = bottomOfHatPointHeight + height * 3 / 50;
  const int midChunckBeard = topBeard + height * 4 / 25;
  const int beardPoint = height * 39 / 50;
  const int bottomCoat = beardPoint + height * 4 / 50;
  const int shoeBuffer = bottomCoat + height * 1 / 50;
  const int shoeHeel = shoeBuffer + height * 3 / 50;
  const int tipOfShoe = height * 46 / 50;
  const int leftHandHeight = height * 38 / 50;
  const int maxheight = height - 1;

  // Horizontal Break Points
  // Since the image will be mirrored. the 0 will be treated as the mid point.

  const int midpoint = width / 2;
  const int hatOuterWidth = width * 3 / 25;
  const int faceWidth = width * 1 / 10;
  const int faceBackroundWidth = width * 6 / 50;
  const int beardWidth = width * 7 / 50;
  const int bodyBackgroundWidth = width * 4 / 25;
  const int pantTaperWidth = width * 2 / 25;
  const int shoeTopWidth = width * 5 / 50;
  const int maxImageWidthRight = midpoint + width * 10 / 50;
  const int maxImageWidthLeft = midpoint - width * 10 / 50;

  // Postitions are meant for single lines vs widths are for boxes
  const int eyePosition = width * 1 / 50;
  const int armlength = height * 3 / 25;
  const int handlength = height * 4 / 50;

  // constants based on scaling width or height
  const int onePixelHeight = height * 1 / 50;
  const int onePixelWidth = width * 1 / 50;
  const int twoPixelHeight = height * 2 / 50;
  const int twoPixelWidth = width * 2 / 50;
  const int threePixelWidth = width * 3 / 50;
  const int rgbAverage = 3;
  // Variables that are placeHolders

  int leftSideStart;
  int tempHeight;
  int tempWidth;
  int secondPointForLine;
  int shoeTemp;
  int additionalShoePoint;

  // Vectors for Triangle Parts
  // Entire vector section is jsut setting up vector Section.
  // Vectors for the hat

  // right Hat Vector
  // All temp values there tempWidth,leftSideStart,shoeTemp used to shape hat
  // Width based off midpoint + hatouterWidth - one pixel (top curve)
  tempWidth = midpoint + hatOuterWidth - onePixelWidth;
  leftSideStart = midpoint + onePixelWidth;
  shoeTemp = midpoint + twoPixelWidth;
  // Multiple temp variables thrown into Widths. Widths have to be
  // mirrored which is why temp is used
  vector<int> rightHatVector{midpoint,      0,
                             midpoint,      bottomOfHatPointHeight,
                             tempWidth,     bottomOfHatPointHeight,
                             shoeTemp,      twoPixelHeight,
                             leftSideStart, onePixelHeight};
  // left Hat
  tempWidth = midpoint - hatOuterWidth;
  leftSideStart = midpoint - onePixelWidth;
  vector<int> leftHatVector{leftSideStart, 0,
                            midpoint,      bottomOfHatPointHeight,
                            tempWidth,     bottomOfHatPointHeight};

  // Vectors for beard
  // All temp values there tempWidth,leftSideStart,shoeTemp used to shape hat
  // Width based off midpoint
  tempWidth = midpoint + beardWidth - onePixelWidth;
  vector<int> rightBeardVector{midpoint,   midChunckBeard, midpoint,
                               beardPoint, tempWidth,      midChunckBeard};
  tempWidth = midpoint - beardWidth;
  vector<int> leftBeardVector{midpoint,   midChunckBeard, midpoint,
                              beardPoint, tempWidth,      midChunckBeard};

  // Vectors for face
  // Rigth face
  tempWidth = midpoint + pantTaperWidth;
  leftSideStart = tempWidth - onePixelWidth;
  secondPointForLine = midpoint + onePixelWidth;
  vector<int> rightFaceVector{midpoint,           topFace,
                              midpoint,           topOfBody,
                              secondPointForLine, topOfBody,
                              leftSideStart,      cheakbone,
                              tempWidth,          cheakboneHigher,
                              leftSideStart,      bottomOfHatPointHeight,
                              secondPointForLine, topFace};

  // left Face
  tempWidth = midpoint - pantTaperWidth - onePixelWidth;
  leftSideStart = tempWidth + onePixelWidth;
  secondPointForLine = midpoint - twoPixelWidth;
  vector<int> leftFaceVector{midpoint,           topFace,
                             midpoint,           topOfBody,
                             secondPointForLine, topOfBody,
                             leftSideStart,      cheakbone,
                             tempWidth,          cheakboneHigher,
                             leftSideStart,      bottomOfHatPointHeight,
                             secondPointForLine, topFace};

  // Vector for Shoes
  // right Shoe
  // line for heel to bottom
  tempWidth = midpoint + hatOuterWidth;
  // Adds one more stop in vector
  additionalShoePoint = tempWidth - onePixelWidth;
  // width tip of shoe
  secondPointForLine = midpoint + bodyBackgroundWidth;

  tempHeight = maxheight - onePixelHeight;
  shoeTemp = shoeTopWidth + midpoint;
  vector<int> rightBootVector{
      midpoint,   shoeBuffer,          midpoint,
      shoeHeel,   additionalShoePoint, maxheight,
      tempWidth,  maxheight,           secondPointForLine,
      tempHeight, secondPointForLine,  tipOfShoe,
      shoeTemp,   shoeBuffer};
  // left Shoe
  // line for heel to bottom
  tempWidth = midpoint - hatOuterWidth;
  // adds one more poin to shoe
  additionalShoePoint = tempWidth + onePixelWidth;
  // width tip of shoe
  secondPointForLine = midpoint - bodyBackgroundWidth;
  shoeTemp = midpoint - shoeTopWidth;
  vector<int> leftBootVector{
      midpoint,   shoeBuffer,          midpoint,
      shoeHeel,   additionalShoePoint, maxheight,
      tempWidth,  maxheight,           secondPointForLine,
      tempHeight, secondPointForLine,  tipOfShoe,
      shoeTemp,   shoeBuffer};
  // End of vetor sction

  // Color Section
  // Second thing I did was make the Image
  Color rightHat(190, 73, 74);
  Color rightBeard(198, 99, 98);
  Color rightSkin(254, 254, 254);
  Color rightBoot(133, 64, 64);
  Color rightHatTrim(182, 47, 45);
  Color rightBody(161, 66, 68);
  // Character left
  Color leftHat(139, 22, 23);
  Color leftBeard(148, 47, 44);
  Color leftSkin(200, 200, 200);
  Color leftBoot(85, 15, 17);
  Color lefthatTrim(139, 22, 23);
  Color leftBody(107, 11, 14);
  // Universal
  Color eyeColor(176, 133, 133);
  Color evilCorruption(41, 217, 33);
  // If Evil Change EyeColor
  if (isEvil) {
    eyeColor.SetRed(255);
    eyeColor.SetGreen(0);
    eyeColor.SetBlue(0);
  }
  // -------------- end of Variable Declaration- -------------------
  // Create Image
  Image image(width, height);

  // 1st Draw is the Body
  // -------- Start Body Background Section --------------------
  rectangleMirror(image, midpoint, topOfBody, bottomCoat, bodyBackgroundWidth,
                  rightBody, leftBody);
  // Draw line next to arms
  // Right arm
  // arm start
  tempHeight = topOfBody + twoPixelHeight;
  // arm end
  secondPointForLine = tempHeight + armlength;
  leftSideStart = midpoint + bodyBackgroundWidth;

  image.DrawLine(leftSideStart, tempHeight, leftSideStart, secondPointForLine,
                 rightBody);
  // Left Arm
  leftSideStart = midpoint - bodyBackgroundWidth - onePixelWidth;
  image.DrawLine(leftSideStart, tempHeight, leftSideStart, secondPointForLine,
                 leftBody);

  // Draw tapered bottom body
  tempWidth = bodyBackgroundWidth - onePixelWidth;
  leftSideStart = bottomCoat;
  tempHeight = leftSideStart + onePixelHeight;
  rectangleMirror(image, midpoint, leftSideStart, tempHeight, tempWidth,
                  rightBody, leftBody);
  // Tapper one more down again
  leftSideStart = leftSideStart + onePixelHeight;
  rectangleMirror(image, midpoint, leftSideStart, tempHeight, shoeTopWidth,
                  rightBody, leftBody);
  // ------------------- End Body Section --------------------
  // ------------------- Start Beard Section ------------------
  // Drawing Face Frame/ hairbackgroound
  rectangleMirror(image, midpoint, bottomOfHatPointHeight, topBeard,
                  faceBackroundWidth, rightBeard, leftBeard);
  // drawing Top of Breard or the main chunck of the beard
  rectangleMirror(image, midpoint, topBeard, midChunckBeard, beardWidth,
                  rightBeard, leftBeard);
  // Beard point
  triangleMirror(image, rightBeardVector, leftBeardVector, rightBeard,
                 leftBeard);
  // ------------------- End Beard Section ------------------
  // ------------------ Start Hat Section ------------------
  // hat
  triangleMirror(image, rightHatVector, leftHatVector, rightBody, leftBody);
  // tiny hat ball
  tempHeight = 0;
  tempWidth = midpoint - threePixelWidth;
  image.DrawRectangle(tempWidth, tempHeight, twoPixelHeight, twoPixelWidth,
                      leftBody);
  // ------------------- End Hat Section ------------------

  // ------------------ Start Hand Section ------------------
  // Draw Right Hand
  // setting the hands at diffeent heights
  tempWidth = midpoint + faceWidth - onePixelWidth;
  tempHeight = leftHandHeight - onePixelHeight;
  image.DrawRectangle(tempWidth, tempHeight, threePixelWidth, handlength,
                      rightSkin);

  // Left Hand
  // setting temp width for location of hand
  tempWidth = midpoint - beardWidth;
  image.DrawRectangle(tempWidth, leftHandHeight, threePixelWidth, handlength,
                      leftSkin);
  // ------------------ End Hand Section ------------------
  // ------------------ Start Face Section ------------------
  // Face
  triangleMirror(image, rightFaceVector, leftFaceVector, rightSkin, leftSkin);
  // ------------------ End Face Section ------------------
  // ------------------ Start shoes Section ------------------
  // Shoes
  triangleMirror(image, rightBootVector, leftBootVector, rightBoot, leftBoot);
  // ------------------ End shoes Section ------------------

  // Pixelization to make it look cooler
  for (int x = 0; x < width; x++) {
    // There is no pixels to edit outside of this Range
    if (maxImageWidthLeft < x && x < maxImageWidthRight) {
      for (int y = 0; y < width; y++) {
        int red = image.GetRed(x, y);
        // If image red is == 255 then the picture is background then skip
        if (red == 255) {
          continue;
        } else if (isEvil) {
          // If its Evil run code
          int random = rand() % 5 + 1;
          // 1 out 5 change add evil Corruption Color
          if (random % 4 == 0) {
            image.SetColor(x, y, evilCorruption);
          } else {
            // 4/5 change to greyScale Evil Image
            // Get Colors
            Color color = image.GetColor(x, y);
            // Then I average the colors to get the grey Scale
            int greyScale =
                (color.Red() + color.Blue() + color.Green()) / rgbAverage;
            // New GreyScale Color
            Color tempColor(greyScale, greyScale, greyScale);
            image.SetColor(x, y, tempColor);
          }
          // Finally don't do anythine else skip loop
          continue;
        } else if (red == 254 || red == 200) {
          // if Color is near white or grey second side. randomize color
          red = red - rand() % 10 + 1;
          Color tempColor(red, red, red);
          image.SetColor(x, y, tempColor);
        } else {
          // random number
          int random = rand() % 4 + 1;
          // 1/4 chance of changing color
          if (random % 4 == 0) {
            // get Colors, then randomize off base
            int green = image.GetGreen(x, y);
            int blue = image.GetBlue(x, y);
            red = red + rand() % 20 + 1;
            blue = blue + rand() % 10 + 1;
            green = green + rand() % 10 + 1;
            Color tempColor(red, green, blue);
            image.SetColor(x, y, tempColor);
          } else {
            continue;
          }
        }
      }
    } else {
      continue;
    }
  }
  // After gnome has been altered add eyes
  // ------------------ Start eye Section ------------------
  // Eyes
  // right Eye

  leftSideStart = midpoint + eyePosition;
  tempHeight = bottomOfHatPointHeight + twoPixelHeight;
  image.DrawLine(leftSideStart, bottomOfHatPointHeight, leftSideStart,
                 tempHeight, eyeColor);
  // Left eye
  leftSideStart = midpoint - eyePosition - onePixelWidth;
  image.DrawLine(leftSideStart, bottomOfHatPointHeight, leftSideStart,
                 tempHeight, eyeColor);
  // ------------------ End eye Section ------------------
  // Save File
  image.SaveImageBmp(fileName);
}

void playerProjecetile(int height, int width, string fileName) {
  Color center(153, 217, 234);
  Color second(78, 171, 252);
  Color third(199, 234, 255);
  const int onePixelWidth = 1;
  Image image(width, height);

  for (int x = 0; x < width - 2; x++) {
    for (int y = 0; y < width; y++) {
      // Image is pixels are one less then the width given
      // Also temx is to mirror to the other side
      int tempx = width - onePixelWidth - x;
      if (x == 0) {
        if (y == 2) {
          image.SetColor(x, y, third);
          image.SetColor(tempx, y, third);
          break;
        }
        continue;
      }
      if (x == 1) {
        if (y == 1) {
          image.SetColor(x, y, third);
          image.SetColor(tempx, y, third);
          continue;
        }
        if (y == 2) {
          image.SetColor(x, y, second);
          image.SetColor(tempx, y, second);
          continue;
        }
        if (y == 3) {
          image.SetColor(x, y, third);
          image.SetColor(tempx, y, third);
          break;
        }
      }
      if (x == 2) {
        if (y == 0) {
          image.SetColor(x, y, third);
          continue;
        }
        if (y == 1) {
          image.SetColor(x, y, second);
          continue;
        }
        if (y == 2) {
          image.SetColor(x, y, center);
          continue;
        }
        if (y == 3) {
          image.SetColor(x, y, second);
          continue;
        }
        if (y == 4) {
          image.SetColor(x, y, third);
          break;
        }
      }
      // Break if the loop gets to 4
      if (x >= 3) {
        break;
      }
    }
  }
  image.SaveImageBmp(fileName);
}

void evilProjecetile(int height, int width, string fileName) {
  Color evilCorruption(41, 217, 33);
  Color evilCorroptionDark(4, 28, 9);
  const int OnePixelWidth = 1;
  Image image(width, height);

  for (int x = 0; x < width; x++) {
    for (int y = 0; y < width; y++) {
      int random = rand() % 3 + 1;
      if (random % 3 == 0) {
        image.SetColor(x, y, evilCorruption);
      } else {
        image.SetColor(x, y, evilCorroptionDark);
      }
    }
  }
  image.SaveImageBmp(fileName);
}

int main() {
  const int characterHeight = 50;
  const int characterWidth = 50;
  const int projectileHeight = 5;
  const int projectileWidth = 5;
  bool isEvilFlag = false;
  string playerFileName;
  string evilFileName;
  string projectileFileName;
  string evilProjectileFileName;

  cout << "Please provide player image filename: ";
  cin >> playerFileName;
  cout << "Please provide opponent image filename: ";
  cin >> evilFileName;
  cout << "Please provide player projectile image filename: ";
  cin >> projectileFileName;
  cout << "Please provide opponent projectile image filename: ";
  cin >> evilProjectileFileName;

  // Player is orginally not evil
  makePlayer(characterHeight, characterWidth, playerFileName, isEvilFlag);
  isEvilFlag = true;
  // when calling the makePlayer. isEvil will change some functionallity
  makePlayer(characterHeight, characterWidth, evilFileName, isEvilFlag);
  // Player Projectile Function
  playerProjecetile(projectileHeight, projectileWidth, projectileFileName);
  // evilProjectile Function
  evilProjecetile(projectileHeight, projectileWidth, evilProjectileFileName);

  return 0;
}
