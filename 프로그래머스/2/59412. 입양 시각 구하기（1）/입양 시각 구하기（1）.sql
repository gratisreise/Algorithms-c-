-- 코드를 입력하세요
SELECT SUBSTR(DATETIME,12, 2) as HOUR, COUNT(*) as COUNT
FROM ANIMAL_OUTS
GROUP BY HOUR
HAVING HOUR BETWEEN '09' AND '19'
ORDER BY HOUR