/*
** EPITECH PROJECT, 2021
** B-CPP-300-BDX-3-1-CPPD01-hugo.domingues
** File description:
** drawing
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

Test(simpleRindex, rindexPassed)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*cosine)(const char *s, int c);
    char str[] = "hello";
    char *ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "rindex");

    if (cosine == NULL)
        return;

    ret = (*cosine)(str, 'l');

    dlclose(handle);

    cr_assert_str_eq(ret, "lo");
}

Test(simpleRindex, rindexNoPassed1)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*cosine)(const char *s, int c);
    char str[] = "hello";
    char *ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "rindex");

    if (cosine == NULL)
        return;

    ret = (*cosine)(str, 'g');

    dlclose(handle);

    cr_assert_eq(ret, NULL);
}

Test(simpleRindex, rindexNoPassed2)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    char *(*cosine)(const char *s, int c);
    char str[] = "";
    char *ret;

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "rindex");

    if (cosine == NULL)
        return;

    ret = (*cosine)(str, 'g');

    dlclose(handle);

    cr_assert_eq(ret, NULL);
}
