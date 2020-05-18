% UFO's
object(balloon).
object(clothesline).
object(frisbee).
object(water_tower).

% Days
day(2).		% Tuesday
day(3).		% Wednesday
day(4).		% Thursday
day(5).		% Friday

solve :-
    object(BarradaObject), object(GortObject), object(KlatuObject), object(NiktoObject),
    all_different([BarradaObject, GortObject, KlatuObject, NiktoObject]),
    
    day(BarradaDay), day(GortDay), day(KlatuDay), day(NiktoDay),
    all_different([BarradaDay, GortDay, KlatuDay, NiktoDay]),
    
    Triples = [ [barrada, BarradaObject, BarradaDay],
                [gort, GortObject, GortDay],
                [klatu, KlatuObject, KlatuDay],
                [nikto, NiktoObject, NiktoDay] ],
    
    % 1. Mr. Klatu made his sighting at some point earlier in the week than the one who saw the balloon,
    %	 but at some point later in the week than the one who spotted the Frisbee (who isn't Ms. Gort).
    \+ member([klatu, balloon, _], Triples),
    \+ member([klatu, frisbee, _], Triples),
    \+ member([gort, frisbee, _], Triples),
    which_day([_, balloon, BalloonDay], Triples),
    which_day([_, frisbee, FrisbeeDay], Triples),
    earlier(KlatuDay, BalloonDay),
    earlier(FrisbeeDay, KlatuDay),
    
    % 2. Friday's sighting was made by either Ms. Barrada or the one who saw a clothesline (or both).
    (member([barrada, _, 5], Triples) ; member([_, clothesline, 5], Triples)),
    
    % 3. Mr. Nikto did not make his sighting on Tuesday.
    \+ member([nikto, _, 2], Triples),
    
    % 4. Mr. Klatu isn't the one whose object turned out to be a water tower.
	\+ member([klatu, water_tower, _], Triples),
    
    tell(barrada, BarradaObject, BarradaDay),
    tell(gort, GortObject, GortDay),
    tell(klatu, KlatuObject, KlatuDay),
    tell(nikto, NiktoObject, NiktoDay).

% Succeed if all elements of the argument list are bound and different.
% Fail if any elements are unbound or equal to some other element.
all_different([H | T]) :- member(H, T), !, fail.        % (1)
all_different([_ | T]) :- all_different(T).             % (2)
all_different([_]).                                     % (3)

% Tell which day is the object X sighted
which_day(X, [_ | T]) :- which_day(X, T).
which_day(X, [X | _]).

% Tell whethor or not X happened before Y.
earlier(X, Y) :- X < Y.

% Write out an English sentence with the solution.
tell(X, Y, Z) :-
    ((X = barrada ; X = gort) -> write('Ms. ') ; (X = klatu ; X = nikto) -> write('Mr. ')),
    write(X), write(' saw a '), write(Y), write(' on '),
    (	Z = 2 -> write('Tuesday');
    	Z = 3 -> write('Wednesday');
    	Z = 4 -> write('Thursday');
    	Z = 5 -> write('Friday')	),
    write('.'), nl.


