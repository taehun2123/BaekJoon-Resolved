-- 코드를 입력하세요
SELECT BOOK.CATEGORY, SUM(BOOK_SALES.SALES) TOTAL_SALES
FROM BOOK JOIN BOOK_SALES
ON BOOK.BOOK_ID = BOOK_SALES.BOOK_ID
AND (YEAR(SALES_DATE) = "2022" AND MONTH(SALES_DATE) = "01")
GROUP BY BOOK.CATEGORY
ORDER BY 1;