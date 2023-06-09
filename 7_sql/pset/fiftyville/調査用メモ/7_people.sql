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

