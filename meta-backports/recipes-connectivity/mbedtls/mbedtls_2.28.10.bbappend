do_configure:prepend() {
	sed -i -e 's@//\s*\(#define MBEDTLS_CMAC_C\)@\1@' ${S}/include/mbedtls/config.h
}
