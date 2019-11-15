Author: Colby Ackerman
Class:  CS4280 Program Translations
Assign: Project 2
Date:   11/15/19

Run `make` to install to current directory.

`./scanner [file]` to run.


Author's Notes:
I would say the weirdest quirk about the way my parse tree is structured is that the token data 
is stored in a separate vector from the children pointers which both are contained in a single node.
It results in slightly odd behavior. E.g. The "if" node stores all of the discardable tokens { (, (, ), ) },
so when I do a left-to-right print of the parse tree, the user ends up seeing all of those tokens printed before what
is contained between them. I believe this is inconsequential though, as all of the meaningful tokens are printed in order.
It might just make p3 slightly weirder to implement is all. I'll figure it out though.

Also the commenting is not the greatest on this project--especially within each nonterminal function, but those
are kindof a cluster**** anyway. I really don't enjoy using recursion and always prefer a 
stack implementation/iterative approach. I guess either way there is a stack involved, but I just prefer not to have
to backtrace on gdb or whatever if I don't have to. Basically, I find it considerably easier to debug iterative programs.

It's probably worth noting that I did end up left factorizing the BNF in its entirety before I started on this project.

Here's a link to the google doc: 
https://docs.google.com/document/d/1VR8K5s5yKMt6-dgH4tkx1-mQVadBxtyZnviaROQOvpQ/edit?usp=sharing

Anyway... the parser seems to work properly and generate a valid parse tree, so that's good.


Here's the remote repo:
https://github.com/CSnackerman/umslCompilersProjects

Project 2 is contained in the branch "p2".
The master branch is P1.
