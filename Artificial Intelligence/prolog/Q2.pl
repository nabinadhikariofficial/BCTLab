/*facts*/
women(jia).
man(john).
healthy(john).
healthy(jia).
wealthy(john).

/*rules*/
traveller(X):-healthy(X),wealthy(X).
travel(X):-traveller(X).

