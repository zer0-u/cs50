from flask import Flask, render_template, request


app = Flask(__name__)


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/greet")
def greet():
    # 入力値チェック
    if not request.form.get("name") or request.form.get("sport") not in ["basketball", "soccer", "ultimate frisbee"]:
        return render_template("failure.html")
    return render_template("success.html")
