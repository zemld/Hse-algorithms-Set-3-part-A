import pandas as pd
import matplotlib.pyplot as plt

def create_graphics(path_to_csv_data_quick_sort: str, path_to_csv_data_intro_sort: str, path_for_saving_graphic: str) -> None:
    quick_sort_data: pd.DataFrame = pd.read_csv(path_to_csv_data_quick_sort, sep=';')
    intro_sort_data: pd.DataFrame = pd.read_csv(path_to_csv_data_intro_sort, sep=';')
    plt.plot(quick_sort_data['array_size'], quick_sort_data['time'], label='quick_sort')
    plt.plot(intro_sort_data['array_size'], intro_sort_data['time'], label='intro_sort')
    plt.legend()
    plt.savefig(path_for_saving_graphic)
    plt.close()

create_graphics('A/A3/SortingTimeMeasurments/almost_sorted_with_quick.csv', 
                'A/A3/SortingTimeMeasurments/almost_sorted_with_intro.csv',
                'A/A3/Plots/almost_sorted.png')
create_graphics('A/A3/SortingTimeMeasurments/random_with_quick.csv',
                'A/A3/SortingTimeMeasurments/random_with_intro.csv',
                'A/A3/Plots/random.png')
create_graphics('A/A3/SortingTimeMeasurments/reversed_with_quick.csv',
                'A/A3/SortingTimeMeasurments/reversed_with_intro.csv',
                'A/A3/Plots/reversed.png')