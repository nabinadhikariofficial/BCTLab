/*facts*/
food(burger).
food(sandwich).
food(pizza).
lunch(sandwich).
dinner(pizza).

/*rules*/
meal(X):-food(X).

