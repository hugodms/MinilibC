/*
** EPITECH PROJECT, 2021
** test_memcpy.cB-CPP-300-BDX-3-1-CPPD01-hugo.domingues
** File description:
** drawing
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

Test(simpleStrcasecmp, strcasecmpPassed)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*cosine)(const char *str1, const char *str2);
    char str1[] = "abcdef";
    char str2[] = "ABCDEF";
    int ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strcasecmp");

    if (cosine == NULL)
        return;

    ret = (*cosine)(str1, str2);

    dlclose(handle);

    cr_assert_eq(ret, 0);
}

Test(simpleStrcasecmp, strcasecmpNoPassed1)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*cosine)(const char *str1, const char *str2);
    char str1[] = "abcd";
    char str2[] = "ABCDEF";
    int ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strcasecmp");

    if (cosine == NULL)
        return;

    ret = (*cosine)(str1, str2);

    dlclose(handle);

    cr_assert_lt(ret, 0);
}

Test(simpleStrcasecmp, strcasecmpNoPassed2)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*cosine)(const char *str1, const char *str2);
    char str1[] = "abcdef";
    char str2[] = "ABCD";
    int ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strcasecmp");

    if (cosine == NULL)
        return;

    ret = (*cosine)(str1, str2);

    dlclose(handle);

    cr_assert_gt(ret, 0);
}

Test(simpleStrcasecmp, strcasecmpNoPassed3)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*cosine)(const char *str1, const char *str2);
    char str1[] = "";
    char str2[] = "ABCD";
    int ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strcasecmp");

    if (cosine == NULL)
        return;

    ret = (*cosine)(str1, str2);

    dlclose(handle);

cr_assert_lt(ret, 0);
}

Test(simpleStrcasecmp, strcasecmpNoPassed4)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*cosine)(const char *str1, const char *str2);
    char str1[] = "abcd";
    char str2[] = "";
    int ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strcasecmp");

    if (cosine == NULL)
        return;

    ret = (*cosine)(str1, str2);

    dlclose(handle);

    cr_assert_gt(ret, 0);
}

Test(simpleStrcasecmp, strcasecmpNoPassed5)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    int (*cosine)(const char *str1, const char *str2);
    char str1[] = "";
    char str2[] = "";
    int ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strcasecmp");

    if (cosine == NULL)
        return;

    ret = (*cosine)(str1, str2);

    dlclose(handle);

    cr_assert_eq(ret, 0);
}
