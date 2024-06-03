--Количество исполнителей в каждом жанре.
SELECT COUNT(author_id) FROM genre_author;

--Количество треков, вошедших в альбомы 2019–2020 годов.
SELECT COUNT(id_trek) FROM album a 
LEFT JOIN  trek t   ON a.id_album  = t.id_trek
LEFT JOIN  collection_trek ct  ON t.id_trek  = ct.trek_id
LEFT JOIN collection c ON ct.collection_id  = c.id_collection
WHERE year_realese BETWEEN '2019-01-01'  AND '2020-01-01';

--Средняя продолжительность треков по каждому альбому.
SELECT AVG(time) FROM trek t  
LEFT JOIN  album a   ON a.id_album  = t.id_trek;

--Все исполнители, которые не выпустили альбомы в 2020 году.
SELECT id_author, a."name"  FROM author a
LEFT JOIN  author_album aa  ON a.id_author  = aa.author_id 
LEFT JOIN  album a2  ON aa.album_id  = a2.id_album 
LEFT JOIN  trek t   ON a2.id_album  = t.id_trek
LEFT JOIN  collection_trek ct  ON t.id_trek  = ct.trek_id
LEFT JOIN collection c ON ct.collection_id  = c.id_collection
WHERE year_realese != '2020-01-01'
GROUP BY id_author, a."name";

