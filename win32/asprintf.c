/*
 * Copyright (C) 2001 Federico Di Gregorio <fog@debian.org> 
 * Copyright (C) 1991, 1994-1999, 2000, 2001 Free Software Foundation, Inc.
 *
 * This code has been derived from an example in the glibc2 documentation.
 * This file is part of the psycopg module.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

/*
 * asprintf.c -- asprintf() implementation for braindamaged operating systems
 */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int asprintf(char **buffer, const char *fmt, ...);
int asprintf(char **buffer, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    const int nchars = _vscprintf(fmt, ap);
    va_end(ap);
    if (nchars < 0) return nchars;

    const size_t size = (size_t)nchars + 1;
    *buffer = (char*)malloc(size);
    if (*buffer == NULL) return -1;

    va_start(ap, fmt);
    const int written = vsnprintf_s(*buffer, size, _TRUNCATE, fmt, ap);
    va_end(ap);
    if (written < 0) {
        free(*buffer);
        *buffer = NULL;
        return -1;
    }
    return written;
}
