#include <fstream> // Include library for file input and output operations
#include <iostream> // Include library for standard input and output
using namespace std; // Use the standard namespace

// Function to find the maximum element in an array
int findMaxElement(int arr[], int size) {
  int maxVal = arr[0]; // Initialize maxVal with the first element
  for (int i = 1; i < size; ++i) { // Iterate through the array
    if (arr[i] > maxVal) { // Check if current element is greater than maxVal
      maxVal = arr[i]; // Update maxVal
    }
  }
  return maxVal; // Return the maximum value found
}

// Function to calculate total precipitation per year
void calculateTotalPrecipitationPerYear(int numLines, int *year, double *precip,
                                        double *totalPrecipitation) {
  for (int i = 0; i < numLines; ++i) { // Iterate through each data point
    totalPrecipitation[year[i]] += precip[i]; // Add precipitation to respective year
  }
}

// Function to calculate average precipitation per year
void calculateAveragePrecipitationPerYear(int numLines, int *year,
                                          double *precip,
                                          double *averagePrecipitation) {
  const int maxYear = findMaxElement(year, numLines) + 1; // Determine the maximum year

  double *totalPrecipitationPerYear = new double[maxYear](); // Allocate memory for total precipitation
  int *countPerYear = new int[maxYear](); // Allocate memory for count of entries per year

  for (int i = 0; i < numLines; ++i) { // Iterate through each data point
    totalPrecipitationPerYear[year[i]] += precip[i]; // Sum precipitation per year
    ++countPerYear[year[i]]; // Increment count per year
  }
  for (int i = 0; i < maxYear; ++i) { // Iterate through years
    if (countPerYear[i] != 0) { // Avoid division by zero
      averagePrecipitation[i] = totalPrecipitationPerYear[i] / countPerYear[i]; // Calculate average precipitation
    }
  }
  delete[] totalPrecipitationPerYear; // Free allocated memory
  delete[] countPerYear; // Free allocated memory
}

// Function to calculate average snowfall per year
void calculateAverageSnowFallPerYear(int numLines, int *year, double *snow,
                                     double *averageSnowFall) {
  const int maxYear = findMaxElement(year, numLines) + 1; // Determine the maximum year

  double *totalsnowFallPerYear = new double[maxYear](); // Allocate memory for total snowfall
  int *countPerYear = new int[maxYear](); // Allocate memory for count of entries per year

  for (int i = 0; i < numLines; ++i) { // Iterate through each data point
    totalsnowFallPerYear[year[i]] += snow[i]; // Sum snowfall per year
    ++countPerYear[year[i]]; // Increment count per year
  }
  for (int i = 0; i < maxYear; ++i) { // Iterate through years
    if (countPerYear[i] != 0) { // Avoid division by zero
      averageSnowFall[i] = totalsnowFallPerYear[i] / countPerYear[i]; // Calculate average snowfall
    }
  }
  delete[] totalsnowFallPerYear; // Free allocated memory
  delete[] countPerYear; // Free allocated memory
}

// Function to calculate average snow depth per year
void calculateAverageSnowDepthPerYear(int numLines, int *year,
                                      double *snowDepth,
                                      double *averageSnowDepth) {
  const int maxYear = findMaxElement(year, numLines) + 1; // Determine the maximum year

  double *totalsnowDepthPerYear = new double[maxYear](); // Allocate memory for total snow depth
  int *countPerYear = new int[maxYear](); // Allocate memory for count of entries per year

  for (int i = 0; i < numLines; ++i) { // Iterate through each data point
    totalsnowDepthPerYear[year[i]] += snowDepth[i]; // Sum snow depth per year
    ++countPerYear[year[i]]; // Increment count per year
  }
  for (int i = 0; i < maxYear; ++i) { // Iterate through years
    if (countPerYear[i] != 0) { // Avoid division by zero
      averageSnowDepth[i] = totalsnowDepthPerYear[i] / countPerYear[i]; // Calculate average snow depth
    }
  }
  delete[] totalsnowDepthPerYear; // Free allocated memory
  delete[] countPerYear; // Free allocated memory
}

int main() {
  ifstream inFile("WeatherData.txt"); // Open the weather data file
  if (!inFile) { // Check if the file opened successfully
    cout << "Error: Unable to open file" << endl;
    return 1; // Exit program with error code
  }

  int numLines = 0; // Variable to store number of lines in file
  string line; // String to read lines from file
  while (getline(inFile, line)) { // Count number of lines
    ++numLines;
  }
  inFile.clear(); // Reset file stream state
  inFile.seekg(0, ios::beg); // Move file cursor back to beginning

  int *day = new int[numLines]; // Allocate memory for day data
  int *month = new int[numLines]; // Allocate memory for month data
  int *year = new int[numLines]; // Allocate memory for year data
  double *precip = new double[numLines]; // Allocate memory for precipitation data
  double *snow = new double[numLines]; // Allocate memory for snowfall data
  double *snowDepth = new double[numLines]; // Allocate memory for snow depth data

  for (int i = 0; i < numLines; ++i) { // Read data from file
    inFile >> day[i] >> month[i] >> year[i] >> precip[i] >> snow[i] >> snowDepth[i];
  }
  inFile.close(); // Close the file

  int startYear, endYear; // Variables to store user input for start and end years
  cout << "Enter start year: "; // Prompt user for input
  cin >> startYear;
  cout << "Enter end year: "; // Prompt user for input
  cin >> endYear;

  const int maxYear = findMaxElement(year, numLines) + 1; // Find the maximum year in data

  double *totalPrecipitation = new double[maxYear](); // Allocate memory for total precipitation
  double *averagePrecipitation = new double[maxYear](); // Allocate memory for average precipitation

  calculateTotalPrecipitationPerYear(numLines, year, precip, totalPrecipitation); // Calculate total precipitation
  calculateAveragePrecipitationPerYear(numLines, year, precip, averagePrecipitation); // Calculate average precipitation

  ofstream outFile("output.txt"); // Open output file for writing
  if (!outFile) { // Check if file opened successfully
    cout << "Error: Unable to open output file" << endl;
    return 1; // Exit program with error code
  }

  for (int i = startYear; i <= endYear; ++i) { // Iterate through years
    if (i >= 0 && i < maxYear && totalPrecipitation[i] != 0) { // Check if data is available
      outFile << i << " " << totalPrecipitation[i] << " " << averagePrecipitation[i] << endl; // Write to file
    }
  }
  outFile.close(); // Close output file

  delete[] day; // Free allocated memory
  delete[] month;
  delete[] year;
  delete[] precip;
  delete[] snow;
  delete[] snowDepth;
  delete[] totalPrecipitation;
  delete[] averagePrecipitation;

  return 0; // End program
}
