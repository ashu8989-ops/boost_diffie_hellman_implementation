# Diffie Hellman Implementation 

An implementation of Diffie Hellman Key Exchange algorithm using boost C++ library 

# Design Choices Outlined 

We make use of the boost c++ library to implement Diffie Hellman and generate a Shared 'Secret' Key. This allows us to make use of the multiprecision library functions. 

# Parameter Generation 

Group generation is hard to get right and can easily lead to much more disastrous vulnerabilities. We make use of the 1536-bit MODP group Outlined here https://www.ietf.org/rfc/rfc3526.txt. 

# The project already contains pre-compiled boost libraries for ease of compilation. This comes with the added cost of increase in the project size. In future iterations this shall be taken care of.  
(Most Boost libraries are header-only: they consist entirely of header files containing templates and inline functions, and require no separately-compiled library binaries or special treatment when linking.)

