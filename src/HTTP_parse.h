/******************************************************************************
* Copyright (c) 2000-2018 Ericsson Telecom AB AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v2.0
* which accompanies this distribution, and is available at
* https://www.eclipse.org/org/documents/epl-2.0/EPL-2.0.html
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
