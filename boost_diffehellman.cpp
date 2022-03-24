// boost_diffehellman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/algorithm/hex.hpp>
#include<vector>
#include<boost/lexical_cast.hpp>
#include<boost/lexical_cast/bad_lexical_cast.hpp>
#include <ctime>            // std::time
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/linear_congruential.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/generator_iterator.hpp>
#include<boost/random.hpp>
#include <intrin.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/random.hpp>
#include <iostream>
#include <iomanip>
#include <boost/chrono/chrono.hpp>
#include<sstream>
#include<string>
#include <sstream>
#include <bitset>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm> 
#include <cctype>
#include <locale>
#include <boost/algorithm/string.hpp>
#include<boost/algorithm/cxx14/equal.hpp>


using namespace boost::multiprecision;
using namespace std;
using namespace boost::algorithm;
using namespace boost::random;
using boost::lexical_cast;
using boost::bad_lexical_cast;

#define p_1536bit = "0xFFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE45B3DC2007CB8A163BF0598DA48361C55D39A69163FA8FD24CF5F83655D23DCA3AD961C62F356208552BB9ED529077096966D670C354E4ABC9804F1746C08CA237327FFFFFFFFFFFFFFFF"
//Recommended diffie-Hellman parameter taken from https://www.ietf.org/rfc/rfc3526.txt



int main()
{
  
 

    cpp_int prime("0xFFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD129024E088A67CC74020BBEA63B139B22514A08798E3404DDEF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7EDEE386BFB5A899FA5AE9F24117C4B1FE649286651ECE45B3DC2007CB8A163BF0598DA48361C55D39A69163FA8FD24CF5F83655D23DCA3AD961C62F356208552BB9ED529077096966D670C354E4ABC9804F1746C08CA237327FFFFFFFFFFFFFFFF");
    //initialising our very large 1536 bit prime number 
    
    cout <<"The 1536 bit prime number \n" << prime <<endl;

    cpp_int g = 2;
    //Recommended generator 


    cout << "The generator chosen is \n" << g << endl;

    
   

    constexpr int bit_limit = 256;
    independent_bits_engine<mt19937, bit_limit, cpp_int> generator;

    //Generating integers for Private Key
    // Generate integers in a given range using cpp_int,
    // the underlying generator is invoked multiple times
    // to generate enough bits:
    //
    mt19937 mt;
    mt.seed(boost::chrono::system_clock::to_time_t(boost::chrono::system_clock::now()));
    uniform_int_distribution<cpp_int> ui(0, cpp_int(1) << 64); //ui is Alice's private key
    uniform_int_distribution<cpp_int> vi(0, cpp_int(1) << 64); //vi is Bob's private key 




    //We set the hard limit at 64 since 256bit integer private key =64 bit hexadecimal
    



    //Generating Alice's Private key
    std::cout << std::hex << std::showbase;
    std::stringstream buffer_Alice;

    for (unsigned i = 0; i < 10; ++i)
    {
        buffer_Alice << ui(mt);
    }
    
    
    std::cout << "Alice's private Key" << std::endl; 
    cout << buffer_Alice.str() << endl;              //We obviously shouldn't be outputting the private keys into the input/output stream
                                                     //But Since this programme is for demonstration purposes and not a real world implementation 
                                                     //We do so to make the demonstration easier 
   //Generating Bob's Private Key 
    
        std::cout << std::hex << std::showbase;   
    std::stringstream buffer_Bob;
    for (unsigned i = 0; i < 10; ++i)
    {
        buffer_Bob << vi(mt);
    }


    std::cout << "Bob's private Key" << std::endl;
    cout << buffer_Bob.str() << std::endl;

    

    std::string bob_privatekey_string = buffer_Bob.str(); //storing bob's private key as a string. Never do this in a Real world Scenario. Use hash functions
    std::string alice_privatekey_string = buffer_Alice.str(); // storing Alice's private key as a string ...
    std::cout << bob_privatekey_string << endl;


    cpp_int bob_privatekey_integer(bob_privatekey_string);
    cpp_int alice_privatekey_integer(alice_privatekey_string);


    

    int l = bob_privatekey_string.length(); //lengthofprivatekey
     cout <<std::dec << l << endl;

     int bob_privatekey_array[256];
     for (int q = 0; q < l, q++;)
     {
         bob_privatekey_array[q] = bob_privatekey_string[q];
     }

     
   
    cpp_int alice_publickey = boost::multiprecision::powm(g, alice_privatekey_integer, prime);
    cpp_int bob_publickey = boost::multiprecision::powm(g, bob_privatekey_integer, prime);

    cout << "The Public Key generated for Alice" << endl << alice_publickey << endl;
    cout << "The Public Key generated for Bob" << endl << bob_publickey << endl;
    
    cpp_int alice_diffie_hellman_key = powm(bob_publickey, alice_privatekey_integer, prime);

    cout << "The diffie hellman key generated for Alice" << endl << alice_diffie_hellman_key << endl;

    cpp_int bob_diffie_hellman_key = powm(alice_publickey, bob_privatekey_integer, prime);

    cout << "The diffie hellman key generated for Alice" << endl << bob_diffie_hellman_key << endl;
    
   
    cout << "The Shared Secret Generation is successfull";

     
      
     

     
     

  
     
    return 0;
}
