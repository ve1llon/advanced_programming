#include <iostream>
#include <vector>

#include "builder.h"

int main() {
    std::vector<std::tuple<CheckpointName, CheckpointCoord, CheckpointFine>>
            checkpoints_data =
                            {
                                std::make_tuple(CheckpointName{"House"}, CheckpointCoord{12.7128, 24.534}, CheckpointFine{-1.0}),
                                std::make_tuple(CheckpointName{"Flag"}, CheckpointCoord{-30.568, -71.5460}, CheckpointFine{10.0}),
                                std::make_tuple(CheckpointName{"Line"}, CheckpointCoord{56.7658, -654.53}, CheckpointFine{-1.0}),
                                std::make_tuple(CheckpointName{"Billboard"}, CheckpointCoord{89.635, 464.46540}, CheckpointFine{12.0}),
                                std::make_tuple(CheckpointName{"Lake"}, CheckpointCoord{30.38, -74.6546}, CheckpointFine{-1.0}),
                                std::make_tuple(CheckpointName{"Towel"}, CheckpointCoord{0.7534, 64.98760}, CheckpointFine{2.0}),
                                std::make_tuple(CheckpointName{"Tube"}, CheckpointCoord{-13.3458, 2.89}, CheckpointFine{1.0}),
                                std::make_tuple(CheckpointName{"Truck"}, CheckpointCoord{1.34, 4.980}, CheckpointFine{-1.0}),
                                std::make_tuple(CheckpointName{"Rock"}, CheckpointCoord{650.458, -89.01}, CheckpointFine{-1.0}),
                            };

    TextPrint text_builder;
    CalculationPrint calculator_builder;
    TablePrint table_builder;

    Director director1(&text_builder);
    director1.Add(checkpoints_data);
    director1.Print();

    Director director2(&calculator_builder);
    director2.Add(checkpoints_data);
    director2.Print();

    Director director3(&table_builder);
    director3.Add(checkpoints_data);
    director3.Print();

    return 0;
}

