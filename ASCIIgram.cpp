#include "ASCIIgram.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream>

namespace ASCIIgram
{
    Histogram::Histogram(const std::vector<int> &dataset, const int maxBins)
    {
        if (dataset.empty())
        {
            throw std::invalid_argument(
                "Could not create histogram: dataset is empty.");
        }
        if (maxBins < 1)
        {
            throw std::invalid_argument(
                "Could not create histogram: maxBins must be greater than 0.");
        }

        // calculate range without sorting
        const auto minMax = std::minmax_element(dataset.begin(), dataset.end());
        m_min = *minMax.first;
        const int max = *minMax.second;
        const int range = max - m_min;
        m_nBins = maxBins;

        // calculate bin size, rounding up
        m_binSize = (range + 1 + m_nBins - 1) / m_nBins;

        // if max bins cannot be used, use the range
        if (range < maxBins)
        {
            m_nBins = range + 1;
            m_binSize = 1;
        }
        // if the start of the last bin > max latency (i.e.empty)
        // reduce the number of bins until the last bin is <= max latency
        //(i.e. not empty)
        while (m_min + ((m_nBins - 1) * m_binSize) > max)
        {
            --m_nBins;
        }

        m_bins.resize(m_nBins); // allocate space for bins
        // calculate bin counts
        for (const auto &points : dataset)
        {
            // Ssubtract the minimum value from the points and divide by the bin
            // size to get a bin number between 0 and the number of bins.
            const int binNo = (points - m_min) / m_binSize;
            ++m_bins[binNo];
        }
    }

    std::string Histogram::toString(std::string unit, char marker, int fieldWidth,
                                    int barScale) const
    {
        // create output stream
        std::stringstream sout;
        // set precision to 2 decimal places and use fixed notation
        sout << std::setprecision(2) << std::fixed;
        // sum of all latencies, needed for normalization
        const int totalLatencies = std::accumulate(m_bins.begin(), m_bins.end(), 0);

        for (int i = 0; i < m_nBins; ++i)
        {
            // normalize bin counts between 0 and 1
            double normalizedBinCount =
                static_cast<double>(m_bins[i]) / totalLatencies;

            // scale normalized bin count
            const int barLength = (static_cast<int>(normalizedBinCount * barScale));

            // calculate bin start and end
            const int binStart = m_min + (i * m_binSize);
            const int binEnd = binStart + m_binSize - 1;

            // // information about the bin
            sout << std::right; // reset to right justification
            sout << std::setw(fieldWidth);
            sout << binStart << unit;
            // only print the end of the bin if it is different from the start
            if (binStart != binEnd)
            {
                sout << " - " << std::setw(fieldWidth);
                sout << binEnd << unit;
            }
            sout << " (";
            sout << std::left; // left justify for decimals
            sout << normalizedBinCount << ") | ";

            // draw the bar symbol barLength times
            sout << std::string(barLength, marker) + "\n";
        }
        return sout.str();
    }
    int Histogram::getMaxBins() const { return m_nBins; }
}