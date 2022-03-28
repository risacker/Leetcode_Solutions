/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int imp=0;
    int getImportance(vector<Employee*> employees, int id) {
        for(auto e : employees) {
            if(e->id==id) {
                imp+=e->importance;
                for(auto i : e->subordinates) {
                    getImportance(employees,i);
                }
                break;
            }
        }
        return imp;
    }
};