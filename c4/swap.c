/*
Exercise 4-14. 
Define a macro swap(t,x,y) that interchanges two arguments of type t.
(Block structure will help).
*/

#define swap(t,x,y) { t temp; temp = x, x = y, y = temp; }