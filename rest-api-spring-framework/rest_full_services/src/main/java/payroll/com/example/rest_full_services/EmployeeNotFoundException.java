package payroll.com.example.rest_full_services;

public class EmployeeNotFoundException extends RuntimeException{

    EmployeeNotFoundException(Long id) {
        super("Could not find employee " + id);
    }
}
