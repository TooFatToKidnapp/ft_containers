#!/bin/bash

find . -name ".DS_Store" -print -delete
rm -fr a.out
make fclean
git add *
echo "Enter your message to commit:"
read message
git commit -m "$message"
git push
