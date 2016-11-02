// Author: Muhammad Tayab Soomro
// Student #: 11199539
// NSID: mts066
// Email: tayab.soomro@usask.ca
// GitHub: https://github.com/tayabsoomro/vecalc.git
// Description: vecalc program created for Assignment 2 for the CMPT-214
// Created On: Tuesday 25th October, 2016.
// Finished On: ---

// Standard headers
#include <assert.h> // for assert()
#include <inttypes.h> // for fixed-width datatypes
#include <stdlib.h> // for EXIT_SUCCESS, etc.
#include <stdio.h> // for printf, etc.

// The program can either be in INPUT or CALC State.
typedef enum { INPUT, CALC } State;
// ... (State s, ...){
//      switch(s){
//	        case INPUT: ...; break;
//		case CALC: ...; break;
//		default: assert(false); break;
//	}
// }

const int MAX_ELEMS = UINT16_MAX; // Value chosen because a vector can
                                  // contain from 0 to 65535 elements.

// A VecSize is uint16_t representing the size of the Vector
typedef uint16_t VecSize;
// for(VecSize i = 0 ...){
//   ...
// }

// An Elem is single precision floating-point value
typedef float Elem;

// A Vector consists of vector's size and it's elements
typedef struct {
    VecSize size; // Number of elements in the vector
    Elem *elements; // Array of Elem for the vector.
} Vector;
// ... (Vector *v, uint8_t index, ...) {
//   ... v->elements[index] ...
// }




// Usage
//  Instruct user on how to use this program; i.e. the commands it
//  supports and the syntax of those commands.
// In:
//    none
// Out:
//    No Return Value
//    effect -- output produced on standard output
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
// 	Prints the Vector *v  provided in param
// In:
// 	Vector != NULL
// 	v->elements != NULL
// 	v->size > 0
// Out:
// 	Return -- true if successful, false otherwise
// 	effect -- Vector is printed on the stdin
bool print_vec(Vector *v){
    if(is_vec_null(v)) return false;
    else if(v->elements == NULL || v->size <= 0) return false;
    puts("** PRINT VECTOR BEGIN ***\n");
    printf("** VECTOR SIZE: %" PRIu16 "\n\n",v->size);
    puts("** VECTOR ELEMENTS:");

    VecSize size = v->size;

    // print the vector
    for(VecSize i = 0; i < size; i++){
        VecSize serialNumber = i+1; // serial number is always 1 unit greater than the index
        printf("%" PRIu16 ": %f\n",serialNumber,v->elements[i]);
    }
    puts("\n");
    puts("** PRINT VECTOR END  **\n");
    return true;
}

