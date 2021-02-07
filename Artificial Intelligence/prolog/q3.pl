/*facts*/
vegetarian(jose).
vegetarian(james).
vegetable(carrot).
vegetable(egg_plant).

/*rules*/
likes(jose, X) :- vegetable(X).
loves(Who, egg_plant) :- vegetarian(Who).


