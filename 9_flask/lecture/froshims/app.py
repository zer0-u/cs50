from flask import Flask, render_template, request


app = Flask(__name__)

SPORTS = [
    "basketball",
    "foorball",
    "soccer",
    "ultimate frisbee"
]


@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)


@app.route("/register", methods=["POST"])
def register():
    # 入力値チェック
    if not request.form.get("name") or request.form.get("sport") not in SPORTS:
        return render_template("failure.html")
    return render_template("success.html")