// alloc_vec:
// 	Allocates an empty Vector
// In:
// 	N/a
// Out:
// 	return -- Pointer to newly allocated Vector if successfull, NULL otherwise
// 	effect -- A new Vector is allocted to dynamic memory space.
Vector *alloc_vec(void){
    // allocate the vector
    Vector *v = new Vector;
    if(v != NULL){
      v->size = 0;
      v->elements = NULL;
    }
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
        if(MAX_ELEMS == v->size) return NULL;
        /*else if(0 == v->size) {
          Vector *new_vector = alloc_vec();
          new_vector->elements = new Elem[1];
          new_vector->elements[0] = value;
          new_vector->size++;
          return new_vector;
        }*/
        else{
          VecSize orig_size = v->size;

          Vector *new_vector = alloc_vec();
          VecSize new_size = orig_size+1;

          new_vector->size = new_size;
          new_vector->elements = new Elem[new_size];

          for(VecSize i = 0; i < orig_size; i++){
            new_vector->elements[i] = v->elements[i];
          }
          new_vector->elements[orig_size] = value;
          return new_vector;
        }
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
            VecSize size = v->size;
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
// 	effect -- All elemtj5e.jpgments in Vector get updated with new values if successful
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
// 	argc > 0 new Elem[newsize];
// 	argv[0 .. argc-1] != NULL
// Out:
// 	return -- EXIT_SUCCESS if program terminates normally,
// 		  EXIT_FAILURE otherwise
int main(int argc, char* argv[]){

#ifdef TESTING

    // New Vector
    Vector *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;

    // Testing is_vec_null for true
    assert(is_vec_null(v1) && is_vec_null(v2) && is_vec_null(v3) && is_vec_null(v4));



    // Checking alloc_vec:
    v1 = alloc_vec();
    assert(NULL != v1);
    assert(NULL == v1->elements);
    assert(0 == v1->size);

    v2 = alloc_vec();
    assert(NULL != v2);
    assert(NULL == v2->elements);
    assert(0 == v2->size);

    v3 = alloc_vec();
    assert(NULL != v3);
    assert(NULL == v3->elements);
    assert(0 == v2->size);

    v4 = alloc_vec();
    assert(NULL != v4);
    assert(NULL == v4->elements);
    assert(0 == v4->size);

    // Testing is_vec_null for false
    assert(!is_vec_null(v1) && !is_vec_null(v2) && !is_vec_null(v3) && !is_vec_null(v4));


    // Checking extend_vec

    assert(NULL == extend_vec(NULL,1.0));

    v2 = extend_vec(v1,100.0);
    assert(NULL != v2);
    assert(1 == v2->size);
    assert(100.0 == v2->elements[0]);

    dealloc_vec(v1);

    v3 = extend_vec(v2,96.0);
    assert(NULL != v3);
    assert(2 == v3->size);
    assert(96.0 == v3->elements[1]);

    dealloc_vec(v2);

    v4 = extend_vec(v3,12.0);
    assert(NULL != v4);
    assert(3 == v4->size);
    assert(12.0 == v4->elements[2]);

    dealloc_vec(v3);

    // Checking scalar_plus:
    assert(NULL != scalar_plus(v4,2.0));
    assert(NULL == scalar_plus(NULL,0.0));

    assert(102.00000 == v4->elements[0]);
    assert(98.000000 == v4->elements[1]);
    assert(14.000000 == v4->elements[2]);

    // Checking for -'ve values in scalar_plus
    assert(NULL != scalar_plus(v4,-2.0));

    assert(100.000000 == v4->elements[0]);
    assert(96.000000 == v4->elements[1]);
    assert(12.000000 == v4->elements[2]);


    // Checking print_vec:
    // Expected output:
    // ** PRINT VECTOR BEGIN ***
    //
    // ** VECTOR SIZE: 3
    //
    // ** VECTOR ELEMENTS:
    // 1. 100.000000
    // 2. 96.000000
    // 3. 12.000000
    // ** PRINT VECTOR END  **
    assert(true == print_vec(v4));
    assert(false == print_vec(NULL));

    // Checking scalar_minus:
    assert(NULL != scalar_minus(v4,2.0));
    assert(NULL == scalar_minus(NULL,0.0));

    assert(98.000000 == v4->elements[0]);
    assert(94.000000 == v4->elements[1]);
    assert(10.000000 == v4->elements[2]);

    // Checking for -'ve values in scalar_minus:
    assert(NULL != scalar_minus(v4,-4.0));

    assert(102.000000 == v4->elements[0]);
    assert(98.000000 == v4->elements[1]);
    assert(14.000000 == v4->elements[2]);


    // Checking scalar_multiply:
    assert(NULL != scalar_mult(v4,1.0));
    assert(NULL == scalar_mult(NULL,0.0));

    assert(102.000000 == v4->elements[0]);
    assert(98.000000 == v4->elements[1]);
    assert(14.000000 == v4->elements[2]);

    // Checking for -'ve values in scalar_mult
    assert(NULL != scalar_mult(v4,-1.0));

    assert(-102.000000 == v4->elements[0]);
    assert(-98.000000 == v4->elements[1]);
    assert(-14.000000 == v4->elements[2]);

    // Checking scalar_divide:
    assert(NULL != scalar_divide(v4,2.0));
    assert(NULL == scalar_divide(NULL,0.0));

    assert(-51.000000 == v4->elements[0]);
    assert(-49.000000 == v4->elements[1]);
    assert(-7.000000 == v4->elements[2]);

    // Checking for -'ve values in scalar_divide
    assert( NULL != scalar_divide(v4,-1.0));

    assert(51.000000 == v4->elements[0]);
    assert(49.000000 == v4->elements[1]);
    assert(7.000000 == v4->elements[2]);


    // Deallocting vector -- Unfortunately there is little that can be done from the program prespective to test that
    // all the dynamic memory tied up by the structures pointed to by v1, v2, v3 and v4 has been freed.
    dealloc_vec(v4);
#endif // TESTING
    return EXIT_SUCCESS;

}
