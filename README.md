## CodeQL Commands


### BMN
```
codeql database create --overwrite --language cpp --build-mode none ./codeql-db

codeql database analyze ./codeql-db --format=sarif-latest --output=./bmn-codeql.sarif
```


### Traced
```
codeql database create --overwrite --language cpp --command "cl HelloWorldApp\main.cpp" ./codeql-db

codeql database analyze ./codeql-db --format=sarif-latest --output=./traced-codeql.sarif
```
