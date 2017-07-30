# Singleton
**NOTE:** No longer thought as good design pattern. 

A component which is instantiated only once. 
## why use a Sigleton

 - If a component is only meant to be used once (e.g. Database repository, Object factory).
 
## Problems with Sigleton

- Constructor calls are expensive
 
	- should only be called once and provide send everything in the same instance
- Hard to use lazy instantiation and multithreading - when do you instantiate?
	

 