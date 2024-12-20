from sqlalchemy import create_engine, Column, Integer, String, DateTime
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker
from datetime import datetime

# Step 1: Set up the database engine
engine = create_engine("sqlite:///my_database.db")

# Step 2: Define the base class and model
Base = declarative_base()

class User(Base):
    __tablename__ = 'user'
    id = Column(Integer, primary_key=True, autoincrement=True)
    name = Column(String, nullable=False)
    email = Column(String, nullable=False, unique=True)
    mobile = Column(String, nullable=False)
    username = Column(String, nullable=False, unique=True)
    password = Column(String, nullable=False)
    date_created = Column(DateTime, default=datetime.utcnow)

# Step 3: Create the database and tables
Base.metadata.create_all(engine)
print("Database and tables created successfully!")

# Step 4: Set up a session
Session = sessionmaker(bind=engine)
session = Session()

# Step 5: Insert data into the database
new_user = User(
    name="John Doe",
    email="john.doe@example.com",
    mobile="1234567890",
    username="johndoe",
    password="hashed_password"
)
session.add(new_user)
session.commit()
print("New user added successfully!")

# Step 6: Query the database
users = session.query(User).all()
