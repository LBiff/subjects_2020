/* 统计各个部门的工资记录数，给出部门编码dept_no、部门名称dept_name以及部门在salaries表里面有多少条记录sum
CREATE TABLE `departments` (
`dept_no` char(4) NOT NULL,
`dept_name` varchar(40) NOT NULL,
PRIMARY KEY (`dept_no`));

CREATE TABLE `dept_emp` (
`emp_no` int(11) NOT NULL,
`dept_no` char(4) NOT NULL,
`from_date` date NOT NULL,
`to_date` date NOT NULL,
PRIMARY KEY (`emp_no`,`dept_no`));

CREATE TABLE `salaries` (
`emp_no` int(11) NOT NULL,
`salary` int(11) NOT NULL,
`from_date` date NOT NULL,
`to_date` date NOT NULL,
PRIMARY KEY (`emp_no`,`from_date`)); */

SELECT dt.dept_no, dt.dept_name, COUNT()
FROM 
    SELECT dept_no, COUNT(salary) 
    FROM dept_no LEFT JOIN salaries ON dt.emp_no=s.emp_no 
    GROUP BY dept_no;


SELECT dept_no, dept_name, (SELECT COUNT()
FROM dept_emp AS de
INNER JOIN salaries AS s
ON de.emp_no=s.emp_no
WHERE de.dept_no=d.dept_no) AS sum
FROM departments AS d;