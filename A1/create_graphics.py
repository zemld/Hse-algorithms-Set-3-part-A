import pandas as pd
import matplotlib.pyplot as plt
import os

path_to_file_with_square_data: str = 'A/A1/square.csv'
square_data: pd.DataFrame = pd.read_csv(path_to_file_with_square_data, sep=';')

path_to_file_with_deviation_data: str = 'A/A1/deviation.csv'
deviation_data: pd.DataFrame = pd.read_csv(path_to_file_with_deviation_data, sep=';')

path_to_save_square_plot: str = 'A/A1/square_plot.png'
path_to_save_deviation_plot: str = 'A/A1/deviation_plot.png'

plt.plot(square_data['points_amount'], square_data['square'])
plt.savefig(path_to_save_square_plot)
plt.close()

plt.plot(deviation_data['points_amount'], deviation_data['deviation'])
plt.savefig(path_to_save_deviation_plot)
plt.close()