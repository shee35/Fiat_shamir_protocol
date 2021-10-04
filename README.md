# Network Security : Fiat_shamir_protocol

## About Fiat Shamir Protocol
Password authentication is very common but it is very much vulnerable to attacks, such as eavesdropping, guessing passwords, stolen passwords, etc. there are some ways in which the user can convince the verifier that he knows the password without actually telling him the exact password. Here the password could be anything , any real password or some numbers that only the real user might know. One of these techniques is fiat shamir protocol. 
Fiat-shamir protocol is a type of zero knowledge protocol. Here the claimant need not disclose any secret keys, or anything that might endanger the confidentiality of the claimant. This is a better way of securing because here the eavesdropper would not know anything about the secret like password or anything, so they cannot steal it anyway. It is just that he has to prove to the verifier that he knows the secret every time the verifier asks to. If at any time the claimant is not able to prove himself the session would be terminated. 



## Algorithm
This protocol works between claimant and verifier as :
Suppose the claimant is Alice and the verifier is Bob, Alice has a private key(s), a public key(v) and a random number as r. 
N is a public number which is very large made by multiplying p and q which are other 2 large prime numbers.
```
* Alice sends x , such that x = r^2%n as a  witness.
* Now Bob sends a challenge c to Alice which is either 0 or 1 randomly.
* Alice now calculates y= r*s^c %n and sends y to Bob as a response.
* Now Bob calculates, y^2 mod n, if this is equal to xv^c mod n then Alice passed this test , otherwise Alice failed. 
* This process is repeated a certain number of times, and Alice has to pass all the times, if fails any test the session will not be established.
```

## Workflow of the Algorithm

<p align="center">
  <img width="1000" height="600" src="https://github.com/shee35/Fiat_shamir_protocol/blob/main/assets/workflow.png">
</p>
 
## Run code
```
git clone [REPO_URL]
Run Claimant(Alice).cpp
Run Verifier(Bob).cpp
```

## Demo
Sample 1 :
<!-- ![Bob](https://github.com/shee35/Fiat_shamir_protocol/blob/main/assets/ns1.png)
![Alice](https://github.com/shee35/Fiat_shamir_protocol/blob/main/assets/ns2.png) -->

<table>
  <tr>
     <td align="center"><img src="https://github.com/shee35/Fiat_shamir_protocol/blob/main/assets/ns2.png" width="450px;" alt=""/><br /><sub><b>Alice</b></sub></a><br /></td>
     <td align="center"><img src="https://github.com/shee35/Fiat_shamir_protocol/blob/main/assets/ns1.png" width="450px;" alt=""/><br /><sub><b>Bob</b></sub></a><br /></td>
    
  </tr>
  </table>
<!-- 
Sample 2 :

<table>
  <tr>
     <td align="center"><img src="https://github.com/shee35/Fiat_shamir_protocol/blob/main/assets/ns22.png" width="450px;" alt=""/><br /><sub><b>Alice</b></sub></a><br /></td>
     <td align="center"><img src="https://github.com/shee35/Fiat_shamir_protocol/blob/main/assets/ns11.png" width="450px;" alt=""/><br /><sub><b>Bob</b></sub></a><br /></td>
    
  </tr>
  </table>
 -->
