Select user_id,MAX(time_stamp) as last_stamp from Logins
where year(time_stamp) = '2020'
GROUP BY user_id;