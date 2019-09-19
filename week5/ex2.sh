if test ! -f "ex2.txt"; then
  echo 1 >ex2.txt
fi

while true; do
  if ln ex2.txt ex2.lock 2>/dev/null; then
    n=$(cat ex2.txt | tail -n 1)
    echo "$((n + 1))" >>ex2.txt
    rm ex2.lock
  fi
done
