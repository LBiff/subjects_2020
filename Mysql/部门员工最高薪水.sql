/* 获取所有部门中当前(dept_emp.to_date = '9999-01-01')员工当前(salaries.to_date='9999-01-01')薪水最高的相关信息，
给出dept_no, emp_no以及其对应的salary，按照部门编号升序排列。
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

SELECT d.dept_no, d.emp_no,s.salary
FROM dept_emp AS d INNER JOIN salaries AS s ON d.emp_no=s.emp_no
WHERE d.to_date = '9999-01-01' AND s.to_date='9999-01-01'
GROUP BY d.dept_no HAVING s.salary = MAX(s.salary)
ORDER BY d.dept_no;