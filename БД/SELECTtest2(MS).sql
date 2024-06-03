--Название и продолжительность самого длительного трека.
SELECT MAX(time) FROM trek;
--Название треков, продолжительность которых не менее 3,5 минут.
SELECT name FROM trek WHERE time >= '00:03:30.1';
--Названия сборников, вышедших в период с 2018 по 2020 годы включительно.
SELECT name FROM collection  WHERE year_realese BETWEEN '2018-01-01'  AND '2022-01-01';
--Исполнители, чьё имя состоит из одного слова.
SELECT name FROM author  WHERE name NOT LIKE '% %';
--Название треков, которые содержат слова «мой» или «my».
SELECT name FROM trek   WHERE name LIKE '%мой%' OR  name LIKE '%my%';