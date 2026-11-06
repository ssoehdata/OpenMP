## General form of directives in Fortran C/C++
********************************************************

### Fortran directive format and example  with a structured block  
	
	!$omp parallel [clause[[,] clause]...]
	
	!$omp parallel private(x)
	
			... code executed by each thread
			
	!$omp end parallel
    
    
### C/C++ directive format and example with a structured block

	#pragma omp parallel [clause[[,] clause] ...]
	
	
	#pragma omp parallel private(x)
	{
	
		... code executed by each thread
		
	}
	
	
	
	## Terms:	
	
	
	
	<ul>
		<li>compiler directive</>
			
			-  aka as "directives" are semantically neutral compiler instructions 
			   informing OpenMP enabled compilers to run in parallel 
			   (e.g. !$omp parallel etc.).
			   They defines transformations made by the OpenMP compiler.
			   
			   e.g. 
			   
					int omp_get_num_threads() 
				
	
		<li>structured block</li>
		
			- code executed from top and exited from the bottom
				(i.e., not from middle of block, jump out from middle etc.).
	
	
		<li>construct</li> 
			
			- a directive and its structured block that are to be executed by OpenMP.
			
			
			
		<li>region</li>
		
			- all the code executed by a thread associated with a construct
			  and represents the "dynamic extent" of a construct.
	
	
	</ul>
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	