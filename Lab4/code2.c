# include <stdio.h>

float celsius_to_fahrenheit (float celsius) {
    return celsius * 9.0 / 5.0 + 32;
}

float fahrenheit_to_celsius (float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

float celsius_to_kelvin (float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius (float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void categorize_temperature(float celsius) {
    if (celsius < 0) { // if the temp is below 0 celsius
        printf("Temperature category: Freezing\n");
    }
    else if (celsius < 10) { // 0 <= celsius < 10 because it already passed the < 0 check
        printf("Temperature category: Cold\n");
    }
    else if (celsius < 25) { // same logic, this is if 10 <= celsius < 25
        printf("Temperature category: Comfortable\n");
    }
    else if (celsius <= 35) { // <= used to include 35 according to the requirements
        printf("Temperature category: Hot\n");
    }
    else { // if the other conditions are false, celsius must be over 35
        printf("Temperature category: Extreme Heat\n");
    }
}

void advise_by_temp(float celsius) {
    if (celsius < 0) { // if the temp is below 0 celsius
        printf("Weather advisory: Stay indoors or go sledding.\n");
    }
    else if (celsius < 10) { // 0 <= celsius < 10 because it already passed the < 0 check
        printf("Weather advisory: Wear a jacket.\n");
    }
    else if (celsius < 25) { // same logic, this is if 10 <= celsius < 25
        printf("Weather advisory: You should feel comfortable.\n");
    }
    else if (celsius <= 35) { // <= used to include 35 according to the requirements
        printf("Weather advisory: It's a hot day, remember to hydrate.\n");
    }
    else { // if the other conditions are false, celsius must be over 35
        printf("Weather advisory: It's a very hot day, stay indoors.\n");
    }
}

void clear() {
    while (getchar() != '\n'); // clear the input buffer by getting chars until it hits a newline
}

float get_temperature() { // get the temperature, making sure that it is a number
    float temperature;
    while(1) { // temperature loop
        printf("Enter the temperature: ");
        int success = scanf("%f", &temperature); // get the input temperature from the user and store it
        if (success < 1) { // if a number was not inputted, print an error message, retry the input, and clear the input buffer
            printf("Invalid input. Enter a number.\n");
            clear();
        }
        else {
            return temperature;
        }
    }
}

int get_scale() {
    int scale;
    while(1) { // same logic as get_temperature()
        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        int success = scanf("%d", &scale); // get the input temperature from the user and store it
        if (success < 1) { // if a number was not inputted, print an error message, retry the input, and clear the input buffer
            printf("Invalid input. Enter a number.\n");
            clear();
        }
        else if (scale == 1 || scale == 2 || scale == 3) {
            return scale;
        }
        else {
            printf("Invalid input. Enter a number from 1 to 3.\n");
        }
    }
}

int get_convert_to() {
    int scale;
    while(1) { // same logic as get_temperature()
        printf("Choose scale to convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        int success = scanf("%d", &scale); // get the input temperature from the user and store it
        if (success < 1) { // if a number was not inputted, print an error message, retry the input, and clear the input buffer
            printf("Invalid input. Enter a number.\n");
            clear();
        }
        else if (scale == 1 || scale == 2 || scale == 3) {
            return scale;
        }
        else {
            printf("Invalid input. Enter a number from 1 to 3.\n");
        }
    }
}


int main() {
    float temperature;
    int scale;
    int convert_to;
    while(1) {
        temperature = get_temperature();
        scale = get_scale();
        if (scale == 1) { // if the input is in Celsius, check if it is valid (>= 0 Kelvin). If so, break out of the while loop as this is valid input
            if (celsius_to_kelvin(temperature) >= 0) {
                break;
            }
        }
        if (scale == 2) { // if the input is in Fahrenheit, convert it to Celsius (change temperature value here) then Kelvin and do the same
            if (fahrenheit_to_kelvin(temperature) >= 0) {
                temperature = fahrenheit_to_celsius(temperature);
                break;
            }
        }
        if (scale == 3) { // if the input is in Kelvin, compare it directly to 0 (and covert it to Celsius)
            if (temperature >= 0) {
                temperature = kelvin_to_celsius(temperature);
                break;
            }
        }
        printf("Invalid temperature and scale combination (less than 0K). Please try again.\n");
        }
    while(1) {
        convert_to = get_convert_to();
        if (scale == convert_to) {
            printf("Invalid input. You need to convert to a different scale than the initial one.\n");
        }
        else {
            break;
        }
    }
    // Now we know we have valid input
    switch (convert_to) { // the temperature has already been converted to Celsius, so we just have to convert it to the final scale.
        case 1: printf("Converted temperature: %.2f °C\n", temperature); // the target scale is Celsius, so leave it alone and print temperature
            break;
        case 2: printf("Converted temperature: %.2f °F\n", celsius_to_fahrenheit(temperature)); // the target scale is Fahrenheit, so convert C to F and print it
            break;
        case 3: printf("Converted temperature: %.2fK\n", celsius_to_kelvin(temperature)); // the target scale is Kelvin, so convert C to K and print it
            break;
    }


    categorize_temperature(temperature); // everything above could be split into more functions as this is much cleaner but oh well
    advise_by_temp(temperature); // these print the desired text based on the temperature value that has already been converted to Celsius
    return 0;
}