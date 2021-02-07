/*facts*/
parent(raghu,shreeram).
parent(rama,shreeram).
parent(raghu,gita).
parent(rama,gita).
parent(shreeram,rahul).
parent(gita,rajat).
parent(yamini,rahul).
parent(rahul,shurva).

/*rules*/
grandparent(X,Y):-parent(X,C),parent(C,Y).
sibling(X,Y):-parent(C,X),parent(C,Y).
children(X,Y):-parent(Y,X).

