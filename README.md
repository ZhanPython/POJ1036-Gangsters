# POJ1036-Gangsters
DP,Dynamic Planning

N gangsters are going to a restaurant. The i-th gangster comes at the time Ti and has the prosperity Pi. The door of the restaurant has K+1 states of openness expressed by the integers in the range [0, K]. The state of openness can change by one in one unit of time; it either opens by one, closes by one or remains the same. At the initial moment of time the door is closed (state 0). 

The i-th gangster enters the restaurant only if the door is opened specially for him, i.e. when the state of openness coincides with his stoutness Si. If at the moment of time when the gangster comes to the restaurant the state of openness is not equal to his stoutness, then the gangster goes away and never returns.

The restaurant works in the interval of time [0,T].

The goal is to gather the gangsters with the maximal total prosperity in the restaurant by opening and closing the door appropriately.

Algorithm description：
1. Each gangsters sort in accordance with the arrival time from small to large. Next description based on an ascending of sequencing.
2. dp [i] is the first i gangsters arrive at the hotel can get the largest ΣPi.
3. State transition equation: dp [i] = dp [j] + p [i];
(1). The above equation must meet the conditions that to move from the state of a former j  to the  i gangsters should satisfy: 
dp [i] <= dp [j];
(2). To transfer from dp [j] to dp [i], that is, when the size of the door is exactly equal to s [j], after passing the T [i] -T [j] time, the value is greater than or equal to | s [i] -s [j] |; (since the gate has three states per second)，that is: T [i] - T [j]> = s [i] - s [j] |;
