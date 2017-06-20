#!/bin/bash

echo "READ WITH SPLAY"
echo "Running uniform"
./jitd_read testscripts/readWithSplay/uniform > output/readWithSplay/uniform
echo "Running heavyhitter"
./jitd_read testscripts/readWithSplay/heavyhitter > output/readWithSplay/heavyhitter
echo "Running uniform to heavyhitter"
./jitd_read testscripts/readWithSplay/uniformToHeavyhitter > output/readWithSplay/uniformToHeavyhitter
echo "Running heavyhitter to uniform"
./jitd_read testscripts/readWithSplay/heavyhitterToUniform > output/readWithSplay/heavyhitterToUniform
echo "Running heavyhitter to heavyhiiter"
./jitd_read testscripts/readWithSplay/heavyhitterToHeavyhitter > output/readWithSplay/heavyhitterToHeavyhitter

echo "READ WITHOUT SPLAY"
echo "Running uniform"
./jitd_read testscripts/readWithoutSplay/uniform > output/readWithoutSplay/uniform
echo "Running heavyhitter"
./jitd_read testscripts/readWithoutSplay/heavyhitter > output/readWithoutSplay/heavyhitter
echo "Running uniform to heavyhitter"
./jitd_read testscripts/readWithoutSplay/uniformToHeavyhitter > output/readWithoutSplay/uniformToHeavyhitter
echo "Running heavyhitter to uniform"
./jitd_read testscripts/readWithoutSplay/heavyhitterToUniform > output/readWithoutSplay/heavyhitterToUniform
echo "Running heavyhitter to heavyhiiter"
./jitd_read testscripts/readWithoutSplay/heavyhitterToHeavyhitter > output/readWithoutSplay/heavyhitterToHeavyhitter

echo "NOREAD WITHOUT SPLAY"
echo "Running uniform"
./jitd_noread testscripts/noreadWithoutSplay/uniform > output/noreadWithoutSplay/uniform
echo "Running heavyhitter"
./jitd_noread testscripts/noreadWithoutSplay/heavyhitter > output/noreadWithoutSplay/heavyhitter
echo "Running uniform to heavyhitter"
./jitd_noread testscripts/noreadWithoutSplay/uniformToHeavyhitter > output/noreadWithoutSplay/uniformToHeavyhitter
echo "Running heavyhitter to uniform"
./jitd_noread testscripts/noreadWithoutSplay/heavyhitterToUniform > output/noreadWithoutSplay/heavyhitterToUniform
echo "Running heavyhitter to heavyhiiter"
./jitd_noread testscripts/noreadWithoutSplay/heavyhitterToHeavyhitter > output/noreadWithoutSplay/heavyhitterToHeavyhitter