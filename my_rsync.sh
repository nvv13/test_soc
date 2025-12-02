#!/bin/bash


git add .
git commit -m "sync1"
git push


if [ -d /home/nvv/github.com/test_soc ]; then
   rsync -r --links --exclude=.git --delete /home/nvv/gitflic.ru/test_soc /home/nvv/github.com
   cd /home/nvv/github.com/test_soc
   git add .
   git commit -m "sync2"
   git push
fi
