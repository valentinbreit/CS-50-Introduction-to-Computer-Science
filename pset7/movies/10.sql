SELECT DISTINCT(name) FROM people JOIN directors JOIN movies JOIN ratings ON ((people.id = directors.person_id) AND (directors.movie_id = movies.id) AND (movies.id = ratings.movie_id) AND (ratings.rating >= 9.0)) ORDER BY name;