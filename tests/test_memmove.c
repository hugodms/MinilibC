/*
** EPITECH PROJECT, 2021
** test_memcpy.cB-CPP-300-BDX-3-1-CPPD01-hugo.domingues
** File description:
** drawing
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

extern void *memmove(void *dest, const void * src, size_t n);

Test(simpleMemmove, memmovePassed)
{
    const char src[] = "http://www.tutorialspoint.com";
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    void *(*cosine)(void *dest, const void * src, size_t n);
    char dest[] = "Heloooo!!";

    if (handle == NULL)
        return;

    *(void **) (&cosine) = dlsym(handle, "memmove");

    if (cosine == NULL)
        return;

    (*cosine)(dest, src, strlen(src)+1);

    dlclose(handle);

    cr_assert_str_eq(dest, "http://www.tutorialspoint.com");
}

