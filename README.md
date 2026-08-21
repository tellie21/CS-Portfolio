# CS 255 Portfolio

## DriverPass Project Reflection

### DriverPass Project Summary

The DriverPass project involved analyzing the business requirements and designing a web-based system for DriverPass, a company that wanted a solution to help students prepare for their driver's license exams. The system allows customers to register, schedule driving lessons, complete online practice tests, make payments, and track their progress. Employees and administrators can manage appointments, customer information, and system data.

### What I Did Well

One of my greatest accomplishments was creating the business requirements and system design documents. I successfully translated the client's needs into clear functional and technical requirements. I also created UML diagrams, including activity and sequence diagrams, that accurately illustrated how users interact with the system and how the system processes requests.

### What I Would Revise

If I could revise one part of my work, I would improve the UML diagrams by adding additional detail and alternative process flows. For example, I would include more exception handling for failed logins, payment errors, and appointment conflicts. This would make the design more complete and better prepare developers for real-world situations.

### Interpreting User Needs

Throughout the project, I focused on understanding the needs of both customers and employees. Every feature in the system was designed to solve a specific business or user problem identified during the requirements-gathering process. Considering user needs is essential because software should be easy to use, reliable, secure, and capable of helping users complete their tasks efficiently.

### My Software Design Approach

When designing software, I begin by gathering and organizing business requirements before creating diagrams and system documentation. I break complex systems into smaller processes using UML diagrams and ensure each requirement is addressed within the design. In future projects, I will continue using requirements analysis, process modeling, UML diagrams, and iterative design reviews to create organized, scalable, and user-focused systems.


# CS 230 Portfolio Reflection

## The Gaming Room Project Summary

The client for this project was The Gaming Room, a company that wanted to expand its game, Draw It or Lose It, from an Android-only application to a web-based application that could support multiple operating systems and devices. The software needed to support multiple teams and players while ensuring that only a single instance of the game service existed at any given time. The system also needed to be scalable, secure, reliable, and capable of handling multiple users simultaneously.

## What I Did Well

One area in which I believe I did well was analyzing different operating platforms and recommending the best architecture for the client's needs. I clearly explained the advantages and disadvantages of Windows, Linux, macOS, and mobile operating systems, including memory and storage management, distributed systems, and security. My recommendations focused on performance, scalability, and long-term growth.

## What I Learned

Creating the software design document before writing code made development much easier. It helped organize the project requirements, identify system constraints, and define how different components would work together. Having a detailed design reduced confusion during implementation and provided a clear roadmap throughout development.

## What I Would Revise

If I could improve one section, I would expand the security recommendations by adding more detail on authentication, encryption, cloud security, and user data protection. I would also include additional diagrams to make the document even more useful for future developers.

## Understanding User Needs

I focused on understanding the client's goal of making the game available across multiple platforms while maintaining performance and reliability. Every design decision was made with those needs in mind. Considering the user's needs is essential because successful software should solve the client's problems while providing a positive user experience.

## My Software Design Approach

I approached software design by first analyzing the client's business requirements before selecting technologies and architectural solutions. I compared different operating platforms, evaluated scalability, security, maintainability, and performance, and recommended the solution that best met the client's needs. In future projects, I will continue to use requirements analysis, UML modeling, and structured design documents before implementation.

# CS 300 Portfolio Reflection

## What was the problem you were solving in the projects for this course?

The main problem I worked on in CS 300 was developing a program that could organize and retrieve course information for academic advisors. The program needed to load course data, organize the courses, print a list of all Computer Science courses in alphanumeric order, and display information about an individual course, including its prerequisites. Throughout the projects, I explored different data structures to determine which one would be the most appropriate for managing the course information.

## How did you approach the problem? Consider why data structures are important to understand.

I approached the problem by comparing different data structures, including vectors, hash tables, and binary search trees. I analyzed how each structure stores, searches, and sorts information, as well as its run-time and memory requirements. This helped me understand that choosing the correct data structure is important because it can affect the efficiency and performance of a program. For this project, I determined that a binary search tree was appropriate because an in-order traversal can produce the course list in alphanumeric order.

