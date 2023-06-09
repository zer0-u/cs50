-- Keep a log of any SQL queries you execute as you solve the mystery.

-- 調査1. 2020/07/28にChamberlin Streetで起きた事件を調べる
select id, description from crime_scene_reports
    where year = 2020 and month = 7 and day = 28
    and street = 'Chamberlin Street';

-- 事件概要
---- 2020/07/28 AM10:15、Chamberlin Streetの裁判所でCS50 duckが盗まれた
---- 事件当日に3人の目撃者に対してインタビューが行われた
---- 3人の目撃者はそれぞれインタビューの中で裁判所(courthouse)について言及した

-- 調査2. 2020/07/28に行われた証言のうち、裁判所(courthouse)に言及したものを調べる
select id,name,transcript from interviews
    where year = 2020 and month = 7 and day = 28
    and transcript like '%courthouse%';

-- 証言から得られた情報
---- 情報A. (Ruth) 泥棒は事件から10分以内に裁判所の駐車場から出ていった
---- 情報B. (Eugene) 事件当日、泥棒はFifer StreetのATMで現金を引き出した
---- 情報C. (Raymond) 泥棒は裁判所から出る時、協力者に短い(1分以内)の電話をかけた
---- 情報D. (Raymond) 泥棒は協力者に「明日(7/29)一番早くFiftyvilleを出る飛行機」のチケットを買うよう指示した

-- 調査3-1. 情報Aを使って、事件発生から10分以内に駐車場を出た車のナンバーを調べる
---- 事件発生から10分以内 = 2020/07/28 午前10時15～25分
select id, hour, minute, license_plate from courthouse_security_logs
    where year = 2020 and month = 7 and day = 28
    and hour = 10
    and minute between 15 and 25
    and activity = 'exit'
    order by minute;

-- 調査3-2. 調査3-1の結果を使って、車の持ち主を調べる
select * from people
    where license_plate in
        (select license_plate from courthouse_security_logs
            where year = 2020 and month = 7 and day = 28
            and hour = 10
            and minute between 15 and 25
            and activity = 'exit'
        )
;

-- 調査4-1. 情報Bを使って、2020/07/28にFifer StreetのATMで現金を引き出した人を調べる
select id, account_number, amount from atm_transactions
    where year = 2020 and month = 7 and day = 28
    and atm_location = 'Fifer Street'
    and transaction_type = 'withdraw'
    order by id;

-- 調査4-2. 調査4-1の結果を使って、口座の持ち主を調べる
select * from people
    where id in
    (select person_id from bank_accounts
        where account_number in
            (select account_number from atm_transactions
                where year = 2020 and month = 7 and day = 28
                and atm_location = 'Fifer Street'
                and transaction_type = 'withdraw'
            )
    )
;

-- 調査5-1. 情報Cを使って、2020/07/28に1分以内の通話を行った情報を調べる
select id, caller, receiver, duration from phone_calls
    where year = 2020 and month = 7 and day = 28
    and duration < 60
    order by id;

-- 調査5-2. 調査5-1を使って、通話を「かけた」人(caller)の情報を調べる
select * from people
    where phone_number in
    (select caller from phone_calls
        where year = 2020 and month = 7 and day = 28
        and duration < 60
    )
;

-- 調査5-3. 調査5-1を使って、通話を「受けた」人(receiver)の情報を調べる
select * from people
    where phone_number in
    (select receiver from phone_calls
        where year = 2020 and month = 7 and day = 28
        and duration < 60
    )
;

-- 調査6. 情報Dを使って、2020/07/29に一番早くFiftyvilleを出る便を調べる
select f.id, f.hour,f.minute,a.full_name,a.city from flights f
    inner join airports a on f.destination_airport_id = a.id
    where f.year = 2020 and f.month = 7 and f.day = 29
    and f.origin_airport_id = (select id from airports where city = 'Fiftyville')
    order by f.hour,f.minute;

---- 情報E. 事件翌日(2020/07/29)に一番早くFiftyvilleを出る便は8時20分発ヒースロー(ロンドン)行き

-- 調査7-1. 情報Eの便の乗客を調べる
select passport_number, seat from passengers where flight_id = 36;

-- 調査7-2. 調査7-1を使って、情報Eの便に乗る客の名前を調べる
select * from people
    where passport_number in
    (select passport_number from passengers where flight_id = 36);

-- 調査8. 調査3-2, 4-2, 5-2, 7-2の積集合を取る
select * from people
    where license_plate in
        (select license_plate from courthouse_security_logs
            where year = 2020 and month = 7 and day = 28
            and hour = 10
            and minute between 15 and 25
            and activity = 'exit'
        )
    and id in
    (select person_id from bank_accounts
        where account_number in
            (select account_number from atm_transactions
                where year = 2020 and month = 7 and day = 28
                and atm_location = 'Fifer Street'
                and transaction_type = 'withdraw'
            )
    )
    and phone_number in
    (select caller from phone_calls
        where year = 2020 and month = 7 and day = 28
        and duration < 60
    )
    and passport_number in
    (select passport_number from passengers where flight_id = 36)
;

-- 情報F. CS50 duckを盗んだのはErnest

-- 調査9. 情報Fと調査5-3を使って、Ernestが電話をかけた相手＝協力者を調べる
select * from people
    where phone_number in
    (select receiver from phone_calls
        where year = 2020 and month = 7 and day = 28
        and duration < 60
        and caller = '(367) 555-5533'
    )
;

-- 情報G. 協力者はBerthold