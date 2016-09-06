#ifndef HASHBOMB_H
#define HASHBOMB_H

#ifdef __cplusplus
extern "C" {
#endif

void hashBomb_1024(const char* input, char* output);
void hashBomb_1536(const char* input, char* output);
void hashBomb_2048(const char* input, char* output);

#ifdef __cplusplus
}
#endif

#endif