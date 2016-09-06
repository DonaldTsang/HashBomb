#include "hashBomb.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "0-sha2/sph_sha2.h"
#include "1-blake/sph_blake.h"
#include "2-groestl/sph_groestl.h"
#include "3-keccak/sph_keccak.h"

void hashBomb_1024(const char* input, char* output){

    sph_sha256_context       ctx_sha2;
    sph_blake256_context     ctx_blake;
    sph_groestl256_context   ctx_groestl;
    sph_keccak256_context    ctx_keccak;

    uint32_t hash0[8], hash1[8], hash2[8], hash3[8]; // 256-bit hash
    uint32_t hash[32]; // 1024-bit hash

    sph_sha256_init(&ctx_sha2);
    sph_sha256 (&ctx_sha2, input, 128);
    sph_sha256_close(&ctx_sha2, hash0);

    sph_blake256_init(&ctx_blake);
    sph_blake256 (&ctx_blake, input, 128);
    sph_blake256_close (&ctx_blake, hash1);

    sph_groestl256_init(&ctx_groestl);
    sph_groestl256 (&ctx_groestl, input, 128);
    sph_groestl256_close(&ctx_groestl, hash2);

    sph_keccak256_init(&ctx_keccak);
    sph_keccak256 (&ctx_keccak, input, 128);
    sph_keccak256_close(&ctx_keccak, hash3);

    for (int i = 0; i < 4; i += 1){
        hash[8*i+0] = hash0[2*i+0]; hash[8*i+1] = hash0[2*i+1];
        hash[8*i+2] = hash1[2*i+0]; hash[8*i+3] = hash1[2*i+1];
        hash[8*i+4] = hash2[2*i+0]; hash[8*i+5] = hash2[2*i+1];
        hash[8*i+6] = hash3[2*i+0]; hash[8*i+7] = hash3[2*i+1];
    }

    memcpy(output, hash, 128);

}

void hashBomb_1536(const char* input, char* output){

    sph_sha384_context       ctx_sha2;
    sph_blake384_context     ctx_blake;
    sph_groestl384_context   ctx_groestl;
    sph_keccak384_context    ctx_keccak;

    uint32_t hash0[12], hash1[12], hash2[12], hash3[12]; // 384-bit hash
    uint32_t hash[48]; // 1536-bit hash

    sph_sha384_init(&ctx_sha2);
    sph_sha384 (&ctx_sha2, input, 192);
    sph_sha384_close(&ctx_sha2, hash0);

    sph_blake384_init(&ctx_blake);
    sph_blake384 (&ctx_blake, input, 192);
    sph_blake384_close (&ctx_blake, hash1);

    sph_groestl384_init(&ctx_groestl);
    sph_groestl384 (&ctx_groestl, input, 192);
    sph_groestl384_close(&ctx_groestl, hash2);

    sph_keccak384_init(&ctx_keccak);
    sph_keccak384 (&ctx_keccak, input, 192);
    sph_keccak384_close(&ctx_keccak, hash3);

    for (int i = 0; i < 4; i += 1){
        hash[12*i+0] = hash0[3*i+0]; hash[12*i+1] = hash0[3*i+1]; hash[12*i+2] = hash0[3*i+2];
        hash[12*i+3] = hash1[3*i+0]; hash[12*i+4] = hash1[3*i+1]; hash[12*i+5] = hash1[3*i+2];
        hash[12*i+6] = hash2[3*i+0]; hash[12*i+7] = hash2[3*i+1]; hash[12*i+8] = hash2[3*i+2];
        hash[12*i+9] = hash3[3*i+0]; hash[12*i+10] = hash3[3*i+1]; hash[12*i+11] = hash3[3*i+2];
    }

    memcpy(output, hash, 192);

}

void hashBomb_2048(const char* input, char* output){

    sph_sha512_context       ctx_sha2;
    sph_blake512_context     ctx_blake;
    sph_groestl512_context   ctx_groestl;
    sph_keccak512_context    ctx_keccak;

    uint32_t hash0[16], hash1[16], hash2[16], hash3[16]; // 512-bit hash
    uint32_t hash[64]; // 2048-bit hash

    sph_sha512_init(&ctx_sha2);
    sph_sha512 (&ctx_sha2, input, 256);
    sph_sha512_close(&ctx_sha2, hash0);

    sph_blake512_init(&ctx_blake);
    sph_blake512 (&ctx_blake, input, 256);
    sph_blake512_close (&ctx_blake, hash1);

    sph_groestl512_init(&ctx_groestl);
    sph_groestl512 (&ctx_groestl, input, 256);
    sph_groestl512_close(&ctx_groestl, hash2);

    sph_keccak512_init(&ctx_keccak);
    sph_keccak512 (&ctx_keccak, input, 256);
    sph_keccak512_close(&ctx_keccak, hash3);

    for (int i = 0; i < 4; i += 1){
        hash[16*i+0] = hash0[4*i+0]; hash[16*i+1] = hash0[4*i+1]; hash[16*i+2] = hash0[4*i+2]; hash[16*i+3] = hash0[4*i+3]; 
        hash[16*i+4] = hash1[4*i+0]; hash[16*i+5] = hash1[4*i+1]; hash[16*i+6] = hash1[4*i+2]; hash[16*i+7] = hash1[4*i+3];
        hash[16*i+8] = hash2[4*i+0]; hash[16*i+9] = hash2[4*i+1]; hash[16*i+10] = hash2[4*i+2]; hash[16*i+11] = hash2[4*i+3];
        hash[16*i+12] = hash3[4*i+0]; hash[16*i+13] = hash3[4*i+1]; hash[16*i+14] = hash3[4*i+2]; hash[16*i+15] = hash3[4*i+3];
    }

    memcpy(output, hash, 256);

}