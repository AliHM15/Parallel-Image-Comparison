#include <stdio.h>
  #include <stdlib.h>
  #include <malloc.h>
  
  #define STB_IMAGE_IMPLEMENTATION
  #include "stb_image.h"
  #define STB_IMAGE_WRITE_IMPLEMENTATION
  #include "stb_image_write.h"
  
  int main(void) {
  	int width, height, channels;
  	unsigned char *img = stbi_load("image.jpeg", &width, &height,&channels, 0);
  	int width2, height2, channels2;
  	bool flag =  false;
  	
      if(img == NULL) {
          printf("Error in loading the image\n");
          exit(1);
      }
     printf("Loaded image1 with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels); 
     
//      stbi_write_png("1.png", width, height, channels, img, width * channels);
      
 
     unsigned char *img2 = stbi_load("img2.png", &width2, &height2, &channels2, 0);
     if(img2 == NULL) {
         printf("Unable to allocate memory for the gray image.\n");
         exit(1);
     }
     printf("Loaded image2 with a width of %dpx, a height of %dpx and %d channels\n", width2, height2, channels2); 
 
	size_t img_size = width * height * channels;
	size_t img_size2 = width2 * height2 * channels2;
	
     for(unsigned char *p = img, *pg = img2; p != img + img_size; p += channels, pg += channels2) {
         if(*p != *pg ) {
             flag=true;
             break;   
         }
         else
         	flag=false;
     }
     
     if(flag==true)
     	printf("Image is Different\n");
     else
     	printf("Image is Same\n");
     	
  //      stbi_write_jpg("sky_gray.jpg", width, height, gray_channels, gray_img, 100);

 }
