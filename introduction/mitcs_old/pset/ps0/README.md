# Trouble shooting

When use matplotlib.pyplot on my mac, I have an error.

```
$python -c "import matplotlib;print(matplotlib.matplotlib_fname())"
```

and then change the statement as below

before

```
backend: macosx
```

after

```
backend: TkAgg
```
