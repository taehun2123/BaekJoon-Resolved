-- 코드를 입력하세요
SELECT b.AUTHOR_ID, a.AUTHOR_NAME, b.CATEGORY, SUM(s.SALES * b.PRICE) TOTAL_SALES
FROM BOOK b JOIN AUTHOR a
ON b.AUTHOR_ID = a.AUTHOR_ID
JOIN BOOK_SALES s
ON s.BOOK_ID = b.BOOK_ID
WHERE s.SALES_DATE LIKE '%2022-01%'
GROUP BY 1,2,3
ORDER BY 1,3 DESC;