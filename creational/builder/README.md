# Builder

when piecewise object constrution if complicated, provide an API for doing it succinctly

## Builder Examples

- Building Strings using their substrings
    - E.g., web server page rendering.
- Concatenate a single `std::string`
    ```C++
    my_text += boost::lexical_cast<string>(my_int);
    ```
- `printf("%s = %n", "meaning of life", 42);`
- Represent as OO structure and implement operator << on the object graph
