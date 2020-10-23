/* 查找所有已经分配部门的员工的last_name和first_name以及dept_no(请注意输出描述里各个列的前后顺序)
CREATE TABLE `dept_emp` (
`emp_no` int(11) NOT NULL,
`dept_no` char(4) NOT NULL,
`from_date` date NOT NULL,
`to_date` date NOT NULL,
PRIMARY KEY (`emp_no`,`dept_no`));
CREATE TABLE `employees` (
`emp_no` int(11) NOT NULL,
`birth_date` date NOT NULL,
`first_name` varchar(14) NOT NULL,
`last_name` varchar(16) NOT NULL,
`gender` char(1) NOT NULL,
`hire_date` date NOT NULL,
PRIMARY KEY (`emp_no`));

last_name	first_name	dept_no */

SELECT e.last_name, e.first_name, d.dept_no
FROM employees as e  INNER JOIN dept_emp as d
    ON e.emp_no=d.emp_no;


/* 查找所有员工的last_name和first_name以及对应部门编号dept_no，也包括暂时没有分配具体部门的员工(请注意输出描述里各个列的前后顺序)
 */

 SELECT e.last_name, e.first_name, d.dept_no
    FROM employees as e  LEFT JOIN dept_emp as d
    ON e.emp_no=d.emp_no;