## How did you overcome any roadblocks you encountered while going through the activities or project?

One of the challenges I encountered was making sure the course information was loaded, stored, and displayed correctly. I worked through problems by reviewing my pseudocode, testing different parts of the program, checking the program output, and correcting errors as I found them. Breaking the program into smaller sections made troubleshooting easier because I could focus on one function or problem at a time.

## How has your work on this project expanded your approach to designing software and developing programs?

This project expanded my approach to software design by teaching me to think about the structure of a program before immediately beginning to code. I learned that planning algorithms and selecting an appropriate data structure can make the development process more organized and efficient. I now have a better understanding of how decisions made during the design stage can affect the performance and usability of the finished program.

## How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?

My work in this course has helped me understand the importance of writing code that can be understood and modified later. I have improved my use of meaningful variable and function names, comments, organized functions, and consistent formatting. Dividing the program into separate functions also makes the code easier to test and maintain. Going forward, I will continue focusing on creating programs that not only work correctly but are also organized, readable, and adaptable to future changes.

## CS 300 Portfolio Artifacts

This repository includes the following artifacts from CS 300 Data Structures and Algorithms:

* **Project One:** Runtime and memory analysis of the vector, hash table, and binary search tree data structures.
* **Project Two:** Working C++ program that loads course information and prints the Computer Science courses in alphanumeric order.



# CS 305 Portfolio Reflection

## Artemis Financial and Software Requirements

Artemis Financial is a financial consulting company that develops individualized financial plans for its customers. The company wanted to improve the security of its software application and protect sensitive client information. My task was to identify security vulnerabilities in the application and apply secure coding practices to reduce potential risks.

## Identifying Software Security Vulnerabilities

I did well identifying vulnerabilities by reviewing the application, analyzing its dependencies, and using security testing tools. Secure coding is important because software vulnerabilities can expose sensitive information and create opportunities for unauthorized access or attacks. Strong software security helps a company protect its customers, maintain trust, reduce risk, and protect the overall integrity of its systems.

## Challenges and Helpful Parts of the Vulnerability Assessment

One of the more challenging parts of the vulnerability assessment was reviewing dependency vulnerabilities and determining which findings required attention. Using the OWASP Dependency-Check was helpful because it provided information about known vulnerabilities within the application's dependencies. This helped me better understand how automated security tools can support a manual review of an application.

## Increasing Layers of Security

I increased the application's security by using secure communication through HTTPS, implementing encryption and certificate-related security measures, and using SHA-256 hashing to verify data integrity. In the future, I would use tools such as OWASP Dependency-Check, vulnerability databases, manual code review, and secure coding standards to identify vulnerabilities and determine appropriate mitigation techniques.

## Verifying Functionality and Security

I tested the application after making security changes to make sure it continued to function correctly. I also performed another dependency scan after refactoring the code to determine whether any new vulnerabilities had been introduced. Testing both functionality and security after making changes helped confirm that the improvements did not negatively affect the application.

## Resources, Tools, and Coding Practices

Some of the most useful resources and practices from this course were OWASP Dependency-Check, Maven, SHA-256 hashing, HTTPS, certificates, dependency analysis, error checking, and secure coding practices. I can use these tools and techniques in future assignments to identify security risks earlier in the software development process and develop more secure applications.

## What I Can Show Future Employers

I can show future employers my Artemis Financial secure software report as an example of my ability to analyze an application for vulnerabilities and apply security improvements. The project demonstrates my experience with vulnerability assessment, secure coding, dependency checking, encryption, hashing, certificates, and software testing. It also shows that I understand the importance of considering security throughout the software development life cycle.

## CS 305 Portfolio Artifact

* **Project Two:** Artemis Financial Practices for Secure Software Report demonstrating vulnerability assessment, secure coding practices, dependency analysis, encryption, hashing, HTTPS, and security testing.
