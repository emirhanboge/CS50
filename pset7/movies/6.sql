SELECT id, year FROM movies WHERE year = 2012
SELECT AVG(rating) as Avr FROM ratings WHERE ratings.movie_id = movies.id;