# veCalc
_Simple. Interactive. Vector Calculator_

## Contents
- [Introduction](#introduction)
 + [Author Info](#author)
 + [Program](#program)
- [Compilation](#compilation)
- [Project Progress](#project-progress)
- [Code Structure](#code-structure)
 + [Data Types](#datatypes)
 + [Constants](#contants)
 + [Functions](#functions)

## Introduction

- ### Author
veCalc is a simple text-based vector calculator proudly created by Muhammad Tayab Soomro in CMPT 214 at the University of Saskatchewan. Tayab is a second-year computer science student, loves solving real-world problems with computer programs.
Student #: 11199539 | NSID: mts066

- ### Program
The vecalc program operates on a retained vector of (single-precision) floating-point values. It alternates between two states, an input state and a calculation (or calculator) state. The program begins execution in the former state, wherein it creates an empty vector, prompts the user for a number of elements in the vector, and builds up a vector with elements obtained one-at-a-time from the user. The program then switches to calculation state. In calculation state vecalc accepts operations and commands from the user and executes them. After most commands the program remains in calculation state. On a "clear" command ("c"), the program frees up the memory used by the current vector (i.e. deletes that exiting vector) and switches back to input state.


## Compilation
 The program can be compiled through following commands.
  - `g++ -Wall -Wextra -o vecalc vecalc.cc` - Outputs executable file named vecalc.
  - `g++ -Wall -Wextra -DTESTING -o vecalc.testing vecalc.cc` - Outputs executable file named vecalc.testing which runs the tests

## Project Progress

 - Implementation
  + Functions (**5**/8)
      - Completed:
        + _`bool print_vec(Vector *)`_
        + _`Vector *alloc_vec(void)`_
        + _`void dealloc_vec(Vector *)`_
        + _`Vector *extend_vec(Vector *, Elem)`_
        + _`Vector *scalar_plus(Vector *, Elem)`_
      - Incomplete
        + _`Vector *scalar_minus(Vector *, Elem)`_
        + _`Vector *scalar_mult(Vector *, Elem)`_
        + _`Vector *scalar_div(Vector *, Elem)`_
        
## Code Structure

- ### Datatypes
  + **Elem** - Represents an element and is of type `float`
  
    ***Example Usage***

      
  + **VecSize** - Represents the size of a Vector
  
    ***Example Usage***
    ```
    // for(VecSize i = 0 ...){
    //   ...
    // }
    ```
    
  + **State** - Representing program states `INPUT` and `CALC`
  
    ***Example Usage***
    ```
    // ... (State s, ...){
    //      switch(s){
    //	        case INPUT: ...; break;
    //		case CALC: ...; break;
    //		default: assert(false); break;
    //	}
    // }
    ```
  + **Vector** - Represents a structured type of vectors
  
    ***Example Usage***
    ```
    // ... (Vector *v, uint8_t index, ...) {
    //   ... v->elements[index] ...
    // }
    ```
- ### Constants
  + **MAX_ELEMS** - Represents the maximum number of elements that a Vector can hold (UINT16_MAX)
    - This value was chosen because a vector can contain elements from 0 - 65535.

- ### Functions
  + ***`void usage(void);`***
  
    ```
    // Usage
    //  Instruct user on how to use this program; i.e. the commands it
    //  supports and the syntax of those commands.
    // In:
    //    none
    // Out:
    //    No Return Value
    //    effect -- output produced on standard output
    ```
   
   + ***`bool is_vec_null(Vector *);`***
   
      ```
      // is_vec_null:
      //  Checks if the vector passed in as param NULL or not
      // In:
      //  Vector != NULL
      // Out:
      //  Return -- true if v is NULL, false otherwise
      ```
    
   + ***`bool print_vec(Vector *);`***
   
      ```
      // print_vec:
      // 	Prints the Vector *v  provided in param
      // In:
      // 	Vector != NULL
      // 	v->elements != NULL
      // 	v->size > 0
      // Out:
      // 	Return -- true if successful, false otherwise
      // 	effect -- Vector is printed on the stdin
      ```
    
   + ***`Vector *alloc_vec(void);`***
   
      ```
      // alloc_vec:
      // 	Allocates an empty Vector
      // In:
      // 	N/a
      // Out:
      // 	return -- Pointer to newly allocated Vector if successfull, NULL otherwise
      // 	effect -- A new Vector is allocted to dynamic memory space.
      ```
    
   + ***`void dealloc_vec(Vector *);`***
   
      ```
      // dealloc_vec:
      // 	Deallocates a given Vector
      // In:
      // 	Vector != NULL
      // Out:
      // 	No return value
      // 	effect -- Vector passed through param is safely deallocated from memory space.
      ```
    
   + ***`Vector *extend_vec(Vector *, Elem);`***
    
      ```
      // extend_vec:
      // 	Extend Vector with specified Elem value
      // In:
      // 	Vector != NULL
      // 	Elem
      // Out:
      // 	return  -- Vector including the new Elem value
      //	effect -- Deallocates the given Vector and creates a new one with new Elem value added.
      ```
    
   + ***`Vector *scalar_plus(Vector *, Elem);`***
   
      ```
      // scalar_plus:
      // 	Adds the specified Elem value to each element in the Vector
      // In:
      // 	Vector != NULL
      // 	Elem
      // Out:
      // 	return -- Vector with updated values, NULL otherwise
      // 	effect -- All elements in Vector get updated with new values if successfull.
      ```
    
   + ***`Vector *scalar_minus(Vector *, Elem);`***
   
      ``` 
      // scalar_minus:
      // 	Subtracts the specified Elem value from each element in Vector
      // In:

      // 	Vector != NULL
      // 	Elem
      // Out:
      //
      // 	return -- Vector with updated values, NULL otherwise
      // 	effect -- All elemtj5e.jpgments in Vector get updated with new values if successful
      ```
    
    + ***`Vector *scalar_mult(Vector *v, Elem)`***
    
      ```
      // scalar_multiply:
      // 	Multiplies the specified Elem value from each element in Vector
      // In:
      // 	Vector != NULL
      // 	Elem
      // Out:
      // 	return -- Vector with updated values, NULL otherwise
      // 	effect -- All elements in Vector get updated with new values if successful.

      ```
   + ***`Vector *scalar_divide(Vector *, Elem)`***
    
      ```
      // scalar_divide:
      // 	Divides the specified Elem value from each element in Vector
      // In:
      // 	Vector != NULL
      // 	Elem
      // Out:
      // 	return -- Vector with updated values, NULL otherwise
      // 	effect -- All elements in Vector get updated with new values.

      ```
    
   + ***`int main(int,char * *)`***
    
      ```
      // main:
      // 	Program entry point
      // In:
      // 	argc > 0 new Elem[newsize];
      // 	argv[0 .. argc-1] != NULL
      // Out:
      // 	return -- EXIT_SUCCESS if program terminates normally,
      // 		  EXIT_FAILURE otherwise
      ```
