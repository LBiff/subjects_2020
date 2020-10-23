/* 获取所有员工当前的(dept_manager.to_date='9999-01-01')manager，
如果员工是manager的话不显示(也就是如果当前的manager是自己的话结果不显示)。
输出结果第一列给出当前员工的emp_no,第二列给出其manager对应的emp_no。
CREATE TABLE `dept_emp` (
`emp_no` int(11) NOT NULL, -- '所有的员工编号'
`dept_no` char(4) NOT NULL, -- '部门编号'
`from_date` date NOT NULL,
`to_date` date NOT NULL,
PRIMARY KEY (`emp_no`,`dept_no`));
CREATE TABLE `dept_manager` (
`dept_no` char(4) NOT NULL, -- '部门编号'
`emp_no` int(11) NOT NULL, -- '经理编号'
`from_date` date NOT NULL,
`to_date` date NOT NULL,
PRIMARY KEY (`emp_no`,`dept_no`)); */

SELECT de.emp_no, dm.emp_no
FROM dept_emp AS de INNER JOIN dept_manager as dm
    ON de.dept_no=dm.dept_no
WHERE dm.to_date='9999-01-01' AND de.emp_no != dm.emp_no AND de.to_date='9999-01-01'

