#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/brock/dev/projects/Image-Processing-Tutorial-0-Setting-Up-OpenCV
  make -f /Users/brock/dev/projects/Image-Processing-Tutorial-0-Setting-Up-OpenCV/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/brock/dev/projects/Image-Processing-Tutorial-0-Setting-Up-OpenCV
  make -f /Users/brock/dev/projects/Image-Processing-Tutorial-0-Setting-Up-OpenCV/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/brock/dev/projects/Image-Processing-Tutorial-0-Setting-Up-OpenCV
  make -f /Users/brock/dev/projects/Image-Processing-Tutorial-0-Setting-Up-OpenCV/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/brock/dev/projects/Image-Processing-Tutorial-0-Setting-Up-OpenCV
  make -f /Users/brock/dev/projects/Image-Processing-Tutorial-0-Setting-Up-OpenCV/CMakeScripts/ReRunCMake.make
fi

