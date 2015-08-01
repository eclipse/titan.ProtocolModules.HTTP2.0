/******************************************************************************
* Copyright (c) 2015  Ericsson AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
* Contributors:
******************************************************************************/
//
//  File:               HTTP.y
//  Rev:                R1C
//  Prodnr:             CNL113
//  Updated:            2014-10-10
//  Contact:            http://ttcn.ericsson.se
//  Reference:          RFC7230 - RFC7235
#ifndef HTTP_parse_parser_H
#define HTTP_parse_parser_H
#include "HTTP_Types.hh"
#include "General_Types.hh"
int HTTP_parse_parse();

int HTTP_parse_lex();

int HTTP_parse_error(const char *s);

#endif
