Given a messenger
When received inf.ug.edu.pl and ab
Then sendMessage should return 2

When received inf.ug.edu.eu and message
Then sendMessage should return 1

When received inf.ug.edu.eu and ab
Then sendMessage should return 2

When received inf.ug.edu.pl and message
Then correct sendMessage should return 0 or 1