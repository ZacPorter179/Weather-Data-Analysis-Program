#include <fstream>
#include <iostream>
using namespace std;

int findMaxElement(int arr[], int size) {
  int maxVal = arr[0];
  for (int i = 1; i < size; ++i) {
    if (arr[i] > maxVal) {
      maxVal = arr[i];
    }
  }
  return maxVal;
}
void calculateTotalPrecipitationPerYear(int numLines, int *year, double *precip,
                                        double *totalPrecipitation) {
  for (int i = 0; i < numLines; ++i) {
    totalPrecipitation[year[i]] += precip[i];
  }
}
void calculateAveragePrecipitationPerYear(int numLines, int *year,
                                          double *precip,
                                          double *averagePrecipitation) {
  const int maxYear = findMaxElement(year, numLines) + 1;

  double *totalPrecipitationPerYear = new double[maxYear]();
  int *countPerYear = new int[maxYear]();

  for (int i = 0; i < numLines; ++i) {
    totalPrecipitationPerYear[year[i]] += precip[i];
    ++countPerYear[year[i]];
  }
  for (int i = 0; i < maxYear; ++i) {
    if (countPerYear[i] != 0) {
      averagePrecipitation[i] = totalPrecipitationPerYear[i] / countPerYear[i];
    }
  }
  delete[] totalPrecipitationPerYear;
  delete[] countPerYear;
}

void calculateAverageSnowFallPerYear(int numLines, int *year, double *snow,
                                     double *averageSnowFall) {
  const int maxYear = findMaxElement(year, numLines) + 1;

  double *totalsnowFallPerYear = new double[maxYear]();
  int *countPerYear = new int[maxYear]();

  for (int i = 0; i < numLines; ++i) {
    totalsnowFallPerYear[year[i]] += snow[i];
    ++countPerYear[year[i]];
  }
  for (int i = 0; i < maxYear; ++i) {
    if (countPerYear[i] != 0) {
      averageSnowFall[i] = totalsnowFallPerYear[i] / countPerYear[i];
    }
  }
  delete[] totalsnowFallPerYear;
  delete[] countPerYear;
}

void calculateAverageSnowDepthPerYear(int numLines, int *year,
                                      double *snowDepth,
                                      double *averageSnowDepth) {
  const int maxYear = findMaxElement(year, numLines) + 1;

  double *totalsnowDepthPerYear = new double[maxYear]();
  int *countPerYear = new int[maxYear]();

  for (int i = 0; i < numLines; ++i) {
    totalsnowDepthPerYear[year[i]] += snowDepth[i];
    ++countPerYear[year[i]];
  }
  for (int i = 0; i < maxYear; ++i) {
    if (countPerYear[i] != 0) {
      averageSnowDepth[i] = totalsnowDepthPerYear[i] / countPerYear[i];
    }
  }
  delete[] totalsnowDepthPerYear;
  delete[] countPerYear;
}
void calculateAverageMaxTempPerYear(int numLines, int *year, double *maxTemp,
                                    double *averageMaxTemp) {
  const int maxYear = findMaxElement(year, numLines) + 1;

  double *totalMaxTempPerYear = new double[maxYear]();
  int *countPerYear = new int[maxYear]();

  for (int i = 0; i < numLines; ++i) {
    totalMaxTempPerYear[year[i]] += maxTemp[i];
    ++countPerYear[year[i]];
  }
  for (int i = 0; i < maxYear; ++i) {
    if (countPerYear[i] != 0) {
      averageMaxTemp[i] = totalMaxTempPerYear[i] / countPerYear[i];
    }
  }
  delete[] totalMaxTempPerYear;
  delete[] countPerYear;
}

