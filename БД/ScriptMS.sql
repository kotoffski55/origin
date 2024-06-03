CREATE TABLE IF NOT EXISTS genre(
id_genre SERIAL PRIMARY KEY,
name VARCHAR(60) NOT NULL
);

CREATE TABLE IF NOT EXISTS author(
id_author SERIAL PRIMARY KEY,
name VARCHAR(60) NOT NULL
);

CREATE TABLE IF NOT EXISTS trek(
id_trek SERIAL PRIMARY KEY,
name VARCHAR(60) NOT NULL,
time TIME
);

CREATE TABLE IF NOT EXISTS album(
id_album INTEGER PRIMARY KEY REFERENCES trek(id_trek),
name VARCHAR(60) NOT NULL
);

CREATE TABLE IF NOT EXISTS collection(
id_collection SERIAL PRIMARY KEY,
name VARCHAR(60) NOT NULL,
year_realese DATE NOT NULL
);

CREATE TABLE IF NOT EXISTS genre_author (
	genre_id INTEGER REFERENCES genre(id_genre),
	author_id INTEGER REFERENCES author(id_author),
	CONSTRAINT GA PRIMARY KEY (genre_id, author_id)
);

CREATE TABLE IF NOT EXISTS author_album (
	album_id INTEGER REFERENCES album(id_album),
	author_id INTEGER REFERENCES author(id_author),
	CONSTRAINT AA PRIMARY KEY (album_id, author_id)
);

CREATE TABLE IF NOT EXISTS collection_trek (
	collection_id INTEGER REFERENCES collection(id_collection),
	trek_id INTEGER REFERENCES trek(id_trek),
	CONSTRAINT CT PRIMARY KEY (collection_id, trek_id)
	);
