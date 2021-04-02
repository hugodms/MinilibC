/*
** EPITECH PROJECT, 2021
** B-CPP-300-BDX-3-1-CPPD01-hugo.domingues
** File description:
** drawing
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

Test(simpleStrpbrk, strpbrkPassed)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*cosine)(const char *s, const char *needle);
    const char haystack[20] = "TutorialsPoint";
    const char needle[10] = "Ps";
    char *ret;


    if (handle == NULL)
        return;


    *(void **) (&cosine) = dlsym(handle, "strpbrk");

    if (cosine == NULL)
        return;

    ret = (*cosine)(haystack, needle);

    dlclose(handle);

    cr_assert_str_eq(ret, "sPoint");
}

Test(simpleStrpbrk, strpbrkNoPassed1)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*cosine)(const char *s, const char *needle);
    const char haystack[] = "TutorialsPoint";
    const char needle[] = "z";
    char *ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strpbrk");

    if (cosine == NULL)
        return;

    ret = (*cosine)(haystack, needle);

    dlclose(handle);

    cr_assert_eq(ret, NULL);
}

Test(simpleStrpbrk, strpbrkNoPassed2)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*cosine)(const char *s, const char *needle);
    const char haystack[] = "TutorialsPoint";
    const char needle[] = "";
    char *ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strpbrk");

    if (cosine == NULL)
        return;

    ret = (*cosine)(haystack, needle);

    dlclose(handle);

    cr_assert_eq(ret, NULL);
}

Test(simpleStrpbrk, strpbrkNoPassed3)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*cosine)(const char *s, const char *needle);
    const char haystack[] = "";
    const char needle[] = "z";
    char *ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strpbrk");

    if (cosine == NULL)
        return;

    ret = (*cosine)(haystack, needle);

    dlclose(handle);

    cr_assert_eq(ret, NULL);
}

Test(simpleStrpbrk, strpbrkNoPassed4)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*cosine)(const char *s, const char *needle);
    const char haystack[] = "";
    const char needle[] = "";
    char *ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "strpbrk");

    if (cosine == NULL)
        return;

    ret = (*cosine)(haystack, needle);

    dlclose(handle);

    cr_assert_eq(ret, NULL);
}
