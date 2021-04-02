/*
** EPITECH PROJECT, 2021
** test_memcpy.cB-CPP-300-BDX-3-1-CPPD01-hugo.domingues
** File description:
** drawing
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

Test(simpleMemset, memsetPassed)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    void *(*cosine)(void *dest, int c, size_t n);
    char str[] = "This is string.h library function";

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "memset");

    if (cosine == NULL)
        return;

    (*cosine)(str,'$',7);

    dlclose(handle);

    cr_assert_str_eq(str, "$$$$$$$ string.h library function");
}
