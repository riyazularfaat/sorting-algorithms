from flask import Flask, render_template, request, redirect, url_for, flash, session
from flask_mysqldb import MySQL 
from flask_login import LoginManager, UserMixin, login_user, login_required, logout_user
import csv
from flask import flash
import os
from datetime import datetime

app = Flask(__name__)
app.secret_key = 'c231296'
EXPENSE_FILE = 'expenses.csv'
USER_DATA = 'user_data.csv'

#MySQL configuration
app.config['MYSQL_HOST'] = 'localhost'
app.config['MYSQL_USER'] = 'root'
app.config['MYSQL_PASSWORD'] = ''
app.config['MYSQL_DB'] = 'personal_finance_manager'

MySQL = MySQL(app)

@app.route('/')
def home():
    if 'username' in session:
        return render_template('home.html', username=session['username'])
    else:
        return render_template('home.html')

@app.route('/sign_up', methods=['GET', 'POST'])
def sign_up():
    if request.method == 'POST':
        fullname = request.form['fullname']
        email = request.form['email']
        phone = request.form['mobile']
        username = request.form['username']
        pwd = request.form['password']
        cur = MySQL.connection.cursor()
        cur.execute(f"INSERT INTO users (full_name, email, mobile, username, password) VALUES ('{fullname}', '{email}', '{phone}', '{username}', '{pwd}')")
        MySQL.connection.commit()
        cur.close()
        flash("Sign up successfully!")
        return redirect(url_for('login'))
    return render_template('sign_up.html')

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        cur = MySQL.connection.cursor()
        cur.execute(f"SELECT username, password FROM users WHERE username = '{username}' AND password = '{password}'")
        user = cur.fetchone()
        cur.close()
        if user and username == user[1]:
            session['username'] = user[0]
            return redirect(url_for('home_page'))
        else:
            error = "Invalid username or password"
            return redirect(url_for('login', error=error))
    return render_template('login.html')

# def read_expenses():
#     if not os.path.exists(EXPENSE_FILE):
#         return []
#     with open(EXPENSE_FILE, 'r') as file:
#         return list(csv.DictReader(file))

# def write_expenses(expenses):
#     with open(EXPENSE_FILE, 'w', newline='') as file:
#         writer = csv.DictWriter(file, fieldnames=['date', 'amount', 'category', 'description'])
#         writer.writeheader()
#         writer.writerows(expenses)

# def read_users():
#     if not os.path.exists(USER_DATA):
#         return []
#     with open(USER_DATA, 'r') as file:
#         return list(csv.DictReader(file))

# def write_expenses(users):
#     with open(USER_DATA, 'w', newline='') as file:
#         writer = csv.DictWriter(file, fieldnames=['fullname', 'username', 'email', 'password', 'phone'])
#         writer.writeheader()
#         writer.writerows(users)

# @app.route('/')
# def home():
#     return render_template('home.html')

@app.route('/home_page', methods=['GET', 'POST'])
def home_page():
    return render_template('home_page.html')

# @app.route('/sign_up', methods=['GET', 'POST'])
# def sign_up():
#     if request.method == 'POST':
#         fullname = request.form['fullname']
#         email = request.form['email']
#         phone = request.form['mobile']
#         username = request.form['username']
#         pwd = request.form['password']
#         r_pwd = request.form['r_password']
        
#         if pwd != r_pwd:
#             with open(USER_DATA, 'a') as file:
#                 file.write(f"{fullname}, {username}, {email}, {pwd}, {phone} \n")
#             flash("Sign up successfully!")
#             return redirect(url_for('login'))
#     return render_template('sign_up.html')

# @app.route('/login', methods=['GET', 'POST'])
# def login():
#     if request.method == 'POST':
#         username = request.form['username']
#         pwd = request.form['password']
#         users = read_users()
#         for user in users:
#             if username == user['username'] and pwd == user['password']:
#                 return redirect(url_for('home_page'))
#         flash('Invalid username or password')
#     return render_template('login.html')

