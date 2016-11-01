// Author: Muhammad Tayab Soomro
// Student #: 11199539
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
  if(!is_vec_null(v) || NULL != v->elements || 0 < v->size){ 
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
  return false;
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
    v->size = 0;
    v->elements = new Elem[v->size];
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
       if(MAX_ELEMS <= v->size) return NULL; 
        VecSize size = v->size;

        Vector *new_vector = alloc_vec();
        VecSize newsize = size+1;
        new_vector->size = newsize; 
        new_vector->elements = new Elem[newsize];

        for(VecSize i = 0; i < size; i++){
            new_vector->elements[i] = v->elements[i];
        }
        new_vector->elements[size] = value;
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
// 	return -- Vec://www.facebook.com/l.php?u=http%3A%2F%2Fwww.nserc-crsng.gc.ca%2FStudents-Etudiants%2FUG-PC%2FUSRA-BRPC_eng.asp%23apply&h=CAQG4uK6qtor with updated values, NULL otherwise
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
  
    // Testing is_vec_null
    assert(true == is_vec_null(v1) && true == is_vec_null(v2) && true == is_vec_null(v3) && is_vec_null(v4));

    // Checking alloc_vec:
    v1 = alloc_vec();
    assert(NULL != v1);
	
    // Checking extend_vec
    
    v2 = extend_vec(v1,1.0);
    assert(NULL != v2);
    assert(1.0 == v2->elements[0]);
    
    dealloc_vec(v1);

    assert(NULL == extend_vec(NULL,1.0));

    v3 = extend_vec(v2,2.0);
    assert(NULL != v3);
    assert(2.0 == v3->elements[1]);

    dealloc_vec(v2);

    v4 = extend_vec(v3,3.0);
    assert(NULL != v4);
    assert(3.0 == v4->elements[2]);

    assert(3 == v4->size);    
    
	
    // Checking scalar_plus:
    assert(NULL != scalar_plus(v4,2.0));	
    
    assert(3.000000 == v4->elements[0]);
    assert(4.000000 == v4->elements[1]);
    assert(5.000000 == v4->elements[2]);
        
    // Checking print_vec:
    // Expected output:
    // ** PRINT VECTOR BEGIN ***
    //
    // ** VECTOR SIZE: 3
    //
    // ** VECTOR ELEMENTS:
    // 1: 3.000000
    // 2: 4.000000
    // 3: 5.000000
    //
    //
    // ** PRINT VECTOR END  **
    print_vec(v4);

    // Checking scalar_minus:
    assert(NULL != scalar_minus(v4,2.0)); 
	
    // Checking scalar_multiply:
    assert(NULL != scalar_mult(v4,2.0));

    // Checking scalar_divide:
    assert(NULL != scalar_divide(v4,2.0));
	

#endif // TESTING
    return EXIT_SUCCESS;

};
