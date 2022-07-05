$meow = get-date -f yyyy-MM-dd
Rename-Item miaou.log $meow+.log
$env:FLASK_APP = "app"
flask run --host=0.0.0.0