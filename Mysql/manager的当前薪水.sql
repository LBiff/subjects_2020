/* 获取所有部门当前(dept_manager.to_date='9999-01-01')manager的当前(salaries.to_date='9999-01-01')薪水情况，
给出dept_no, emp_no以及salary(请注意，同一个人可能有多条薪水情况记录)
CREATE TABLE `dept_manager` (
`dept_no` char(4) NOT NULL,
`emp_no` int(11) NOT NULL,
`from_date` date NOT NULL,
`to_date` date NOT NULL,
PRIMARY KEY (`emp_no`,`dept_no`));
CREATE TABLE `salaries` (
`emp_no` int(11) NOT NULL,
`salary` int(11) NOT NULL,
`from_date` date NOT NULL,
`to_date` date NOT NULL,
PRIMARY KEY (`emp_no`,`from_date`)); */

SELECT d.dept_no, d.emp_no, s.salary
FROM dept_manager AS d INNER JOIN salaries AS s on d.emp_no=s.emp_no
WHERE d.to_date='9999-01-01' AND s.to_date='9999-01-01';