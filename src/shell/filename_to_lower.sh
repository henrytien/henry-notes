#!/bin/bash
cvitem() 
{
  DName=`dirname $1`
  BName=`basename $1`
  lc_BName=`basename $1 | tr '[A-Z]' '[a-z]'`
  if [ "$BName" = "$lc_BName" ]; then
    echo "****: $1 ---x--- $DName/$lc_BName identical!"
  else
    echo "----renaming $1 to $DName/$lc_BName ..."
    mv $1 $DName/$lc_BName
  fi
}
 
[ $# = 0 ] && { echo "Usage: lcdir item1 item2 ..."; exit; }
 
for item in $*
do
  [ "`dirname $item`" != "`basename $item`" ] && {
  [ -d $item ] &&
  {
  for subitem in `ls $item`
  do
  ./Aa.sh $item/$subitem
  done
  }
  cvitem $item
}
done

