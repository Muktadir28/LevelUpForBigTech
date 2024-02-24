class ITemperatureConverter{
public:
    virtual double getConvertedTemperature(double celsius) = 0;
};

class KalvinTemperatureConverter : public ITemperatureConverter {
    double getConvertedTemperature(double celsius);
};

double KalvinTemperatureConverter::getConvertedTemperature(double celsius) {
    double kelvinTempurature = celsius + 273.15;
    return kelvinTempurature;
}

class FahrenheitTemperatureConverter : public ITemperatureConverter {
    double getConvertedTemperature(double celsius);
};

double FahrenheitTemperatureConverter::getConvertedTemperature(double celsius) {
    double fahrenheitTemperature = celsius * 1.80 + 32.00;
    return fahrenheitTemperature;
}

class Solution {
    vector<ITemperatureConverter*> temperatureConvertersList;
public:
    Solution() {
        createTemperatureConverterList();
    }

    void createTemperatureConverterList() {
        ITemperatureConverter* kelvinTempuratureConverter = new KalvinTemperatureConverter();
        ITemperatureConverter* fahrenheitTempuratureConverter = new FahrenheitTemperatureConverter();
        temperatureConvertersList.push_back(kelvinTempuratureConverter);
        temperatureConvertersList.push_back(fahrenheitTempuratureConverter);
    }

    vector<double> convertTemperature(double celsius) {
        vector<double> convertedTemperatures;
        for(ITemperatureConverter* temperatureConverter : temperatureConvertersList) {
            convertedTemperatures.push_back(temperatureConverter->getConvertedTemperature(celsius));
        }
        return convertedTemperatures;
    }
};
