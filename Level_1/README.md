### Level 0 -> Level 1

Simple encryption
:A password has been crypted using the /semtex/semtex1 tool.
:
:The crypted password is HRXDZNWEAWWCP.
:
:You have to reverse engineer the algorithm and decrypt the password.
:You might try the -v switch for encrypt.

#### My Solution:
This is over thought but i had a good idea of how the encryption worked after playing with it for a few min.
Basicly the input is rearanged and each char is transformed by some constant.

semtex1 is a dirty replication of the actual semtex1 but it is not correct and it will only work for values below 'L' Well it might work at higher values but it is not important.

analizer sends diffrent values to semtex1 to reverse the mapping and transform values and spits out the correct mapping and transform arrays that are plugged into semtex1_decrypt

semtex1_decrypt runs exactly backwards from semtex1 and does account for values above 'L' ;) 

NOTE: when running the analizer on the server you have to change the ./semtex1 executable to the correct path on the server.
