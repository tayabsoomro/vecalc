// Author: Muhammad Tayab Soomro
// Student #: 11199539
// Description: vecalc program created for Assignment 2 for the CMPT-214
// Created On: Tuesday 25th October, 2016.
// Finished On: ---

// Standard headers
#include <assert.h> // for 
#include <inttypes.h> // for fixed-width datatypes
#include <stdlib.h> // for EXIT_SUCCESS, etc.
#include <stdio.h> // for printf, etc.

// The program can either be in INPUT state or CALC state
typedef enum { FORMER, INPUT, CALC } State; 
// ... (State s, ...){
//	switch(s){
//		case INPUT: ...; break;
//		case CALC: ...; break;
//		default: assert(false); break;
//	}
// }

const int MAX_ELEMS = UINT16_MAX; // Maximum Elements: 0 - 65535



// An Elem is single precision floating-point value
typedef float Elem;

// A Vector is a structured type of vectors.
typedef struct {
	uint8_t size;
	Elem *elements;
} Vector;




// Usage
//  Instruct user on how to use this program; i.e. the commands it
//  supports and the syntax of those commands.
// In:
//    none
// Out:
//    output produced on standard output
void usage( void ) {
    puts( " Usage:" );
    puts( "  p   - print vector" );
    puts( "  q,e - quit, end" );
    puts( "  h   - print usage help" );
    puts( "  + <operand> - add <operand> to each element of vector" );
    puts( "  - <operand> - subtract <operand> from each element of vector" );
    puts( "  * <operand> - multiple each element of vector by <operand>" );
    puts( "  / <operand> - divide each element of vector by <operand>" );
    puts( "  a <value> - extend vector by additional value" );
}

// is_vec_null:
//  Checks if the vector passed in as param NULL or not
// In:
//  Vector != NULL
// Out:
//  Return -- true if v is NULL, false otherwise
bool is_vec_null(Vector *v){
  if(v == NULL) return true;
  return false;
}


// print_vec:
// 	Prints the vector provided in param
// In:
// 	Vector != NULL
// Out:
// 	No return value
// 	effect -- Vector is printed on the stdin
void print_vec(Vector *v){
  puts("FAILURE: Did not print vector");
}

// alloc_vec:
// 	Allocates an empty Vector
// In:
// 	N/a
// Out:
// 	return -- Pointer to newly allocated Vector if successfull, NULL otherwise
// 	effect -- A new Vector is allocted to dynamic memory space.
Vector *alloc_vec(void){
	Vector *v = new Vector;
  v->size = 0;
  v->elements = NULL;
	return v;
}

// dealloc_vec:
// 	Deallocates a given Vector
// In:
// 	Vector != NULL
// Out:
// 	No return value
// 	effect -- Vector passed through param is safely deallocated from memory space.
void dealloc_vec(Vector *v){
	if(v != NULL){
    delete [] v->elements;
  	delete v;	
  }
}

// extend_vec:
// 	Extend Vector with specified Elem value
// In:
// 	Vector != NULL
// 	Elem
// Out:
// 	return  -- Vector including the new Elem value
//	effect -- Deallocates the given Vector and creates a new one with new Elem value added.
Vector *extend_vec(Vector *v,Elem value){
	if(!is_vec_null(v)){
      uint8_t size = v->size;
      Vector *new_vector = alloc_vec();
      uint8_t newsize = size+1;
      new_vector->size = newsize; 
      new_vector->elements = new Elem[newsize];

      for(uint8_t i = 0; i < size; i++){
        new_vector->elements[i] = v->elements[i];
      }
      new_vector->elements[size] = value;
      dealloc_vec(v);
      return new_vector;
  }
  return NULL;
}

// scalar_plus:
// 	Adds the specified Elem value to each element in the Vector
// In:
// 	Vector != NULL
// 	Elem
// Out:
// 	return -- Vector with updated values, NULL otherwise
// 	effect -- All elements in Vector get updated with new values if successfull.
Vector *scalar_plus(Vector *v, Elem value){
  if(!is_vec_null(v)){
    if(v->size > 0){ // don't add to an empty vector
      uint8_t size = v->size;
      for(int i = 0; i < size; i++){
        v->elements[i] += value;
      }
      return v;
    }
  }
  return NULL;
}
// scalar_minus:
// 	Subtracts the specified Elem value from each element in Vector
// In:

// 	Vector != NULL
// 	Elem
// Out:
//
// 	return -- Vector with updated values, NULL otherwise
// 	effect -- All elements in Vector get updated with new values if successful
Vector *scalar_minus(Vector *v, Elem value){
        return NULL;
}


// scalar_multiply:
// 	Multiplies the specified Elem value from each element in Vector
// In:
// 	Vector != NULL
// 	Elem
// Out:
// 	return -- Vector with updated values, NULL otherwise
// 	effect -- All elements in Vector get updated with new values if successful.
Vector *scalar_mult(Vector *v, Elem value){
        return NULL;
}

// scalar_divide:
// 	Divides the specified Elem value from each element in Vector
// In:
// 	Vector != NULL
// 	Elem
// Out:
// 	return -- Vector with updated values, NULL otherwise
// 	effect -- All elements in Vector get updated with new values.
Vector *scalar_divide(Vector *v, Elem value){
        return NULL;
}

// main: 
// 	Program entry point
// In:
// 	argc > 0
// 	argv[0 .. argc-1] != NULL
// Out:
// 	return -- EXIT_SUCCESS if program terminates normally,
// 		  EXIT_FAILURE otherwise
int main(int argc, char* argv[]){

#ifdef TESTING
	
	// New Vector
	Vector *v = NULL;
  
  // Testing is_vec_null
  assert(true == is_vec_null(v));

	// Checking alloc_vec:
	v = alloc_vec();
	//assert(NULL != v);
	
	// Checking extend_vec
	assert(NULL != extend_vec(v,1.0));
  v = extend_vec(v,1.0);
	
  // Checking scalar_plus:
  assert(NULL != scalar_plus(v,2.0));	
  v = scalar_plus(v,2.0);

  // Checking scalar_minus:
	assert(NULL != scalar_minus(v,2.0)); 
  v = scalar_minus(v,2.0);
	
  // Checking scalar_multiply:
	assert(NULL != scalar_mult(v,2.0));
  v = scalar_mult(v,2.0);

	// Checking scalar_divide:
	assert(NULL != scalar_divide(v,2.0));
  v = scalar_divide(v,2.0);
	
	// Checking print_vec:
	// Expected output value: 1.0
	print_vec(v);
	

#endif // TESTING
	return EXIT_SUCCESS;

};