@app.route('/add', methods=['GET', 'POST'])
def add_expense():
    if request.method == 'POST':
        date = request.form['date']
        amount = request.form['amount']
        category = request.form['category']
        description = request.form['description']
        
        cur = MySQL.connection.cursor()
        cur.execute(f"INSERT INTO expenses (date, amount, category, description) VALUES ('{date}', '{amount}', '{category}', '{description}')")
        MySQL.connection.commit()
        cur.close()
        
        
        # # Save expense to the file
        # with open(EXPENSE_FILE, 'a') as file:
        #     file.write(f"{date},{amount},{category},{description}\n")
        
        flash("Expense added successfully!", "success")
        return redirect(url_for('add'))

    return render_template('add.html')

@app.route('/view')
def view_expenses():
    expenses = read_expenses()
    return render_template('view.html', expenses=expenses)

@app.route('/search', methods=['GET', 'POST'])
def search_expenses():
    if request.method == 'POST':
        search_type = request.form['search_type']
        search_term = request.form['search_term']
        expenses = read_expenses()
        filtered_expenses = [
            expense for expense in expenses 
            if (search_type == 'date' and expense['date'] == search_term) or
               (search_type == 'category' and expense['category'].lower() == search_term.lower())
        ]
        return render_template('search_expenses.html', expenses=filtered_expenses, searched=True)

    return render_template('search.html', searched=False)

@app.route('/delete', methods=['GET', 'POST'])
def delete_expense():
    if request.method == 'POST':
        search_type = request.form['search_type']
        search_term = request.form['search_term']
        results_found = False
        
        try:
            with open(EXPENSE_FILE, 'r') as file:
                expenses = file.readlines()
            
            with open(EXPENSE_FILE, 'w') as file:
                for expense in expenses:
                    date, amount, category, description = expense.strip().split(',')
                    if (search_type == 'date' and date == search_term) or \
                       (search_type == 'category' and category.lower() == search_term.lower()):
                        results_found = True
                        continue
                    file.write(expense)
            
            if results_found:
                flash("Expense deleted successfully!", "success")
            else:
                flash("No matching expense found to delete.", "error")
        except FileNotFoundError:
            flash("No expenses found to delete.", "error")
        
        return redirect(url_for('delete_expense'))
    
    return render_template('delete_expense.html')

@app.route('/update', methods=['GET', 'POST'])
def update_expense():
    if request.method == 'POST':
        search_type = request.form['search_type']
        search_term = request.form['search_term']
        new_amount = request.form['new_amount']
        new_category = request.form['new_category']
        new_description = request.form['new_description']
        results_found = False
        
        try:
            with open(EXPENSE_FILE, 'r') as file:
                expenses = file.readlines()
            
            with open(EXPENSE_FILE, 'w') as file:
                for expense in expenses:
                    date, amount, category, description = expense.strip().split(',')
                    if (search_type == 'date' and date == search_term) or \
                       (search_type == 'category' and category.lower() == search_term.lower()):
                        results_found = True
                        file.write(f"{date},{new_amount},{new_category},{new_description}\n")
                    else:
                        file.write(expense)
            
            if results_found:
                flash("Expense updated successfully!", "success")
            else:
                flash("No matching expense found to update.", "error")
        except FileNotFoundError:
            flash("No expenses found to update.", "error")
        
        return redirect(url_for('update_expense'))
    
    return render_template('update.html')

@app.route('/spport', methods=['GET', 'POST'])
@app.route('/total', methods=['GET', 'POST'])
def calculate_total():
    if request.method == 'POST':
        expenses = read_expenses()
        total = sum(float(expense['amount']) for expense in expenses)
        return render_template('total.html', total=total)
    return render_template('total.html', total=None)

if __name__ == '__main__':
    app.run(debug=True)

    