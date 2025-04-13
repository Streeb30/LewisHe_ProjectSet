import yfinance as yf
import pandas as pd
import matplotlib.pyplot as plt

data = yf.download("NVDA", start="2023-01-01", end="2025-01-01")
data['SMA_short'] = data['Close'].rolling(window=20).mean()
data['SMA_long'] = data['Close'].rolling(window=50).mean()

data['Signal'] = 0
data.loc[data['SMA_short'] > data['SMA_long'], 'Signal'] = 1
data['Position'] = data['Signal'].diff()

init_cash = 10000
cash = init_cash
shares = 0
portfolio_value = []
in_position = False

for i in range(len(data)):
    price = data['Close'].iloc[i]
    signal = data['Position'].iloc[i]

    if signal == 1 and not in_position:
        shares = cash/price
        cash = 0
        in_position = True

    elif signal == -1 and in_position:
        cash = shares * price
        shares = 0
        in_position = False

    total_value = cash + shares * price
    portfolio_value.append(total_value)

data['Portfolio'] = portfolio_value

# Drawing the total value we get from day to day
plt.figure(figsize=(14,7))
plt.plot(data['Portfolio'], label='Strategy Portfolio Value ($)')
plt.title('Actual Account Value Over Time (Double Moving Average Strategy)')
plt.xlabel('Date')
plt.ylabel('Portfolio Value')
plt.legend()
plt.grid(True)
plt.show()

# Drawing the Close, short and long average line, and buying, selling point
plt.plot(data['Close'], label='Close Price', alpha=0.5)
plt.plot(data['SMA_short'], label='20-Day SMA')
plt.plot(data['SMA_long'], label='50-Day SMA')

plt.plot(data[data['Position'] == 1].index, data['SMA_short'][data['Position'] == 1],
         '^', markersize=10, color='g', label='Buy Signal')
plt.plot(data[data['Position'] == -1].index, data['SMA_long'][data['Position'] == -1],
         'v', markersize=10, color='r', label='Sell Signal')
plt.legend()
plt.title('AAPL Dual moving Average S')
plt.show()

# For print the actual buying and selling signal
# print(data[data['Position'] == 1])
# print(data[data['Position'] == -1])
# print(data.head(10))
# print(data[['Close', 'SMA_short', 'SMA_long']].describe())