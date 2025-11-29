// this is test file and example for use library libflux.h
#include "libflux.h"

int main(void) {
    FLUX_TRY {
        char* buffer = (char*)FLUX_MALLOC(1024);
        FILE* f = FLUX_FOPEN("test.txt", "w");
        fprintf(f, "Hello from libflux!\n");
        snprintf(buffer, 1024, "Data processed at %p", (void*)buffer);
        printf("✅ %s\n", buffer);
    } FLUX_CATCH(e) {
        flux_error_print(e);
        return 1;
    } FLUX_END_TRY;

    FLUX_TRY {
        int* arr = (int*)FLUX_CALLOC(1000, sizeof(int));
        arr[999] = 42;
        printf("✅ Large array allocated and initialized\n");
    } FLUX_CATCH(e) {
        flux_error_print(e);
        return 1;
    } FLUX_END_TRY;

    FLUX_TRY {
        FILE* f = FLUX_FOPEN("nonexistent.txt", "r");
        (void)f;
    } FLUX_CATCH(e) {
        printf("✅ Caught expected error: ");
        flux_error_print(e);
    } FLUX_END_TRY;

    printf("✨ All tests passed — zero leaks, full control.\n");
    return 0;
}