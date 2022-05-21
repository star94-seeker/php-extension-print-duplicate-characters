PHP extensions
--------------
PHP extensions are compiled libraries which enable specific functions to be used in your PHP code. It is much easier to implement PHP extensions on Linux than on Windows.

Building Your First Extensions
-------------------------------
1. To build a PHP extension, you must use the corresponding version of the source code.
 Example :-

    $ php –v    
      PHP 7.4.3 (cli) (built: Mar  2 2022 15:36:52) ( NTS )
     Copyright (c) The PHP Group
     Zend Engine v3.4.0, Copyright (c) Zend Technologies
       with Zend OPcache v7.4.3, Copyright (c), by Zend Technologies

2. Then download the PHP source code (here my version is PHP 7.4.3)

3. Unzip the code and switch to the ext directory:

	$ cd ~/Downloads/php-7.4.3/ext

4. Create an extension  hello


	 $ php php-src/ext/ext_skel.php --ext hello
     
      This will create a directory “hello” with extension skeleton files. Let’s look inside:

      4.1   $  cd hello
	   $  ls
	   config.m4	  config.w32   php_hello.h   hello.c   tests
	
	In the above code snippet:
	• config.m4 is an extension configuration script used by “phpize” or “buildconf” to 
   	add extension configuration options into the “configure” command.
	
	• config.w32 is a similar configuration file for the Windows builds system.
	
	• php_test.h is a C header file that contains our common extension definitions. 
	
  	 It’s not necessary for simple extensions with a single source C file, but it’s 
   	useful in case the implementation is spread among a few files.
	
	• test.c is the main extension implementation source. It defines all the structures 
   	that allow to plug the extension into PHP and make all their internal functions, 
   	classes and constants to be available.
	
	• tests refers to the directory with PHP tests. 
	
	 This extension skeleton can be compiled without any changes

5. Building and Installing a PHP Extension
	
	$  phpize
$  ./configure
$  make
$  sudo make install

6. Add the  path after installation ( /usr/lib/php7/20121212/hello.so ) to the php.ini file:
	
         $ locate php.ini


   Modify the php.ini file and add the following code:

        extension=hello.so


7. Check that extension is loaded and works. “php -m” command prints the list of loaded 
    extensions:
   
    $ php -m | grep hello
       hello

8. We may also run the functions defined in our “test” extension:

	$ php -r ‘hello_test1();’
    The extension test is loaded and working!
$ php -r ‘echo hello_test2(“world\n”);’
Hello world







