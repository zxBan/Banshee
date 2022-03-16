awk -f test1.awk file1.txt
#!/usr/bin/env bash
{
  for (i=1; i<=NF; i++) {
    a[$i]++;
    if (max < a[$i]) { max = a[$i]; m = $i;}
}
} END{for (k in a) n=0; if (n<1) {print m, max; n++}}
