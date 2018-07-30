# Elastic Scaling in the Virtualized Evolved Packet Core

The scaling is a pivotal task to address workload variation that affects the performance of mobile networks. In the literature, several approaches propose scaling methods to the mobile Evolved Packet Core (EPC). However, so far, none of these approaches have exploited the benefits of elastic scaling to achieve an adaptive EPC in front of workload variations. In this paper, we demonstrate that Network Functions Virtualization (NFV) allows incorporating elastic scaling to EPC aiming to address workload variations, and thus, to improve the network performance and the resources utilization. In particular, we present an elastic scaling mechanism in a virtualized EPC (vEPC), an implementation of a vEPC that supports elastic scaling capability and a performance evaluation of each vEPC entity regarding registrations per second and latency. The evaluation results reveal a significant increase (~300%) in registrations per second and an important decrease (~70%) of latency when the vEPC uses our elastic scaling mechanism. These results corroborate the importance of including elastic scaling capability to improve the vEPC performance.

**Note:** To evaluate our mechanism, we deployed an open source vEPC from the Indian Institute of Technology Bombay (IIT Bombay). The IIT Bombay vEPC, hereinafter, just called B-vEPC simulates the behavior of a typical EPC that handles control and data traffic. B-vEPC has two versions: version 1.0 that is a monolithic implementation of vEPC, and version 2.0 that is a distributed implementation of vEPC. In our evaluation, version 1.0 was used to define the vEPC baseline and vertical scalability. Version 2.0 was used to analyze the behavior of vEPC with horizontal scalability. The GitHub repository of IIT Bombay is available online in the URL: https://github.com/networkedsystemsIITB/NFV_LTE_EPC


**Authors**

1. Kelly Tatiana Tobar Ortega, Telematics Department, University of Cauca.

2. Faiber Botina Anacona, Telematics Department, University of Cauca.

3. Carlos Hernan Tobar Arteaga, Telematics Department, University of Cauca.

4. Oscar Mauricio Caicedo Rendon, Telematics Department, University of Cauca.

**Contact**

- Kelly Tatiana Tobar Ortega, kellytobar@unicauca.edu.co

- Faiber Botina Anacona, faibera@unicauca.edu.co

- Carlos Hernan Tobar Arteaga, carlost@unicauca.edu.co

- Oscar Mauricio Caicedo Rendon, omcaicedo@unicauca.edu.co
