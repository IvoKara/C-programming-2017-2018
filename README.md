# C-programming-2017-2018
<h3>Commands not to forget:</h3>
<ul>
   <li>
       Compile
       
    gcc -Wall -pedantic -std=c11 <C files> 
   </li>
   <li>
       Rename executable file
    
    gccl -o <new name> <C files>
   </li>
   <li>
       Compile to object file
    
    gccl -c <C files>
   </li>
   <li>
       See optut of the program
    
    ./<exec file> <arguments if any>
   </li>
</ul>   

<h3>Makefiles</h3>
<p>Structure</p>
   
      <target>: <dependancy list>
      TAB <commands>
<ul>
   <li>
      Constants
      
      GCCL=gcc -Wall -pedantic -std=c11
      #some code here
      $(GCCL) file.c
   </li>
</ul>
