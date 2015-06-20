#pragma once

long diff_nano(struct timespec *start, struct timespec *end);
long diff_micro(struct timespec *start, struct timespec *end);
long diff_milli(struct timespec *start, struct timespec *end);
