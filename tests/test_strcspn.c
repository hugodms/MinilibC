/*
** EPITECH PROJECT, 2021
** B-CPP-300-BDX-3-1-CPPD01-hugo.domingues
** File description:
** drawing
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

Test(simpleStrcspn, strcspnPassed)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    size_t (*cosine)(const char *s, const char *needle);
    const char haystack[] = "ABCDEF4960910";
    const char needle[] = "013";
    size_t ret;


    if (handle == NULL)
        return;


    *(void **) (&cosine) = dlsym(handle, "strcspn");

    if (cosine == NULL)
        return;

    ret = (*cosine)(haystack, needle);

    dlclose(handle);

    cr_assert_eq(ret, 9);
}

Test(simpleStrcspn, strcspnNoPassed1)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    size_t (*cosine)(const char *s, const char *needle);
    const char haystack[] = "ABCDEF4960910";
    const char needle[] = "z";
    size_t ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strcspn");

    if (cosine == NULL)
        return;

    ret = (*cosine)(haystack, needle);

    dlclose(handle);

    cr_assert_eq(ret, 13);
}

Test(simpleStrcspn, strcspnNoPassed2)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    size_t (*cosine)(const char *s, const char *needle);
    const char haystack[] = "ABCDEF4960910";
    const char needle[] = "";
    size_t ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strcspn");

    if (cosine == NULL)
        return;

    ret = (*cosine)(haystack, needle);

    dlclose(handle);

    cr_assert_eq(ret, 13);
}

Test(simpleStrcspn, strcspnNoPassed3)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    size_t (*cosine)(const char *s, const char *needle);
    const char haystack[] = "";
    const char needle[] = "z";
    size_t ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strcspn");

    if (cosine == NULL)
        return;

    ret = (*cosine)(haystack, needle);

    dlclose(handle);

    cr_assert_eq(ret, 0);
}

Test(simpleStrcspn, strcspnNoPassed4)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    size_t (*cosine)(const char *s, const char *needle);
    const char haystack[] = "";
    const char needle[] = "";
    size_t ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strcspn");

    if (cosine == NULL)
        return;

    ret = (*cosine)(haystack, needle);

    dlclose(handle);

    cr_assert_eq(ret, 0);
}
