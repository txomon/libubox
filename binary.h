/*
 * binary - binary blob writer
 *
 * Copyright (C) 2015 Javier Domingo Cansino <javierdo1@gmail.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef __LIBUBOX_BINARY_H
#define __LIBUBOX_BINARY_H

#include <varargs.h>

/*
 * Syntax for the function is as follows.
 *   %[n][a][lb][01r]{i,y,w,d,q,s}
 *
 * Data type
 *   * i - bit
 *   * y - byte
 *   * w - 2 byte word
 *   * d - 4 byte word
 *   * q - 8 byte word
 *   * s - string without termination (use strlen()+1 in quantity to null)
 *
 * Data value
 *   * 0 - fill the specified space with zeros
 *   * 1 - fill the specified space with ones
 *   * r - fill the specified space with random data
 *
 *     String data type is not valid in this case
 *
 * Endianess. No conversion by default
 *   * l - little endian
 *   * b - big endian
 *
 * Alignment. No alignment by default
 *   * a - align this to it's datatype
 *         bits are aligned to byte
 *
 * Quantity. One by default
 *   * n - number of same datatype (placed together)
 *         this denotes length of string, padded with 0
 *
 * Some examples:
 *   * %4lw - 4 little endian 2 byte word
 *   * %2i  - 2 bits 'ab' from value b'000000ab'
 *   * %2bi - 2 bits 'ab' from value b'000000ba'
 *   * %2li - 2 bits 'ab' from value b'ab000000'
 *
 */

void * writeb(char *, ...);
void * readb(char *, ...);

int vwriteb(void *, char *, ...);
int vreadb(void *, char *, ...);


#endif //__LIBUBOX_BINARY_H
