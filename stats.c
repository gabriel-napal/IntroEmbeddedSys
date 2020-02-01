/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  
  //print_array(test,SIZE);
 // sort_array(test,SIZE);
  print_statistics(test,SIZE);

}

void print_statistics(unsigned char *p, unsigned int sizeArray){

  printf("\n Those are the statistic values of the array: \n");
  print_array(p,sizeArray);
  printf("\n");
  printf("\n The minimum value is: %d",find_minimum(p,sizeArray));
  printf("\n The Maximum value is: %d",find_maximum(p,sizeArray));
  printf("\n The mean value is: %f ",find_mean(p,sizeArray));
  printf("\n The median value is: %f",find_median(p,sizeArray));
  printf("\n");


}

/* Add other Implementation File Code Here */
void print_array(unsigned char *p, unsigned int sizeArray){

	int i;
	
	printf("\n");
	for (i=0;i< sizeArray ;i++){
		printf("%d \n",*p);
		p++;
	}
}

  float find_mean(unsigned char *p, unsigned int sizeArray){

  int i;
  unsigned int cum_sum = 0;

  for (i=0;i<sizeArray;i++){

    cum_sum += *p;
    p++;
    }

  return (float) cum_sum / sizeArray;
  }
  
  float find_median(unsigned char *p, unsigned int sizeArray){

    sort_array(p,sizeArray);

    if((sizeArray%2)==0)
      return (float)(  p[(int)sizeArray/2] + p[(int)sizeArray/2 - 1]) / 2;
    

    else
      return (float) p[(int)sizeArray/2];
  }


  unsigned char find_maximum(unsigned char *p,unsigned int sizeArray){

    int i;
    unsigned char cap;
    unsigned char candidate;

    cap = *p;
    
    for (i=0;i<sizeArray;i++){
      candidate = *(p++);
      
      if(candidate>cap){
        cap = candidate;
      }
    }

    return cap;
  }

  unsigned char find_minimum(unsigned char *p, unsigned int sizeArray){

    int i;
    unsigned char cap;
    unsigned char candidate;

    cap = *p;
    
    for (i=0;i<sizeArray;i++){
      candidate = *(p++);
      
      if(candidate<cap){
        cap = candidate;
      }
    }

    return cap;
  }

  void sort_array(unsigned char *pArray, unsigned int sizeArray){

    unsigned int i = 0;
    unsigned int j = 0;
    unsigned char foo;

    /* Bubble Sorte Algorith*/
    for (j=0;j<sizeArray;j++){
      for (i=0;i<sizeArray-1;i++){
        if (pArray[i+1]>pArray[i]){

          //swap
          foo = pArray[i];
          pArray[i]=pArray[i+1];
          pArray[i+1]= foo;

        }
      }
    }
  }