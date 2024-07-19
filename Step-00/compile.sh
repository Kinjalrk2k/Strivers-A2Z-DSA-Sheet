function compile() {
  filename="${1%%.*}"
  extension="${1#*.}"
  g++ $1 -o $filename.out
}