void calculateAverageMinTempPerYear(int numLines, int *year, double *minTemp,
                                    double *averageMinTemp) {
  const int maxYear = findMaxElement(year, numLines) + 1;

  double *totalMinTempPerYear = new double[maxYear]();
  int *countPerYear = new int[maxYear]();

  for (int i = 0; i < numLines; ++i) {
    totalMinTempPerYear[year[i]] += minTemp[i];
    ++countPerYear[year[i]];
  }
  for (int i = 0; i < maxYear; ++i) {
    if (countPerYear[i] != 0) {
      averageMinTemp[i] = totalMinTempPerYear[i] / countPerYear[i];
    }
  }
  delete[] totalMinTempPerYear;
  delete[] countPerYear;
}
void calculateAverageObsTempPerYear(int numLines, int *year, double *obsTemp,
                                    double *averageObsTemp) {
  const int maxYear = findMaxElement(year, numLines) + 1;

  double *totalObsTempPerYear = new double[maxYear]();
  int *countPerYear = new int[maxYear]();

  for (int i = 0; i < numLines; ++i) {
    totalObsTempPerYear[year[i]] += obsTemp[i];
    ++countPerYear[year[i]];
  }
  for (int i = 0; i < maxYear; ++i) {
    if (countPerYear[i] != 0) {
      averageObsTemp[i] = totalObsTempPerYear[i] / countPerYear[i];
    }
  }
  delete[] totalObsTempPerYear;
  delete[] countPerYear;
}
int main() {
  ifstream inFile("WeatherData.txt");
  if (!inFile) {
    cout << "Error: Unable to open file" << endl;
    return 1;
  }

  int numLines = 0;
  string line;
  while (getline(inFile, line)) {
    ++numLines;
  }
  inFile.clear();
  inFile.seekg(0, ios::beg);

  int *day = new int[numLines];
  int *month = new int[numLines];
  int *year = new int[numLines];
  double *precip = new double[numLines];
  double *snow = new double[numLines];
  double *snowDepth = new double[numLines];
  double *maxTemp = new double[numLines];
  double *minTemp = new double[numLines];
  double *obsTemp = new double[numLines];

  for (int i = 0; i < numLines; ++i) {
    inFile >> day[i] >> month[i] >> year[i] >> precip[i] >> snow[i] >>
        snowDepth[i] >> maxTemp[i] >> minTemp[i] >> obsTemp[i];
  }
  inFile.close();

  int startYear, endYear;
  cout << "Enter start year: ";
  cin >> startYear;
  cout << "Enter end year: ";
  cin >> endYear;

  const int maxYear = findMaxElement(year, numLines) + 1;

  double *totalPrecipitation = new double[maxYear]();
  double *averagePrecipitation = new double[maxYear]();
  double *averageSnowFall = new double[maxYear]();
  double *averageSnowDepth = new double[maxYear]();
  double *averageMaxTemp = new double[maxYear]();
  double *averageMinTemp = new double[maxYear]();
  double *averageObsTemp = new double[maxYear]();

  calculateTotalPrecipitationPerYear(numLines, year, precip,
                                     totalPrecipitation);
  calculateAveragePrecipitationPerYear(numLines, year, precip,
                                       averagePrecipitation);
  calculateAverageSnowFallPerYear(numLines, year, snow, averageSnowFall);
  calculateAverageSnowDepthPerYear(numLines, year, snowDepth, averageSnowDepth);
  calculateAverageMaxTempPerYear(numLines, year, maxTemp, averageMaxTemp);
  calculateAverageMinTempPerYear(numLines, year, minTemp, averageMinTemp);
  calculateAverageObsTempPerYear(numLines, year, obsTemp, averageObsTemp);

  ofstream outFile("output.txt");
  if (!outFile) {
    cout << "Error: Unable to open output file" << endl;

    return 1;
  }
  for (int i = startYear; i <= endYear; ++i) {
    if (i >= 0 && i < maxYear && totalPrecipitation[i] != 0) {
      outFile << i << " ";
      outFile << totalPrecipitation[i] << " ";
      outFile << averagePrecipitation[i] << " ";
      outFile << averageSnowFall[i] << " ";
      outFile << averageSnowDepth[i] << " ";
      outFile << averageMaxTemp[i] << " ";
      outFile << averageMinTemp[i] << " ";
      outFile << averageObsTemp[i] << endl;
    }
  }
  outFile.close();

  delete[] day;
  delete[] month;
  delete[] year;
  delete[] precip;
  delete[] snow;
  delete[] snowDepth;
  delete[] maxTemp;
  delete[] minTemp;
  delete[] obsTemp;
  delete[] totalPrecipitation;
  delete[] averagePrecipitation;
  delete[] averageSnowFall;
  delete[] averageSnowDepth;
  delete[] averageMaxTemp;
  delete[] averageMinTemp;
  delete[] averageObsTemp;

  return 0;
}