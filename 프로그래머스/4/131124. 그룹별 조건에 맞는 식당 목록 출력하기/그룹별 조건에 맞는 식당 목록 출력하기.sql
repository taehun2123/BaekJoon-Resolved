-- 코드를 입력하세요
SELECT p.MEMBER_NAME, r.REVIEW_TEXT, DATE_FORMAT(r.REVIEW_DATE, '%Y-%m-%d')
FROM MEMBER_PROFILE p JOIN REST_REVIEW r
ON r.MEMBER_ID = p.MEMBER_ID
WHERE p.MEMBER_ID IN(
        SELECT * FROM (
            SELECT
                MEMBER_ID
            FROM
                REST_REVIEW
            GROUP BY
                MEMBER_ID
            ORDER BY
                COUNT(REVIEW_ID) DESC
            LIMIT 1
        ) AS SUB
    )
ORDER BY 3,2;