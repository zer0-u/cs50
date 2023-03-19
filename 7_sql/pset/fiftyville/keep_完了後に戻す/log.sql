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
---- 情報C. (Raymond) 泥棒は裁判所から出る時誰かに短い(1分以内)の電話をかけた
---- 情報D. (Raymond) 泥棒は協力者に「明日(7/29)一番早くFiftyvilleを出る飛行機」のチケットを買うよう指示した

-- 調査3. 情報Aにもとづき、事件発生から10分以内に駐車場を出た車のナンバーを調べる
---- 事件発生から10分以内 = 2020/07/28 午前10時15～25分
select id, hour,minute, license_plate from courthouse_security_logs
    where year = 2020 and month = 7 and day = 28 and hour = 10
    and minute between 15 and 25
    and activity = 'exit'
    order by minute;