// Author: Muhammad Tayab Soomro
// Student #: 11199539
// NSID: mts066
// Email: tayab.soomro@usask.ca

#ifndef _VECTOR_H
#define _VECTOR_H

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


#endif _VECTOR_H
