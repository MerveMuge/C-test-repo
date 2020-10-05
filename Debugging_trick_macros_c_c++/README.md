# Debugging Trick Using Variadic Macros in C and C++

Following you can find a very practical trick that allows you to enable/disable all prints to the screen with as little effort as possible while not dramatically increasing the overall code size to do this.

## Usage for C

Place on the top of your code or on a header file the following

```C
#define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
    #define XDEBUG(...) printf(__VA_ARGS__)
#else
    #define XDEBUG(...)  /**/
#endif
```
and then inside the code whenever you want to print some debug information do as follows:


```C
XDEBUG("Max Weight %d, Total Trips %d\n", minMax, trips);
```


## Usage for C++

Place on the top of your code or on a header file the following:

```C++
#define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
    #define XDEBUG cout
#else
    #define XDEBUG if(0) cerr
#endif
```
and then inside the code whenever you want to print some debug information do as follows:


```C++
XDEBUG << "We got " << disks << " disks\n";
```

## Source
[bytefreaks.net](https://bytefreaks.net/programming-2/debugging-trick-using-variadic-macros-in-c-and-c)
