/*
** EPITECH PROJECT, 2021
** B-CPP-300-BDX-3-1-CPPD01-hugo.domingues
** File description:
** drawing
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

Test(simpleStrstr, strstrPassed1)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*cosine)(const char *s, const char *needle);
    const char haystack[20] = "TutorialsPoint";
    const char needle[10] = "Point";
    char *ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strstr");

    if (cosine == NULL)
        return;

    ret = (*cosine)(haystack, needle);

    dlclose(handle);

    cr_assert_str_eq(ret, "Point");
}

Test(simpleStrstr, strstrPassed2)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*cosine)(const char *s, const char *needle);
    const char haystack[20] = "TutorialsPoint";
    const char needle[10] = "ts";
    char *ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strstr");

    if (cosine == NULL)
        return;

    ret = (*cosine)(haystack, needle);

    dlclose(handle);

    cr_assert_eq(ret, NULL);
}

Test(simpleStrstr, strstrPassed3)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*cosine)(const char *s, const char *needle);
    const char haystack[20] = "TutorialsPoint";
    const char needle[10] = "tor";
    char *ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strstr");

    if (cosine == NULL)
        return;

    ret = (*cosine)(haystack, needle);

    dlclose(handle);

    cr_assert_str_eq(ret, "torialsPoint");
}

Test(simpleStrstr, strstrNoPassed1)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*cosine)(const char *s, const char *needle);
    const char haystack[] = "TutorialsPoint";
    const char needle[] = "z";
    char *ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strstr");

    if (cosine == NULL)
        return;

    ret = (*cosine)(haystack, needle);

    dlclose(handle);

    cr_assert_eq(ret, NULL);
}

Test(simpleStrstr, strstrNoPassed2)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*cosine)(const char *s, const char *needle);
    const char haystack[] = "TutorialsPoint";
    const char needle[] = "";
    char *ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strstr");

    if (cosine == NULL)
        return;

    ret = (*cosine)(haystack, needle);

    dlclose(handle);

    cr_assert_str_eq(ret, "TutorialsPoint");
}

Test(simpleStrstr, strstrNoPassed3)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*cosine)(const char *s, const char *needle);
    const char haystack[] = "";
    const char needle[] = "P";
    char *ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strstr");

    if (cosine == NULL)
        return;

    ret = (*cosine)(haystack, needle);

    dlclose(handle);

    cr_assert_eq(ret, NULL);
}
