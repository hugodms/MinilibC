/*
** EPITECH PROJECT, 2021
** test_memcpy.cB-CPP-300-BDX-3-1-CPPD01-hugo.domingues
** File description:
** drawing
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

extern size_t strlen(const char *str);

Test(simpleStrlen, strlenPassed)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*cosine)(const char *);
    char str[] = "This is tutorialspoint.com";
    int len;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strlen");

    if (cosine == NULL)
        return;

    len = (*cosine)(str);

    dlclose(handle);

    cr_assert_eq(len, 26);
}

Test(simpleStrlen, strlenNoPassed)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*cosine)(const char *);
    char str[] = "";
    int len;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strlen");

    if (cosine == NULL)
        return;

    len = (*cosine)(str);

    dlclose(handle);

    cr_assert_eq(len, 0);
}

