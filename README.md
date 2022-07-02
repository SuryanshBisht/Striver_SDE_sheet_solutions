Some thoughts about the hare and tortoise algo (used to find loops in linked lists):- 
if we have two particles one goes with v and the other goes with 2v constant velocities
if they're in straight lines, then they'll never meet, 
but if they're in a loop, they'll always meet regardless of their starting points. 
In the worst case, they'll meet after wandering through all the loop



warning: LF will be replaced by CRLF in README.md.
The file will have its original line endings in your working directory

2096

In Unix systems the end of a line is represented with a line feed (LF). In windows a line is represented with a carriage return (CR) and a line feed (LF) thus (CRLF). when you get code from git that was uploaded from a unix system they will only have an LF.

If you are a single developer working on a windows machine, and you don't care that git automatically replaces LFs to CRLFs, you can turn this warning off by typing the following in the git command line

git config core.autocrlf true
