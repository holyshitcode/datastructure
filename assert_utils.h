// assert_utils.h

#ifndef ASSERT_UTILS_H
#define ASSERT_UTILS_H

#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#include <stdlib.h>

typedef enum Boolean {
    IsNot,
    null
} boolean;

int assertEqualString(char *input, char *expected, boolean boolean);
int assertEqualInt(int input, int expected, boolean boolean);
int assertEqualCharLen(char *input, char *expected, boolean boolean);
int assertEqualIntArray(int input[], int inputLen, int expected[], int expectedLen, boolean boolean);
int assertEqualDoubleArray(double input[], double inputLen, double expected[], double expectedLen, boolean boolean);
int assertEqualLongArray(long input[], long inputLen, long expected[], long expectedLen, boolean boolean);
int assertCharContaining(char *input, char expected, boolean boolean);
int assertStrContainingStr(char *input, char *expected, boolean boolean);
int assertIntArrayContainingInt(int input[], int inputLen, int expected, boolean boolean);
int assertDoubleArrayContainingDouble(double input[], int inputLen, double expected, boolean boolean);
int assertLongArrayContainingLong(long input[], int inputLen, long expected, boolean boolean);
int assertMallocIsNotNull(void *input, boolean boolean);
void try();

extern jmp_buf jump;

#endif // ASSERT_UTILS_H