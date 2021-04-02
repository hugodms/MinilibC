/*
** EPITECH PROJECT, 2021
** test_memcpy.cB-CPP-300-BDX-3-1-CPPD01-hugo.domingues
** File description:
** drawing
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

extern char *strchr(const char *str, int c);

Test(simpleStrchr, strchrPassed)
{
    char str[] = "This is tutorialspoint.com";
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*cosine)(const char*, int);
    char *len;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strchr");

    if (cosine == NULL)
        return;

    len = (*cosine)(str, '.');

    dlclose(handle);

    cr_assert_str_eq(len, ".com");
}

Test(simpleStrchr, strchrNoPassed1)
{
    char str[] = "This is tutorialspoint.com";
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*cosine)(const char*, int);
    char *len;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strchr");

    if (cosine == NULL)
        return;

    len = (*cosine)(str, 'z');

    dlclose(handle);

    cr_assert_eq(len, NULL);
}

Test(simpleStrchr, strchrNoPassed2)
{
    char str[] = "";
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*cosine)(const char*, int);
    char *len;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strchr");

    if (cosine == NULL)
        return;

    len = (*cosine)(str, 'z');

    dlclose(handle);

    cr_assert_eq(len, NULL);
}
