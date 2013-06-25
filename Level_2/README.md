### Level 1 -> Level 2

Dynamic tricks
:This program checks your user ID.

:Perhaps you can trick it, so that it thinks you have a different one.

:Think dynamically.
Reading Material
Link - http://www.google.com/search?q=linux+function+interception

### My Solution
Use LD_PRELOAD to replace the libc call to geteuid();
Run like this:
<pre>$ LD_PRELOAD=./evil.so ./semtex2</pre>
