-- Keep a log of any SQL queries you execute as you solve the mystery.

-- 2020/07/28にChamberlin Streetで起きた事件を調べる
select id, description from crime_scene_reports
    where year = 2020 and month = 7 and day = 28
    and street = 'Chamberlin Street';

-- 事件概要
---- 2020/07/28 AM10:15、Chamberlin Streetの裁判所でCS50 duckが

-- 2020/07/28に行われた証言のうち、裁判所(courthouse)に言及したものを調べる
select id,name,transcript from interviews
    where year = 2020 and month = 7 and day = 28
    and transcript like '%courthouse%';

-- 証言から得られた情報
-- 1
---- 泥棒は事件から10分以内に裁判所の駐車場から出ていった
-- 2
---- 事件当日、Eugeneが裁判所に着く前、Fifer StreetのATMで泥棒が現金を引き出しているところを見た

-- 泥棒を探す
-- ヒント1 監視カメラから分かったナンバープレート
-- ヒント2 事件翌日にヒースローへ移動した乗客のパスポート番号
-- ヒント3 逃走直前にかけていた電話の記録
select * from people
    where license_plate in
        (select license_plate from courthouse_security_logs
            where year = 2020 and month = 7 and day = 28 and hour = 10
            and minute between 10 and 25
            and activity = 'exit'
        )
    and passport_number in
        (select passport_number from passengers where flight_id = 36)
    and phone_number in
        (select caller from phone_calls
            where year = 2020 and month = 7 and day = 28
            and duration < 60
        )
;

select * from people
    where phone_number in ('(996) 555-8899','(892) 555-8872','(375) 555-8161');