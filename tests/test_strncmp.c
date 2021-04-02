/*
** EPITECH PROJECT, 2021
** test_memcpy.cB-CPP-300-BDX-3-1-CPPD01-hugo.domingues
** File description:
** drawing
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

Test(simpleStrncmp, strncmpPassed)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*cosine)(const char *str1, const char *str2, size_t i);
    char str1[] = "ABCzzF";
    char str2[] = "ABCDEF";
    int ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strncmp");

    if (cosine == NULL)
        return;

    ret = (*cosine)(str1, str2, 3);

    dlclose(handle);

    cr_assert_eq(ret, 0);
}

Test(simpleStrncmp, strncmpNoPassed1)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*cosine)(const char *str1, const char *str2, size_t i);
    char str1[] = "abcdef";
    char str2[] = "ABCDEF";
    int ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strncmp");

    if (cosine == NULL)
        return;

    ret = (*cosine)(str1, str2, 3);

    dlclose(handle);

    cr_assert_gt(ret, 0);
}

Test(simpleStrncmp, strncmpNoPassed2)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*cosine)(const char *str1, const char *str2, size_t i);
    char str1[] = "ABCdef";
    char str2[] = "abcDEF";
    int ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strncmp");

    if (cosine == NULL)
        return;

    ret = (*cosine)(str1, str2, 3);

    dlclose(handle);

    cr_assert_lt(ret, 0);
}

Test(simpleStrncmp, strncmpNoPassed3)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*cosine)(const char *str1, const char *str2, size_t i);
    char str1[] = "";
    char str2[] = "ABCDEF";
    int ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strncmp");

    if (cosine == NULL)
        return;

    ret = (*cosine)(str1, str2, 3);

    dlclose(handle);

    cr_assert_lt(ret, 0);
}

Test(simpleStrncmp, strncmpNoPassed4)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*cosine)(const char *str1, const char *str2, size_t i);
    char str1[] = "abcdef";
    char str2[] = "";
    int ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strncmp");

    if (cosine == NULL)
        return;

    ret = (*cosine)(str1, str2, 3);

    dlclose(handle);

    cr_assert_gt(ret, 0);
}

Test(simpleStrncmp, strncmpNoPassed5)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*cosine)(const char *str1, const char *str2, size_t i);
    char str1[] = "";
    char str2[] = "";
    int ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strncmp");

    if (cosine == NULL)
        return;

    ret = (*cosine)(str1, str2, 3);

    dlclose(handle);

    cr_assert_eq(ret, 0);
}

Test(simpleStrncmp, strncmpNoPassed6)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*cosine)(const char *str1, const char *str2, size_t i);
    char str1[] = "ABCDEF";
    char str2[] = "ABCDEF";
    int ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strncmp");

    if (cosine == NULL)
        return;

    ret = (*cosine)(str1, str2, 20);

    dlclose(handle);

    cr_assert_eq(ret, 0);
}
