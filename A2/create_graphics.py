import pandas as pd
import matplotlib.pyplot as plt

def create_graphics(path_to_csv_data_standart: str, path_for_saving_graphic_merge_and_insertion: str, path_for_saving_graphic: str) -> None:
    standart_data: pd.DataFrame = pd.read_csv(path_to_csv_data_standart, sep=';')
    merge_and_insertion_data: pd.DataFrame = pd.read_csv(path_for_saving_graphic_merge_and_insertion, sep=';')
    standart_plot = plt.plot(standart_data['size'], standart_data['time'], label='Standart merge sort')
    merge_and_insertion_plot = plt.plot(merge_and_insertion_data['size'], merge_and_insertion_data['time'], label='Merge and insertion sort')
    plt.legend()
    plt.savefig(path_for_saving_graphic)
    plt.close()

create_graphics('A/A2/CsvData/almost_sorted_array_standart_merge_sort.csv', 
                'A/A2/CsvData/almost_sorted_array_merge_and_insertion_sort.csv',
                'A/A2/Plots/almost_sorted.png')
create_graphics('A/A2/CsvData/random_array_standart_merge_sort.csv',
                'A/A2/CsvData/random_array_merge_and_insertion_sort.csv',
                'A/A2/Plots/random.png')
create_graphics('A/A2/CsvData/reversed_array_standart_merge_sort.csv',
                'A/A2/CsvData/reversed_array_merge_and_insertion_sort.csv',
                'A/A2/Plots/reversed.png')