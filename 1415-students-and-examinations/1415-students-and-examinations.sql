# Write your MySQL query statement below
select
    s1.student_id,
    s1.student_name,
    sub1.subject_name,
    count(e1.student_id) as attended_exams
    FROM Students s1
    CROSS JOIN Subjects sub1
    left join Examinations e1 on e1.student_id = s1.student_id 
    AND sub1.subject_name = e1.subject_name
    group by s1.student_id, s1.student_name, sub1.subject_name
    order by s1.student_id, sub1.subject_name;