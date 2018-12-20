#include "yespower.h"

void yespower_hash(const char *input, char *output, uint32_t len) {
    static const yespower_params_t params = {YESPOWER_1_0, 2048, 32, NULL, 0};
    yespower_tls( (yespower_binary_t*)input, len, &params, (yespower_binary_t*)output );
}

void yespowerr8_hash(const char *input, char *output, uint32_t len) {
    static const yespower_params_t params = {YESPOWER_0_5, 2048, 8, "Client Key", 10};
    yespower_tls( (yespower_binary_t*)input, len, &params, (yespower_binary_t*)output );
}

void yespowerr16_hash(const char *input, char *output, uint32_t len) {
    static const yespower_params_t params = {YESPOWER_0_5, 4096, 16, "Client Key", 10};
    yespower_tls( (yespower_binary_t*)input, len, &params, (yespower_binary_t*)output );
}

void yespowerr24_hash(const char *input, char *output, uint32_t len) {
    static const yespower_params_t params = {YESPOWER_0_5, 4096, 24, "JagaricoinR", 10};
    yespower_tls( (yespower_binary_t*)input, len, &params, (yespower_binary_t*)output );
}

void yespowerr32_hash(const char *input, char *output, uint32_t len) {
    static const yespower_params_t params = {YESPOWER_0_5, 4096, 32, "WaviBanana", 10};
    yespower_tls( (yespower_binary_t*)input, len, &params, (yespower_binary_t*)output );
}

void yespower_koto_hash(const char *input, size_t inputlen, char *output)
{
	yespower_params_t params = {
		.version = YESPOWER_0_5,
		.N = 2048,
		.r = 8,
		.pers = (const uint8_t *)input,
		.perslen = inputlen
	};
	if (yespower_tls((unsigned char *)input, inputlen, &params, (yespower_binary_t *)output))
		abort();
}