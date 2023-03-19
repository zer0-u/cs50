-- fiftyvilleにある空港の情報を調べる
-- select * from airports where city = 'Fiftyville';

-- 2020/07/29にfiftyvilleを出る便を調べる
-- select id, hour,minute,destination_airport_id from flights
--     where year = 2020 and month = 7 and day = 29
--     and origin_airport_id = (select id from airports where city = 'Fiftyville')
--     order by hour,minute;

-- destination_airport_idから行き先の空港を調べる
select f.id, f.hour,f.minute,a.full_name,a.city
    from flights f
    inner join airports a on f.destination_airport_id = a.id
    where f.year = 2020 and f.month = 7 and f.day = 29
    and f.origin_airport_id = (select id from airports where city = 'Fiftyville')
    order by f.hour,f.minute;