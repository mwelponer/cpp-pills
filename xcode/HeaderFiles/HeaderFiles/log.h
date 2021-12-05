//
//  log.h
//  HeaderFiles
//
//  Created by Mike on 27/11/2021.
//

// specifies that it is preprocessed before to be compiled
 
/* pragma once is an header guard
it means only include this file once. It prevents
to include a single header file multiple times into a
single translation unit (so a single c++ file)
..so if i declare a struct inside my header file and the header
file is included two times, we will have an error because of
redefinition of struct */
#pragma once

// it can be substituted with:

//#ifndef _LOG_H
//#define _LOG_H

void initLog();
void log(const char* message);

//#endif

