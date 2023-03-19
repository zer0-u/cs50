-- Keep a log of any SQL queries you execute as you solve the mystery.
-- 2020/07/28にChamberlin Streetで起きた事件を調べる
SELECT id, description FROM crime_scene_reports
    WHERE year = 2020 AND month = 7 AND day = 28
        AND street = 'Chamberlin Street';

