#!/bin/bash

cd .. && npm run clean && find . -iname *.re | xargs refmt --in-place && npm run build
