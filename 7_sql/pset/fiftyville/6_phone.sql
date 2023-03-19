select id, caller, receiver, duration from phone_calls
    where year = 2020 and month = 7 and day = 28
    and duration < 60
    order by id;
