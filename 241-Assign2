#ifndef PRODUCT_H
#define PRODUCT_H

//*****************************************************************
// FILE:      Product.h
// AUTHOR:    
// LOGON ID:  
// DUE DATE:  September 20, 2012
//
// PURPOSE:   	HEADER
// 				Contains the declaration for the Product class.
//*****************************************************************

class Product
{
private:
char code[12];  //private data members
char name[46];
double price;
int quantity;

public:
Product();      //public method prototypes
Product(char[], char[], double, int);
char* getProductCode();
char* getName();
double getPrice();
int getQuantity();
void setPrice(double);
void setQuantity(int);
int fulfillOrder(int);
void print();

};

#endif

#ifndef STORE_H
#define STORE_H

//*****************************************************************
// FILE:      Store.h
// AUTHOR:    
// LOGON ID:  
// DUE DATE:  September 20, 2012
//
// PURPOSE:   Contains the declaration for the Store  class.
//*****************************************************************

#include <fstream>
#include <cstdlib>
#include "Product.h"


class Store
{
private:
Product product[30];    //private data members
int object;

public:
Store();
Store(const char*);
void print();
void sortProducts();
int searchForProduct(const char*);
void processOrders(const char*);

};

#endif
